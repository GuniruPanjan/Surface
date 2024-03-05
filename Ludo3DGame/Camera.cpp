#include "Camera.h"
#include "Map.h"

Map* map = new Map;

Camera::Camera():
	Near(0.1f),
	Far(1000.0f)
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(Near, Far);

	
}

Camera::~Camera()
{
}

void Camera::Init()
{
	Position = VGet(0.0f, 100.0f, -1.0f);
	//Target = map->pos;
	Target = VGet(0, 0, 0);

	//(0,10,-20)の視点からのターゲットを見る角度にカメラを設置
	SetCameraPositionAndTarget_UpVecY(Position, Target);
}

void Camera::Update()
{
	// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// 上を押していたら上に進む
	//if (Key & PAD_INPUT_UP)
	//{
	//	Position.z += 1;
	//}

	//// 下を押していたら下に進む
	//if (Key & PAD_INPUT_DOWN)
	//{
	//	Position.z -= 1;
	//}

	//// 右を押していたら右に進む
	//if (Key & PAD_INPUT_RIGHT)
	//{
	//	Position.x += 1;
	//}

	//// 左を押していたら左に進む
	//if (Key & PAD_INPUT_LEFT)
	//{
	//	Position.x -= 1;
	//}

	////Wを押していたら上に進む
	//if (CheckHitKey(KEY_INPUT_W))
	//{
	//	Position.y += 1;
	//}

	////Sを押していたら下に進む
	//if (CheckHitKey(KEY_INPUT_S))
	//{
	//	Position.y -= 1;
	//}


	//カメラに位置を反映
	SetCameraPositionAndTarget_UpVecY(Position, Target);
}

void Camera::Draw()
{
}
