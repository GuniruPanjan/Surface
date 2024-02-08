#include "EnemyBase.h"
#include "DxLib.h"

EnemyBase::EnemyBase():
	HP(6),
	Speed(2),
	Attack(2),
	EnemyW(0),
	EnemyH(0)
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Finalize(EnemyLoadDate& date)
{
	//for (int i = 0; i < 12; i++)
	//{
	//	DeleteGraph(date.WalkEnemyGraph[i]);
	//}
	//for (int i = 0; i < 14; i++)
	//{
	//	DeleteGraph(date.WalkEnemyDeadAnim[i]);
	//	DeleteGraph(date.DistanceEnemyDeadAnim[i]);
	//}
	//for (int i = 0; i < 4; i++)
	//{
	//	DeleteGraph(date.SkyEnemyDeadAnim[i]);
	//}
	//for (int i = 0; i < 3; i++)
	//{
	//	DeleteGraph(date.SkyEnemyGraph[i]);
	//}
	//for (int i = 0; i < 2; i++)
	//{
	//	DeleteGraph(date.ShotHitGraphLeft[i]);
	//	DeleteGraph(date.ShotHitGraphRight[i]);
	//	DeleteGraph(date.ShotSparkGraphLeft[i]);
	//	DeleteGraph(date.ShotSparkGraphRight[i]);
	//}

	DeleteGraph(date.DistanceEnemyGraph);
	DeleteGraph(date.ShotDistance);

	DeleteGraph(date.WalkPoint);
	DeleteGraph(date.SkyPoint);
	DeleteGraph(date.DistancePoint);

	DeleteSoundMem(date.WalkEnemySound);
	DeleteSoundMem(date.WalkEnmeyDeadSound1);
	DeleteSoundMem(date.WalkEnmeyDeadSound2);
	DeleteSoundMem(date.SkyEnemyDead);
	DeleteSoundMem(date.DistanceEnmeySound);
	DeleteSoundMem(date.DistanceEnemyDeadSound);
	DeleteSoundMem(date.DistanceEnemyDamageSound);
	DeleteSoundMem(date.DistanceEnemyShotSound);
}

void EnemyBase::Init(EnemyLoadDate& date)
{
	//LoadDivGraph("date/WalkEnemy.png", 12, 6, 2, 20, 25, date.WalkEnemyGraph);

	//LoadDivGraph("date/����Down.png", 14, 8, 2, 30, 30, date.WalkEnemyDeadAnim);

	date.WalkEnemySound = LoadSoundMem("SE/se_blood03.mp3");

	date.WalkEnmeyDeadSound1 = LoadSoundMem("SE/����1.mp3");

	date.WalkEnmeyDeadSound2 = LoadSoundMem("SE/���������������2.mp3");

	//LoadDivGraph("date/���S�����Ԃ�.png", 4, 4, 1, 15, 15, date.SkyEnemyDeadAnim);

	//LoadDivGraph("date/SkyEnemy.png", 3, 3, 1, 15, 20, date.SkyEnemyGraph);

	date.SkyEnemyDead = LoadSoundMem("SE/se_tsubureru04.mp3");

	//LoadDivGraph("date/����Down.png", 14, 8, 2, 30, 30, date.DistanceEnemyDeadAnim);

	date.DistanceEnemyGraph = LoadGraph("date/DistanceEnemy.png");

	date.DistanceEnmeySound = LoadSoundMem("SE/���^���{�b�g�̋쓮��2.mp3");

	date.DistanceEnemyDeadSound = LoadSoundMem("SE/����2.mp3");

	date.DistanceEnemyDamageSound = LoadSoundMem("SE/�����@��.mp3");

	date.ShotDistance = LoadGraph("date/�e�e.png");

	//LoadDivGraph("date/�����Ԃ�(��)��.png", 2, 2, 1, 5, 5, date.ShotHitGraphLeft);
	//LoadDivGraph("date/�����Ԃ�(��)�E.png", 2, 2, 1, 5, 5, date.ShotHitGraphRight);

	//LoadDivGraph("date/�Ή�(��)��.png", 2, 2, 1, 5, 5, date.ShotSparkGraphLeft);
	//LoadDivGraph("date/�Ή�(��)�E.png", 2, 2, 1, 5, 5, date.ShotSparkGraphRight);

	date.DistanceEnemyShotSound = LoadSoundMem("SE/�_���e����.mp3");

	date.WalkPoint = LoadGraph("date/100pt.png");

	date.SkyPoint = LoadGraph("date/50pt.png");

	date.DistancePoint = LoadGraph("date/120pt.png");
}

