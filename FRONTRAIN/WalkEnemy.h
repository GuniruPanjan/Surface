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
	int WalkEnemyGraph[12];

	//�G�̑傫��
	int WalkEnemyWidth = 20;
	int WalkEnemyHeight = 20;

	//�G�l�~�[�̃X�s�[�h
	float WalkEnemySpeed = 0.04f;
	//�G�l�~�[�̎��S����
	bool WalkEnemyDead = false;
	//�G���e�Ŏ��񂾔���
	bool WalkShotDead = false;

	//�A�j���[�V�����^�C��
	int AnimTime = 0;

	int RightAnim = 0;
	int LeftAnim = 0;

	//���񂾃A�j���[�V����
	int Handle[14];

	//�A�j���[�V�����^�C��
	int AnimCount = 0;
	int AnimTimeDead = 0;

	//�G�l�~�[���o������t���O
	bool WalkEnemyflag = false;

	//SE�p�i�[�ϐ�
	int SEWalkEnemy;

	int SEWalkEnemyDead1, SEWalkEnemyDead2;

	//SE����񂾂��炷
	bool SE1,SE2;
	
};

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init(WalkEnemyStruct enemy[], WalkEnemy& Wenemy, int WenemySize);
	void Update(Player& player, Shot& shot, WalkEnemyStruct enemy[],int WenemySize,float ScrollX,TimeCount* time,WalkEnemy& Wenemy);
	void Draw(float ScrollX, WalkEnemyStruct enemy[], Point& point, int WenemySize, Player& player, Shot shot[]);

	EnemyBase Base;
	WalkEnemyStruct WenemyS[ENEMY_NOW];

	//�G�̏o���t���O
	bool WalkEnemyAppearance = true;
	
	//���Ԃ�i�߂�ϐ�
	int T = 0;
	int TUP = 0;
};

