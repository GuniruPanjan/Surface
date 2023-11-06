#include "SceneMain.h"
#include "DxLib.h"
#include "Game.h"
#include <cassert>

namespace
{
	//�Q�[���I�[�o�[���ɕ\�����镶����
	const char* const kGameOverString = "GAME OVER";

	//�G�̐����Ԋu�i�t���[�����j
	constexpr int kEnemyDefaultWaitFrame = 60;
	//�G�̍ŒZ�����Ԋu
	constexpr int kEnemyWaitFrameMin = 3;
	//�G�̐����Ԋu��G���̐������邽�тɒZ�����邩
	constexpr int kEnemyWaitFrameChangeNum = 5;
	//��x�����Ԋu��Z�����鎞�ɉ��t���[���Z�����邩
	constexpr int kEnemyWaitFrameChangeFrame = 1;

}

SceneMain::SceneMain():
	m_playerHandle(-1),
	m_enemyHandle(-1),
	m_enemyStartSe(-1),
	m_bgmHndle(-1),
	m_player(),    //�N���X������������Ƃ��A()�̒��ɂ̓R���X�g���N�^�̈���������
	               //Player�N���X�Ɋւ��Ă̓R���X�g���N�^�Ɉ������Ȃ��̂�()��OK
	m_enemy(),
	m_isGameOver(false),
	m_isSceneEnd(false),
	m_playFrameCount(0),
	m_enemyCreateNum(0),
	m_enemyWaitFrame(0),
	m_fadeAlpha(255)      //�s�����ŏ�����
{
}

SceneMain::~SceneMain()
{
	
}

void SceneMain::Init()
{
	//BGM�̓ǂݍ���
	m_bgmHndle = LoadSoundMem("data/Sound/30m.rarara.mp3");

	//BGM�̍Đ�
	PlaySoundMem(m_bgmHndle, DX_PLAYTYPE_LOOP);


	ChangeFont("�l�r �S�V�b�N");
	
	//�O���t�B�b�N�̃��[�h
	int m_playerHandle= LoadGraph("data/gamechara.png");
	assert(m_playerHandle != -1);    //�O���t�B�b�N�̃��[�h�Ɏ��s
	int m_enemyHandle = LoadGraph("data/�Q�[���L�����Q.png");
	assert(m_enemyHandle != -1);     //�O���t�B�b�N�̃��[�h�Ɏ��s

	//�T�E���h�̃��[�h
	//m_enemyStartSe = LoadSoundMem("data/Sound/30m.rarara.mp3");

	m_player.Init();
	m_player.SetGraphHandle(m_playerHandle);

	for (int i = 0; i < kEnemyMax; i++)
	{
		m_enemy[i].Init();
		m_enemy[i].SetGraphHandle(m_enemyHandle);
		m_enemy[i].SetStartPos();
	}

	//�e��ϐ��̏�����
	m_isGameOver = false;
	m_isSceneEnd = false;
	m_playFrameCount = 0;
	m_enemyCreateNum = 0;
	m_enemyWaitFrame = 0;

	m_fadeAlpha = 255;
	
}

