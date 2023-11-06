#include "DxLib.h"
#include "Application.h"
#include<Dxlib.h>


//�V�[���J�ڂɂ���
//�^�C�g�����->�Q�[����->�Q�[���I�[�o�[->�ŏ���
//��ʂɂ���ĕ\�������͂ɑ΂��鉞�����ς��
//���̈��̏�ʂ̎����u�V�[���v�Ƃ����܂�
//��ʂ�؂�ւ�����悤�ɂ��悤

//�g���e�N�j�b�N�Ƃ��ẮuState�p�^�[���v�Ƃ����̂��g��
//�|�����[�t�B�Y������悤���āA�u���݂̃V�[���v�������玟�֐؂�ւ��đJ�ڂ���
//���܂ŃV�[���̐؂�ւ����Q�[���Ǘ��N���X��֐�����switch���Ő؂�ւ��Ă���������Ȃ���
//�����ł̓V�[�������̃V�[���ւ̐؂�ւ��𐧌䂵�܂�

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//auto app = new Application();
	Application& application = Application::GetInstance();
	if (!application.Init())
	{

	}
	application.Run();
	Application& application2 = Application::GetInstance();

	//�N���X������
	//�@�Öق̃R���X�g���N�^&�f�X�g���N�^����������Ă���
	//�A�Öق̃R�s�[�R���X�g���N�^����������Ă���

	//���ʂ̃R���X�g���N�^
	//�N���X��();
	//�R�s�[�R���X�g���N�^
	//�N���X��(const �N���X��&);

	//���Z�q�I�[�o�[���[�h�Ƃ�=+-*/���Ē�`������̂ł�
	//�߂�l operator���Z�q(�E�Ӓl);

	//����̂悤�ɁA�I�u�W�F�N�g����I�u�W�F�N�g�ւ̑�����֎~
	//�������Ȃ�A
	//void operator(const �N���X��&);
	//��private�ɒu���悤�ɂ��܂�

	//����ɁA�����ƓO�ꂷ��Ȃ�

	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���


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

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}