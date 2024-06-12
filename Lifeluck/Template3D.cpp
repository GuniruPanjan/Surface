#include "DxLib.h"
#include "Player/Player.h"
#include "Camera/Camera.h"
#include "Enemy/Enemy.h"
#include "Machine/Machine.h"
#include "Map/MapGround.h"
#include <cmath>
#include<memory>

namespace
{
	constexpr float kCameraDist = 96;
	constexpr float kCameraHeight = 32;
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

	//�|�C���^�ŊǗ�
	std::shared_ptr<Player> player = std::make_shared<Player>();
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
	std::shared_ptr<Machine> machine = std::make_shared<Machine>();
	std::shared_ptr<MapGround> ground = std::make_shared<MapGround>();

	player->Init();
	camera->Init();
	enemy->Init();
	machine->Init();
	ground->Init();


	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
		ClearDrawScreen();

		//�Q�[���X�V
		player->SetCameraAngle(camera->cameraAngle.y);
		player->Update();
		camera->Update(*player);
		enemy->Update();
		machine->Update();
		ground->Update();

		player->Draw();
		enemy->Draw();
		machine->Draw();
		ground->Draw();


		for (int x = -50; x <= 50; x += 10)
		{
			DrawLine3D(VGet(static_cast<float>(x),0,-50), VGet(static_cast<float>(x), 0, 50), 0xffff00);
		}
		for (int z = -50; z <= 50; z += 10)
		{
			DrawLine3D(VGet(-50, 0, static_cast<float>(z)), VGet(50, 0, static_cast<float>(z)), 0xff0000);
		}



		//����ʂ�\��ʂ����ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}
	player->End();
	enemy->End();
	machine->End();
	ground->End();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}