void SceneMain::Update()
{

	
	//�Q�[���I�[�o�[�Ȃ�e�������s�킸�A��Update()���I��������
	if (m_isGameOver)
	{
		if (m_isSceneEnd)
		{
			//�t�F�[�h�A�E�g
			m_fadeAlpha += 8;
			if (m_fadeAlpha > 255 )
			{
				m_fadeAlpha = 255;
			}
		}
		int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if(pad & PAD_INPUT_1)
		{
			m_isSceneEnd = true;
		}
		return;
	}

	//�t�F�[�h�C��
	m_fadeAlpha -= 8;
	if (m_fadeAlpha < 0)
	{
		m_fadeAlpha = 0;
	}

	m_playFrameCount++;

	m_player.Update();
	for (int i = 0; i < kEnemyMax; i++)
	{
		m_enemy[i].Update();
		if (IsCollison(m_player, m_enemy[i]))
		{
			m_isGameOver = true;
		}
	}

	//���Ԋu�œG�𐶐�
	m_enemyWaitFrame++;

	
	//�G����萔�������邽�тɓG�̐����Ԋu���Z���Ȃ�
	int waitFrame = kEnemyDefaultWaitFrame;
	waitFrame -= (m_enemyCreateNum / kEnemyWaitFrameChangeNum) * kEnemyWaitFrameChangeFrame;
	//��ԒZ�������Ԋu�̃`�F�b�N
	if (waitFrame < kEnemyWaitFrameMin) waitFrame = kEnemyWaitFrameMin;

	if(m_enemyWaitFrame >= kEnemyDefaultWaitFrame)
	{
		for (int i = 0; i < kEnemyMax; i++)
		{
			//m_enemy[i].isExist()��false�̏ꍇ���݂��Ă��Ȃ�
			if (!m_enemy[i].isExist())
			{
				m_enemyCreateNum++;
				m_enemyWaitFrame = 0;
				m_enemy[i].Start();

				//PlaySoundMem(m_enemyStartSe,DX_PLAYTYPE_BACK);

				break; //1�̐���������I��
			}
		}
		
	}
	
}

void SceneMain::Draw()
{
	m_player.Draw();
	for (int i = 0; i < kEnemyMax; i++)
	{
		m_enemy[i].Draw();
	}
	

	//�������Ԃ�\��
	//���F�b.�~���b
	int milliSec = m_playFrameCount * 1000 / 60;
	int sec = (milliSec / 1000) % 60;
	int min = (milliSec / 1000) / 60;
	milliSec %= 1000;    //�~���b�̕����̂ݎc��

	//������̉����擾
	int strWidth = GetDrawFormatStringWidth("%d:%d.%d", min, sec, milliSec);

	DrawFormatString(Game::kScreenWidth / 2 - strWidth / 2, 8, GetColor(255, 255, 255), "%d:%d.%d", min, sec, milliSec);

	for (int i = 0; i < kEnemyMax; i++)
	{
		if (IsCollison(m_player, m_enemy[i]))
		{
			//��ʒ����ɃQ�[���I�[�o�[�\��

			//�\�����镶���̉������擾����
			//GetDrawStringWidth(char* String, int StrLen);
			int len = strlen(kGameOverString);
			int width = GetDrawStringWidth("GAMEOVER", 14);
			int height = GetFontSize();

			DrawString(Game::kScreenWidth / 2 - width / 2, Game::kScreenHeigth / 2 - height / 2, "GAMEOVER", GetColor(255, 32, 32));
		}
	}
	
	//�t�F�[�h�̕`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,m_fadeAlpha);        //�������ŕ\���J�n
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeigth, GetColor(255, 255, 255), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      //�s�����ɂ��Ă���
}

void SceneMain::End()
{
	//BGM���~�߂�
	StopSoundMem(m_bgmHndle);

	//BGM������������폜
	DeleteSoundMem(m_bgmHndle);

	DeleteGraph(m_playerHandle);
	DeleteGraph(m_enemyHandle);
}


bool SceneMain::IsSceneEnd() const
{
	return m_isSceneEnd && (m_fadeAlpha >= 255);
}

//�������Ă���ꍇtrue��Ԃ�(return true;����)
//�������Ă��Ȃ��ꍇfalse��Ԃ�(return false;����)
bool SceneMain::IsCollison(const Player& player, const Enemy& enemy)
{
	if (!enemy.isExist())	return false;
	bool isCollison = true;   //���������t���O

	//�v���C���[�������S�ɍ����ɂ���ꍇ�͓������Ă��Ȃ�
	//�v���C���[���[�������ɓG�ɉE�[������ꍇ�͓������Ă��Ȃ�
	if (player.GetLeft() > enemy.GetRight())
	{
		return false;  //�m���ɓ������Ă��Ȃ��̂�false��Ԃ�
	}

	if (player.GetBottom() < enemy.GetTop())
	{
		return false;
	}

	if (player.GetRight() < enemy.GetLeft())
	{
		return false;
	}

	if (player.GetTop() > enemy.GetBottom())
	{
		return false;
	}
	return true;
}
