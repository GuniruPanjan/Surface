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
	float WalkEnemyX; 
	float WalkEnemyY;
	int WalkEnemyGraph;

	//�G�̑傫��
	int WalkEnemyWidth = 20;
	int WalkEnemyHeight = 20;
	//�G�l�~�[�̑傫���擾����ϐ�
	int WalkEnemyW, WalkEnmeyH;

	//�G�l�~�[�̃X�s�[�h
	float WalkEnemySpeed = 0.03f;
	//�G�l�~�[�̎��S����
	bool WalkEnemyDead = false;

	//�G�l�~�[���o������t���O
	bool WalkEnemyflag = false;

	
};

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init(WalkEnemyStruct enemy,WalkEnemy& Wenemy);
	void Update(Player& player, Shot& shot, WalkEnemyStruct enemy[],int WenemySize,int ScrollX,TimeCount* time,WalkEnemy& Wenemy);
	void Draw(int ScrollX, WalkEnemyStruct& enemy, Point& point);

	EnemyBase Base;
	Point point;
	WalkEnemyStruct WenemyS[ENEMY_NOW];

	//�G�̏o���t���O
	bool WalkEnemyAppearance = true;
	
	//���Ԃ�i�߂�ϐ�
	int T;
};

