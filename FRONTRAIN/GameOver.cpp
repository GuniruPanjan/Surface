#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Rect.h"

SceneFedo Scenefedo;

Rect m_colRect;
Rect Mouse;

int GameOverColor, GameOverblack, GameOverYello;

static int mimageHandle;  //�摜�n���h���i�[�p�ϐ�

static int GameOverHandle;  //�摜�n���h���i�[�p�ϐ�

static int Botton;   //�{�^���摜�i�[�p�ϐ�

static int b;   //�摜���ߗp�ϐ�

bool gameover;

//�}�E�X�̍��W���擾���邽�߂̕ϐ�
int  gmMouseX, gmMouseY;

//�}�E�X�̓����蔻��̕�
int GameOverMouseDecisionX, GameOverMouseDecisionY;

//GameOver�����o�͂���ꏊ�ϐ�
int GameOverX, GameOverY;

//�T�E���h�p�i�[�ϐ�
int SoundGameOver;

//SE�p�i�[�ϐ�
int SEClickGameOver;

//������
void GameOver_Initialize()
{
	mimageHandle = LoadGraph("date/�Q�[���I�[�o�[���.png");  //�摜�̃��[�h

	GameOverHandle = LoadGraph("date/Game Over.png");  //�摜���[�h

	Scenefedo.Init();

	GameOverColor = 0;
	GameOverblack = GetColor(0, 0, 0);
	GameOverYello = GetColor(255, 255, 0);

	gmMouseX = 0;
	gmMouseY = 0;

	gameover = false;

	Botton = LoadGraph("date/�{�^��.png");

	b = 255;

	SoundGameOver = LoadSoundMem("BGM/�p��̕�.mp3");

	SEClickGameOver = LoadSoundMem("SE/����{�^��������40.mp3");

	GameOverMouseDecisionX = 10;
	GameOverMouseDecisionY = 10;

	GameOverX = 70;
	GameOverY = 0;
}

//�I������
void GameOver_Finalize()
{
	DeleteGraph(mimageHandle);   //�摜�̉��

	DeleteGraph(GameOverHandle);  //�摜�̉��

	DeleteSoundMem(SoundGameOver);

	DeleteSoundMem(SEClickGameOver);

	DeleteGraph(Botton);

	Scenefedo.FinalizeFedo();
}

//�X�V
void GameOver_Update()
{
	Scenefedo.UpdateIn();

	if (Scenefedo.a >= 255)
	{
		Scenefedo.Update();
	}
	
	//�N���b�N�����ƃV�[���ύX
	if (Scenefedo.end == 1 && Scenefedo.Setting == true)
	{
		SceneMgr_ChageScene(eScene_Config);//�V�[�����L�^�ɕύX
	}

	
	if(gameover == true)
	{
		Scenefedo.Out = 1;

		Scenefedo.Setting = true;
	}

	//�}�E�X�̍��W�擾
	GetMousePoint(&gmMouseX, &gmMouseY);

	//�{�^���ɐG��Ă���Ƃ�
	if (m_colRect.IsCollision(Mouse) == true)
	{
		GameOverColor = GameOverYello;

		b = 120;
		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			PlaySoundMem(SEClickGameOver, DX_PLAYTYPE_BACK, FALSE);

			gameover = true;
		}
	}
	//�{�^���ɐG��Ă��Ȃ��Ƃ�
	else if (m_colRect.IsCollision(Mouse) == false)
	{
		GameOverColor = GameOverblack;

		b = 255;
	}

	PlaySoundMem(SoundGameOver, DX_PLAYTYPE_LOOP, FALSE);

}

void GameOver_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);

	DrawGraph(GameOverX, GameOverY, GameOverHandle, true);

	//�}�E�X�̓����蔻��擾
	Mouse.SetCenter(static_cast<float>(gmMouseX), static_cast<float>(gmMouseY + 5), static_cast<float>(GameOverMouseDecisionX), static_cast<float>(GameOverMouseDecisionY));

	//�{�^���̕\��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(40, 400, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetFontSize(22);

	m_colRect.SetCenter(100, 415, 120, 30);
	DrawString(65, 402, "�X�R�A", GameOverColor);

}
