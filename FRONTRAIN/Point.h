#pragma once
class Point
{
public:
	Point();
	~Point();

	void InitPoint();
	void UpdatePoint();
	void DrawPoint();

	int PointNow, WenemyPoint;

	//�G�l�~�[�̏o������
	int WalkEnemyTime = 0;
};

