#pragma once
class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	

private:
	int HP;
	int Speed;
	//プレイヤーの画像を入れる変数
	int playerGraph;

	//プレイヤーの初期位置
	int PlayerX;
	int PlayerY;


	//プレイヤーの幅
	int PlayerW;
	int PlayerH;

	bool PlayerShotFlag;
	
};

