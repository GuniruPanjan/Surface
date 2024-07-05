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
	DeleteSoundMem(date.LoadSEPoint);
}

void EnemyBase::Init(EnemyLoadDate& date)
{

	date.WalkEnemySound = LoadSoundMem("SE/se_blood03.mp3");

	date.WalkEnmeyDeadSound1 = LoadSoundMem("SE/”š”­1.mp3");

	date.WalkEnmeyDeadSound2 = LoadSoundMem("SE/Œš•¨‚ª­‚µ•ö‚ê‚é2.mp3");

	date.SkyEnemyDead = LoadSoundMem("SE/se_tsubureru04.mp3");

	date.DistanceEnemyGraph = LoadGraph("date/DistanceEnemy.png");

	date.DistanceEnmeySound = LoadSoundMem("SE/’†Œ^ƒƒ{ƒbƒg‚Ì‹ì“®‰¹2.mp3");

	date.DistanceEnemyDeadSound = LoadSoundMem("SE/”š”­2.mp3");

	date.DistanceEnemyDamageSound = LoadSoundMem("SE/‹à‘®’@‚«.mp3");

	date.ShotDistance = LoadGraph("date/e’e.png");

	date.DistanceEnemyShotSound = LoadSoundMem("SE/‘_Œ‚e”­Ë.mp3");

	date.WalkPoint = LoadGraph("date/100pt.png");

	date.SkyPoint = LoadGraph("date/50pt.png");

	date.DistancePoint = LoadGraph("date/120pt.png");

	date.LoadSEPoint = LoadSoundMem("SE/se_coin_get1.mp3");
}

