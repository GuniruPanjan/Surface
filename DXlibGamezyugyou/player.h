#pragma once

class Player
{
public:
	Player();   //生成時に呼ばれる
	~Player();  //削除時に呼ばれる

	void init();     //初期化
	void update();   //毎フレームの更新処理
	void draw();     //描画

	//小さい関数はヘッダーに中身を書くこと
	int getPosX() { return m_posX; }
	int getPosY() { return m_posY; }

	int getRadius();

	//メンバ変数はprivate
private:
	int m_posX;
	int m_posY;

};