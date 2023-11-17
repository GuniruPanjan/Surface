#pragma once

class Enemy
{
public:
	Enemy();
	~Enemy();

	void init();
	void update();
	void draw();

	//メンバ変数を直接変更したい場合は
	//publicなメンバ関数を経由して変更する
	//不正な値を設定された場合、不正じゃないようにしたりできる
	void setPosX(int x);
	int getPosX();   //メンバ変数の値を取得するためのget関数
	int getPosY();

	int getRadius();
	void setColor(unsigned int x);
	//メンバ変数はprivate
private:
	int m_posX;
	int m_posY;
	unsigned int Color;
	

};