#pragma once
#include "EnemyBase.h"
#include "Vec2.h"
//右から出現する敵のクラス
class EnemyRight : public EnemyBase
{
public:
	EnemyRight();
	virtual ~EnemyRight();

	//void Init();
	virtual void Update() override;
	//void Draw() const;

	//メンバー変数にアクセスする
	//void SetHandle(int handle) { m_handle = handle; }

	//bool isExist() const { return m_isExist; }

	//敵キャラクターをスタートさせる
	virtual void Start() override;

private:
	//int m_handle;   //グラフィックのハンドル

	//bool m_isExist; //存在するかフラグ(使用中かどうか)

	//float m_posX;
	//float m_posY;
	//表示位置
	//Vec2 m_pos;
	//移動量  1フレームあたりの移動ベクトルを入れる
	//Vec2 m_vec;
};

