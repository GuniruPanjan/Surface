#pragma once
#include "Rect.h"
#include "Map.h"
#include "WalkEnemy.h"
#define SHOT 30

struct Shot
{
	//�e�����˒����ǂ���
	bool Flag = false;
	//x���W
	double X = 0;
	//y���W
	double Y = 0;
	//�O���t�B�b�N�n���h��
	int Graph = -1;
	//�摜�̕��ƍ���
	int Width;
	int Height;
	//�e���Ə��Ɍ������Ă���
	double AimX = 0;
	double AimY = 0;
	//�e�̃_���[�W
	int Damage = 3;
	

	//�����蔻��̋�`
	Rect m_colRect;

};

class WalkEnemy;
class Map;

class Player
{
public:
	Player();
	~Player();

	void Init();
	void InitShot(Shot& shot);
	void Update(Player& player, Map& map);
	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() { return m_colRect; }

	void ShotUpdate(Player& player, Shot shot[], int shotSize);

	void Draw();
	void DrawShot(Shot& shot);

	//�e
	Shot shot[SHOT];

	//�v���C���[��HP
	int HP;
	//�v���C���[�̏����ʒu
	float PlayerX;
	float PlayerY;
	//�v���C���[�̃T�C�Y
	int PlayerWidth, PlayerHeight;

	//��ʃX�N���[��
	int ScrollX, ScrollY;

	//�X�N���[������
	bool PlayerRight;

	//�_���[�W����
	bool PlayerDamage;

	//�e�؂�ϐ�
	int Bullet = 12;

	//�d��
	float Gravity = 2.0f;

	//�����蔻��̋�`
	Rect m_colRect;

private:
	
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