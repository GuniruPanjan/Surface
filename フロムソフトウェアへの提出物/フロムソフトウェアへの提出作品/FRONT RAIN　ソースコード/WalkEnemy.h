#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"

class Player;
class Shot;
class Point;
class TimeCount;

struct WalkEnemyStruct : public EnemyBase
{
	//�G�̌��ݒn
	float WalkEnemyX = 0.0f; 
    float WalkEnemyY = 0.0f;
	float WalkEnemyDeadY = 0.0f;
	int WalkEnemyGraph[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

	//�G�̑傫��
	int WalkEnemyWidth = 20;
	int WalkEnemyHeight = 20;

	//�G�l�~�[�̃X�s�[�h
	float WalkEnemySpeed = 0.0f;
	//�G�l�~�[�̎��S����
	bool WalkEnemyDead = false;
	//�G���e�Ŏ��񂾔���
	bool WalkShotDead = false;
	bool WalkShotDeadPoint = false;
	bool WalkShotDeadSE = false;

	//�A�j���[�V�����^�C��
	int AnimTime = 0;

	int RightAnim = 0;
	int LeftAnim = 0;

	//���񂾃A�j���[�V����
	int Handle[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//�|�C���g�̉摜������ϐ�
	int DeadPoint = 0;

	//�A�j���[�V�����^�C��
	int AnimCount = 0;
	int AnimTimeDead = 0;

	//�G�l�~�[���o������t���O
	bool WalkEnemyflag = false;

	//SE�p�i�[�ϐ�
	int SEWalkEnemy = 0;

	int SEWalkEnemyDead1 = 0, SEWalkEnemyDead2 = 0;

	int DeadPointSe = 0;

	//SE����񂾂��炷
	bool SE1 = false, SE2 = false;
	
};

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void FinalizeWalkEnemy(WalkEnemyStruct enemy[], int WenemySize, EnemyLoadDate& date);
	void Init(WalkEnemyStruct enemy[], WalkEnemy& Wenemy, int WenemySize, EnemyLoadDate& date);
	void Update(Player& player, Shot& shot, WalkEnemyStruct enemy[],int WenemySize,float ScrollX,TimeCount* time,WalkEnemy& Wenemy);
	void Draw(float ScrollX, WalkEnemyStruct enemy[], Point& point, int WenemySize, Player& player, Shot shot[], TimeCount* time);

	EnemyBase Base;
	WalkEnemyStruct WenemyS[ENEMY_NOW];

	//�G�̏o���t���O
	bool WalkEnemyAppearance = true;
	
	//���Ԃ�i�߂�ϐ�
	int T = 0;
	int TUP = 0;
	int TUP2 = 0;
	int TUP3 = 0;
	int TUP4 = 0;


	//�ϋv�͑���
	int HPUP = 0;
	int HPUP2 = 0;
};

