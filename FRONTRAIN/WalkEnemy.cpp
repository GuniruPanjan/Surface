#include "WalkEnemy.h"

#include "DxLib.h"


WalkEnemy::WalkEnemy():
	WalkEnemyGraph(0),
	WalkEnemyX(610),
	WalkEnemyY(230),
	WalkEnemyW(0),
	WalkEnmeyH(0)
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init()
{
	DrawGraph(WalkEnemyX, WalkEnemyY, WalkEnemyGraph, true);

	GetGraphSize(WalkEnemyGraph, &WalkEnemyW, &WalkEnmeyH);

}

void WalkEnemy::Update(Shot& shot)
{
	for (int i = 0; i < SHOT; i++)
	{
		if (shot.Flag == 1)
		{
			//“G‚Æ‚Ì‚ ‚½‚è”»’è
			if (((shot.X > WalkEnemyX && shot.X < WalkEnemyX + WalkEnemyW) ||
				(WalkEnemyX > shot.X && WalkEnemyX < shot.X + shot.Width)) &&
				((shot.Y > WalkEnemyY && shot.Y < WalkEnemyY + WalkEnmeyH) ||
					(WalkEnemyY > shot.Y && WalkEnemyY < shot.Y + shot.Height)))
			{
				//ÚG‚µ‚Ä‚¢‚éê‡‚Í“–‚½‚Á‚½’e‚Ì‘¶Ý‚ðÁ‚·
				shot.Flag = 0;
			}
		}
	}
}

void WalkEnemy::Draw()
{
	WalkEnemyGraph = DrawBox(WalkEnemyX, WalkEnemyY, 630, 250, GetColor(255, 255, 0), true);
}
