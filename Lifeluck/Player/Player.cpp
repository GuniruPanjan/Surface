#include "Player.h"
#include<math.h>
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player() :
	cameraAngle(0.0f),
	angle(0.0f),
	PlayerAnimWalking(-1),
	PlayerAnimRun(-1),
	PlayerAnimDying(-1),
	PlayTime(0.0f),
	PlayerMove(false),
	Pad(0)
{
	for (int i = 0; i < 4; i++)
	{
		PlayerAnim[i] = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		TotalTime[i] = 0;
	}
}

Player::~Player()
{
	//メモリ解放
	MV1DeleteModel(PlayerModel);
	MV1DeleteModel(PlayerAnimWalking);
	MV1DeleteModel(PlayerAnimRun);
	MV1DeleteModel(PlayerAnimDying);
}

void Player::Init()
{
	PlayerHp = 10;
	//Playerの3Dモデルを読み込む
	PlayerModel = MV1LoadModel("PlayerData/PlayerModel.mv1");

	//Playerの大きさを変える
	MV1SetScale(PlayerModel, VGet(0.4f, 0.4f, 0.4f));

	//Playerのスピードを設定
	PlayerSpeed = 2.0f;

	//Playerのポジション設定
	PlayerPos = VGet(0.0f, 2.0f, 0.0f);

	//Playerのアニメーション読み込み
	PlayerAnimWalking = MV1LoadModel("PlayerData/PlayerAnimWalk.mv1");
	PlayerAnimRun = MV1LoadModel("PlayerData/PlayerAnimRun.mv1");
	PlayerAnimDying = MV1LoadModel("PlayerData/PlayerAnimDying.mv1");


	//アニメーションアタッチ
	PlayerAnim[0] = MV1AttachAnim(PlayerModel, 0, PlayerModel, TRUE);
	PlayerAnim[1] = MV1AttachAnim(PlayerModel, 0, PlayerAnimWalking, TRUE);
	PlayerAnim[2] = MV1AttachAnim(PlayerModel, 0, PlayerAnimRun, TRUE);
	PlayerAnim[3] = MV1AttachAnim(PlayerModel, 0, PlayerAnimDying, TRUE);

	//アタッチしたアニメーションの総再生時間を取得する
	TotalTime[0] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[0]);
	TotalTime[1] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[1]);
	TotalTime[2] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[2]);
	TotalTime[3] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[3]);

	//一旦待機意外のアニメーションデタッチ
	MV1DetachAnim(PlayerModel, PlayerAnim[1]);
	MV1DetachAnim(PlayerModel, PlayerAnim[2]);
	MV1DetachAnim(PlayerModel, PlayerAnim[3]);
	PlayerAnim[1] = -1;
	PlayerAnim[2] = -1;
	PlayerAnim[3] = -1;

	m_pos = Pos3(PlayerPos.x - 2.0f, PlayerPos.y + 35.0f, PlayerPos.z);
	m_vec = Vec3(PlayerPos.x, PlayerPos.y, PlayerPos.z);
	m_len = 40.0f;
	m_radius = 16.0f;
	m_col.Init(m_pos, m_vec, m_len, m_radius);
}

