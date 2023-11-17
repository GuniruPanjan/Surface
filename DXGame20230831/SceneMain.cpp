#include "SceneMain.h"
#include "DxLib.h"
#include "Player.h"
#include "Bg.h"
#include "Pad.h"
#include "Rect.h"

//�o�ꂷ��G
//#include "EnemyBase.h"
#include "EnemyLeft.h"
#include "EnemyRight.h"
#include "EnemyToPlayer.h"

//�o�ꂷ��V���b�g
#include "ShotMagicWand.h"

#include <cassert>

namespace
{
	//��x�ɓo��ł���G�̍ő吔
	constexpr int kEnemyMax = 64;
	//���t���[�������ɓG���o�ꂷ�邩
	constexpr int kEnemyInterval = 20;

	//��ʓ��Ɉ�x�ɏo�Ă���e�̍ő吔
	constexpr int kShotMax = 20;
}

SceneMain::SceneMain()
	//m_enemyFrameCount(0)
{
	//�O���t�B�b�N�̃��[�h
	m_playerHandle = LoadGraph("data/player.png");
	assert(m_playerHandle != -1);
	m_enemyHandle = LoadGraph("data/gamechara.png");
	assert(m_enemyHandle != -1);
	m_bgHandle = LoadGraph("data/bg.png");
	assert(m_bgHandle != -1);
	//�v���C���[�̃������m��
	m_pPlayer = new Player(this);
	m_pPlayer->SetHandle(m_playerHandle);   //Player�ɃO���t�B�b�N�̃n���h����n��

	//�G�̃������m��
	/*for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemyRight[i] = new EnemyRight;
		m_pEnemyRight[i]->SetHandle(m_enemyHandle);

		m_pEnemyToPlayer[i] = new EnemyToPlayer;
		m_pEnemyToPlayer[i]->SetHandle(m_enemyHandle);
		m_pEnemyToPlayer[i]->SetPlayer(m_pPlayer);
	}
	m_pEnemyLeft = new EnemyLeft;
	m_pEnemyLeft->SetHandle(m_enemyHandle);*/

	//�w�i�̃������m��
	m_pBg = new Bg;
	m_pBg->SetHandle(m_bgHandle);

	//�G�̏���
	//m_pEnemy(vector)�������Ȃ���΃T�C�Y��0

	//resize�֐���kEnemyMax�����f�[�^��ۑ��ł���悤�ɂ���
	m_pEnemy.resize(kEnemyMax);

	//�����̓R���X�g���N�^�Ń��������m�ۂ���
	//�f�X�g���N�^�ŉ�����Ă�������
	//�����_����EnemyLeft,EnemyRight,EnemyToPlayer���m�ۂ�����
	//�ǂꂩ������Ȃ��̂ł��炩���ߊm�ۂ��邱�Ƃ��ł��Ȃ��I
	//->���I�Ƀ��������m�ۂ��� Update()���ɕK�v�ɉ�����

	//������Ԃł̓��������m�ۂ��Ă��Ȃ�����������悤�ɂ��Ă���
	//���g�p��Ԃɂ��� nullptr�����Ă���
	// size()�Ō��ݎg�p�\�ȗv�f�����擾�\
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		m_pEnemy[i] = nullptr;

		//m_pEnemy�̒��ɂ͉������邩������Ȃ�
		//���̂����ꂩ������
		// �����_�ł͂ǂꂪ����̂�����ł��Ȃ�
		// new EnemyLeft;
		// new EnemyRight;
		// new EnemyToPlayer;

	}
	//�V���b�g�̏���
	m_pShot.resize(kShotMax);
	for (int i = 0; i < m_pShot.size(); i++)
	{
		m_pShot[i] = nullptr;  //���g�p
	}

	//m_pEnemy[0] ~ m_pEnemy[63]
	//m_pShot = new ShotMagicWand;
	//SceneMain�̊֐����g�������̂Ń|�C���^��n���Ă���
	//this�Ŏ��g�̃|�C���^���擾�\
	//m_pShot->SetMain(this);
}

