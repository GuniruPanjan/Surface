#include "Player.h"
#include<math.h>
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	m_cameraAngle(0.0f),
	m_moveAnimFrameIndex(0),
	m_a(0),
	m_pad(0)
{
}

Player::~Player()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animWalk);
	MV1DeleteModel(m_animRun);

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

	//プレイヤーのアニメーション読み込み
	m_animStand = MV1LoadModel("Data/PlayerAnimation/PlayerAnimStand.mv1");
	m_animWalk = MV1LoadModel("Data/PlayerAnimation/PlayerAnimWalk.mv1");
	m_animRun = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRun.mv1");
	m_animRoll = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRoll.mv1");

	//アニメーションで移動しているフレームの番号を検索する
	m_moveAnimFrameIndex = MV1SearchFrame(m_animRoll, "mixamorig:Hips");

	//アニメーションアタッチ
	m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);
	m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);
	m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);
	m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);

	//アタッチしたアニメーションの総再生時間を取得する
	m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);
	m_totalAnimTime[1] = MV1GetAttachAnimTotalTime(m_handle, m_animation[1]);
	m_totalAnimTime[2] = MV1GetAttachAnimTotalTime(m_handle, m_animation[2]);
	m_totalAnimTime[3] = MV1GetAttachAnimTotalTime(m_handle, m_animation[3]);

	//アニメーションで移動しているフレームを無効にする
	MV1SetFrameUserLocalMatrix(m_animRoll, m_moveAnimFrameIndex, MV1GetFrameLocalMatrix(m_animRoll, m_moveAnimFrameIndex));

	//一旦待機以外のアニメーションデタッチ
	MV1DetachAnim(m_handle, m_animation[1]);
	MV1DetachAnim(m_handle, m_animation[2]);
	MV1DetachAnim(m_handle, m_animation[3]);
	m_animation[1] = -1;
	m_animation[2] = -1;
	m_animation[3] = -1;


	//プレイヤーもポジション設定
	m_pos = VGet(m_posX, m_posY, m_posZ);
}

void Player::Update()
{
	//パッド入力所得
	m_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//アナログスティックを使って移動
	int analogX = 0;
	int analogY = 0;

	float SetAngleX = 0.0f;
	float SetAngleY = 0.0f;

	GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

	m_move = VGet(-analogX, 0.0f, analogY);  //ベクトルの長さ

	//ベクトルの長さを取得する
	float len = VSize(m_move);
	//ベクトル長さを0.0～1.0の割合に変換する
	float rate = len / 1000.0f;

	//アナログスティック無効な範囲を除外する
	rate = (rate - 0.1f) / (0.8f - 0.1f);
	rate = min(rate, 1.0f);
	rate = max(rate, 0.0f);

	//速度が決定できるので移動ベクトルに反映する
	m_move = VNorm(m_move);
	float speed = m_speed * rate;

	m_move = VScale(m_move, speed);

	//cameraの角度から
	//コントローラーによる移動方向を決定する
	MATRIX mtx = MGetRotY(m_cameraAngle + DX_PI_F);
	m_move = VTransform(m_move, mtx);

	//移動方向からプレイヤーへの向く方向を決定する
	//移動していない場合(ゼロベクトル)の場合は変更しない
	//プレイヤーが充電中じゃなければ
	if (VSquareSize(m_move) > 0.0f)
	{
		m_angle = atan2f(-m_move.z, m_move.x) - DX_PI_F / 2;

		SetAngleX += D2R(1.0f);
		SetAngleY += D2R(1.0f);

		//プレイヤーが動いたら
		m_moveflag = true;
	}
	//プレイヤーが動いてなかったら
	else if (VSquareSize(m_move) <= 0.0f)
	{
		m_moveflag = false;
	}

	m_pos = VAdd(m_pos, m_move);

	//アニメーション時間を進める前の「アニメーションで移動をしているフレームの座標」を取得しておく


	//再生時間を進める
	m_playerTime += 0.5f;


	//Aボタンが押されたら
	if (m_pad & PAD_INPUT_1)
	{
		if (m_a < 51)
		{
			m_a++;
		}
	}
	else
	{
		m_a = 0;
	}


	Animation(m_a, m_playerTime);
}

/// <summary>
/// アニメーションに関する実装をまとめる関数
/// </summary>
/// <param name="time"></param>
void Player::Animation(int& A, float& time)
{
	//プレイヤーが動いていないなら
	if (m_moveflag == false)
	{
		if (m_animation[1] != -1 || m_animation[2] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);


			//アニメーションアタッチ
			m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);

			time = 0.0f;

			m_animation[1] = -1;
			m_animation[2] = -1;
		}
		
	}
	//プレイヤーが動いたら
	//Aボタン長押し
	if (A > 50 && m_moveflag == true)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);

			//アニメーションアタッチ
			m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;

		}
	}
	else if (m_pad & PAD_INPUT_1)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);

			//アニメーションアタッチ
			m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;


		}
	}
	else if (m_moveflag == true)
	{
		if (m_animation[0] != -1 || m_animation[2] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[2]);


			//アニメーションアタッチ
			m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[2] = -1;
		}
	}

	//再生時間がアニメーションの相殺性時間に達したら再生時間を0に戻す
	if (time >= m_totalAnimTime[0] && m_animation[0] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[1] && m_animation[1] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[2] && m_animation[2] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		time = 0.0f;
	}

	//再生時間をセットする
	if (m_animation[0] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[0], time);
	}
	if (m_animation[1] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[1], time);
	}
	if (m_animation[2] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[2], time);
	}
	if (m_animation[3] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[3], time);
	}
}

void Player::Draw()
{
	//3Dモデルのポジション設定
	MV1SetPosition(m_handle, m_pos);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	//3Dモデル描画
	MV1DrawModel(m_handle);
}

void Player::End()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animWalk);
	MV1DeleteModel(m_animRun);

}
