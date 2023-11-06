#include<iostream>
#include <vector>
#include "Application.h"

//今日(10/6)やること
//①Applicationシングルトンクラスを作る
//②時間が足りれば、Stateパターンによるシーン遷移を作る

//シングルトン(Singleton)クラスとは何か
//アプリケーション中で一つしかインスタンスがないことを保障するクラス
//どこからでもこのインスタンスにアクセスできる
//シングルトンクラスとは「お行儀のよいグローバルオブジェクト」である
using namespace std;
//配列でint a[10];　この時a[7] = 7[a] = *(a+7)です
//実は、配列の名前というのは配列のために確保されたメモリのアドレスを入れている変数です。つまりポインタと一緒です
//ここで言う+7は、7バイトのことじゃない
//+7→+7*4 = +28に変換されます僕らに見えないところで
//その結果7番目の要素をかえしているという事になります
//2次元配列は1次元配列です
//2次元配列でもメモリが1次元的に連続しているため

struct Object
{
	int a;
	int b;
	int c;
};

void CreateObject(int a, int b, int c, Object** obj)
{
	*obj = new Object();
	(*obj)->a = a;
	(*obj)->b = b;
	(*obj)->c = c;
}

int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

string Add(string a, string b)
{
	return a + b;
}

//テンプレート関数
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

//テンプレートクラス
template<typename T>
class Array
{
private:
	T array_[10];
public:
	Array()
	{
		float start = 3.14f;
		for (T& a : array_)
		{
			a = start;
			start += 0.1f;
		}
	}
	void Output()
	{
		for (const T& a : array_)
		{
			cout << a << endl;
		}
	}

};