SceneMain::~SceneMain()
{
	//����������O���t�B�b�N���폜
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_enemyHandle);
	DeleteGraph(m_bgHandle);
	//�������̉��
	delete m_pPlayer;
	m_pPlayer = nullptr;

	delete m_pBg;
	m_pBg = nullptr;

	/*for (int i = 0; i < kEnemyNum; i++)
	{
		delete m_pEnemyRight[i];
		m_pEnemyRight[i] = nullptr;

		delete m_pEnemyToPlayer[i];
		m_pEnemyToPlayer[i] = nullptr;
	}
	delete m_pEnemyLeft;
	m_pEnemyLeft = nullptr;*/

	//���������m�ۂ���Ă���G��T���ĉ�����Ă���
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		//nullptr�ȊO�̕��������Ă���Ƃ������Ƃ͂����Ƀ|�C���^�������Ă���
		if (m_pEnemy[i] == nullptr)
		{
			delete m_pEnemy[i];
			m_pEnemy[i] = nullptr;  //���g�p��Ԃƕ�����悤�ɂ��Ă���

		}
	}

	m_pShot.resize(kShotMax);
	for (int i = 0; i < m_pShot.size(); i++)
	{
		if (m_pShot[i])
		{
			//nullptr�ł͂Ȃ��ꍇ
			delete m_pShot[i];
			m_pShot[i] = nullptr;
		}
	}

	//delete m_pShot;
	//m_pShot = nullptr;
}

void SceneMain::Init()
{
	assert(m_pPlayer);   // m_pPlayer == nullptr�̏ꍇ�~�܂�

	m_pPlayer->Init();
	/*for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemyRight[i]->Init();
		m_pEnemyToPlayer[i]->Init();
	}
	m_pEnemyLeft->Init();

	m_enemyFrameCount = 0;*/

	m_pBg->Init();
}

void SceneMain::End()
{
	
}

void SceneMain::Update()
{
	
	m_pPlayer->Update();
	/*for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemyRight[i]->Update();
		m_pEnemyToPlayer[i]->Update();
	}
	m_pEnemyLeft->Update();*/

	m_pBg->Update();

	Rect playerRect = m_pPlayer->GetColRect();

	//�G�L�����N�^�[��o�ꐧ��
//	m_enemyFrameCount++;
//	if (m_enemyFrameCount >= 60)
//	{
//		m_enemyFrameCount = 0;
//
//		for (int i = 0; i < kEnemyNum; i++)
//		{
//#if false
//			if (!m_pEnemyRight[i]->isExist())
//			{
//				m_pEnemyRight[i]->Start();
//				break;
//			}
//#else
//			if (!m_pEnemyToPlayer[i]->isExist())
//			{
//				m_pEnemyToPlayer[i]->Start();
//				break;
//			}
//#endif
//		}
//	}
//	//Test �{�^�����������Ƃ��o�ꂷ��G
//	if (Pad::isPadTrigger(PAD_INPUT_1))
//	{
//		m_pEnemyLeft->Start();
//	}
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (m_pEnemy[i])   //nullptr�ł͂Ȃ��`�F�b�N
		{
			m_pEnemy[i]->Update();

			//�g�p�ς݂̓G�L�����N�^�[���폜����K�v������
			if (!m_pEnemy[i]->isExist() )
			{
				//���������������
				delete m_pEnemy[i];
				m_pEnemy[i] = nullptr; //�g���Ă��Ȃ��ƕ�����Ή��
			}
			else
			{
				//���݂��Ă���G�ƃv���C���[�̂����蔻��
				Rect enemyRect = m_pEnemy[i]->GetColRect();
				if (playerRect.IsCollision(enemyRect))
				{
					//test
					//printfDx("�������Ă���\n");
					m_pPlayer->OnDamage();
				}
			}
		}
	}

	for (int i = 0; i < m_pShot.size(); i++)
	{
		//nullptr�Ȃ珈���͍s��Ȃ�
		if (!m_pShot[i]) continue;

		m_pShot[i]->Update();
		//��ʊO�ɏo���烁�������
		if (!m_pShot[i]->isExist())
		{
			delete m_pShot[i];
			m_pShot[i] = nullptr;
		}
	}
	

	//�G�L�����N�^�[��o�ꂳ����
	//kEnemyInterval�t���[���o�߂��邲�ƂɃ����_���ɓG��o�ꂳ����

	m_enemyInterval++;
	if (m_enemyInterval >= kEnemyInterval)
	{
		m_enemyInterval = 0;

		//�����_���ɓG��I��
		switch (GetRand(2))
		{
		case 0:     //Left

			CreateEnemyLeft();

			break;
		case 1:     //Right

			CreateEnemyRight();

			break;
		default:
			//�z�肵�Ȃ��������@�@�����ɂ�����o�O
			assert(false);
			break;
		case 2:     //ToPlayer

			CreateEnemyToPlayer();

			break;

			
		}
	}

	if (Pad::isPadTrigger(PAD_INPUT_1))
	{
		//m_pShot->Start(m_pPlayer->GetPos());
		for (int i = 0; i < m_pShot.size(); i++)
		{
			//�g�p���Ȃ玟�̃`�F�b�N��
			if (m_pShot[i]) continue;

			//�����ɂ����Ƃ������Ƃ�m_pShot[i] == nullptr
			m_pShot[i] = new ShotMagicWand;

			m_pShot[i]->Init();
			m_pShot[i]->SetMain(this);
			m_pShot[i]->Start(m_pPlayer->GetPos());

			//1���݂̂�������
			break;
		}
	}

}

