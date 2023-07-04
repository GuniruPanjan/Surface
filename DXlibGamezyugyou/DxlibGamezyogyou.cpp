#include "DxLib.h"

//�N���X�̐錾
class Enemy
{
//�����o�ϐ��A�����o�֐��ɂ�private,public�Ƃ�������������
//�����o�ϐ��͂��ׂ�private:�ɂ��܂��傤�I

	//public:��private:�������ĂȂ��ꏊ�ɂ����������o�[��private�����o
	int m_pri000;       //private�����o

	//private:������ɏ����������o�i�ϐ��A�֐��j��private�����o
private:
	int m_pri001;    //private�����o

	//public:������ɏ����������o�i�ϐ��A�֐��j��public�����o
public:
	int m_pub000;     //public�����o
	void pubFunc();   //public�����o�̊֐�
	//private:public:���x�������Ă��悢
private:
	int m_pri002;
	void priFunc();
	//private
public:       //�O������̃A�N�Z�X�\�ɂ���

	//�����o�ϐ����͂��̃v���O�����������l�����������ł���̓����o�ϐ��A
	//�Ƃ킩��悤�ɖ��O��t���邱�Ƃ�����
	//���͕ϐ����̑O��m_��t���܂�           handle -> m_handle
	//�ق��ɂ��ϐ����̑O�� _ ��t����l��    handle -> _handle
	//�ϐ����̍Ō��_��t����l�����܂�      handle -> handle_
	//���[���͂ǂ�ł����܂��܂��񂪁A�K�����ꂵ�Ă�������
	//�`�[������̏ꍇ�̓`�[���łǂ̂悤�ȃ��[���ɂ��邩���߂Ă�������
	int m_handle;   //�O���t�B�b�N�n���h��
	int m_posX;     //X���W
	int m_posY;     //Y���W
	int m_moveX;    //X�����ւ̈ړ���
	int m_moveY;    //Y�����ւ̈ړ���

	//�R���X�g���N�^
	//���̂��쐬���ꂽ�Ƃ��i���������m�ۂ��ꂽ�Ƃ��j�����I�ɌĂ΂��֐�
	//�߂�l�����A�N���X���Ɠ����֐���
	Enemy();
	//�f�X�g���N�^
	//����������������Ƃ������I�ɌĂ΂��֐�
	//�I�����ɖY�ꂸ�ɂ���Ă����Ȃ��Ƃ����Ȃ�
	//�߂�l�Ȃ��A�������ݒ�ł��Ȃ��@�֐����̓N���X���̑O��~������
	~Enemy();

	//�N���X�͍\���̂ɉ����ăN���X���Ŋ֐����쐬���鎖���ł���
	//�N���X���̊֐��������o�֐��Ƃ���

	void init();
	void update();
	void draw();
};

//Enemy�N���X�̃R���X�g���N�^
Enemy::Enemy():m_posX(320),m_posY(240)


{
	//�l��������������A0�N���A����
	//�����o�֐����瓯���N���X���̃����o�ϐ��ɃA�N�Z�X�ł���
	//�A�N�Z�X����ۂ�enemy.handle�̂悤�ȏ����������Ȃ��Ă�handle�݂̂ŃA�N�Z�X�ł���

	m_handle = LoadGraph("data/�Q�[���L�����Q.png");
	m_posX = 320;
	m_posY = 240;
	m_moveX = 0;
	m_moveY = 0;
}

//Enemy�N���X�̃f�X�g���N�^
Enemy::~Enemy()
{
	//�I�����ɖY�ꂸ�ɂ���Ă����Ȃ��Ƃ����Ȃ�����������
	DeleteGraph(m_handle);
}

//�����o�֐����������������͊֐����̑O�� �N���X��::�Ə���
void Enemy::init()
{
	
}


void Enemy::draw()
{
	//�N���X������Ȃ�private�����o�Apublic�����o���ɃA�N�Z�X�\
	m_pub000 = 10;
	pubFunc();

	m_pri000 = 100;
	priFunc();

	DrawGraph(m_posX, m_posY, m_handle, false);
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
	//�����o�֐��̌Ăяo��
	//�����o�ϐ��Ɠ�����.(�h�b�g)�łȂ��Ń����o�֐����Ăяo��
	enemy.init();

	//public�����o�ɂ̓N���X�O����A�N�Z�X�ł���
	//private�����o�ɂ̓N���X�O����A�N�Z�X�ł��Ȃ�
	//�N���X�O�H�@���̃N���X�̃����o�֐����̓N���X���A����ȊO�̓N���X�O
	//������Enemy�̃N���X�O

	//public �����o�ɂ̓A�N�Z�X�\�@�g�p�\
	enemy.m_pub000 = 10;
	enemy.pubFunc();

	//private�����o�ɂ̓A�N�Z�X�s�@�g�p�s��

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