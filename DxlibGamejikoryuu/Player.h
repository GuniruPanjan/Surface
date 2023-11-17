#pragma once
class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	//グラフィックの設定、幅と高さの取得を行う
	void SetGraphHandle(int handle);

	//当たり判定をとるために必要な情報をだす所得する関数
	float GetLeft() const;    //左の座標
	float GetTop() const;     //上の座標
	float GetRight() const;   //右の座標
	float GetBottom() const;  //下の座標




	int GetposX() { return m_posX; }
	int GetposY() { return m_posY; }



private:
	int m_handle;
	//グラフィックのサイズ
	int m_width;
	int m_height;

	float m_posX;
	float m_posY;

	bool m_isTurn;

};

