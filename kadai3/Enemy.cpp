#include "DxLib.h"
#include "Enemy.h"

typedef struct Enemy
{
	int handle;
	float x;
	float y;
	float moveX;
	float moveY;

}Enemy;

void updateEnemy(Enemy* eEnemy)
{
	eEnemy->x += eEnemy->moveX;
	eEnemy->y += eEnemy->moveY;
	if (eEnemy->x < 0)
	{
		eEnemy->x = 0;
		eEnemy->moveX *= -1.0f;
	}
	if (eEnemy->x > 600)
	{
		eEnemy->x > 600;
		eEnemy->moveX *= -1.0f;
	}
	if (eEnemy->y < 0)
	{
		eEnemy->y = 0;
		eEnemy->moveY *= -1.0f;
	}
	if (eEnemy->y > 440)
	{
		eEnemy->y = 440;
		eEnemy->moveY *= -1.0f;
	}
}

//敵を一体描画する関数
void drawEnemy(Enemy enemy)
{
	DrawGraph((int)enemy.x, (int)enemy.y, (int)enemy.handle, 0);
}

//全ての敵を移動させる関数
void updateAllEnemy(Enemy enemy[])
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		updateEnemy(&enemy[i]);
	}
}

//全ての敵を描画する関数
void drawAllEnemy(Enemy enemy[])
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		drawEnemy(enemy[i]);
	}
}