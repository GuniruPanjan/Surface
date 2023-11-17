#include "Player.h"
#include "Game.h"
#include "DxLib.h"
#include<cmath>
#include "SceneMain.h"
#include "ShotMagicWand.h"
#include "ShotBible.h"
#include "Pad.h"

//Playerで使用する定数
namespace
{
	//移動速度
	constexpr float kSpeed = 3.0f;

	//キャラクターのサイズ
	constexpr int kWidth = 32;
	constexpr int kHeight = 32;

	//キャラクターのアニメーション
	constexpr int kUseFrame[] = { 0,1,2,1 };
	//キャラクター１コマのフレーム数
	constexpr int kAnimFrameNum = 8;
	//アニメーション１サイクルのフレーム数
	constexpr int kAnimFrameCycle = _countof(kUseFrame) * kAnimFrameNum;

	//ダメージ演出フレーム数
	constexpr int kDamageFrame = 5;

	//魔法の杖の発射間隔
	constexpr int kMagicWandFrame = 8;
}

Player::Player(SceneMain* pMain):
	m_pMain(pMain),
	m_handle(-1),
	m_pos(Game::kScreenWidth / 2, Game::kScreenHeight / 2),
	m_dir(kDirDown),
	m_warkAnimFrame(0),
	m_warkAnimCount(0),
	m_magicWandFrame(0),
	m_damageFrame(0)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	//ダメージ演出の進行
	m_damageFrame--;
	if (m_damageFrame < 0)  m_damageFrame = 0;

	
	//パッドの十字キーを使用してプレイヤーを移動させる
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isMove = false;   //移動中かどうか

	//移動量を持つようにする

	Vec2 move{ 0.0f,0.0f };

	if (pad & PAD_INPUT_UP)
	{
		//m_pos.y -= kSpeed;
		move.y -= kSpeed;
		m_dir = kDirUp;
		isMove = true;
	}
	if (pad & PAD_INPUT_DOWN)
	{
		//m_pos.y += kSpeed;
		move.y += kSpeed;
		m_dir = kDirDown;
		isMove = true;
	}
	if (pad & PAD_INPUT_LEFT)
	{
		//m_pos.x -= kSpeed;
		move.x -= kSpeed;
		m_dir = kDirLeft;
		isMove = true;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		//m_pos.x += kSpeed;
		move.x += kSpeed;
		m_dir = kDirRight;
		isMove = true;
	}
	//斜め移動の場合も同じ速さで移動するようにする

	//ベクトルの正規化を行うためにはベクトルの長さを求める
	float moveLength = move.length();
	
	//sqrt(1.0);    //double型の平方根を求めたい場合はこちら
	//sqrtf(1.0f);  //float型の場合はこちら
	moveLength = sqrtf(moveLength);  //平方根を求めて長さに

	//moveLength(ベクトルの長さ)が0.0の可能性がある
	
		//ベクトルの正規化
		move.normalize();
	
		//ベクトルの長さをkSpeedにする
		//move.x *= kSpeed;
		//move.y *= kSpeed;
		//move = move.mul(kSpeed);
		//Vec2 temp = (move *= kSpeed);
		move *= kSpeed;

		//座標とベクトルの足し算
		//m_pos.x += move.x;
		//m_pos.y += move.y;
		m_pos += move;
		//あたり判定の更新
		m_colRect.SetCenter(m_pos.x, m_pos.y, kWidth, kHeight);

	if (isMove)
	{
		//歩きアニメーション
		m_warkAnimFrame++;
		if (m_warkAnimFrame >= kAnimFrameCycle) m_warkAnimFrame = 0;
	}

	//ショット
	m_magicWandFrame++;
	if (m_magicWandFrame >= kMagicWandFrame)
	{
		m_magicWandFrame = 0;

		//魔法の杖生成
		ShotMagicWand* pShot = new ShotMagicWand;

		pShot->Init();
		pShot->SetMain(m_pMain);
		pShot->SetPlayer(this);
		pShot->Start(GetPos());
		//以降更新やメモリの解放はSceneMainに任せる
		m_pMain->AddShot(pShot);
	}

	//聖書テスト
	//ボタンを押したら
	if (Pad::isPadTrigger(PAD_INPUT_1))
	{
		//聖書メモリの確保
		ShotBible* pShot = new ShotBible;

		pShot->Init();
		pShot->SetMain(m_pMain);
		pShot->SetPlayer(this);
		pShot->Start(GetPos());
		//以降更新やメモリの解放はSceneMainに任せる
		m_pMain->AddShot(pShot);

	}
}

void Player::Draw() const
{
	//ダメージ演出 2フレーム間隔で表示非表示切り替え
	//0: 表示される
	//1: 表示される
	//2: 非表示
	//3: 非表示
	//4: 表示される
	// % 4 することで012301230123　……　に変換する
	if (m_damageFrame & 4 >= 2) return;

	int animFrame = m_warkAnimFrame / kAnimFrameNum;

	int srcX = kUseFrame[animFrame] * kWidth;
	int srcY = kHeight * m_dir;
	//DrawGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), static_cast<int>(m_handle), true);
#if false
	switch (m_dir)
	{
	case kDirDown:
		srcY = 32 * 0;
		break;
	case kDirLeft:
		srcY = 32 * 1;
		break;
	case kDirRight:
		srcY = 32 * 2;
		break;
	case kDirUp:
		srcY = 32 * 3;
		break;
	}
#endif
	//DrawRectGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		          //srcX, srcY, kWidth, kHeight, m_handle, true);

	DrawRectRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y)
		, srcX, srcY, kWidth, kHeight, 1.0, 0.0, m_handle, true, false);

}

void Player::OnDamage()
{
	//ダメージ演出中は食らわない
	if (m_damageFrame > 0) return;
	//演出フレーム数を設定する
	m_damageFrame = kDamageFrame;
}
