#pragma once

class Point
{
public:
	Point();
	~Point();

	void InitPoint();
	void UpdatePoint();
	void DrawPoint(int ScrollX);

	int PointNow, WenemyPoint;

	//エネミーの出現時間
	int WalkEnemyTime = 0;
};

