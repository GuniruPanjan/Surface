#pragma once
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

};

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();

	void ShotUpdate();

	void Draw();

	//弾
	Shot shot[SHOT];

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

	//プレイヤーの初期位置
	int PlayerX;
	int PlayerY;

	//プレイヤーの幅と高さ
	int PlayerW;
	int PlayerH;

	//前のフレームでショットを撃ったかどうか
	bool PlayerShotFlag;

	//弾の画像サイズ
	int ShotGraph;
	int W, H;
	
	

};

