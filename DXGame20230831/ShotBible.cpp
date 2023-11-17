#include "ShotBible.h"
#include "DxLib.h"
#include "Player.h"
#include <cassert>

namespace
{
	//ショットの大きさ
	constexpr int kWidth = 16;
	constexpr int kHeight = 24;
	//発生してから消えるまでのフレーム数
	constexpr int kExistFrame = 60 * 5;
	//プレイヤーの周りを1回転するのにかかるフレーム数
	constexpr int kRotFrame = 60;

	//プレイヤーの周りを回る時の半径
	constexpr float kRadius = 100.0f;

	//プレイヤーから観た相対位置をデータとして持つ
	const Vec2 kOffset[] =
	{
		Vec2 {kRadius,0.0f},    //右
		Vec2 {0.0f,kRadius},    //下
		Vec2 {-kRadius,0.0f},   //左
		Vec2 {0.0f,-kRadius},   //上

	};

}

ShotBible::ShotBible():
	m_frameCount(0),
	m_angle(0)
{
}

ShotBible::~ShotBible()
{
}

void ShotBible::Init()
{
}

void ShotBible::Update()
{
	if (!m_isExist) return;
	//プレイヤーのポインタが設定されていない
	assert(m_pPlayer);
	//一定時間経過したら消える
	m_frameCount++;
	if (m_frameCount > kExistFrame)
	{
		m_isExist = false;
		return; //終了が確定したら以降の処理は行わない
	}


	//移動処理
	//プレイヤーの位置によって表示する場所が変わる

	//index:kOffsetの何番目のデータを使うか
	//_countof():配列の要素数を取得する
	//int index = m_frameCount % _countof(kOffset);


	//プレイヤーから見た角度の更新
	//kRotFrame(60)かけて1回転する
	m_angle += DX_TWO_PI_F / kRotFrame;

	//kSffset[index]　と　プレイヤーの位置から最終的なショットの位置を決定する
	//m_pos = m_pPlayer->GetPos() + kOffset[index];
	//m_pos : ショットの位置　今回はこれをcos,sinで生成する
	// m_pPlayer->GetPos() : 回転の中心座標
	//m_angle : 真左を0とした場合の回転角度
	//kRadius : 回転半径

	Vec2 offset;  //プレイヤーから見た位置
	offset.x = cosf(m_angle) * kRadius;
	offset.y = sinf(m_angle) * kRadius;

	m_pos = m_pPlayer->GetPos() + offset;


}

void ShotBible::Draw()
{
	if (!m_isExist) return;
	DrawBox(m_pos.x - kWidth / 2, m_pos.y - kHeight / 2, m_pos.x + kWidth / 2, m_pos.y + kHeight / 2, GetColor(32, 32, 255), true);
}

void ShotBible::Start(Vec2 pos)
{
	m_isExist = true;

	m_pos = pos;
	m_frameCount = 0;
}
