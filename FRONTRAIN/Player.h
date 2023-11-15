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

	

private:
	int HP;
	int Speed;
	//�v���C���[�̉摜������ϐ�
	int playerGraph;

	//�v���C���[�̏����ʒu
	int PlayerX;
	int PlayerY;


	//�v���C���[�̕��ƍ���
	int PlayerW;
	int PlayerH;

	bool PlayerShotFlag;

	//�e�̉摜�T�C�Y
	int ShotGraph;
	int W, H;
	
	//�e
	Shot shot[SHOT];

};

