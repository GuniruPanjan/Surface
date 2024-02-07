#pragma once
#include "Rect.h"
#define ENEMY_NOW 20
#define SKY_ENEMY_NOW 20
#define DISTANCE_ENEMY_NOW 15

struct EnemyLoadDate
{
	//�G�̉摜�擾�ϐ�
	int WalkEnemyGraph[12], SkyEnemyGraph[3], DistanceEnemyGraph;

	//�G�̉��擾�ϐ�
	int WalkEnemySound, WalkEnmeyDeadSound1, WalkEnmeyDeadSound2;

	int SkyEnemyDead;

	int DistanceEnmeySound, DistanceEnemyDamageSound, DistanceEnemyDeadSound;

	//�G�����񂾎��̃A�j���[�V�����擾�ϐ�
	int WalkEnemyDeadAnim[14],SkyEnemyDeadAnim[4],DistanceEnemyDeadAnim[14];

	//Distance�G�l�~�[��Shot�p�̊i�[�ϐ�
	int ShotDistance;

	int ShotHitGraphRight[2];
	int ShotHitGraphLeft[2];

	int ShotSparkGraphRight[2];
	int ShotSparkGraphLeft[2];

	//Distance�G�l�~�[��Shot�̉��i�[�p�ϐ�
	int DistanceEnemyShotSound;

	//�G�l�~�[��|�����Ƃ��̃|�C���g�\��
	int WalkPoint, SkyPoint, DistancePoint;
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

