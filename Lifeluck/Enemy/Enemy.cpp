#include "Enemy/Enemy.h"

Enemy::Enemy() :
	PlayTime(0.0f),
	EnemyWark(-1)
{
	for (int i = 0; i < 3; i++)
	{
		EnemyAnim[i] = 0;
		TotalTime[i] = 0;
	}
}

Enemy::~Enemy()
{
	//メモリ解放
	MV1DeleteModel(EnemyModel);
	MV1DeleteModel(EnemyWark);
}

void Enemy::Init()
{
	EnemyX = 200.0f;
	EnemyY = 0.0f;
	EnemyZ = 0.0f;

	//モデル読み込み
	EnemyModel = MV1LoadModel("EnemyData/EnemyModel.mv1");
	EnemyWark = MV1LoadModel("EnemyData/EnemyWalking.mv1");

	EnemyAnim[0] = MV1AttachAnim(EnemyModel, 0, EnemyModel, TRUE);
	EnemyAnim[1] = MV1AttachAnim(EnemyModel, 0, EnemyWark, TRUE);

	//エネミーの大きさを変える
	MV1SetScale(EnemyModel, VGet(0.45f, 0.45f, 0.45f));

	//アタッチしたアニメーションの総再生時間を取得する
	TotalTime[0] = MV1GetAttachAnimTotalTime(EnemyModel, EnemyAnim[0]);
	TotalTime[1] = MV1GetAttachAnimTotalTime(EnemyModel, EnemyAnim[1]);

	//一旦待機以外のアニメーションをデタッチする
	MV1DetachAnim(EnemyModel, EnemyAnim[0]);

	EnemyPos = VGet(EnemyX, EnemyY, EnemyZ);
}

void Enemy::Update()
{

	//アニメーションを再生する
	PlayTime += 0.5f;

	//再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (PlayTime >= TotalTime[1] && EnemyAnim[1] != -1)
	{
		PlayTime = 0.0f;
	}

	if (EnemyAnim[1] != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(EnemyModel, EnemyAnim[1], PlayTime);
	}

}

void Enemy::Draw()
{
	//3Dモデルのポジション設定
	MV1SetPosition(EnemyModel, EnemyPos);

	//3Dモデル描画
	MV1DrawModel(EnemyModel);
}

void Enemy::End()
{
	//メモリ解放
	MV1DeleteModel(EnemyModel);
	MV1DeleteModel(EnemyWark);
}
