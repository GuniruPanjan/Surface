#pragma once
#include "Rect.h"
#include "WalkEnemy.h"
#define SHOT 30

struct Shot
{
	//弾が発射中かどうか
	bool Flag;
	//x座標
	double X;
	//y座標
	double Y;
	//グラフィックハンドル
	int Graph;
	//画像の幅と高さ
	int Width, Height;
	//弾が照準に向かっていく
	double AimX, AimY;

	//当たり判定の矩形
	Rect m_colRect;

};

class Player
{
public:
	Player();
	~Player();

	void Init();
	void InitShot(Shot& shot, int shotGraph);
	void Update(Player& player);
	//プレイヤーの当たり判定を取得する
	Rect GetColRect() { return m_colRect; }

	void ShotUpdate(Player& player,Shot shot[], int shotSize);

	void Draw();
	void DrawShot(Shot& shot);

	//弾
	Shot shot[SHOT];
	
	//プレイヤーの初期位置
	int PlayerX;
	int PlayerY;
	//プレイヤーのサイズ
	int PlayerWidth, PlayerHeight;

	int ScrollX, ScrollY;

	bool PlayerRight;
	
	//当たり判定の矩形
	Rect m_colRect;

private:
	int HP;
	int Speed;
	//プレイヤーの画像を入れる変数
	int playerGraph;

	//照準の画像を入れる変数
	int Aiming;

	//照準の画像サイズ
	int AimingW, AimingH;

	//マウスの座標取得
	int MouseX, MouseY;

	

	//プレイヤーの幅と高さ
	int PlayerW;
	int PlayerH;

	//前のフレームでショットを撃ったかどうか
	bool PlayerShotFlag;

	//弾の画像サイズ
	int ShotGraph;
	int W, H;
	
	//マップチップ座標
	int rightMapX = 0;
	int leftMapX = 0;
	int upMapY = 0;
	int downMapY = 0;

	//スクロール処理
	int maxDrawMapX; //最大の描画範囲X
	int minDrawMapX = 0;   //最小の描画範囲X
	int mapScrollX = 0;   //スクロール量X
	int moveNumX = 0;    //総移動量X

};

