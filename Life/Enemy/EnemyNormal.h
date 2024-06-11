#pragma once
#include "EnemyBase.h"

class EnemyNormal : public EnemyBase
{
public:
	EnemyNormal();
	virtual ~EnemyNormal();

	void Init();
	void Update();
	void Draw();
	void End();

private:
	//エネミーのモーション格納変数
	int EnemyAnim[3];
	//モーションのトータル時間
	float TotalTime[3];

	//エネミーのモーション読み込み変数
	int EnemyWark;

	//再生時間
	float PlayTime;
};