void SceneMain::Draw() const
{
	m_pBg->Draw();

	m_pPlayer->Draw();

	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (m_pEnemy[i])   //nullptr�ł͂Ȃ��`�F�b�N
		{
			m_pEnemy[i]->Draw();
		}
	}
	for (int i = 0; i < m_pShot.size(); i++)
	{
		if (!m_pShot[i])  continue;
		m_pShot[i]->Draw();
	}
	/*for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemyRight[i]->Draw();
		m_pEnemyToPlayer[i]->Draw();
	}
	m_pEnemyLeft->Draw();*/

	//�f�o�b�O�\��
	DrawString(8, 8, "SceneMain", GetColor(255, 255, 255));

	//�v���C���[�̍��W���f�o�b�O�\������
	Vec2 playerPos = m_pPlayer->GetPos();
	DrawFormatString(8, 24, GetColor(255, 255, 255),
		"�v���C���[�̍��W(%.2f,%.2f)", playerPos.x, playerPos.y);

	//m_pShot->Draw();
}

Vec2 SceneMain::GetNearEnemyPos(Vec2 pos) const
{
	//�G�����Ȃ��ꍇ�͓K���ȍ��W��Ԃ�
	Vec2 result{ 0,0 };
	//�ŏ��̓G�`�F�b�N�ς݃t���O
	bool isFirst = true;

	//��ԋ߂��G�L�����N�^�[�̍��W��rezult�ɓ����
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		//�g���Ă��Ȃ��G�̓`�F�b�N���Ȃ�
		if (!m_pEnemy[i]) continue;

		//�����ɂ��Ă��鎞�_��m_pEnem[i]��nullptr�o�Ȃ����Ƃ͊m��

		//���łɏ����邱�Ƃ��m�肵�Ă���G�̓`�F�b�N���Ȃ�
		if (!m_pEnemy[i]->isExist()) continue;

		//pos��m_pEnemy[i]�̋������`�F�b�N����

		if (!isFirst)
		{
			//1�̖ڂ̓G
			//�����������痣��Ă��悤�ƌ����_�ł͈�ԋ߂��G
			result = m_pEnemy[i]->GetPos();
			isFirst = false;
		}
		else
		{
			//2�̖ڂ̈ȍ~�̓G
			//result�̒��ɂ͈�ԋ߂��G�̍��W�������Ă���

			//���܂Ń`�F�b�N�������ň�ԋ߂��G�Ƃ̋���
			Vec2 toNear = result - pos; //pos����b��1�ʂ̍��W�Ɍ������x�N�g��
			//float minDist;

			//�`�F�b�N����G�Ƃ̋���
			Vec2 toEnemy = m_pEnemy[i]->GetPos() - pos; //pos����`�F�b�N���̓G�Ɍ������x�N�g��

			//�������y�����邽�ߋ����̔�r���s���ꍇ�͂Q��ōs��
			if (toNear.sqLength() > toEnemy.sqLength())
			{
				//���`�F�b�N���Ă���G�ւ̋������b��P�ʂ����Z���ꍇ
				//���`�F�b�N���Ă���G���b��P�ʂ�
				result = m_pEnemy[i]->GetPos();
			}
			//�b��P�ʂ̕������`�F�b�N���Ă���G���߂��ꍇ�͉������Ȃ�

			//��ԋ߂��G�Ȃ�����X�V

			//��ԋ߂��G���������ꍇ�͉������Ȃ�

		}
	}
	//���ׂĂ̓G�̃`�F�b�N���s�����̂ł������P�ʂŊm��
	return result;
}

