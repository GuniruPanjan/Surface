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

//ハイスコア用の構造体
typedef struct
{
	int Distance;    //移動時間
	int Point;       //ポイント
	int Time;        //経過時間
}save_hiscore_t;

class Save
{
public:
	Save();
	~Save();

	void FinalizeSave();
	void SaveInit();

	void SaveDate(Point& point, TimeCount& timecount);

	int GetHiScore(void);

	void SaveInput();
	void NameOutPut();

	void SaveLoad();
	void SaveHiscoreLoad();

	save_data_t save_date;

	save_hiscore_t save_hiscore;

	bool Start = false;
	bool end = false;

	int name; //セーブの名前入力保存変数宣言
	int White;  //色の宣言

	char String[20];  //名前出力

	int hiscore = 0;   //ハイスコア

	//サウンド用格納変数
	int Soundname;

};

