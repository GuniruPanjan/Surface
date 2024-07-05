#include "Player.h"

Player::Player():
	m_cameraAngle(0.0f),
	m_pad(0)
{
}

Player::~Player()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
}

void Player::Init()
{
	//プレイヤーHPの初期化
	m_hp = 150.0f;

	//プレイヤースピード初期化
	m_speed = 2.0f;

	m_modelSize = 0.4f;

	//プレイヤーもモデル読み込み
	m_handle = MV1LoadModel("Data/Player/PlayerModel.mv1");

	//プレイヤーの大きさを変える
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));

	//プレイヤーもポジション設定
	m_pos = VGet(m_posX, m_posY, m_posZ);
}

void Player::Update()
{
	//パッド入力所得
	m_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}

void Player::Draw()
{
	//3Dモデルのポジション設定
	MV1SetPosition(m_handle, m_pos);

	//3Dモデル描画
	MV1DrawModel(m_handle);
}

void Player::End()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
}
