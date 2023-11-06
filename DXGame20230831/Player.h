#pragma once
#include "Vec2.h"
#include "Rect.h"

class SceneMain;
class Player
{
public:
	Player(SceneMain* pMain);
	~Player();

	void Init();
	void Update();
	void Draw() const;

	//メンバー変数にアクセスする
	void SetHandle(int handle) { m_handle = handle; }
	//プレイヤーの現在位置を取得する
	Vec2 GetPos() const { return m_pos; }
	//プレイヤーのあたり判定を取得する
	Rect GetColRect() const { return m_colRect; }

	//魔法の杖の発射フレームカウント
	int m_magicWandFrame;

	//プレイヤーがダメージを受けた
	void OnDamage();

public:
	//向いてる方向
	enum Dir
	{
		kDirDown,   //下
		kDirLeft,   //左
		kDirRight,   //右
		kDirUp,     //上
	};

private:
	SceneMain* m_pMain;

	int m_handle;   //グラフィックのハンドル
	//表示位置
	Vec2 m_pos;
	//あたり判定の矩形
	Rect m_colRect;

	float m_posX;
	float m_posY;
	//向いている方向
	Dir m_dir;
	//歩きアニメーション
	int m_warkAnimFrame;
	int m_warkAnimCount;

	//ダメージを受けてからのフレーム数
	//普段は０
	//当たった時にフレーム数を設定して
	//以降フレーム減らしていく
	int m_damageFrame;
};

