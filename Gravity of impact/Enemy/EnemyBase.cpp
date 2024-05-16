#include "EnemyBase.h"

EnemyBase::EnemyBase():
	Speed(0.0f),
	KnockBack(0.0f),
	EnemyModel(0.0f),
	EnemyX(0.0f),
	EnemyY(0.0f),
	EnemyZ(0.0f)
{
}

EnemyBase::~EnemyBase()
{
	MV1DeleteModel(EnemyModel);
}

void EnemyBase::Init()
{
	//敵のスピード初期化
	Speed = 0.1f;
	//敵のノックバック初期化
	KnockBack = 10.0f;
	//敵の3Dモデル読み込み
	EnemyModel = MV1LoadModel("data/Enemy.mv1");

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

void EnemyBase::End()
{
}
