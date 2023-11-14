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

private:
	//基準座標、真右方向に移動する基準座標
	//y成分にsinの値を足して上下に動くようにする
	Vec2 m_basePos;
	//sin()に与える引数
	float m_sinRate;



};

