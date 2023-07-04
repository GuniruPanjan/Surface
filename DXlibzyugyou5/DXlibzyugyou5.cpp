#include "DxLib.h"

//�萔
namespace
{
	//�����ʒu
	constexpr int kStartPosX = 200;
	constexpr int kStartPosY = 120;
	//�ړ����x
	constexpr int kSpeed = 2;
}

class Player
{
public:
	//�O���t�B�b�N�̃��[�h
	int m_handle;    //�O���t�B�b�N�n���h��
	int m_posX;      //�\�����WX
	int m_posY;      //�\�����WY

	//�O���t�B�b�N���]�t���O
	bool m_IsTurn;   //���E���]�t���O

	//�����o�֐�
	void init();     //�������p�̊֐�
	void update();   //���t���[���̍X�V
	void draw();     //�`��

	//�R���X�g���N�^�@���������m�ۂ������_�ŏ���ɌĂ΂��֐�
	Player();          //���������R���X�g���N�^
	Player(int x, int y);  //�����ŏ����ʒu��ݒ�ł���R���X�g���N�^

	//�f�X�g���N�^�@���������J���������_�ŏ����ĂɌĂ΂��֐�
	~Player();
};


//Player�N���X�̃R���X�g���N�^
Player::Player()
{
	//�O���t�B�b�N�̃��[�h
	m_handle = LoadGraph("data/huruhurubebi-.png");
	m_posX = 200;
	m_posY = 120;
	//�O���t�B�b�N���]�t���O
	m_IsTurn = false;

}

Player::Player(int x, int y)
{
	//�O���t�B�b�N�̃��[�h
	m_handle = LoadGraph("data/huruhurubebi-.png");
	m_posX = 200;
	m_posY = 120;
	//�O���t�B�b�N���]�t���O
	m_IsTurn = false;
}

//Player�N���X�̃f�X�g���N�^
Player::~Player()
{
	//���������J�������Ƃ��ɕK���Ă�łق�������������
	DeleteGraph(m_handle);
}

//init�̃����o�֐��̎���
void Player::init()
{
/*
	handle = LoadGraph("data/huruhurubebi-.png");
	posX = 200;
	posY = 120;
	IsTurn = false;
	*/
}

//update�̃����o�֐��̎���
void Player::update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_UP)
	{
		//��L�[��������Ă���
		m_posY -= kSpeed;  //������Ɉړ�����
	}
	if (pad & PAD_INPUT_DOWN)
	{
		//���L�[��������Ă���
		m_posY += kSpeed;  //�������Ɉړ�����
	}
	if (pad & PAD_INPUT_LEFT)
	{
		//���L�[��������Ă���
		m_posX -= kSpeed;  //�������Ɉړ�����
		m_IsTurn = false;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		//�E�L�[��������Ă���
		m_posX += kSpeed;  //�E�����Ɉړ�����
		m_IsTurn = true;
	}
}
//�����o�֐��̎���
//�֐����̑O�ɃN���X��::�������Ă���Ă��̃N���X��darw�֐��ł��A�Ɛ錾����
void Player::draw()
{
	if (m_IsTurn)
	{
		DrawTurnGraph(m_posX, m_posY, m_handle, false);
	}
	else
	{
		DrawGraph(m_posX, m_posY, m_handle, false);
	}
}

/*
//�v���C���[�̏�����
void initPlayer(Player& player)
{
	player.handle = LoadGraph("data/huruhurubebi-.png");
	player.posX = 200;
	player.posY = 120;

	player.IsTurn = false;
}
*/

/*
//�v���C���[�̍X�V
void updatePlayer(Player& player)
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_UP)
	{
		//��L�[��������Ă���
		player.posY -= kSpeed;  //������Ɉړ�����
	}
	if (pad & PAD_INPUT_DOWN)
	{
		//���L�[��������Ă���
		player.posY += kSpeed;  //�������Ɉړ�����
	}
	if (pad & PAD_INPUT_LEFT)
	{
		//���L�[��������Ă���
		player.posX -= kSpeed;  //�������Ɉړ�����
		player.IsTurn = false;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		//�E�L�[��������Ă���
		player.posX += kSpeed;  //�E�����Ɉړ�����
		player.IsTurn = true;
	}
}
*/
/*
//�v���C���[�̕`��
void drawPlayer(Player player)
{
	if (player.IsTurn)
	{
		DrawTurnGraph(player.posX, player.posY, player.handle, false);    //���E���]��\��
	}
	else
	{
		DrawGraph(player.posX, player.posY, player.handle, false);
	}
}
*/

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

	//�v���C���[
	Player player;
	//Player player_B(80, 120);    ������ƌÂ�
	Player player_B{ 80, 120 };
	
	//�v���C���[�̏�����
	player.init();
	player_B.init();

	
	//�Q�[�����[�v
	while (ProcessMessage() != 1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();


		//�`����s���O�ɉ�ʂ��N���A����

		ClearDrawScreen();

		//�Q�[���̏���

		player.update();
		player_B.update();
		
		//�v���C���[�̕`��
	//	drawPlayer(player);
		player.draw();
		player_B.draw();


		//�摜��\�L������   DrawGraph
		//�\�L�����摜�𔽓]������@�@DrawTurnGraph
		

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

	//�O���t�B�b�N������������폜
	DeleteGraph(player.m_handle);

	DxLib_End();            //DX���C�u�����g�p


	return 0;				// �\�t�g�̏I�� 
}