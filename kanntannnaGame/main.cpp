#include "DxLib.h"
#include "Circle.h"

namespace
{
	//�N���b�N����Z�̐�
	constexpr int kCircleNum = 20;

}


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[���̃t���[�����v��
	int frameCount = 0;

	//�Z���N���b�N������
	int clickCount = 0;

	Circle circle;
	circle.init();

	
	//�Q�[�����[�v
	while (ProcessMessage() != 1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();


		//�`����s���O�ɉ�ʂ��N���A����

		ClearDrawScreen();

		//�Q�[���̏���
		if (clickCount < kCircleNum)    //�Q�[�����I�������v�����~�߂�
		{
			frameCount++;
		}

		
		circle.update();
		if (!circle.isExist())
		{
			//�Z���N���b�N����ď�������
			clickCount++;
			if (clickCount >= kCircleNum)
			{
				//�Q�[���I��
			}
			else
			{
				//�Z���N���b�N����ď����Ă����ꍇ�̏���
				circle.init();
			}
			
		}

		//�`��
		circle.draw();
		if (clickCount >= kCircleNum)
		{
			DrawString(320, 240, "�Q�[���N���A�I", GetColor(255, 255, 0));
		}
		
		//�v���C���ԕ\��
		//frameCount�����Ԃɕϊ�������
		//�b�ɕϊ�frameCount / 60
		//1/100�b�P�ʂɕϊ�  frameCount / 60 * 100      
		int tempCount = frameCount * 100 / 60;   //1�b�̏ꍇ100,2.5�b�̏ꍇ250
		DrawFormatString(320, 480 - 16, GetColor(255, 255, 255)," %d.%02d",tempCount /100,tempCount % 100);


		//��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66�~���b�o�߂���܂ő҂�
			
		}
	}

	DxLib_End();            //DX���C�u�����g�p
	

	return 0;				// �\�t�g�̏I�� 
}