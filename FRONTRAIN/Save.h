#pragma once
#include "Point.h"
#include "TimeCount.h"

//セーブデータの構造体
typedef struct
{
	int Distance;     //移動距離
	int Point;        //ポイント
	int Time;         //経過時間
}save_data_t;

class Save
{
public:
	Save();
	~Save();

	void SaveDraw(Point& point, TimeCount& timecount);

};