bool SceneMain::AddShot(ShotBase* pShot)
{
	for (int i = 0; i < m_pShot.size(); i++)
	{
		//�g�p���Ȃ玟�̃`�F�b�N��
		if (m_pShot[i]) continue;

		//�����ɗ����Ƃ������Ƃ�m_pShot[i] == nullptr
		m_pShot[i] = pShot;
		//�o�^������I��
		return false;
	}

	//�����ɗ����A�Ƃ������Ƃ�m_pShot�Ƀ|�C���^��o�^�o���Ȃ�����
	delete pShot;
	return false;
}

void SceneMain::CreateEnemyLeft()
{
	//�g���Ă��Ȃ�����T���Ă����ɃA�h���X��ۑ�����
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i]) //nullptr�ł��邱�Ƃ��`�F�b�N����
		{
			m_pEnemy[i] = new EnemyLeft;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);
			m_pEnemy[i]->Start();
			return;  //�������m�ۂł����炻�̎��_�ŏI��
		}
	}
}

void SceneMain::CreateEnemyRight()
{
	//�g���Ă��Ȃ�����T���Ă����ɃA�h���X��ۑ�����
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i]) //nullptr�ł��邱�Ƃ��`�F�b�N����
		{
			m_pEnemy[i] = new EnemyRight;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);
			m_pEnemy[i]->Start();
			return;  //�������m�ۂł����炻�̎��_�ŏI��
		}
	}
}

void SceneMain::CreateEnemyToPlayer()
{
	//�g���Ă��Ȃ�����T���Ă����ɃA�h���X��ۑ�����
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i]) //nullptr�ł��邱�Ƃ��`�F�b�N����
		{
			//Base�������Ȃ��Ǝ��̊֐����Ăт���
			EnemyToPlayer* pEnemy = new EnemyToPlayer;

			pEnemy->Init();
			pEnemy->SetHandle(m_enemyHandle);
			pEnemy->SetPlayer(m_pPlayer);  //pPlayer��EnemyToPlaeyr�Ȃ̂ŌĂׂ�
			pEnemy->Start();

			//pEnemy�͂���������̂�m_pEnemy�Ɋm�ۂ����A�h���X���R�s�[���Ă���
			m_pEnemy[i] = pEnemy;

			/*m_pEnemy[i] = new EnemyToPlayer;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);*/

			//Player��ݒ肷��K�v������
			/*m_pEnemy[i]->SetHandle(m_pPlayer);

			m_pEnemy[i]->Start();*/

			return;  //��̕��������m�ۂł����炻�̎��_�ŏI��
		}
	}
}
