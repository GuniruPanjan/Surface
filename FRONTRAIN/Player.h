#pragma once
#define SHOT 30

struct Shot
{
	//�e�����˒����ǂ���
	bool Flag;
	//x���W
	double X;
	//y���W
	double Y;
	//�O���t�B�b�N�n���h��
	int Graph;
	//�摜�̕��ƍ���
	int Width, Height;
	//�e���Ə��Ɍ������Ă���
	double AimX, AimY;

};

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();

	void ShotUpdate();

	void Draw();

	//�e
	Shot shot[SHOT];

private:
	int HP;
	int Speed;
	//�v���C���[�̉摜������ϐ�
	int playerGraph;

	//�Ə��̉摜������ϐ�
	int Aiming;

	//�Ə��̉摜�T�C�Y
	int AimingW, AimingH;

	//�}�E�X�̍��W�擾
	int MouseX, MouseY;

	//�v���C���[�̏����ʒu
	int PlayerX;
	int PlayerY;

	//�v���C���[�̕��ƍ���
	int PlayerW;
	int PlayerH;

	//�O�̃t���[���ŃV���b�g�����������ǂ���
	bool PlayerShotFlag;

	//�e�̉摜�T�C�Y
	int ShotGraph;
	int W, H;
	
	

};

