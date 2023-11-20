#include "WalkEnemy.h"
#include "DxLib.h"

WalkEnemy::WalkEnemy():
	WalkEnemyGraph(0)
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init()
{
	DrawGraph(610, 230, WalkEnemyGraph, true);
}

void WalkEnemy::Update()
{
}

void WalkEnemy::Draw()
{
	WalkEnemyGraph = DrawBox(610, 230, 630, 250, GetColor(255, 255, 0), true);
}
