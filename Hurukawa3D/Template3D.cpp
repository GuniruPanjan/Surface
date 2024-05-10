#include "DxLib.h"
#include "Player.h"
#include <cmath>
#include<memory>

namespace
{
	//�J�������
	constexpr float kCameraDist = 3.5f;
	constexpr float kCameraHeight = 2.2f;

	constexpr float kCameraNear = 0.5f;
	constexpr float kCameraFar = 180.0f;
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// window���[�h�ݒ�
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	float cameraAngle = -DX_PI_F / 2;

	//Player���Ǘ�����|�C���^
	std::shared_ptr<Player> pPlayer = std::make_shared<Player>();
	pPlayer->Load();
	pPlayer->Init();

	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
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
		//�A�i���O�X�e�B�b�N�̓��͏����f�o�b�O�\��
		int analogX = 0;
		int analogY = 0;
		GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

		//DrawFormatString(0, 0, 0xffffff, "ANALOG(%d,%d)", analogX, analogY);

		DrawLine(320, 240, 320 + analogX / 10, 240 + analogY / 10, 0xffffff, 4);
#endif

		//����ʂ�\��ʂ����ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	pPlayer->Delete();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}