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

	

private:
	int HP;
	int Speed;
	//プレイヤーの画像を入れる変数
	int playerGraph;

	//プレイヤーの初期位置
	int PlayerX;
	int PlayerY;


	//プレイヤーの幅と高さ
	int PlayerW;
	int PlayerH;

	bool PlayerShotFlag;

	//弾の画像サイズ
	int ShotGraph;
	int W, H;
	
	//弾
	Shot shot[SHOT];

};

