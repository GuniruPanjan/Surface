#include "Player.h"
#include<math.h>
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	cameraAngle(0.0f),
	angle(0.0f),
	PlayerAnimStanding(0.0f),
	PlayerAnimWalking(0.0f),
	PlayerAnimRun(0.0f),
	PlayerAnimDying(0.0f),
	PlayTime(0.0f)
{
}

Player::~Player()
{
}

void Player::Init()
{
	PlayerHp = 10;
	//Playerの3Dモデルを読み込む
	PlayerModel = MV1LoadModel("PlayerData/PlayerMet.mv1");

	//Playerの大きさを変える
	MV1SetScale(PlayerModel, VGet(0.4f, 0.4f, 0.4f));

	//Playerのスピードを設定
	PlayerSpeed = 2.0f;

	//Playerのポジション設定
	PlayerPos = VGet(0.0f, 2.0f, 0.0f);

	//Playerのアニメーション読み込み
	PlayerAnimStanding = MV1LoadModel("PlayerData/PlayerAnimStanding.mv1");

	//アニメーション読み込み
	PlayerAnim[1] = MV1AttachAnim(PlayerModel, 0, PlayerAnimStanding, TRUE);

	//アタッチしたアニメーションの総再生時間を取得する
	TotalTime[1] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[1]);
}

void Player::Update()
{

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
	if (VSquareSize(move) > 0.0f)
	{
		angle = atan2f(-move.z, move.x) - DX_PI_F / 2;

		SetAngleX += D2R(1.0f);
		SetAngleY += D2R(1.0f);
	}
	
	PlayerPos = VAdd(PlayerPos, move);

	//再生時間を進める
	PlayTime += 1.0f;

	//再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (PlayTime >= TotalTime[1])
	{
		PlayTime = 0.0f;
	}
}

void Player::Draw()
{

	//3Dモデルのポジション設定
	MV1SetPosition(PlayerModel, PlayerPos);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(PlayerModel, VGet(0.0f, angle, 0.0f));

	//3Dモデル描画
	MV1DrawModel(PlayerModel);

	//再生時間をセットする
	MV1SetAttachAnimTime(PlayerModel, PlayerAnim[1], PlayTime);
}

void Player::End()
{
	//メモリ解放
	MV1DeleteModel(PlayerModel);
	MV1DeleteModel(PlayerAnimStanding);

}
