#include "Explanation.h"
#include "DxLib.h"

Explanation::Explanation():
	UK(0),
	LK(0),
	RK(0),
	UnderKey(0),
	RightKey(0),
	LeftKey(0),
	LeftClick(0),
	RightClick(0),
	Mouse(0),
	Graph(0)
{
}

Explanation::~Explanation()
{
}

void Explanation::ExplanationInit()
{
	UK = 255;
	LK = 255;
	RK = 255;

	UnderKey = LoadGraph("date/UnderKey.png");
	LeftKey = LoadGraph("date/RightKey.png");
	RightKey = LoadGraph("date/LeftKey.png");

	LeftClick = LoadGraph("date/���N���b�N.png");
	RightClick = LoadGraph("date/�E�N���b�N.png");
	Mouse = LoadGraph("date/�}�E�X.png");

	Graph = -1;

}

void Explanation::ExplanationUpdate()
{
	//���L�[������
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		UK = 150;
	}
	//���L�[�������ĂȂ��Ƃ�
	else if (CheckHitKey(KEY_INPUT_DOWN) == false)
	{
		UK = 255;
	}
	//�E�L�[������
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		RK = 150;
	}
	//�E�L�[�������Ă��Ȃ���
	else if (CheckHitKey(KEY_INPUT_RIGHT) == false)
	{
		RK = 255;
	}
	//���L�[������
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		LK = 150;
	}
	//���L�[�������Ă��Ȃ���
	else if (CheckHitKey(KEY_INPUT_LEFT) == false)
	{
		LK = 255;
	}

	
	
	//���N���b�N�����Ƃ�
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		Graph = LeftClick;
	}
	//�E�N���b�N�����Ƃ�
	else if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		Graph = RightClick;
	}
	else
	{
		Graph = Mouse;
	}
	

}

void Explanation::ExplanationDraw()
{
	//���L�[�`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, UK);
	DrawGraph(515, 430, UnderKey, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, UK);

	DrawFormatString(518, 460, GetColor(255, 255, 255), "��");

	//�E�L�[�`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, RK);
	DrawGraph(530, 400, RightKey, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, RK);

	DrawFormatString(560, 400, GetColor(255, 255, 255), "�E�ړ�");

	//���L�[�`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, LK);
	DrawGraph(500, 400, LeftKey, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, LK);

	DrawFormatString(430, 400, GetColor(255, 255, 255), "���ړ�");

	//�}�E�X�`��
	DrawGraph(150, 400, Graph, true);
	DrawFormatString(90, 410, GetColor(255, 255, 255), "�V���b�g");
	DrawFormatString(200, 410, GetColor(255, 255, 255), "�����[�h");


}
