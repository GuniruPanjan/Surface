#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(1);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�\��ʂł͂Ȃ��A����ʂɕ`�悷��
	SetDrawScreen(DX_SCREEN_BACK);

	//�~�̕\���ʒu
	int posX = 320;
	//�~�̈ړ�����
	int moveX = 5;   //�E�����Ɉړ�������

	//�O���t�B�b�N�f�[�^���������ɓǂݍ���
	//��while���[�v���œǂݍ��܂Ȃ��悤�ɋC������
	//while���[�v���œǂݍ���ł��܂���1�b�Ԃ�60��O���t�B�b�N��ǂݍ���ł��܂�
	int playerHandle = LoadGraph("�O���t�B�b�N�f�[�^/sukaihai.png");     //vcxproj�Ɠ����t�H���_�ɂ���摜��ǂݍ���
	                               //data�t�H���_�ɓ��ꂽ�̂�vcxproj����̑��΃p�X���w�肷�� 
	
	//�v���C���[�̕\���ʒu��ϐ��Ŏ���
	int playerX = 320;
	int playerY = 240;

	//�v���C���[�̈ړ���
	int playerMoveY = 4;

	//�Q�[�����I�����Ȃ������ɃQ�[���̏����͍s����(�P�b�ԂɂU�O�񏈗����s����)
	while(ProcessMessage() != -1)   //windows����ʂ����ƌ���Ȃ�����J��Ԃ�
	{

		//�`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		///////////////////////////
		//�ړ�����
		///////////////////////////

		//�~�̈ʒu��ύX����
		posX += moveX;       //moveX��+4�������́A-4�ɂ����Ȃ�Ȃ�
		//��ʒ[�܂ōs������i�s������ς���
		if (posX >= 640)   //�~�̒��S����ʉE�[�����E�ɍs�����ꍇ
		{
			posX = 640;    //��ʊO�ɏo�Ă������ʓ��ɖ߂�
			moveX = -5;    //�E�Ɉړ����Ă����̂����Ɉړ����������̂ňړ�������ύX
		}
		if (posX < 0)      //��ʍ��[��荶�ɂł��ꍇ
		{
			posX = 0;      //��ʓ��ɖ߂�
			moveX = 5;     //�E�Ɉړ���������
		}
		//�R���g���[���[�i�L�[�{�[�h�j�ŃL�����N�^�[���ړ�������

		//GetJoypadInputState()���g�p����
		//padState�Ƀp�b�h�̉�����Ă����Ԃ��擾����
		int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if ((padState & PAD_INPUT_UP) != 0)
		{
			//������Ă���
			playerY -= 4;
			if (playerY < 0)
			{
				playerY = 0;
			}
		}
		
		if ((padState & PAD_INPUT_DOWN) != 0)
		{
			//������Ă���
			playerY += 4;
			if (playerY >= 320)
			{
				playerY = 320;
			}
		}
		
		if ((padState & PAD_INPUT_LEFT) != 0)
		{
			playerX -= 4;
			if (playerX < 0)
			{
				playerX = 0;
			}
		}
		
		if ((padState & PAD_INPUT_RIGHT) != 0)
		{
			playerX += 4;
			if (playerX >= 480)
			{
				playerX = 480;
			}
		}
		//Z�L�[����
		if ((padState & PAD_INPUT_1) != 0)
		{
			playerY -= 2;
			playerX -= 2;
			if (playerY < 0)
			{
				playerY = 0;
			}
			if (playerX < 0)
			{
				playerX = 0;
			}
			
		}
		//X�L�[����
		if ((padState & PAD_INPUT_2) != 0)
		{
			playerY += 2;
			playerX += 2;
			if (playerY >= 320)
			{
				playerY = 320;
			}
			if (playerX >= 480)
			{
				playerX = 480;
			}
		}
		//C�L�[����
		if ((padState & PAD_INPUT_3) != 0)
		{
			playerY += 2;
			playerX -= 2;
			if (playerY >= 320)
			{
				playerY = 320;
			}
			if (playerX < 0)
			{
				playerX = 0;
			}
		}
		//A�L�[����
		if ((padState & PAD_INPUT_4) != 0)
		{
			playerY -= 2;
			playerX += 2;
			if (playerY < 0)
			{
				playerY = 0;
			}
			if (playerX >= 480)
			{
				playerX = 480;
			}
		}


		

		/*�v���C���[�L�����̈ړ��R�[�h
		//�v���C���[�̈ړ������@�㉺�Ɉړ�������
		playerY += playerMoveY;    //�v���C���[�̈ړ�
		if (playerY > 320)         //��ʉ��[�������ɂ������ꍇ�̏���
		{
			playerY = 320;
			playerMoveY = -4;
		}
		if (playerY < 0)
		{
			playerY = 0;
			playerMoveY = 4;
		}
		*/
		///////////////////////////
		//�`�揈��
		///////////////////////////

		//�~���E�ɓ����������I
		DrawCircle(posX, 240, 40, GetColor(255, 0, 0), 1);

		//�ǂݍ��񂾃O���t�B�b�N�f�[�^��`�悷��
		DrawGraph(playerX, playerY, playerHandle, 1);

		
		//��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//�Q�[�����I������A��I�������Ƃ�
		if (0) break;
	}
	
	// �ǂݍ��񂾃O���t�B�b�N�f�[�^������������J������
	DeleteGraph(playerHandle);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}