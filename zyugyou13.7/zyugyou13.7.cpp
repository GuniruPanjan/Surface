#include<iostream>
using namespace std;

//Cの定数定義の作法　　　忘れていい
//#define NUM 3

//C++を使う際はこの定義を使う
//C++風定数定義
//const int kArraySize = 5;

//現代的C++の定数定義
namespace
{
	constexpr int kConstexprNum = 3;         //constexpr:定数を定義するために準備された書き
	                                         //コンパイル時点で値決まっている場合はこっち
	const int kConstNum = 3;                 //const:変数の変更を不可能にするための書き方
	                                         //最初に決めた値から変更できないという性質を利用して
	                                         //定数定義に使用していた
}

//定数定義のまとめ
//namespace（無名名前空間　名前が設定されていないnamespace）の中に入れる
//無名名前空間の中に書いている変数や定数、関数はそのソースコードでのみ有効

namespace
{
	//基本的に定数はconstexprで定義する
	//定数名はgoogleのコーディング規約準拠
	//定数名の命名規則はほかのルールが良いならそれでいいが必ず統一すること
	constexpr int kNum = 16;
	
	constexpr int kDoublNum = kNum * 2;       //定数を使用して定数を定義することも可能
	constexpr float kFloatNum = 12.25f;   // int以外もOK

	//当たり判定のサイズ
	constexpr float kRadius = 8.0f;
}    //namespace終了時セミコロン不要

namespace
{
	constexpr int kEnemyNum = 16;
}

//通常のnamespaceの書き方
//namespaceの後に名前を設定する
namespace Test
{
	int num = 10;
}

//文字列を定義として定義したい
const char* const kConstText = "定数として定義された文字列";
const char* const kFileName = "data/image.ping";    //ファイル名を定義する

//pNumの参照先変更不可
//pNumの中身固定ではない 初期化はできるという事
void func(const int* pNum)
{

}

int main()
{
	/*
	int tbl[kArraySize] = { 10,20,30 };
	for (int i = 0; i < kArraySize; i++)
	{
		cout << tbl[i] << endl;
	}

	cout << kConstText << endl;
	*/

	//constは初期化できる
	const int constNum = rand() % 16;
	//後から変更はできない
	//constNum = 10;

	//コンパイルした時点で値が決まらない
	//constexpr int constexprNum = rand() & 16;

	//定数定義はconstexprを使う
	//それ以外の変更してほしくない値はconstを使う
	return 0;
}

/*
//身長の配列をわたしてそれぞれの標準体重を表示する関数　身長-105を表示する
//変数名やポインタの宣言前にconstを付けることでその中身を変更することができなくなる
void dispStandardWaight(const int height[])
{
	cout << "標準体重" << endl;
	for (int i = 0; i < 3; i++)
	{
		int stdWeight = height[i] - 105;
		cout << i + 1 << ":" << stdWeight << endl;
	}
}

//身長を表示する関数
void dispHeight(const int height[])
{
	cout << "身長" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ":" << height[i] << endl;
	}

	
}

struct Test
{
	int testData0;
	int testData1;

};

//ポインタや参照をconstにするとそのメンバー変更できなくなる
void testFunc(const Test& pTest)
{
	pTest.testData0 = 100;
	pTest.testData1 = 100;
}

int main()
{
	Test test;
	testFunc(test);

#if false
	//３人分に身長データ
	int height[3] = { 170,180,190 };

	//標準体重を表示する
	dispStandardWaight(height);

	//身長データを表示する
	dispHeight(height);

#endif




	return 0;
}
*/