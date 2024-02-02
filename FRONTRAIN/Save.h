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

	void SaveInit();

	void SaveDate(Point& point, TimeCount& timecount);

	void SaveInput();

	void SaveLoad();

	save_data_t save_date;

	bool Start = false;
	bool end = false;

	int name; //セーブの名前入力保存変数宣言
	int White;  //色の宣言

	//サウンド用格納変数
	int Soundname;

};

