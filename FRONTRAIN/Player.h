#pragma once
#include "Rect.h"
#include "Map.h"
#include "WalkEnemy.h"
#include "Background.h"
#define SHOT 20

struct Shield
{
	//���̔����t���O
	bool LeftFlag = false;
	bool RightFlag = false;

	//�O���t�B�b�N�n���h��
	int ShieldGraph = -1;

	//���̕��ƍ���
	int ShieldWidth = 0;
	int ShieldHeight = 0;

	//�����蔻��̋�`
	Rect m_colRect;
};

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
	int Width = 0;
	int Height = 0;
	//�e���Ə��Ɍ������Ă���
	double AimX = 0;
	double AimY = 0;
	//�e�̃_���[�W
	int Damage = 3;

	//�|�����A�j���[�V����
	int ShotAnimGraphLeft[2];
	int ShotAnimGraphRight[2];
	int ShotAnimCountRight = 0;
	int ShotAnimCountLeft = 0;
	int ShotAnimTime = 0;

	int ShotSparkGraphRight[2];
	int ShotSparkGraphLeft[2];
	int ShotSparkCountRight = 0;
	int ShotSparkCountLeft = 0;
	int ShotSparkTime = 0;
	

	//�����蔻��̋�`
	Rect m_colRect;

	//SE�p�i�[�ϐ�
	int SEShot = 0;
	int SENotShot = 0;

};

class WalkEnemy;
class Map;

class Player
{
public:
	Player();
	~Player();

	void FinalizePlayer(Player& player, Shot shot[], Shield& shield);
	void Init(Shield& shield, Player& player);
	void InitShot(Shot shot[], Player& player);
	void Update(Player& player, Map& map, Shield& shield, Background& back);
	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() { return m_colRect; }

	void ShotUpdate(Player& player, Shot shot[], int shotSize);

	void Draw(Shield& shield, Player& player);
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
	float ScrollX, ScrollY;

	//�X�N���[������
	bool PlayerRight;

	//�_���[�W����
	bool PlayerDamage;

	//�e�؂�ϐ�
	int Bullet = 12;

	//�����[�h����
	int BulletTime = 0;

	//�v���C���[���ǂ�����Ă��锻��
	bool PlayerRise;

	//�_���[�W�J�E���g
	int Count = 0;
	int DamegeCount = 0;

	//�d��
	float Gravity = 0.3f;

	//�����[�h�ϐ�
	bool Reload;

	//�O�̃t���[���ŃV���b�g�����������ǂ���
	bool PlayerShotFlag;

	//�Ə��̉摜������ϐ�
	int Aiming;

	//�}�E�X�̍��W�擾
	int MouseX, MouseY;

	//�����蔻��̋�`
	Rect m_colRect;

private:
	
	float Speed;
	//�v���C���[�̉摜������ϐ�
	int playerGraph[12];

	//�v���C���[�A�j���[�V�����^�C��
	int RightAnimCount;
	int LeftAnimCount;

	//�v���C���[�A�j���[�V����
	int RightAnimTime;
	int LeftAnimTime;

	//�v���C���[�̘r
	int PlayerArm;
	bool PlayerArmFlag;

	//���S�摜
	int DeadGraph[14];
	int DeadAnim;

	//�v���C���[���S
	int DeadAnimTime;
	int DeadAnimCount;

	//�Ə��̉摜�T�C�Y
	int AimingW, AimingH;

	//�ړ����锻��
	bool Left;
	bool Right;

	//�v���C���[�̕��ƍ���
	int PlayerW;
	int PlayerH;

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

	//SE�p�i�[�ϐ�
	int SEReload, SEDamage, SEShotMem, SENotShotMem;
	int SEReloadCan;

	//SE�����炷
	bool SE = false;
};