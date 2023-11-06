#include "ShotMagicWand.h"
#include "Game.h"
#include "DxLib.h"
#include "SceneMain.h"
#include<cassert>

namespace
{
	//定数の定義

	constexpr float kSpeed = 4.0f;  //弾の移動速度

	//ショットの大きさ
	constexpr float kWidth = 4.0f;
	constexpr float kHeight = 4.0f;

	//覚えておく過去の位置情報の数
	constexpr int kPosLogNum = 8;

	
}

ShotMagicWand::ShotMagicWand()
{
	m_posLog.resize(kPosLogNum);
}

ShotMagicWand::~ShotMagicWand()
{
}

void ShotMagicWand::Init()
{
}

void ShotMagicWand::Update()
{
	if (m_isExist) return;

	//位置のログをずらす
	//for (int i = 1; i < m_posLog.size(); i++)
	for(int i = m_posLog.size() - 1; i >= 1; i--)
	{
		m_posLog[i] = m_posLog[i - 1];
	}
	//1フレーム前の情報を入れる
	m_posLog[0] = m_pos;

	m_pos += m_vec;
	//あたり判定の更新
	m_colRect.SetCenter(m_pos.x, m_pos.y, kWidth, kHeight);

	//画面外に出た処理
	//過去の表示位置も含めてすべて画面外にでたら終了
	bool isOut = false;
	if (m_pos.x < 0.0f - kWidth / 2) isOut = true;
	if (m_pos.x > Game::kScreenWidth + kWidth / 2) isOut = true;
	if (m_pos.x < 0.0f - kHeight / 2) isOut = true;
	if (m_pos.x > Game::kScreenHeight + kHeight / 2) isOut = true;
	//チェック中の座標が画面内ならここで終了
	if (!isOut) return;

	//過去ログも画面外にあるかをチェックする
	for (int i = 0; i < m_posLog.size(); i++)
	{
		if (m_posLog[i].x < 0.0f - kWidth / 2) isOut = true;
		if (m_posLog[i].x > Game::kScreenWidth + kWidth / 2) isOut = true;
		if (m_posLog[i].x < 0.0f - kHeight / 2) isOut = true;
		if (m_posLog[i].x > Game::kScreenHeight + kHeight / 2) isOut = true;
		//チェック中の座標が画面内ならここで終了
		if (!isOut) return;
	}

	//ここに来たということは画面外にいる
	m_isExist = false;

	if ((m_vec.x < 0.0f) &&   //左に移動している敵
		(m_pos.x < 0.0f - kWidth / 2))   //左から画面外に出た
	{
		m_isExist = false;
	}
	//右に移動している敵が"画面右から完全に出きった敵を消す
	if ((m_vec.x > 0.0f) &&   //右に移動している敵
		(m_pos.x > Game::kScreenWidth + kWidth / 2))   //右から画面外に出た
	{
		m_isExist = false;
	}
	//上に移動している敵が"画面上から完全に出きった敵を消す
	if ((m_vec.y < 0.0f) &&   //上に移動している敵
		(m_pos.y < 0.0f - kHeight / 2))   //上から画面外に出た
	{
		m_isExist = false;
	}
	//下に移動している敵が"画面下から完全に出きった敵を消す
	if ((m_vec.y > 0.0f) &&   //下に移動している敵
		(m_pos.y > Game::kScreenHeight + kHeight / 2))   //下から画面外に出た
	{
		m_isExist = false;
	}
}

void ShotMagicWand::Draw()
{
	if (!m_isExist) return;

#if false
	//残像の表示
	for (int i = 0; i < m_posLog.size(); i++)
	{
		int alpha = 255 - (10 * (i + 1));
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawBox(m_posLog[i].x - kWidth / 2, m_posLog[i].y - kHeight / 2,
			    m_posLog[i].x + kWidth / 2, m_posLog[i].y + kHeight / 2, GetColor(255, 255, 0), true);
	}
	//表示モードを元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//弾の実態
	DrawBox(m_pos.x - kWidth / 2, m_pos.y - kHeight / 2,
		    m_pos.x + kWidth / 2,m_pos.y + kHeight / 2, GetColor(255,255,0),true);
    //test
	DrawLine(m_pos.x, m_pos.y, m_posLog[7].x, m_posLog[7].y, GetColor(255, 0, 0), kWidth);
#else
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	for (int i = 0; i < m_posLog.size(); i++)
	{
		for (int linenum = 0; linenum < 8; linenum++)
		{
			int startX = m_pos.x;
			int startY = m_pos.y;
			int endX = m_posLog[i].x;
			int endY = m_posLog[i].y;

			//ここはやっていない内容
			//かっこよくするために使います
			float angle = GetRand(359) / DX_TWO_PI_F * 360.0f;
			float len = GetRand(4) - 2;
			startX += cosf(angle) * len;
			startY += sinf(angle) * len;
			angle = GetRand(359) / DX_TWO_PI_F * 360.0f;
			len = GetRand(4) - 2;
			endX += cosf(angle) * len;
			endY += sinf(angle) * len;

			DrawLine(startX, startY, endX, endY, GetColor(16, 4, 2), kWidth);
		}
		
	}
	//表示モードを元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
#endif
#ifdef _DEBUG
	//弾の当たり判定デバッグ表示
	m_colRect.Draw(GetColor(0, 0, 0), false);
#endif
}

void ShotMagicWand::Start(Vec2 pos)
{
	//SceneMainの設定忘れチェック
	assert(m_pMain);

	m_isExist = true;
	//初期位置の設定
	m_pos = pos;

	//過去の情報を初期化時点では初期位置と同じにしてしまう
	//残像が変な位置に表示されないようにするため
	for (int i = 0; i < m_posLog.size(); i++)
	{
		m_posLog[i] = m_pos;
	}

	//仮実装
	//m_vec.x = kSpeed;
	//m_vec.y = 0.0f;

	//一番近い敵の方向に移動する
	

	//ターゲット位置
	//弾の発射位置から一番近くにいる敵の座標を所得する
	//SceneMainに実装した関数を利用する
	const Vec2 target = m_pMain->GetNearEnemyPos(m_pos);

	//発射位置からターゲットに向かうベクトル
	Vec2 toTarget = target - m_pos;
	//正規化 toTarget自身を正規化
	toTarget.normalize();
	//弾の速度をkSpeedに
	m_vec = toTarget * kSpeed;
}
