#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"
#define ENEMY_SHOT 100

class Player;
class Shot;
class Point;
class TimeCount;
struct Shield;

struct EnemyShot
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
	//�e���W�I�Ɍ������Ă���
	double PX = 0;
	double PY = 0;
	//�e�̃_���[�W
	int ShotDamage = 2;

	//�e�������������̉��o
	int ShotHitGraphRight[2];
	int ShotHitGraphLeft[2];
	int ShotHitRightCount = 0;
	int ShotHitLeftCount = 0;
	int ShotHitTime = 0;

	int ShotSparkGraphRight[2];
	int ShotSparkGraphLeft[2];
	int ShotSparkRightCount = 0;
	int ShotSparkLeftCount = 0;
	int ShotSparkTime = 0;

	//�����蔻��̋�`
	Rect m_colRect;

	//SE�p�i�[�ϐ�
	int SEDistanceShot;
};

struct DistanceEnemyStruct : public EnemyBase
{
	//�G�̌��ݒn
	float DistanceEnemyX = 0.0f;
	float DistanceEnemyY = 0.0f;
	float DistanceEnemyDeadY = 0.0f;
	int DistanceEnemyGraph = -1;

	//�G�̑傫��
	int DistanceEnemyWidth = 20;
	int DistanceEnemyHeight = 20;

	//�G�̃X�s�[�h
	float DistanceEnemySpeed = 0.0f;
	//�G�̎��S����
	bool DistanceEnemyDead = false;
	//�G���e�Ŏ��񂾔���
	bool DistanceShotDead = false;
	bool DistanceShotDeadPoint = false;
	bool DistanceShotDeadSE = false;

	//�G���o������t���O
	bool DistanceEnemyflag = false;

	//���ݎ��Ԃ𓾂�
	int Time = 0;
	//�G�̒e���˂܂ł̎���
	int ShotEnemy = 0;
	int ShotDistance = 0;

	//�G�����񂾎��̃A�j���[�V�����t���[��
	int m_DeadAnimFrame;

	//�|�C���g�̉摜������ϐ�
	int DeadPoint = 0;

	//�O�̃t���[���Ō��������ǂ���
	bool EnemyShotFlag = false;

	//���񂾃A�j���[�V����
	int Handle[14];

	//�A�j���[�V�����^�C��
	int AnimCount;
	int AnimTime;

	//SE�p�i�[�ϐ�
	int SEDistanceEnemy;

	int SEDistanceDead, SEDistanceDamage;

	int DeadPointSE;

	//SE�����炷
	bool SE1, SE2;
};
class DistanceEnemy : public EnemyBase
{
public:
	DistanceEnemy();
	~DistanceEnemy();

	void FinalizeDistanceEnemy(DistanceEnemyStruct& enemy);
	void FinalizeDistanceEnemyShot(EnemyShot shot[]);
	void Init(DistanceEnemyStruct& enemy, DistanceEnemy& Denemy, EnemyLoadDate& date);
	void EnemyShotInit(EnemyShot shot[], EnemyLoadDate& date);
	void Update(Player& player, Shot& shot, DistanceEnemyStruct enemy[], int DenemySize, float ScrollX, TimeCount* time, DistanceEnemy& Denemy, EnemyShot enemyshot[], int EnemyShotSize, Shield& shield);
	void EnemyShotUpdate(DistanceEnemyStruct enemy[], EnemyShot& shot, int enemySize, Player& player, float ScrollX, Shield& shield);
	void Draw(float ScrollX, DistanceEnemyStruct& enemy, Point& point, Player& player, int DownAnimGraph, Shot shot[], TimeCount* time);
	void DrawShot(EnemyShot shot[], int EnemyShotSize, int ScrollX, Player& player, Shield& shield);

	//�G�̏o���t���O
	bool DistanceEnemyAppearance = true;

	//���Ԃ�i�߂�ϐ�
	int T = 0;
	int TUP = 0;
	int TUP2 = 0;
	int TUP3 = 0;
	int TUP4 = 0;

	//�ϋv�̓A�b�v
	int HPUP = 0;
	int HPUP2 = 0;
};

