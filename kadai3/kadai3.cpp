#include "DxLib.h"
#include "player.h"
#include "Enemy.h"

#if false //��������R�����Q�[���J��

�Q�[���J������Debug�ŁA
���������Q�[����Release��

Debug�łł̓}�N���Ƃ���       _DEBUG
Relase�łł̓}�N���Ƃ��ā@�@�@NDEBUG
�����ꂼ���`����Ă���

#ifdef DEBUG
//�f�o�b�O�łł̂ݎ��s�����
//���W��\��������A�����{�^���ŃN���A�����肷��@�\������
#else
//�����[�X�łł̂ݎ��s�����
//���܂�Ȃ�����

#endif

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(1);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);


	//�v���C���[�֘A�̏��
	Player player;
	player.handle = LoadGraph("data/sukaihai.png");
	player.x = 320.0f;
	player.y = 240.0f;
	
	//�G�֘A�̏��
	Enemy enemy[ENEMY_NUM];
	int Load = LoadGraph("data/huruhurubebi-.png");
	enemy[ENEMY_NUM].handle;
	enemy[ENEMY_NUM].x;
	enemy[ENEMY_NUM].y;
	enemy[ENEMY_NUM].moveX;
	enemy[ENEMY_NUM].moveY; 

	//�G�̏�����
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].handle = Load;
		enemy[i].x = (float)(GetRand(640 - 40));
		enemy[i].y = (float)(GetRand(480 - 40));
		enemy[i].moveX = 2.0f;
		if (GetRand(1))	enemy[i].moveX *= -1.0f;
		enemy[i].moveY = 2.0f;
		if (GetRand(1))	enemy[i].moveY *= -1.0f;
		

	}

	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//�`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		//update
		updatePlayer(&player);
		//�G��updata
		updateAllEnemy(enemy);

		// draw
		drawPlayer(player);
		
		drawAllEnemy(enemy);
		
		//��ʓ��̎w�肵�����W�ɕ������\���ł���
		//DrawString(0, 0, "�e�X�g", GetColor(255, 128, 0));

		//�����t���R���p�C���𗘗p����
		//Debug�łł̂ݎ��s����鏈������������

		//�v���C���[�̍��W�\��
		DrawFormatString(8,8,GetColor(255,255,255),"Player(%f,%f)",player.x, player.y);
		

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

	}


	DeleteGraph(player.handle);
	DeleteGraph(Load);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}