int main()
{
	/*int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	cout << a[7] << endl;
	cout << 7[a] << endl;
	cout << *(a + 7) << endl;*/

	constexpr int row = 3;
	constexpr int col = 4;
	Array<int> iarray;
	Array<float> farray;

	iarray.Output();
	farray.Output();

	////これは中身がint型の動的配列
	//std::vector<int> ivec;
	////これは中身がfloat型の動的配列
	//std::vector<float> fvec;
	////これは中身がstring型の動的配列
	//std::vector<string> svec;
	////これは中身がEnemy型の動的配列
	//std::vector<Enemy> enemies;

	//int a[10];
	//int idx = rand() % 20;
	//a[10] = 3;

	vector<int> array_ = { 1,2,3,4,5 };
	array_[5] = 9;
	for (auto& a : array_)
	{
		cout << a << endl;
	}

	//listかvectorで迷ったらvectorでOK

	string str = "Hello,World,Fukuoka";
	cout << str << endl;
	auto idx = str.find(',');
	cout << str.substr(idx + 1) << endl;

	int idx = 0;
	do
	{
		int nidx = str.find(',', idx);
		cout << str.substr(idx) << endl;
		idx = nidx + 1;
		nidx = str.find(',', idx);
		if (idx == std::string::npos)
		{
			break;
		}
		cout << str.substr(idx, nidx - idx) << endl;
		++nidx;
	} while (idx != std::string::npos);

	//stringはchar型の動的配列に便利な関数を足しただけのもの

	//cout << str.rfind('o') << endl;

	cout << str.length() << endl;
	cout << str << endl;

	Add(1, 2);
	Add(3.14f, 2.7f);

	Add(string("Hello"), string("World"));

	const char* bgPath = "bg.png";
	

	//Unicode以前:マルチバイト文字列<-char*で表現可能
	//Unicode以降:ワイド文字列<-wchar_t*で表現可能
	//stringのワイド文字バージョンはwstringです
	 
	//cout << a[idx] << endl;

	/*cout << Add(row, col) << endl;
	cout << Add(3.14f, 2.71f) << endl;
	cout << Add(string("Hello"), string("World")) << endl;*/

	/*int b[row][col] = {{1,2,3,4}, {5,6,8,7}, {12,11,10,9}};
	int c[row * col] = { 1,2,3,4,5,6,8,7,12,11,10,9 };*/
	//cout << c[2*col+2] << endl;
	/*cout << b[2][2] << endl;
	cout << b[0][10] << endl;*/

	//cout << "abcdefghi"[3] << endl;
	//cout << 3["abcdefghi"] << endl;

	//float a = 3.14f;
	//int b = 5;
	//cout << *((int*)&a) << endl;
	//cout << b << endl;

	//std::vector<int>a = { 1,2,3,4,5 };
	//int& b = a[3];
	//cout << b << endl;
	////a = { 2,4,6,8,10 };
	//a.push_back(20);
	//cout << b << endl;

	//ややこしい型
	//union UniTest
	//{
	//	int a;     //4バイト
	//	float b;   //4バイト
	//	char c[4]; //4バイト
	//};
	//struct StTest
	//{
	//	int a;     //4バイト
	//	float b;   //4バイト
	//	char c[4]; //4バイト
	//};

	//struct BitField
	//{
	//	int a : 1;
	//	int b : 2;
	//	int c : 3;
	//	int d : 4;
	//	int e : 6;
	//	int f : 16;
	//};
	//BitField bf;
	//cout << sizeof(bf) << endl;
	/*UniTest u;
	StTest st;*/
	/*cout << sizeof(u) << endl;
	cout << sizeof(st) << endl;*/

	/*u.b = 3.14f;

	cout << u.b << endl;
	cout << u.a << endl;
	cout << u.c << endl;*/

	/*std::vector<std::string> strList;

	int a[4] = { 1,2,3,4 };
	int b[4];*/

	//b = a;//aもbも指し示しているのはアドレスなので

	/*struct Array
	{
		int array[4];
	};

	Array c = { 1,2,3,4 };
	Array d;

	d = c;
	for (auto& e : d.array)
	{
		e *= 2;
	}
	for (auto e : c.array)
	{
		cout << e;
	}
	cout << endl;
	for (auto e : c.array)
	{
		cout << e;
	}
	cout << endl;*/

	/*class Vector
	{
	private:
		int array_[10];
	public:
		void operator = (Vector& v)
		{
			for (int i = 0; i < _countof(array_); i++)
			{
				array_[i] = v.array_[i];
			}
		}
	};

	std::vector<int> a = { 1,2,3,4,5 };
	std::vector<int> b;
	b = a;

	for (auto& c : b)
	{
		c *= 2;
	}
	for (auto c : a)
	{
		cout << c;
	}

	struct Alignment
	{
		int a;
		char b;
	};
	struct Alignment2
	{
		char a;
		int b;
	};
	struct Alignment3
	{
		char a;
		char b;
	};*/

	/*cout << sizeof(char) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(Alignment) << endl;
	cout << sizeof(Alignment2) << endl;
	cout << sizeof(Alignment3) << endl;*/

	/*char* c = 0;
	int* b = 0;

	c++;
	b++;

	cout << (unsigned int)c << endl;
	cout << (unsigned int)b << endl;

	Object* obj;
	CreateObject(1, 2, 3, &obj);

	cout << (unsigned int)obj << endl;*/

	//文字列には、通常の文字とワイド文字の2種類があります
	//通常の文字列リテラルは、char*で表せる""ダブルクォートでOK
	//ワイド文字列リテラルは、wchar_t*で表せる L""のようにLが頭に必要です

//①C++に置けるテンプレート
//②
//③stringはchar型を改良したものです
//④C/C++の文字列型にはマルチバイト文字とワイド文字がある

//マルチバイト文字：Shift-JIS(SJIS)
//ワイド文字:Unicode(UTF-8)
//プロジェクトの設定をUnicodeにしても、cppのテキストファイルの仕様そのものはSJISになっている
//マルチバイト文字：char*, string
//ワイド文字：wchar_t*,wstring
//これた相互のｎ変換をするにはWidndows関数を使う必要があります
//MultiByteTowideCharという関数を使う
//自分のプロジェクトにStringUtilityというクラスを作る
//static関数ばかりのクラスはnewなどをする必要がない

//クラスのpublicメンバ関数には「必ず」コメントを付けよう
//publicメンバ関数を使うのは、利用者側です（自分ではない人が使う）
//コメントはヘッダ側に書こう

//MicrosoftのAPIのマニュアルの読み方
//[in]と書かれてたら普通のパラメータ（値が書き換えられない）
//[out]と書かれてたら、ポインタを渡して書き換えられる事を期待します
//[oprional]は、この引数が無くてもいいよ（nullptrや0でも動作する）を表す
//UNIT = unsigned int
//DWORD = uint32_t = 4バイト符号なしの整数型の事です
//LPCCH = LPはポインタの事、CCH = (C言語のchar型)->const char*を入れろ
//LPWSTR = WSTRはワイド文字の事、それのポインタに入れろ
//とにかくMSのマニュアルを見る癖を付けろ

	return 0;
}