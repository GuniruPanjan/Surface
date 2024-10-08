#pragma once
#include "Vec2.h"
#include "Rect.h"
//敵の基底クラス
//継承元となるクラスを基底クラスと呼ぶ
class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	virtual void Init();
	virtual void Update();
	virtual void Draw() const;

	//メンバー変数にアクセスする
	void SetHandle(int handle) { m_handle = handle; }

	bool isExist() const { return m_isExist; }
	//位置の取得
	Vec2 GetPos() const { return m_pos; }
	//あたり判定の矩形を取得する
	Rect GetColRect() const { return m_colRect; }

	//敵キャラクターをスタートさせる
	virtual void Start() = 0;

protected:
	//m_posを左上に、m_handleのグラフィックサイズを幅高さにした
	//あたり判定を設定する
	virtual void UpdateCollision();

protected:
	int m_handle;   //グラフィックのハンドル

	bool m_isExist; //存在するかフラグ(使用中かどうか)

	//float m_posX;
	//float m_posY;
	//表示位置
	Vec2 m_pos;
	//あたり判定の矩形
	Rect m_colRect;
	//移動量  1フレームあたりの移動ベクトルを入れる
	Vec2 m_vec;
};

