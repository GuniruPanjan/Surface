#include "SceneFedo.h"

SceneFedo::SceneFedo():
	c(0),
	a(0),
	b(0),
	White(0),
	end(0),
	Out(0),
	Start(false),
	Setting(false),
	Count(0),
	handle(0),
	WhiteHandle(0),
	WhiteCount(0),
	WhiteTime(0),
	EndHandle(),
	AnimCount(0),
	AnimTime(0),
	LetGo(false),
	Explanation(false)
{
}

SceneFedo::~SceneFedo()
{
}

void SceneFedo::FinalizeFedo()
{
	DeleteGraph(handle);

	DeleteGraph(WhiteHandle);

	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(EndHandle[i]);
	}
}

void SceneFedo::Init()
{
	c = 0;
	a = 0;
	b = 255;
	White = GetColor(255, 255, 255);

	end = 0;

	Out = 0;

	Start = false;

	Setting = false;

	Explanation = false;

	LetGo = false;

	Count = 0;

	WhiteCount = 0;

	WhiteTime = 0;

	AnimTime = 0;

	AnimCount = 0;

	handle = LoadGraph("date/�X�^�[�g��ʉ��o.png");

	WhiteHandle = LoadGraph("date/WhiteOut.png");

	LoadDivGraph("date/���_.png", 9, 3, 3, 853, 480, EndHandle);
}

void SceneFedo::Update()
{

	if (c >= 0 && 256)
		SetDrawBright(255 - c, 255 - c, 255 - c);

	if (Out == 1)
	{
		c += 2;                 //c���J�E���g�A�b�v
	}

	if (c >= 256)     //�Â��Ȃ�I�������I��
	{
		end = 1;
	}
}

void SceneFedo::StartUpdate()
{
	Count++;
	//1�t���[����
	if (Count >= 56)
	{
		b -= 1;
	}
	

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(0, 0, handle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void SceneFedo::UpdateInSetting()
{
	end = 0;
	c = 255;

	SetDrawBright(255, 255, 255);
}

void SceneFedo::UpdateIn()
{
	a++;

	if (a >= 0 && 256)
		SetDrawBright(a, a, a);
}

void SceneFedo::DeadOut()
{
	end = 0;
	a = 0;

	SetDrawBright(a, a, a);
}

void SceneFedo::WhiteOut()
{

	//�v���C���[�����񂾎���ʂ��z���C�g�A�E�g����
	WhiteCount += 3;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, WhiteCount);
	DrawGraph(0, 0, WhiteHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void SceneFedo::DeadAnim()
{
	//�v���C���[�����񂾎��̃A�j���[�V����
	AnimTime++;
	if (AnimTime >= 6)
	{
		AnimCount++;

		AnimTime = 0;
	}

	if (AnimCount >= 8)AnimCount = 8;

	DrawGraph(-106, 0, EndHandle[AnimCount], TRUE);
}
