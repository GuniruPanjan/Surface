#include "DxLib.h"
#include "player.h"
#include "enemy.h"
#include<cmath>

#define CIRCLE_NUM 3

namespace
{
	//�G�̐�

	//�G�̈ʒu���
	constexpr int kEnemyIntervalX = 160;
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

	//�v���C���[
	Player player;
	player.init();

	//�G
	Enemy enemy[CIRCLE_NUM];
	for (int i = 0; i < CIRCLE_NUM; i++)
	{
		enemy[i].init();
		enemy[i].setPosX(kEnemyIntervalX * (i + 1));
	}
	

	
	//�Q�[�����[�v
	while (ProcessMessage() != 1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();


		//�`����s���O�ɉ�ʂ��N���A����

		ClearDrawScreen();

		//�Q�[���̏���
		player.update();
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			enemy[i].update();
		}
		
		//�����蔻��
		int playerPosX = (float)player.getPosX();
		int playerPosY = (float)player.getPosY();
		int enemyPosX = (float)enemy[0].getPosX();
		int enemyPosY = (float)enemy[0].getPosY();
		
		float playerRadius = (float)player.getRadius();
		float enemyRadius = (float)enemy[0].getRadius();

		float dx = enemyPosX - playerPosX;
		float dy = enemyPosY - playerPosY;
		float dist = sqrtf(dx * dx + dy * dy);

		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			if (dist < (playerRadius + enemyRadius))
			{
				enemy[i].getDraw();
				
			}
			else
			{

				enemy[i].draw();
				
			}

		}

		//�`��
		player.draw();
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			enemy[i].draw();
			enemy[i].setPosX(kEnemyIntervalX * (i + 1));
		}
		
		
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