#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Game.h"
#include "SceneFedo.h"
#include "SceneExplanation.h"

SceneFedo fedo;

//�����蔻��̋�`
Rect m_colRectStart;   //Start�{�^���̔���
Rect m_colRectExplanation;   //�����{�^���̔���
Rect m_colRectRecord;    //�L�^�{�^���̔���

Rect m_colRectMouse;  //�}�E�X�̔���

static int mimageHandle;  //�摜�n���h���i�[�p�ϐ�

static int Graph[9];   //�摜�n���h���i�[�p�ϐ�

static int AnimCount; //�A�j���[�V�����J�E���g

static int Time; //�A�j���[�V�����^�C��

static bool Plus, Mainas;

bool ContinueInit; //�R���e�j���[�����Ƃ��ɏ���������

bool Start, Explanaion, Record;

//�}�E�X�̍��W���擾���邽�߂̕ϐ�
int MouseX, MouseY;

int StartColor, StartWhite, StartYello;
int ExplanationColor, ExplanationWhite, ExplanationYello;
int RecordColor, RecordWhite, RecordYello;


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

	Start = false;

	Explanaion = false;

	Record = false;

	MouseX = 0;
	MouseY = 0;

	StartColor = 0;
	ExplanationColor = 0;
	RecordColor = 0;

	StartWhite = GetColor(255, 255, 255);
	ExplanationWhite = GetColor(255, 255, 255);
	RecordWhite = GetColor(255, 255, 255);

	StartYello = GetColor(255, 255, 0);
	ExplanationYello = GetColor(255, 255, 0);
	RecordYello = GetColor(255, 255, 0);

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
	//if (CheckHitKey(KEY_INPUT_A) != 0)
	if(Start == true)
	{

		fedo.Out = 1;
		
		fedo.Start = true;

	}
	//B�L�[��������Ă�����
	//if (CheckHitKey(KEY_INPUT_B) != 0)
	if(Explanaion == true)
	{
		fedo.Out = 1;

		fedo.Explanation = true;
	}
	//C�L�[��������Ă�����
	//if (CheckHitKey(KEY_INPUT_C) != 0)
	if(Record == true)
	{
		fedo.Out = 1;

		fedo.Setting = true;
		
	}

	//�}�E�X�̍��W�擾
	GetMousePoint(&MouseX, &MouseY);

	//�{�^���Ƃ̓����蔻��
	if (m_colRectStart.IsCollision(m_colRectMouse) == true)
	{
		StartColor = StartYello;

		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Start = true;
		}
	}
	else if (m_colRectStart.IsCollision(m_colRectMouse) == false)
	{
		StartColor = StartWhite;
	}

	if (m_colRectExplanation.IsCollision(m_colRectMouse) == true)
	{
		ExplanationColor = ExplanationYello;

		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Explanaion = true;
		}
	}
	else if (m_colRectExplanation.IsCollision(m_colRectMouse) == false)
	{
		ExplanationColor = ExplanationWhite;
	}

	if (m_colRectRecord.IsCollision(m_colRectMouse) == true)
	{
		RecordColor = RecordYello;

		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Record = true;
		}
	}
	else if (m_colRectRecord.IsCollision(m_colRectMouse) == false)
	{
		RecordColor = RecordWhite;
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

	SetFontSize(22);

	//�}�E�X�̓����蔻��擾
	m_colRectMouse.SetCenter(MouseX, MouseY + 5, 10, 10);

	ChangeFont("�A�v������", DX_CHARSET_DEFAULT);
	//DrawBox(248, 310, 390, 340, GetColor(255, 0, 0),false);
	m_colRectStart.SetCenter(320, 320, 120, 30);
	DrawString(285, 310, "START", StartColor);

	//DrawBox(248, 400, 405, 365, GetColor(255, 0, 0), false);
	m_colRectExplanation.SetCenter(320, 380, 120, 30);
	DrawString(280, 370, "�������", ExplanationColor);

	//DrawBox(248, 460, 360, 425, GetColor(255, 0, 0), false);
    m_colRectRecord.SetCenter(320, 440, 60, 30);
	DrawString(300, 430, "�L�^", RecordColor);

	fedo.StartUpdate();


	/*m_colRectStart.Draw(GetColor(255, 0, 0), false);
	m_colRectExplanation.Draw(GetColor(255, 0, 0), false);
	m_colRectRecord.Draw(GetColor(255, 0, 0), false);
	m_colRectMouse.Draw(GetColor(255, 255, 0), false);*/
}
