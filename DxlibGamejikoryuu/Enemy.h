#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Draw() const;

	void SetGraphHandle(int handle);

	//敵キャラクター開始位置
	//画面上から落ち始める
	void Start();

	//存在するかチェック
	bool isExist() const { return m_isExist; }

	//当たり判定をとるために必要な情報をだす所得する関数
	float GetLeft() const;    //左の座標
	float GetTop() const;     //上の座標
	float GetRight() const;   //右の座標
	float GetBottom() const;  //下の座標



	void SetStartPos();

private:
	//残像用に保存する位置情報の数
	static constexpr int kPosLogFrame = 8;


private:
	int m_handle;
	//グラフィックのサイズ
	int m_width;
	int m_height;

	//存在するかフラグ
	bool m_isExist;

	float m_posX[kPosLogFrame];
	float m_posY[kPosLogFrame];

	//移動量
	float m_moveY;
};

