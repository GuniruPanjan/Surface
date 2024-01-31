#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Game.h"
#include "SceneFedo.h"
#include "SceneExplanation.h"

SceneFedo fedo;


static int mimageHandle;  //�摜�n���h���i�[�p�ϐ�

static int Graph[9];   //�摜�n���h���i�[�p�ϐ�

static int AnimCount; //�A�j���[�V�����J�E���g

static int Time; //�A�j���[�V�����^�C��

static bool Plus, Mainas;

bool ContinueInit; //�R���e�j���[�����Ƃ��ɏ���������

//������
void Menu_Initialize()
{
	mimageHandle = LoadGraph("date/�X�^�[�g���.png");    //�摜���[�h

	LoadDivGraph("date/Danceto.png", 9, 3, 3, 160, 90, Graph);

	AnimCount = 0;

	Time = 0;

	Plus = true;

	Mainas = false;

	ContinueInit = true;
}

//�I������
void Menu_Finalize()
{
	DeleteGraph(mimageHandle); //�摜�̉��

	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(Graph[i]);
	}

	fedo.Init();
}

//�X�V
void Menu_Update()
{

	//ContinueInit��true�Ȃ�1����s����
	if (ContinueInit == true)
	{
		//�Q�[���V�[��������������
		Game_Initialize();

		fedo.Init();
	}
	
	ContinueInit = false;


	fedo.Update();

	//�Q�[���V�[��
	if (fedo.end == 1 && fedo.Start == true)
	{
	
		SceneMgr_ChageScene(eScene_Game);//�V�[�����Q�[����ʂɕύX

		ContinueInit = true;

		
	}
	//�������
	if (fedo.end == 1 && fedo.Explanation == true)
	{
		SceneMgr_ChageScene(eScene_Explanation); //�V�[���������ʂɕύX

		ContinueInit = true;
	}
	//�ݒ���
	if (fedo.end == 1 && fedo.Setting == true)
	{
		SceneMgr_ChageScene(eScene_Config);//�V�[����ݒ��ʂɕύX

		ContinueInit = true;

		
	}



	//A�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_A) != 0)
	{

		fedo.Out = 1;
		
		fedo.Start = true;

	}
	//B�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_B) != 0)
	{
		fedo.Out = 1;

		fedo.Explanation = true;
	}
	//C�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		fedo.Out = 1;

		fedo.Setting = true;
		
	}
}

//�`��
void Menu_Draw()
{
	fedo.Draw();

	DrawGraph(0, 0, mimageHandle, false);

	Time++;
	if (Time >= 5)
	{

		
		if (Plus == true)
		{
			AnimCount++;

			if (AnimCount >= 9)
			{
				Plus = false;

				Mainas = true;
			}
		}
		if (Mainas == true)
		{
			AnimCount--;

			if (AnimCount <= 0)
			{
				Mainas = false;

				Plus = true;
			}
		}
		

		Time = 0;
	}
	

	DrawGraph(0, 50, Graph[AnimCount], true);

	fedo.StartUpdate();

	SetFontSize(22);

	ChangeFont("�A�v������", DX_CHARSET_DEFAULT);
	DrawBox(248, 310, 390, 340, GetColor(255, 0, 0),false);
	DrawString(250, 310, "A�L�[START", GetColor(255, 255, 255));

	DrawBox(248, 400, 405, 365, GetColor(255, 0, 0), false);
	DrawString(250, 370, "B�L�[�������", GetColor(255, 255, 255));

	DrawBox(248, 460, 360, 425, GetColor(255, 0, 0), false);
	DrawString(250, 430, "C�L�[�L�^", GetColor(255, 255, 255));

}
