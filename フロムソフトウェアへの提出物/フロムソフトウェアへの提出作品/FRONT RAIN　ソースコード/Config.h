#pragma once
#include "Point.h"
#include "TimeCount.h"

void Config_Initialize();//初期化
void Config_Finalize();//終了処理
void Config_Update(Point& point,TimeCount& timecount);//更新
void Config_Draw(Point& point,TimeCount& timecount);//描画