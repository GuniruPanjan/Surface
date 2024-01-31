#pragma once
class Player;

class HP
{
public:
	void PlayerHPInit();
	//プレイヤーのHP表示する関数
	void PlayerHP(Player& player);

	//HPバーの変数
	int HPberGraph[10];

	int HPCount;

	//弾倉の残り弾数
	int MagazineGraph[13];

	//Reload画像
	int Reload;

	//点滅変数
	int Blinking;
};

