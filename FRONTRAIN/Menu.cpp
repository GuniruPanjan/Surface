#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Game.h"
#include "SceneFedo.h"
#include "SceneExplanation.h"
#include "Config.h"

SceneFedo fedo;

//�����蔻��̋�`
Rect m_colRectStart;   //Start�{�^���̔���
Rect m_colRectExplanation;   //�����{�^���̔���
Rect m_colRectRecord;    //�L�^�{�^���̔���

Rect m_colRectMouse;  //�}�E�X�̔���

static int mimageHandle;  //�摜�n���h���i�[�p�ϐ�

static int Graph[9];   //�摜�n���h���i�[�p�ϐ�

static int ClickShot;

static int AnimCount; //�A�j���[�V�����J�E���g

static int Time; //�A�j���[�V�����^�C��

static bool Plus, Mainas;

bool ContinueInit; //�R���e�j���[�����Ƃ��ɏ���������

bool Start, Explanaion, Record;

static int Botton;     //Botton�̉摜������n���h��

static int b, b2, b3;     //�摜���ߕϐ�

//�T�E���h�i�[�p�ϐ�
int SoundMenu;

//SE�i�[�p�ϐ�
int SEClickShot;

//�}�E�X�̍��W���擾���邽�߂̕ϐ�
int MouseX, MouseY;

int StartColor, Startblack, StartYello;
int ExplanationColor, Explanationblack, ExplanationYello;
int RecordColor, Recordblack, RecordYello;


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

	b = 255;

	b2 = 255;

	b3 = 255;

	MouseX = 0;
	MouseY = 0;

	StartColor = 0;
	ExplanationColor = 0;
	RecordColor = 0;

	Botton = LoadGraph("date/�{�^��.png");

	SoundMenu = LoadSoundMem("BGM/���I.mp3");

	Startblack = GetColor(0, 0, 0);
	Explanationblack = GetColor(0, 0, 0);
	Recordblack = GetColor(0, 0, 0);

	StartYello = GetColor(255, 255, 0);
	ExplanationYello = GetColor(255, 255, 0);
	RecordYello = GetColor(255, 255, 0);

	SEClickShot = LoadSoundMem("SE/�_���e����.mp3");

	ClickShot = LoadGraph("date/Destruction.png");
}

//�I������
void Menu_Finalize()
{
	DeleteGraph(mimageHandle); //�摜�̉��

	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(Graph[i]);
	}

	DeleteSoundMem(SoundMenu);

	DeleteSoundMem(SEClickShot);

	DeleteGraph(Botton);

	fedo.Init();

	fedo.FinalizeFedo();
}

//�X�V
void Menu_Update()
{

	//ContinueInit��true�Ȃ�1����s����
	if (ContinueInit == true)
	{
		fedo.Init();
	}
	
	ContinueInit = false;


	fedo.Update();

	//�Q�[���V�[��
	if (fedo.end == 1 && fedo.Start == true)
	{

		ContinueInit = true;

		SceneMgr_ChageScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	//�������
	if (fedo.end == 1 && fedo.Explanation == true)
	{

		ContinueInit = true;

		SceneMgr_ChageScene(eScene_Explanation); //�V�[���������ʂɕύX
	}
	//�ݒ���
	if (fedo.end == 1 && fedo.Setting == true)
	{

		/*DeleteSoundMem(SoundMenu);

		DeleteSoundMem(SEClickShot);

		DeleteGraph(mimageHandle);

		for (int i = 0; i < 9; i++)
		{
			DeleteGraph(Graph[i]);
		}*/

		ContinueInit = true;

		SceneMgr_ChageScene(eScene_Config);//�V�[����ݒ��ʂɕύX

	}



	//A�L�[��������Ă�����
	//if (CheckHitKey(KEY_INPUT_A) != 0)
	//�N���b�N���ꂽ��
	if(Start == true)
	{

		fedo.Out = 1;
		
		fedo.Start = true;

	}
	//B�L�[��������Ă�����
	//if (CheckHitKey(KEY_INPUT_B) != 0)
	//�N���b�N���ꂽ��
	if(Explanaion == true)
	{
		fedo.Out = 1;

		fedo.Explanation = true;
	}
	//C�L�[��������Ă�����
	//if (CheckHitKey(KEY_INPUT_C) != 0)
	//�N���b�N���ꂽ��
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

		b = 120;

		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Start = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);
		}
	}
	else if (m_colRectStart.IsCollision(m_colRectMouse) == false)
	{
		StartColor = Startblack;

		b = 255;
	}

	if (m_colRectExplanation.IsCollision(m_colRectMouse) == true)
	{
		ExplanationColor = ExplanationYello;

		b2 = 120;

		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Explanaion = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);

		}
	}
	else if (m_colRectExplanation.IsCollision(m_colRectMouse) == false)
	{
		ExplanationColor = Explanationblack;

		b2 = 255;
	}

	if (m_colRectRecord.IsCollision(m_colRectMouse) == true)
	{
		RecordColor = RecordYello;

		b3 = 120;

		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Record = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);

		}
	}
	else if (m_colRectRecord.IsCollision(m_colRectMouse) == false)
	{
		RecordColor = Recordblack;

		b3 = 255;
	}

	PlaySoundMem(SoundMenu, DX_PLAYTYPE_LOOP, FALSE);

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

	if (Start == true)
	{
		DrawGraph(210, 190, ClickShot, true);
	}
	if (Explanaion == true)
	{
		DrawGraph(210, 240, ClickShot, true);
	}
	if (Record == true)
	{
		DrawGraph(210, 300, ClickShot, true);
	}

	ChangeFont("�A�v������", DX_CHARSET_DEFAULT);
	//DrawBox(248, 310, 390, 340, GetColor(255, 0, 0),false);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(263, 305, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	m_colRectStart.SetCenter(323, 320, 120, 30);
	DrawString(285, 310, "START", StartColor);

	//DrawBox(248, 400, 405, 365, GetColor(255, 0, 0), false);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b2);
	DrawGraph(263, 365, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	m_colRectExplanation.SetCenter(323, 380, 120, 30);
	DrawString(277, 370, "�������", ExplanationColor);

	//DrawBox(248, 460, 360, 425, GetColor(255, 0, 0), false);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b3);
	DrawGraph(263, 425, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    m_colRectRecord.SetCenter(323, 440, 120, 30);
	DrawString(300, 430, "�L�^", RecordColor);

	fedo.StartUpdate();


	/*m_colRectStart.Draw(GetColor(255, 0, 0), false);
	m_colRectExplanation.Draw(GetColor(255, 0, 0), false);
	m_colRectRecord.Draw(GetColor(255, 0, 0), false);
	m_colRectMouse.Draw(GetColor(255, 255, 0), false);*/
}
