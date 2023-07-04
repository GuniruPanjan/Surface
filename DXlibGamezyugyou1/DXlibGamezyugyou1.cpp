#include "DxLib.h"

//�Ȃ��킴�킴�N���X�̃����o��private�ɂ���́H
//���ׂ�public�Ȃ�֗��ł́H

//const  �l��������Ȃ��悤�ɂ���
//�l�������ꂽ�ق����֗��@���ԈႦ�Ă����鎖��h�����߂�const�ł�������������Ȃ��悤�ɂ���

//�E�N���X�̏����̓N���X���g�ɂ�点��
//�E�O���珟��ɒl��������Ȃ��悤�ɂ���
//��.�G���\���ɂ������@����ɉ�ʊO�̍��W�Ɉړ�������A�݂����Ȃ��Ƃ���������@���G�͐����Ă���͂��Ȃ̂ɉ�ʂɕ\������Ȃ��H�Ƃ������o�O

class Enemy
{
public:
	//�R���g���N�^�A�f�X�g���N�^�͓���Ȏ������Ȃ�����public
	Enemy();
	~Enemy();

	//�N���X�O����g�������i�����WinMain�Ŏg���j���̂�public
	void init();
	void update();
	void draw();

	//�N���X�O���烁���o�ϐ���ύX�������ꍇ��public�ȃ����o�֐���ʂ�
	void setPos(int x, int y);

	//�ȒP�Ȓ��g�Ȃ�w�b�_�ɒ��ڏ������Ƃ�����
	void setPosX(int x) { m_posX = x; }
	void setPos(int y) { m_posY = y; }



private:
	//�����o�ϐ��͂��ׂ�private
	int m_handle;
	int m_posX;
	int m_posY;
};

Enemy::Enemy() :
	m_handle(LoadGraph("data/�Q�[���L�����Q.png")),
	m_posX(320),
	m_posY(240)
{

}
//�f�X�g���N�^
Enemy::~Enemy()
{
	DeleteGraph(m_handle);
}
void Enemy::init()
{

}
void Enemy::draw()
{
	DrawGraph(m_posX, m_posY, m_handle, false);
}
void Enemy::setPos(int x,int y)
{
	//��ʊO�ɏo�Ă�����߂�����
	if (x < 0)   x = 0;
	if (x > 640)  x = 640;
	if (y < 0) y = 0;
	if (y > 480) y = 480;
	m_posX = x;
	m_posY = y;
}


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	Enemy enemy;
	enemy.init();

	//�G�̈ʒu��ύX����
	int x = 120;
	int y = 120;
	//����͒��ړ���Ă��邪���ۂɂ͐F�X���������������ʉ�ʊO�ɂȂ���
	x = -120;
	y = -120;
	enemy.setPos(x , y);
	//�Q�[�����[�v
	while (ProcessMessage() != 1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();


		//�`����s���O�ɉ�ʂ��N���A����

		ClearDrawScreen();

		//�Q�[���̏���

		enemy.draw();

		//��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66�~���b�o�߂���܂ő҂�

		}
	}

	DxLib_End();            //DX���C�u�����g�p


	return 0;				// �\�t�g�̏I�� 
}