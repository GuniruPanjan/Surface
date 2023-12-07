#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"

class Player;
class Shot;
class Point;
class TimeCount;

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init(WalkEnemy& enemy,TimeCount* time);
	void Update(Player& player, Shot& shot, WalkEnemy& enemy);
	void Draw(int ScrollX, WalkEnemy& enemy, Point& point);

	EnemyBase Base;
	Point point;

	int WalkEnemyGraph;
	//�G�̏o���X�^�[�g����
	int WalkEnemyTime;
	//�G�̏o������
	int WalkEnemyNowTime;
	//�G�̌��ݒn
	float WalkEnemyX, WalkEnemyY;

	//�G�̑傫��
	int WalkEnemyWidth, WalkEnemyHeight;

	//�G�l�~�[�̑傫���擾����ϐ�
	int WalkEnemyW, WalkEnmeyH;

	//�G�l�~�[�̃X�s�[�h
	float WalkEnemySpeed;
	//�G�l�~�[�̎��S����
	bool WalkEnemyDead = false;
	

	//�G�l�~�[���o������t���O
	bool WalkEnemyflag = false;
};

