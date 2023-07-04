#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
	
	for (int i = 1; i <= 10; i++)
	{
		DrawLine(64 * i, 0, 640, 48 * i, GetColor(255, 0, 0));
		
		DrawLine(0, 48 * 1, 640 - (64 * 1), 480, GetColor(255, 0, 0));
	}
	

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}