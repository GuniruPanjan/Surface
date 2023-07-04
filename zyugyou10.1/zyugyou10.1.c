#include<stdio.h>  //printf(),scanf_s()等のプロトタイプ宣言が書かれている
//#include<stdio.h>  //rand(),srand()等のプロトタイプ宣言が書かれている
#include"zyugyou10.h"



//練習問題7-2
void showAverage(int val1, int val2)   //val:valueの略　　値
{
	int i;
	float f;
	i = (val1 + val2);
	//整数で計算すると小数点以下が切り捨てられる
	//キャストを使って少数点まで求める
	f = (float)i / 2.0f;          //平均を求める
	printf("1つ目の値は%dです。\n", val1);
	printf("2つ目の値は%dです。\n", val2);
	printf("2つの値の平均値は、%fです。\n", f);
}

//練習問題７－１
void transSeconds(int sec)
{
	int aHour, aMin, aSec;

	aHour = sec / (60 * 60);  //時間を求める
	aMin = (sec % (60 * 60)) / (aHour * 60);   //分を求める
	aSec = (sec % (60 * 60)) % (aHour * 60);    //秒を求める

	printf("%d秒は、%d時間%d分%d秒です\n", sec, aHour, aMin, aSec);

	return;
}

int main(void)
{
	int timeSec = 5000;

	transSeconds(timeSec);  //引数として秒数を渡す（この例では5000秒）

	return 0;
}










/*
void f(void)
{
	static int num = 0;
	num++;
	printf("f関数が呼ばれたのは%d回目です\n", num);
}







int main(void)
{
	f();
	f();
	f();
	f();

	return 0;
}
*/

/*
//変数の値に足し算したい
void add(int baseNum, int addNum)
{

	return (baseNum + addNum);
}

int main(void)
{
	int num = 0;

	printf("num = %d\n", num);

	 add(num, 5);

	printf("num = %d\n", num);

	return 0;
}
*/


/*
int a = 1;

void f(void)
{
	int a = 1;
	printf("関数の中の変数aの値は%dです\n", a);
	return;
}

int main(void)
{
	int a = 2;
	printf("main関数の中の変数の値は%dです\n", a);
	f();
	return 0;
}
*/

/*グローバル変数とローカル変数
int a = 1;          //グローバル変数

void f(void)
{
	int b;        //ローカル変数
//  printf("関数fの中でaの値は%dです\n", a);
	printf("関数fの中でaの値は%dです\n", b);
	return;
}



int main(void)
{
	int c;
	printf("main関数の中でaの値は%dです\n", a);
	f();

	for (int i = 0; i < 5; i++)
	{
		printf("i = %d\n", i);
	}
	return 0;       //ローカル変数
}
*/