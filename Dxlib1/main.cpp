#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�O���t�B�b�N�f�[�^�̃������ɓǂݍ���
	//�ǂݍ��񂾃f�[�^���g�������ꍇ�͂��̔ԍ����w�肵�Ă���A
	//�Ƃ���������Ԃ��Ă����i�n���h���ƌĂ΂��j
	//���̃n���h�����g�p���ĕ\������O���t�B�b�N���w�肷��
	int handle = LoadGraph("�F�B.jpg");

	//�ǂݍ��񂾃O���t�B�b�N��\������
	DrawGraph(0, 0, handle, 1);

	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
	DrawLine(0, 120, 640, 120, GetColor(255, 0, 0));
	DrawLine(0, 240, 640, 240, GetColor(0, 255, 0));
	DrawLine(0, 360, 640, 360, GetColor(0, 0, 255));
	DrawLine(0, 0, 640, 120, GetColor(255, 255, 0));
	DrawLine(0, 240, 640, 120, GetColor(255, 0, 255));
	DrawLine(0, 240, 640, 360, GetColor(0, 255, 255));
	WaitKey();				// �L�[���͑҂�

	//�������ォ��O���t�B�b�N�f�[�^���폜����
	//����ȍ~�g��Ȃ��A�Ƃ�����ԂɂȂ�����K���폜����
	DeleteGraph(handle);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}