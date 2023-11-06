#pragma once
#include "EnemyBase.h"
//class 作成中クラス名　:　public継承元クラス
//public以外にもprivate,protectedが使用できるが大体public
class EnemyLeft : public EnemyBase
{
public:
	EnemyLeft();
	virtual ~EnemyLeft();

	//今のところ継承元をそのまま使いので不要
	//void Init();
	//void Upadte();
	//void Draw();

	virtual void Update() override;

	virtual void Start() override;
};

