#include "StringUtility.h"
#include<cassert>
#include "windows.h"

std::wstring 
StringUtility::StringToWString(const std::string& str)
{
	//in : 情報側はstring
	//out : 戻り値はwstiring



	std::wstring ret;//最終的に返すワイド文字列

	//1回目の呼び出し
	int result = MultiByteToWideChar(
		CP_ACP,   //コードページ
		0,        //文字の種類を指定するフラグ
		str.data(),   //マップ元文字列のアドレス
		str.length(), //マップ元文字列のバイト数
		nullptr,      //マップ先ワイド文字列を入れるバッファのアドレス
		0);           //バッファのサイズ

	//一度目の呼び出しの戻り値が、変換後文字列の文字列数になっています

	//標準の特殊な書き方
	//基本的には数字がビット数を表していると思ってください
	//先頭にuがついているものは、符号なし(unsigned)を表しています
	uint8_t a; //8bit符号なし
	int8_t b;  //8bit符号あり
	uint16_t c;//16bit符号なし
	int16_t d; //16bit符号あり
	uint32_t e;//32bit符号なし
	int32_t f; //32bit符号あり
	byte g;    //


	assert(result >= 0);

	ret.resize(result);//受け取れる文字列のバッファを確保する
	return std::wstring();
}
