#include "EnemyBase.h"
// 重力加速度
#define GravitationalAcceleration 9.80665 / 2

EnemyBase::EnemyBase() :
	EnemyX(0.0f),
	EnemyY(0.0f),
	EnemyZ(0.0f),
	EnemyMoveX(0.0f),
	EnemyMoveZ(0.0f),
	EnemyWidth(0.0f),
	Angle(0.0f),
	Enemyflag(false)
{
	//敵のスピード初期化
	Speed = 1.5f;
	//敵のノックバック初期化
	KnockBack = 10.0f;

	//オブジェクトの大きさを変える変数
	float Scale = 0.5f;

	//敵の3Dモデル読み込み
	EnemyModel = MV1LoadModel("data/Enemy.mv1");

	//敵の大きさを変更
	MV1SetScale(EnemyModel, VGet(Scale, Scale, Scale));
}

EnemyBase::~EnemyBase()
{
	//メモリ解放
	MV1DeleteModel(EnemyModel);
}

void EnemyBase::Update()
{
	//3Dモデルのポジション設定
	MV1SetPosition(EnemyModel, pos);
}

void EnemyBase::Draw()
{
	//3Dモデル描画
	MV1DrawModel(EnemyModel);
}