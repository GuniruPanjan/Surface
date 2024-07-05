#pragma once
#include "Background.h"
#include "Save.h"
#include "Rect.h"
#include "Point.h"
class Player;

class HP
{
public:
	void FinalizeHP();
	void PlayerHPInit();
	//プレイヤーのHP表示する関数
	void PlayerHP(Player& player, Background& back, Save& save, Point& point, Shot shot[]);

	//HPバーの変数
	int HPberGraph[11];

	int HPCount;

	//ボタンの変数
	int Botton;
	//色変数宣言
	int GreenColor, RedColor, YelloColor;
	int HPColor, AttackColor;

	//ショップに必要なポイント
	int AttackShop, AttackCount;
	//買うたびにポイントを多くするための変数
	int FirstBuy, SecondBuy, ThirdBuy;
	//HPを回復するための変数
	int HPBuy;

	//当たり判定で暗くする
	int b, b2;

	//弾倉の残り弾数
	int MagazineGraph[13];

	//Reload画像
	int Reload;
	int ReloadGraph[21];

	//ポイント変換音
	int PointHPChange, PointAttackChange;
	int PointHPChangeUse, PointAttackChangeUse;

	//ポイントを変換したかどうかの判断
	bool PointHP = false;
	bool PointAttack = false;

	//点滅変数
	int Blinking;

	//ボタンを連続でクリックしないようにする変数
	bool AttackClick = false;

	//マウスの座標取得
	int MouseX, MouseY;

	//マウスの当たり判定の幅
	int UIMouseDecisionX, UIMouseDecisionY;

	//白色を入れる変数
	int UIWhiteColor;

	//黒色を入れる変数
	int UIBlackColor;

	//ボタン当たり判定
	Rect m_HP;
	Rect m_Attack;

	//マウス当たり判定
	Rect m_Mouse;
};