void Player::Update()
{
	m_pos = Pos3(PlayerPos.x - 2.0f, PlayerPos.y + 35.0f, PlayerPos.z);

	//パッド入力所得
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//Playerが動いていないなら
	if (PlayerMove == false)
	{
		if (PlayerAnim[1] != -1 || PlayerAnim[2] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(PlayerModel, PlayerAnim[1]);
			MV1DetachAnim(PlayerModel, PlayerAnim[2]);

			//アニメーションをアタッチ
			PlayerAnim[0] = MV1AttachAnim(PlayerModel, 0, PlayerModel, TRUE);

			PlayTime = 0.0f;

			PlayerAnim[1] = -1;
			PlayerAnim[2] = -1;
		}


	}
	//Aボタンを押したらダッシュ
	if (Pad & PAD_INPUT_1 && PlayerMove == true)
	{
		if (PlayerAnim[1] != -1 || PlayerAnim[0] != -1)
		{
			//アニメーションをデタッチ
			MV1DetachAnim(PlayerModel, PlayerAnim[0]);
			MV1DetachAnim(PlayerModel, PlayerAnim[1]);

			//アニメーションをアタッチする
			PlayerAnim[2] = MV1AttachAnim(PlayerModel, 0, PlayerAnimRun, TRUE);

			PlayTime = 0.0f;

			PlayerAnim[0] = -1;
			PlayerAnim[1] = -1;

		}


		PlayerSpeed = 4.0f;

		DrawFormatString(0, 0, GetColor(255, 255, 255), "ダッシュ");
	}
	//歩くモーション
	else if (PlayerMove == true)
	{
		if (PlayerAnim[0] != -1)
		{
			//アニメーション1をデタッチ
			MV1DetachAnim(PlayerModel, PlayerAnim[0]);

			//アニメーションをアタッチする
			PlayerAnim[1] = MV1AttachAnim(PlayerModel, 0, PlayerAnimWalking, TRUE);

			PlayTime = 0.0f;

			PlayerAnim[0] = -1;

		}
		//Aボタンを押してなかったら
		if ((Pad & PAD_INPUT_1) == false)
		{
			if (PlayerAnim[2] != -1)
			{
				//アニメーションをデタッチ
				MV1DetachAnim(PlayerModel, PlayerAnim[2]);

				//アニメーションをアタッチする
				PlayerAnim[1] = MV1AttachAnim(PlayerModel, 0, PlayerAnimWalking, TRUE);

				PlayTime = 0.0f;

				PlayerAnim[2] = -1;
			}

			PlayerSpeed = 2.0f;
		}

	}

	//Bボタンを押していたら
	if (Pad & PAD_INPUT_2)
	{
		PlayerMove = false;
		//プレイヤーが充電中なら
		PlayerChargingMove = true;
		//プレイヤーがエネルギーを与える量
		PlayerGiveEnergy = 1.0f;

		DrawString(0, 0, "マシンエネルギー補充", 0xffffff);
	}
	//プレイヤーが充電中じゃければ
	else
	{
		PlayerChargingMove = false;
	}

	//アナログスティックを使って移動
	int analogX = 0;
	int analogY = 0;

	float SetAngleX = 0.0f;
	float SetAngleY = 0.0f;

	GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

	VECTOR move = VGet(-analogX, 0.0f, analogY);  //ベクトルの長さ

	//ベクトルの長さを取得する
	float len = VSize(move);
	//ベクトル長さを0.0～1.0の割合に変換する
	float rate = len / 1000.0f;

	//アナログスティック無効な範囲を除外する
	rate = (rate - 0.1f) / (0.8f - 0.1f);
	rate = min(rate, 1.0f);
	rate = max(rate, 0.0f);

	//速度が決定できるので移動ベクトルに反映する
	move = VNorm(move);
	float speed = PlayerSpeed * rate;

	move = VScale(move, speed);

	//cameraの角度から
	//コントローラによる移動方向を決定する
	MATRIX mtx = MGetRotY(cameraAngle + DX_PI_F);
	move = VTransform(move, mtx);

	//移動方向からプライヤーの向く方向を決定する
	//移動してない場合(ゼロベクトル)の場合は変更しない
	//プレイヤーが充電中じゃなければ
	if (PlayerChargingMove == false)
	{
		if (VSquareSize(move) > 0.0f)
		{
			angle = atan2f(-move.z, move.x) - DX_PI_F / 2;

			SetAngleX += D2R(1.0f);
			SetAngleY += D2R(1.0f);

			//プレイヤーが動いたら
			PlayerMove = true;
		}
		//プレイヤーが動いてなかったら
		else if (VSquareSize(move) <= 0.0f)
		{
			PlayerMove = false;

			DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", PlayTime);
		}

		PlayerPos = VAdd(PlayerPos, move);

	}

	//再生時間を進める
	PlayTime += 0.5f;

	//再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (PlayTime >= TotalTime[0] && PlayerAnim[0] != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime[1] && PlayerAnim[1] != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime[2] && PlayerAnim[2] != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime[3] && PlayerAnim[3] != -1)
	{
		PlayTime = 0.0f;
	}

	if (PlayerAnim[0] != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[0], PlayTime);
	}
	if (PlayerAnim[1] != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[1], PlayTime);
	}
	if (PlayerAnim[2] != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[2], PlayTime);
	}
	if (PlayerAnim[3] != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[3], PlayTime);
	}

	m_col.Update(m_pos, m_vec);
}

void Player::Draw()
{
	//方向ベクトル
	Vec3 Vec = m_vec.GetNormalized() * m_len * 0.5f;

	Pos3 pos1 = m_pos + Vec;
	Pos3 pos2 = m_pos - Vec;

	DrawCapsule3D(pos1.GetVector(), pos2.GetVector(), m_radius, 16, m_color, 0, false);

	//3Dモデルのポジション設定
	MV1SetPosition(PlayerModel, PlayerPos);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(PlayerModel, VGet(0.0f, angle, 0.0f));

	//3Dモデル描画
	MV1DrawModel(PlayerModel);
}

bool Player::IsHit(const CapsuleCol& col)
{
	bool isHit = m_col.IsHit(col);

	if (isHit)
	{
		m_color = 0xffff00;
	}
	else
	{
		m_color = 0xffffff;
	}

	return isHit;
}

void Player::End()
{
	//メモリ解放
	MV1DeleteModel(PlayerModel);
	MV1DeleteModel(PlayerAnimWalking);
	MV1DeleteModel(PlayerAnimRun);
	MV1DeleteModel(PlayerAnimDying);

}
