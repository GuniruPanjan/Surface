#pragma once
#include "Rect.h"
#include "Map.h"
#include "WalkEnemy.h"
#include "Background.h"
#define SHOT 20

struct Shield
{
	//盾の発生フラグ
	bool LeftFlag = false;
	bool RightFlag = false;

	//グラフィックハンドル
	int ShieldGraph = -1;

	//盾の幅と高さ
	int ShieldWidth = 0;
	int ShieldHeight = 0;

	//当たり判定の矩形
	Rect m_colRect;
};

struct Shot
{
	//弾が発射中かどうか
	bool Flag = false;
	//x座標
	double X = 0;
	//y座標
	double Y = 0;
	//グラフィックハンドル
	int Graph = -1;
	//画像の幅と高さ
	int Width = 0;
	int Height = 0;
	//弾が照準に向かっていく
	double AimX = 0;
	double AimY = 0;
	//弾のダメージ
	int Damage = 3;

	//倒したアニメーション
	int ShotAnimGraphLeft[2];
	int ShotAnimGraphRight[2];
	int ShotAnimCountRight = 0;
	int ShotAnimCountLeft = 0;
	int ShotAnimTime = 0;

	int ShotSparkGraphRight[2];
	int ShotSparkGraphLeft[2];
	int ShotSparkCountRight = 0;
	int ShotSparkCountLeft = 0;
	int ShotSparkTime = 0;
	

	//当たり判定の矩形
	Rect m_colRect;

	//SE用格納変数
	int SEShot = 0;

};

class WalkEnemy;
class Map;

class Player
{
public:
	Player();
	~Player();

	void FinalizePlayer(Player& player, Shot shot[], Shield& shield);
	void Init(Shield& shield, Player& player);
	void InitShot(Shot shot[], Player& player);
	void Update(Player& player, Map& map, Shield& shield, Background& back);
	//プレイヤーの当たり判定を取得する
	Rect GetColRect() { return m_colRect; }

	void ShotUpdate(Player& player, Shot shot[], int shotSize);

	void Draw(Shield& shield, Player& player);
	void DrawShot(Shot& shot);

	//弾
	Shot shot[SHOT];

	//プレイヤーのHP
	int HP;
	//プレイヤーの初期位置
	float PlayerX;
	float PlayerY;
	//プレイヤーのサイズ
	int PlayerWidth, PlayerHeight;

	//画面スクロール
	float ScrollX, ScrollY;

	//スクロール判定
	bool PlayerRight;

	//ダメージ判定
	bool PlayerDamage;

	//弾切れ変数
	int Bullet = 12;

	//リロード時間
	int BulletTime = 0;

	//プレイヤーが壁を上っている判定
	bool PlayerRise;

	//ダメージカウント
	int Count = 0;
	int DamegeCount = 0;

	//重力
	float Gravity = 0.3f;

	//リロード変数
	bool Reload;

	//当たり判定の矩形
	Rect m_colRect;

private:
	
	float Speed;
	//プレイヤーの画像を入れる変数
	int playerGraph[12];

	//プレイヤーアニメーションタイム
	int RightAnimCount;
	int LeftAnimCount;

	//プレイヤーアニメーション
	int RightAnimTime;
	int LeftAnimTime;

	//死亡画像
	int DeadGraph[14];
	int DeadAnim;

	//プレイヤー死亡
	int DeadAnimTime;
	int DeadAnimCount;

	//照準の画像を入れる変数
	int Aiming;

	//照準の画像サイズ
	int AimingW, AimingH;

	//マウスの座標取得
	int MouseX, MouseY;

	//移動する判定
	bool Left;
	bool Right;

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

	//SE用格納変数
	int SEReload, SEDamage,SEShotMem;

	//SEを一回鳴らす
	bool SE = false;
};