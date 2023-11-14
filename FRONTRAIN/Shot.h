#pragma once

#define SHOT 30


class Shot
{
public:
	Shot();
	~Shot();

	void Init();
	void Update();
	void Draw();

	//弾があるかのショットフラグ
	bool ShotFlag;

	//ショットの位置
	int X;
	int Y;

	//ショットの大きさを確保
	int Wdit;
	int Hight;

	Shot* shot[SHOT];

private:
	int ShotGraph;
	
	
	
};

