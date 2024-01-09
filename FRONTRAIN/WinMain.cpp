#include "Player.h"
#include "WalkEnemy.h"
#include "Background.h"
#include "DxLib.h"
#include "Map.h"
#include "GraphMode.h"
#include "TimeCount.h"
#include "Point.h"

// �v���O������ WinMain ����n�܂�܂�

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{
	GraphMode graph;

	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������

	ChangeWindowMode(true);

	SetWindowSize(graph.GraphModeWIDTH, graph.GraphModeHEIGHT);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������

	{

		return -1;			// �G���[���N�����璼���ɏI��

	}

	

	SetDrawScreen(DX_SCREEN_BACK);

	Player player;
	Shot shot[SHOT];
	WalkEnemy WEnemy;
	WalkEnemyStruct WenemyS[ENEMY_NOW];
	Map map;
	Background Back;
	TimeCount timecount;
	Point point;

	int shotGraph = LoadGraph("date/�e�e.png");
	bool Isflag = false;

	

	timecount.InitTime();
	point.InitPoint();
	player.Init();
	for (int i = 0; i < SHOT; i++)
	{
		player.InitShot(shot[i],shotGraph);
	}

	for (int i = 0; i < ENEMY_NOW; i++)
	{
		WEnemy.Init(WenemyS[i], WEnemy);
	}

	
	

	map.InitMap();
	// �Q�[�����[�v

	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���

		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����

		ClearDrawScreen();

		// �Q�[���̏���

		Back.Draw();

		timecount.UpdateTime(point);

		player.Update(player, map);

		for (int i = 0; i < SHOT; i++)
		{
			WEnemy.Update(player, shot[i], WenemyS, ENEMY_NOW,player.ScrollX,&timecount,WEnemy);
		}

		player.ShotUpdate(player, shot, SHOT);
		map.UpdateMap(player.ScrollX);
		
		timecount.DrawTime();
		point.DrawPoint();
		player.Draw();
		for (int i = 0; i < SHOT; i++)
		{
			player.DrawShot(shot[i]);
		}

		for (int i = 0; i < ENEMY_NOW; i++)
		{
			WEnemy.Draw(player.ScrollX, WenemyS[i], point);
		}
		
		
		
		
		for (int i = 0; i < SHOT; i++)
		{
			map.DrawMap(player.ScrollX, shot[i], player, WenemyS);
			
		}
		

		

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