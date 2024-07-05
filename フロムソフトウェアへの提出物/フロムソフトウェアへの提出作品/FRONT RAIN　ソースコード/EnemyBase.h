#pragma once
#include "Rect.h"
#define ENEMY_NOW 30
#define SKY_ENEMY_NOW 10
#define DISTANCE_ENEMY_NOW 20

struct EnemyLoadDate
{
	//�G�̉摜�擾�ϐ�
	int DistanceEnemyGraph;

	//�G�̉��擾�ϐ�
	int WalkEnemySound, WalkEnmeyDeadSound1, WalkEnmeyDeadSound2;

	int SkyEnemyDead;

	int DistanceEnmeySound, DistanceEnemyDamageSound, DistanceEnemyDeadSound;

	//Distance�G�l�~�[��Shot�p�̊i�[�ϐ�
	int ShotDistance;

	//Distance�G�l�~�[��Shot�̉��i�[�p�ϐ�
	int DistanceEnemyShotSound;

	//�G�l�~�[��|�����Ƃ��̃|�C���g�\��
	int WalkPoint, SkyPoint, DistancePoint;

	//�G�l�~�[��|�����Ƃ��̃|�C���g�l����
	int LoadSEPoint;
};

class EnemyBase
{
public:
	EnemyBase();
	~EnemyBase();

	void Finalize(EnemyLoadDate& date);
	void Init(EnemyLoadDate& date);

	int HP;
	int Speed;
	int Attack;
	int EnemyW;
	int EnemyH;

	//�����蔻��̋�`
	Rect m_colRect;
};

