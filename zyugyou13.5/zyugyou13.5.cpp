#include<iostream>
#include<cmath>     //数字関数

//#include<stdio.h>
//#include<stlib.h>
//↓  C++で上に含まれる関数を使いたい！
//#include<cstdio>
//#include<cstdiob>

//<cmath>
//↓　Cで上に含まれる関数を使いたい！
//<math.h>
using namespace std;

int main()
{
	//直角三角形の斜辺の長さを求めるプログラム
	double a, b;   //底辺と高さ

	cout << "直角をはさむ２辺の長さを入力してください >" << flush;
	cin >> a >> b;

	//斜辺の長さを計算する
	double result = (a * a + b * b);     // sqrt(x)でxの平方根を求める
	cout << "斜辺の長さは" << result << "です。" << endl;

	//abs(x)      :xの絶対値を求める
	//float(x)    :小数点以下切り捨て
	//cell(x)     :小数点以上切り上げ
	//fmod(x,y)   :xをyで割ったあまり
	//sqrt(x)     :xの平方根
	//... 等　　教科書140ページ～参照

	return 0;
}

/*
//値渡しを使用した関数
void add_1(int x)
{
	x += 1;
}
//ポインタ渡しを使用した関数
void add_2(int* pX)
{
	//参照先がないので何もしない
	if (pX == nullptr) return;
	*pX += 2;
}

//参照渡しを使用した関数
void add_3(int& x)
{
	//必ず何かしらの変数を参照しているので
	//チェックなどは不要
	x += 3;
}

int main()
{
	int num = 123;
	cout << "num = " << num << endl;

	add_1(num);   //値渡し    numは変化しない
	cout << "add_1:" << num << endl;

	add_2(&num);  //ポインタ渡し   numは変化する
	cout << "add_2:" << num << endl;

	add_3(num);   //参照渡し　　numは変化する
	cout << "add_3:" << num << endl;

	//参照を使ってみる
	int& refNum = num;
	cout << "refNum = " << refNum << endl;

	refNum -= 100;
	cout << "num = " << num << endl;
	cout << "refNum = " << refNum << endl;

	refNum += 1000;
	cout << "num = " << num << endl;
	cout << "refNum = " << refNum << endl;

	//参照の注意点　参照先の変更はできない
	int num2 = 999;

	int* pNum = &num;
	pNum = &num2;

	//参照先の変更はできないはずだが…
	refNum = num2;
	cout << "refNum = " << refNum << endl;

	//参照先は必ず初期化時に設定する
//	int& refNum2 = //ng 生成時に参照先を設定する必要がある
	int& refNum2 = num2;    //必ず参照先を設定する


	int* pNum2 = nullptr;    //ポインタは生成時に初期化不要
//	cout << "pNum2 = " << (*pNum2) << endl; //??
	//ポインタは参照先がない可能性がある


	return 0;
}
*/


/*
//西暦を昭和に変換する関数
//昭和ではない年が指定された場合0にする
void WesternToShouwa(int* x)
{
	if (1926 <= *x && *x <= 1989)  //1926年～1989年が昭和
	{
		*x -= 1925;
	}
	else
	{
		*x = 0;
	}
}

void Shouwa(void)
{
	int year;

	cout << "西暦を入力してください" << flush;
	cin >> year;     //キーボードから数値を入力する

	//  cout << "入力" <<year << endl;     //デバック表示
	WesternToShouwa(&year);
	if (year != 0)
	{
		cout << "その年は昭和" << year << "年です。" << endl;
	}
	else
	{
		cout << "その年は昭和ではありません。" << endl;
	}
}

int main()
{
	Shouwa();
	Shouwa();



	return 0;
}
*/