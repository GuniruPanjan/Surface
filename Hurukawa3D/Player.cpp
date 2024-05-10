#include "Player.h"
#include "DxLib.h"
#include<cmath>

namespace
{
	//モデルのファイル名
	const char* const kPlayerModelFilename = "date/Knight.mv1";

	//アニメーション番号
 	constexpr int KIdleAnimIndex = 1;    //待機
 //   constexpr int KIdleAnimIndex = 2;    //待機
	constexpr int KAttackAnimIndex = 30; //攻撃

	//アニメーションの切り替えにかかるフレーム数
	constexpr float kAnimChangeFrame = 8.0f;
	constexpr float kAnimChageRateSpeed = 1.0f / kAnimChangeFrame;

	//アナログスティックによる移動関連
	constexpr float kMaxSpeed = 0.05f;        //プレイヤーの最大移動速度
	constexpr float kAnalogRangeMin = 0.1f;   //アナログスティックの入力判定範囲
	constexpr float kAnalogRangeMax = 0.8f;
	constexpr float kAnglogInputMax = 1000.0f;   //アナログスティックから入力されるベクトルの最大

}

Player::Player():
	m_modelHandle(-1),
	m_currentAnimNo(-1),
	m_prevAnimNo(-1),
	m_animBlendRate(0.0f),
	m_isAttack(false),
	m_cameraAngle(0.0f),
	m_angle(0.0f)
{
	
}

Player::~Player()
{
}

void Player::Load()
{
	m_modelHandle = MV1LoadModel(kPlayerModelFilename);
}

void Player::Delete()
{
	//リソースをメモリから解放
	MV1DeleteModel(m_modelHandle);
	m_modelHandle = -1;
}

void Player::Init()
{
	//待機アニメーションを設定
	m_currentAnimNo = MV1AttachAnim(m_modelHandle, KIdleAnimIndex, -1, false);
	m_prevAnimNo = -1;
	m_animBlendRate = 1.0f;

	//プレイヤーの初期位置設定
	m_pos = VGet(0.0f, 0.0f, 0.0f);
	MV1SetPosition(m_modelHandle, m_pos);

	m_isAttack = false;
}

void Player::Update()
{
	//アニメーションの切り替え
	if (m_prevAnimNo != -1)
	{
		m_animBlendRate = kAnimChageRateSpeed;
		if (m_animBlendRate >= 1.0f) m_animBlendRate = 1.0f;

		//変更後のアニメーション割合を設定する
		MV1SetAttachAnimBlendRate(m_modelHandle, m_prevAnimNo, 1.0f - m_animBlendRate);
		MV1SetAttachAnimBlendRate(m_modelHandle, m_currentAnimNo, m_animBlendRate);

	}

	//アニメーションを進める
	bool isLoop = UpdateAnim(m_currentAnimNo);
	UpdateAnim(m_prevAnimNo);
	
	//ボタンを押したら攻撃アニメーションを再生する
	if (!m_isAttack)
	{
		int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (pad & PAD_INPUT_1)
		{
			m_isAttack = true;
			
			ChangeAnim(KAttackAnimIndex);
		}
		else
		{
			//アナログスティックを使って移動
			int analogX = 0;
			int analogY = 0;

			GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

			//アナログスティックの入力の10%～80%の範囲を使用する
			// 
			//ベクトルの長さが最大で1000になる
			//プレイヤーの最大移動速度は0.01f / frame

			VECTOR move = VGet(analogX, 0.0f, -analogY);    //ベクトルの長さは0～1000
			                                                //0.00～0.01の長さにする
			//ベクトルの長さを取得する
			float len = VSize(move);
			//ベクトル長さを0.0～1.0の割合に変換する
			float rate = len / kAnglogInputMax;

			//アナログスティック無効な範囲を除外する
			rate = (rate - kAnalogRangeMin) / (kAnalogRangeMax - kAnalogRangeMin);
			rate = min(rate, 1.0f);
			rate = max(rate, 0.0f);

			//速度が決定できるので移動ベクトルに反映する
			move = VNorm(move);
			float speed = kMaxSpeed * rate;

			move = VScale(move, speed);

			//カメラのいる場所(角度)から
			//コントローラによる移動方向を決定する
			MATRIX mtx = MGetRotY(-m_cameraAngle - DX_PI_F / 2);
			move = VTransform(move, mtx);

			//移動方向からプレイヤーの向く方向を決定する
			//移動してない場合(ゼロベクトル)の場合は変更しない
			if (VSquareSize(move) > 0.0f)
			{
				m_angle = -atan2f(move.z, move.x) - DX_PI_F / 2;
			}


			m_pos = VAdd(m_pos, move);
		}
	}
	else
	{
		//攻撃アニメーションが終了したら待機アニメーションを再生する
		if (isLoop)
		{
			m_isAttack = false;
			
			ChangeAnim(KIdleAnimIndex);
		}
	}

	MV1SetPosition(m_modelHandle, m_pos);
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle, 0.0f));
}

void Player::Draw()
{
	//モデルの描画
	MV1DrawModel(m_modelHandle);
}

bool Player::UpdateAnim(int attackNo)
{
	//アニメーションが設定される
	if (attackNo == -1) return false;

	//アニメーションを進行させる
	float now = MV1GetAttachAnimTime(m_modelHandle, attackNo);
	now += 0.5f;

	//現在再生中のアニメーションの総カウントを取得する
	float total = MV1GetAttachAnimTotalTime(m_modelHandle, attackNo);
	bool isLoop = false;
	while (now >= total)
	{
		now -= total;
		isLoop = true;
	}
	//進めた時間に設定
	MV1SetAttachAnimTime(m_modelHandle, attackNo, now);

	return isLoop;
}

void Player::ChangeAnim(int animIndex)
{
	//さらに古いアニメーションがアタッチされている場合はこの時点で削除しておく
	if (m_prevAnimNo != -1)
	{
		MV1DetachAnim(m_modelHandle, m_prevAnimNo);
	}

	//現在再生中の待機アニメーションは変更前のアニメーション扱いに
	m_prevAnimNo = m_currentAnimNo;

	//変更後のアニメーションとして攻撃アニメーションを改めて設定する
	m_currentAnimNo = MV1AttachAnim(m_modelHandle, KAttackAnimIndex, -1, false);

	//切り替えの習慣は変更前のアニメーションが再生される状態にする
	m_animBlendRate = 0.0f;

	//変更前のアニメーション100
	MV1SetAttachAnimBlendRate(m_modelHandle, m_prevAnimNo, 1.0f - m_animBlendRate);

	MV1SetAttachAnimBlendRate(m_modelHandle, m_currentAnimNo, m_animBlendRate);
}
