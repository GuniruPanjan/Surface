#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Rect.h"

SceneFedo Scenefedo;

Rect m_colRect;
Rect Mouse;

int GameOverColor, GameOverWhite, GameOverYello;

static int mimageHandle;  //�摜�n���h���i�[�p�ϐ�

static int GameOverHandle;  //�摜�n���h���i�[�p�ϐ�

bool gameover;

//�}�E�X�̍��W���擾���邽�߂̕ϐ�
int  gmMouseX, gmMouseY;

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
	GameOverWhite = GetColor(255, 255, 255);
	GameOverYello = GetColor(255, 255, 0);

	gmMouseX = 0;
	gmMouseY = 0;

	gameover = false;

	SoundGameOver = LoadSoundMem("BGM/�p��̕�.mp3");

	SEClickGameOver = LoadSoundMem("SE/����{�^��������40.mp3");
}

//�I������
void GameOver_Finalize()
{
	DeleteGraph(mimageHandle);   //�摜�̉��

	DeleteGraph(GameOverHandle);  //�摜�̉��
}

//�X�V
void GameOver_Update()
{
	Scenefedo.UpdateIn();

	//SPACE�L�[��������Ă�����
	//if (CheckHitKey(KEY_INPUT_SPACE) != 0)
	if(gameover == true)
	{
		SceneMgr_ChageScene(eScene_Config);//�V�[�������j���[�ɕύX

		DeleteSoundMem(SoundGameOver);

		DeleteSoundMem(SEClickGameOver);
	}

	//�}�E�X�̍��W�擾
	GetMousePoint(&gmMouseX, &gmMouseY);

	if (m_colRect.IsCollision(Mouse) == true)
	{
		GameOverColor = GameOverYello;
		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			PlaySoundMem(SEClickGameOver, DX_PLAYTYPE_BACK, FALSE);

			gameover = true;
		}
	}
	else if (m_colRect.IsCollision(Mouse) == false)
	{
		GameOverColor = GameOverWhite;
	}

	PlaySoundMem(SoundGameOver, DX_PLAYTYPE_LOOP, FALSE);

}

void GameOver_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);

	DrawGraph(70, 0, GameOverHandle, true);

	//�}�E�X�̓����蔻��擾
	Mouse.SetCenter(gmMouseX, gmMouseY + 5, 10, 10);

	//DrawString(0, 0, "�Q�[���I�[�o�[��ʂł�", GetColor(255, 255, 255));
	m_colRect.SetCenter(63, 410, 50, 25);
	DrawString(40, 400, "�L�^", GameOverColor);

	/*m_colRect.Draw(GetColor(255, 0, 0), false);
	Mouse.Draw(GetColor(255, 0, 0), false);*/
}
