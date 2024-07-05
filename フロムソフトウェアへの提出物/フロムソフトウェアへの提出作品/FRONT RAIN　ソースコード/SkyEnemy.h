#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"

class Player;
class Shot;
class Point;
class TimeCount;
struct Shield;

struct SkyEnemyStruct : public EnemyBase
{
	//�G�̌��ݒn
	float SkyEnemyX = 0.0f;
	float SkyEnemyY = 0.0f;
	float SkyEnemyDeadY = 0.0f;
	int SkyHandle[3];

	//�A�j���[�V�����摜�\���̕ϐ�
	int S = 0;

	int Time = 0;

	//���S�A�j���[�V����
	int DeadAnimGraph[4];
	int DeadAnimCount;
	int DeadAnimTime;
	//�|�C���g�̉摜������ϐ�
	int DeadPoint = 0;

	//�G�̑傫��
	int SkyEnemyWidth = 15;
	int SkyEnemyHeight = 10;

	//�G���v���C���[�Ɍ������Ă���
	double PX = 0;
	double PY = 0;

	//�G�����������ǂ���
	bool Flag = false;

	//�G�̎��S����
	bool SkyEnemyDead = false;
	//�G���e�Ŏ��񂾔���
	bool SkyShotDead = false;
	bool SkyShotDeadPoint = false;
	bool SkyShotDeadSE = false;

	//�G���o������t���O
	bool SkyEnemyflag = false;

	//���񂾎���SE�p�i�[�ϐ�
	int SESkyEnemyDead;
	int DeadPointSE = 0;

	//SE�����炷
	bool SE;
};

class SkyEnemy : public EnemyBase
{
public:
	SkyEnemy();
	~SkyEnemy();

	void FinalizeSky(SkyEnemyStruct& enemy);
	void Init(SkyEnemyStruct& enemy, SkyEnemy& Senemy, EnemyLoadDate& date);
	void Update(Player& player, Shot& shot, SkyEnemyStruct enemy[], int SenemySize, float ScrollX, TimeCount* time, SkyEnemy& Senemy, Shield& shield);
	void Draw(float ScrollX, SkyEnemyStruct& enemy, Point& point);

	//�G�̏o���t���O
	bool SkyEnemyAppearance = true;

	

	//���Ԃ�i�߂�ϐ�
	int T = 0;
	int TUP = 0;
	int TUP2 = 0;
	int TUP3 = 0;
	int TUP4 = 0;
};

