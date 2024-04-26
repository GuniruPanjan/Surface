#include "Camera.h"
//度をラジアンに変換
#define D2R(deg) ((deg)*DX_PI_F/180.0f)


Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Init()
{
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	//基準となるカメラの座標
	cameraPos = VGet(0.0f, 50.0f, -100.0f);

	//カメラのターゲット座標初期化
	cameraTarget = VGet(0.0f, 5.0f, 0.0f);

	//カメラのアングル初期設定
	cameraAngle = VGet(D2R(-20.0f), 0.0f, 0.0f);

	SetCameraNearFar(1.0f, 500.0f);
}

void Camera::Update(Player& player)
{

	//左キー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT)
	{
		cameraAngle.y += D2R(1.0f);
	}
	//右キー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT)
	{
		cameraAngle.y -= D2R(1.0f);
	}
	//上キー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP)
	{
		//カメラがプレイヤーを超えないくらいまで
		if (cameraAngle.x <= 0.7f)
		{
			cameraAngle.x += D2R(1.0f);
		}
		
	}
	//下キー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN)
	{
		//カメラがプレイヤーをくぐらないくらいまで
		if (cameraAngle.x >= -2.2f)
		{
			cameraAngle.x -= D2R(1.0f);
		}
		
	}

	//基準のベクトル
	VECTOR Direction = VGet(0.0f, 100.0f, -100.0f);

	//X軸回転行列
	MATRIX matrixX = MGetRotX(cameraAngle.x);
	//Y軸回転行列
	MATRIX matrixY = MGetRotY(cameraAngle.y);

	//行列の合成
	MATRIX matrix = MMult(matrixX, matrixY); 

	//基準ベクトルを行列で変換
	Direction = VTransform(Direction, matrix);

	//カメラ座標はプレイヤー座標から少しはなれたところ
	cameraPos = VAdd(player.Playerpos, Direction);

	//注視点の座標はプレイヤー座標の少し上
	cameraTarget = VAdd(player.Playerpos, VGet(0.0f, 2.0f, 0.0f));

	SetCameraPositionAndTarget_UpVecY(cameraPos, cameraTarget);
	

	DrawFormatString(300, 0, 0xffffff, "%f", player.Playerpos.x);
	DrawFormatString(300, 20, 0xffffff, "%f", player.Playerpos.y);
	DrawFormatString(300, 40, 0xffffff, "%f", player.Playerpos.z);
}

void Camera::Draw()
{

	DrawFormatString(0, 0, 0xffffff, "%f", cameraPos.x);
	DrawFormatString(0, 20, 0xffffff, "%f", cameraPos.y);
	DrawFormatString(0, 40, 0xffffff, "%f", cameraPos.z);

	DrawFormatString(0, 360, 0xffffff, "%f", cameraAngle.x);
	DrawFormatString(0, 380, 0xffffff, "%f", cameraAngle.y);
	DrawFormatString(0, 400, 0xffffff, "%f", cameraAngle.z);
	
}

void Camera::End()
{
}
