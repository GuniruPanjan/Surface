#include<stdio.h>

int main(void)
{
	//ポケモンのコンプリート率を計算したい
	//ポケモンの数は151種類

	//百分率　割合
	//100%    1.0
	//50%     0.5
	//25%     0.25

	//現在登録されているポケモンの数
	int pokeNum = 120;
	float rate = 0.0f;
	//コンプリート率の計算
	rate = (float)pokeNum / 151;  //異なる型同士で計算を行う際には、キャストを用いる

	printf("コンプリート率　＝　%f %%\n", rate * 100.0f);

	int a = 10 + 20;
	int b = 10 + 20 + 30;
	int c = b = a;



	return 0;
	/*
	//整数型（int)に少数を入れると小数点以下が消える
	float numFloat = 1.999999f;
	int numInt = numFloat;
	printf("numInt = %d\n", numInt);


	//floatに整数の値を入れる
	numInt = 256;
	numFloat = numInt;
	printf("numFloat = %f\n", numFloat);

	//浮動小数点は誤差が発生する
	float floatTest = 0.0f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	printf("floatTest = %f\n", floatTest);
	printf("floatTest = %1.16f\n", floatTest);



	//変数
	int hp = 100;

	hp = hp - 10;
	hp = hp + 5;

	hp -= 10;  //hp = hp - 10と同じ

	hp--;  //デクリメント　変数の値を１減らしてその変数の値に代入
	hp++;  //インクリメント　変数の値を１増やしてその変数の値に代入

	++hp;
	--hp;

	hp = 10;
	int a = hp;
	hp++;
	printf("a = %d, hp = %d\n", a, hp);

	hp = 10;
	++hp;
	int b = hp;
	printf("b = %d, hp = %d\n", b, hp);

	int test = 10 + 10 * 3;
	printf("test = %d\n", test);

	test = (10 + 10) * 3;
	printf("test = %d\n", test);



	//変数
	int numInt = 10;     //整数
	float numFloat = 1.2345f;   //少数
	char numChar = 'z';    //文字



	numInt = 10 + 10;  //加算
	numInt = 10 - 10;  //減算
	numInt = 10 * 10;  //乗算
	numInt = 10 / 10;  //除算
	numInt = 10 % 10;  //余算

	numInt = 53;

	printf("割り算　%d/5=%d余り　%d\n",
		numInt, numInt / 5, numInt % 5);



	printf("文字列を表示するときは\nprintf("")\n");

	printf("整数を表示するとき　%d\n", 10);

	printf("少数を表示するとき %f\n", 1.234f);

	printf("１文字を表示するとき　%c\n", 'ｚ');

	printf("文字　%c\t 整数　%d\t 少数　%f\n", 'a', 64, 3.14f);
	*/
}