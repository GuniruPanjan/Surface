#include "DxLib.h"
#include "Player.h"
#include <cmath>
#include<memory>

namespace
{
	//カメラ情報
	constexpr float kCameraDist = 3.5f;
	constexpr float kCameraHeight = 2.2f;

	constexpr float kCameraNear = 0.5f;
	constexpr float kCameraFar = 180.0f;
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// windowモード設定
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	float cameraAngle = -DX_PI_F / 2;

	//Playerを管理するポインタ
	std::shared_ptr<Player> pPlayer = std::make_shared<Player>();
	pPlayer->Load();
	pPlayer->Init();

	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();

		if ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_5))
		{
			cameraAngle += 0.05f;
		}
		if ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_6))
		{
			cameraAngle -= 0.05f;
		}
		pPlayer->SetCameraAngle(cameraAngle);
		pPlayer->Update();

		SetCameraNearFar(kCameraNear, kCameraFar);
		VECTOR cameraPos;
		cameraPos.x = cosf(cameraAngle) * kCameraDist;
		cameraPos.y = kCameraHeight;
		cameraPos.z = sinf(cameraAngle) * kCameraDist;
		SetCameraPositionAndTarget_UpVecY(cameraPos, VGet(0, 1.2f, 0));

		pPlayer->Draw();

#if false
		//アナログスティックの入力情報をデバッグ表示
		int analogX = 0;
		int analogY = 0;
		GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

		//DrawFormatString(0, 0, 0xffffff, "ANALOG(%d,%d)", analogX, analogY);

		DrawLine(320, 240, 320 + analogX / 10, 240 + analogY / 10, 0xffffff, 4);
#endif

		//裏画面を表画面を入れ替える
		ScreenFlip();

		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	pPlayer->Delete();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}