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
	PlayTime(0.0f),
	PlayerMove(false),
	PlayerAnim1(0),
	PlayerAnim2(0),
	PlayerAnim3(0),
	PlayerAnim4(0),
	TotalTime1(0.0f),
	TotalTime2(0.0f),
	TotalTime3(0.0f),
	TotalTime4(0.0f)
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
	PlayerAnimWalking = MV1LoadModel("PlayerData/PlayerAnimWalk.mv1");
	PlayerAnimRun = MV1LoadModel("PlayerData/PlayerAnimRunning.mv1");
	PlayerAnimDying = MV1LoadModel("PlayerData/PlayerAnimDying.mv1");

	
	//アニメーションアタッチ
	PlayerAnim1 = MV1AttachAnim(PlayerModel, 1, PlayerAnimStanding, TRUE);
	PlayerAnim2 = MV1AttachAnim(PlayerModel, 1, PlayerAnimWalking, TRUE);
	PlayerAnim3 = MV1AttachAnim(PlayerModel, 1, PlayerAnimRun, TRUE);
	PlayerAnim4 = MV1AttachAnim(PlayerModel, 1, PlayerAnimDying, TRUE);

	//一旦待機意外のアニメーションデタッチ
	MV1DetachAnim(PlayerModel, PlayerAnim2);
	MV1DetachAnim(PlayerModel, PlayerAnim3);
	MV1DetachAnim(PlayerModel, PlayerAnim4);
	PlayerAnim2 = -1;
	PlayerAnim3 = -1;
	PlayerAnim4 = -1;

}

void Player::Update()
{

	//アタッチしたアニメーションの総再生時間を取得する
	TotalTime1 = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim1);
	TotalTime2 = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim2);
	TotalTime3 = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim3);
	TotalTime4 = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim4);

	//Playerが動いていないなら
	if (PlayerMove == false)
	{
		

		
	}
	else if (PlayerMove == true)
	{
		if (PlayerAnim1 != -1)
		{
			//アニメーション1をデタッチ
			MV1DetachAnim(PlayerModel, PlayerAnim1);

			//アニメーションをアタッチする
			PlayerAnim2 == MV1AttachAnim(PlayerModel, 1, PlayerAnimWalking, TRUE);

			PlayTime = 0.0f;

			PlayerAnim1 = -1;

		}
		
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
	if (VSquareSize(move) > 0.0f)
	{
		angle = atan2f(-move.z, move.x) - DX_PI_F / 2;

		SetAngleX += D2R(1.0f);
		SetAngleY += D2R(1.0f);

		//プレイヤーが動いたら
		PlayerMove = true;
	}
	
	PlayerPos = VAdd(PlayerPos, move);

	//再生時間を進める
	PlayTime += 0.5f;

	//再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (PlayTime >= TotalTime1 && PlayerAnim1 != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime2 && PlayerAnim2 != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime3 && PlayerAnim3 != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime4 && PlayerAnim4 != -1)
	{
		PlayTime = 0.0f;
	}

	if (PlayerAnim1 != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[0], PlayTime);
	}
	if (PlayerAnim2 != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[1], PlayTime);
	}
	if (PlayerAnim3 != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[2], PlayTime);
	}
	if (PlayerAnim4 != -1)
	{
		//再生時間をセットする
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[3], PlayTime);
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
	
}

void Player::End()
{
	//メモリ解放
	MV1DeleteModel(PlayerModel);
	MV1DeleteModel(PlayerAnimStanding);
	MV1DeleteModel(PlayerAnimWalking);
	MV1DeleteModel(PlayerAnimRun);
	MV1DeleteModel(PlayerAnimDying);


}
