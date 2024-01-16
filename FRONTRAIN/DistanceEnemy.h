#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"

class Player;
class Shot;
class Point;
class TimeCount;

struct DistanceEnemyStruct : public EnemyBase
{
	//�G�̌��ݒn
	float DistanceEnemyX = 0.0f;
	float DistanceEnemyY = 0.0f;
	int DistanceEnemyGraph = -1;

	//�G�̑傫��
	int DistanceEnemyWidth = 20;
	int DistanceEnemyHeight = 20;

	//�G�̃X�s�[�h
	float DistanceEnemySpeed = 0.02f;
	//�G�̎��S����
	bool DistanceEnemyDead = false;
	//�G���e�Ŏ��񂾔���
	bool DistanceShotDead = false;

	//�G���o������t���O
	bool DistanceEnemyflag = false;

};
class DistanceEnemy : public EnemyBase
{
public:
	DistanceEnemy();
	~DistanceEnemy();

	void Init(DistanceEnemyStruct& enemy,DistanceEnemy& Denemy);
	void Update(Player& player,Shot& shot,DistanceEnemyStruct enemy[],int DenemySize,float ScrollX,TimeCount* time,DistanceEnemy& Denemy);
	void Draw(float ScrollX, DistanceEnemyStruct& enemy,Point& point);

	//�G�̏o���t���O
	bool DistanceEnemyAppearance = true;

	//���Ԃ�i�߂�ϐ�
	int T = 0;
};

