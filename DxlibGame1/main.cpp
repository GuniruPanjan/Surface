#include "DxLib.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include<cassert>
#include<cmath>
#include "SceneManager.h" 
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"

namespace
{
	////�񋓌^�ŃV�[�����`
	//enum SceneKind
	//{
	//	SceneKindTitle,
	//	SceneKindMain,
	//	SceneKindResult,
	//};
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	//��ʂ̃T�C�Y�ύX
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeigth, 32);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//�V�[��
	SceneManager scene;
	scene.Init();

	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		//�`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		//�Q�[���V�[���̍X�V
		scene.Updete();
		//�Q�[���V�[���̕`��
		scene.Draw();
		

		//��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	//���s���Ă����V�[���̏I��
	scene.End();

/*
	SceneMain sceneMain;

	sceneMain.Init();
	
	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		sceneMain.Update();
		sceneMain.Draw();

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	//����������O���t�B�b�N���폜����
	//DeleteGraph(sceneMain.);
	sceneMain.End();

	//SceneResult����������n�߂�
	SceneResult sceneResult;

	sceneResult.Init();

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		sceneResult.Update();
		sceneResult.Draw();

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//�V�[���̏I��
		if (sceneMain.IsSceneEnd())
		{
			break;
		}

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	//�V�[���̏I������
	sceneResult.End();
	*/

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}