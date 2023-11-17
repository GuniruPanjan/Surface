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

	//�F�̐錾
	const unsigned int kchageColor = GetColor(255, 0, 0);
	const unsigned int kdefalutColor = GetColor(200, 200, 200);
}

//�v���C���[�ƓG���������Ă��邩�𔻒肷��
//�N���X�A�\���̂������Ƃ��ēn���ꍇ�̓|�C���^�A�Q�Ɠn������
//�l�n����
bool isCollision(Player player, Enemy enemy)
{
	//����ɕK�v�ȃv���C���[���̎擾
	float playerPosX = (float)player.getPosX();
	float playerPosY = (float)player.getPosY();
	float playerRadius = (float)player.getRadius();

	//����ɕK�v�ȓG���̎擾
	float enemyPosX = (float)enemy.getPosX();
	float enemyPosY = (float)enemy.getPosY();
	float enemyRadius = (float)enemy.getRadius();

	//X���W
	float dx = playerPosX - enemyPosX;
	//Y���W
	float dy = playerPosY - enemyPosY;
	//�O�����̒藝�𗘗p���ċ��������߂�
	float dist = sqrtf(dx * dx + dy * dy);
	if (dist < (playerRadius + enemyRadius))
	{
		//��������
		return true;
	}
	return false;

}

//�v���C���[�����W��\������֐�
void dispPlayerPos(Player& player)
{
	int x = player.getPosX();
	int y = player.getPosY();
	DrawFormatString(8, 8, GetColor(255, 255, 255), "(%3d,%3d", x, y);
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
			float playerPosX = (float)player.getPosX();
			float playerPosY = (float)player.getPosY();
			float playerRadius = (float)player.getRadius();
		
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			//�����蔻��
			float enemyPosX = (float)enemy[i].getPosX();
			float enemyPosY = (float)enemy[i].getPosY();
			float enemyRadius = (float)enemy[i].getRadius();

			float dx = playerPosX - enemyPosX;
			float dy = playerPosY - enemyPosY;
			float dist = sqrtf(dx * dx + dy * dy);

			
			if (dist <= (playerRadius + enemyRadius))
			{
				enemy[i].setColor(kchageColor);
					
			}
			else
			{
				enemy[i].setColor(kdefalutColor);
					
			}
			
			
		}

		//�`��
		player.draw();
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			enemy[i].draw();
			
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