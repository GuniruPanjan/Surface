#pragma once



//構造体の宣言
typedef struct Enemy
{
	int handle;
	float x;
	float y;
	float moveX;
	float moveY;

}Enemy;

void updateEnemy(Enemy* eEnemy);
void drawEnemy(Enemy enemy);
void updateAllEnemy(Enemy enemy[]);
void drawAllEnemy(Enemy enemy[]);
