#pragma once
#include "Rect.h"
#include "WalkEnemy.h"
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

	//�����蔻��̋�`
	Rect m_colRect;

};

class Player
{
public:
	Player();
	~Player();

	void Init();
	void InitShot(Shot& shot, int shotGraph);
	void Update(Player& player);
	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() { return m_colRect; }

	void ShotUpdate(Player& player,Shot shot[], int shotSize);

	void Draw();
	void DrawShot(Shot& shot);

	//�e
	Shot shot[SHOT];
	
	//�v���C���[�̏����ʒu
	int PlayerX;
	int PlayerY;
	//�v���C���[�̃T�C�Y
	int PlayerWidth, PlayerHeight;

	int ScrollX, ScrollY;

	bool PlayerRight;
	
	//�����蔻��̋�`
	Rect m_colRect;

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

	

	//�v���C���[�̕��ƍ���
	int PlayerW;
	int PlayerH;

	//�O�̃t���[���ŃV���b�g�����������ǂ���
	bool PlayerShotFlag;

	//�e�̉摜�T�C�Y
	int ShotGraph;
	int W, H;
	
	//�}�b�v�`�b�v���W
	int rightMapX = 0;
	int leftMapX = 0;
	int upMapY = 0;
	int downMapY = 0;

	//�X�N���[������
	int maxDrawMapX; //�ő�̕`��͈�X
	int minDrawMapX = 0;   //�ŏ��̕`��͈�X
	int mapScrollX = 0;   //�X�N���[����X
	int moveNumX = 0;    //���ړ���X

};

