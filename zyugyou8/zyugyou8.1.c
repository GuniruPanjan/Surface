#include<stdio.h>

//2つの値x,y(int 以下すべてそう）を渡してその合計を返す関数
int add(int x, int y)
{
	int a = x + y;
	return a;
}

//2つの値x,yを渡してその差を返す関数（単純な引き算でOK）
int sub(int x, int y)
{
	int b = x - y;
	return b;
}

//2つの値x,yを渡してその乗算結果を返す関数
int mul(int x, int y)
{
	int c = x * y;
	return c;
}

//2つの値x,yを渡してxのy乗を返す関数
int pow(int x, int y)
{
	int d = 1;
	for (int i = 0; i < y; i++)
	{
		d *= x;
	}

		return d;
}




int main(void)
{
	

	int x = 4;
	int y = 3;

	int result = add(4, 3); //作ったadd関数を呼び出す
	printf("add = %d\n", result);

	result = sub(4, 3);   //作ったsub関数を呼び出す
	printf("sub = %d\n", result);

	result = mul(4, 3);   //作ったmul関数を呼び出す
	printf("mul = %d\n", result);

	result = pow(4, 3);   //作ったpow関数を呼び出す
	printf("pow = %d\n", result);

}

/*int total(int x, int y)
{
	int z = x + y;  //合計値を計算する
	return z;
}

//戻り値の勉強
int main(void)
{
	int a = total(1, 3);
	printf("合計は%dです\n", a);
	return 0;
}
*/
/*2つの値のうち、どちらが大きいかを比較する関数
void bigger(int x, int y, float z)
{
	printf("z = %f\n", z);
	printf("2つの引数のうち、大きいほうを表示する\n");
	if (x > y)
	{
		printf("%dのほうが大きいです\n", x);
	}
	else
	{
		printf("%dのほうが大きいです\n", y);
	}
	return;
}


int main(void)
{
	bigger(1, 5, 3.14f);
	return 0;
}
*/
/*関数化する基準
//1.同じ処理が書かれている場所が複数ある場合
//例.ゲームの場合ダメージ処理など
//ダメージ処理->HPを減らして、画面を揺らして、プレイヤーが赤く点滅する
//同じ処理を今後書きそうだな、と思ったら関数化

//2.パッと見て何をやっているか分からない処理
// ソースを見ても分からない処理に分かりやすい関数名をつけてやる
//float angle = acos (cross(dir, toEnemy));
//printf("angle = %f\n",angle);
//↓
//void calcAngle(void) //関数名を見たら角度を計算する処理だな、と分かる
//{
// float angle = acos(cross(dir, toEnemy));
// printf("angle = %f\n", angle);
//}

void function(void)
{
	printf("勝ち！");


	return;
}

//引数ありの関数
//引数に応じた処理を行うことができる
void dispNumber(int num)
{
	printf("num = %d\n", num);
	return 0;
}

//関数の中で渡された数を変更する
void addNumber(int num)
{
	printf("num = %d\n", num);
	num += 10;
	printf("num + 10 = %d\n", num);
	return;
}

//関数の中でif,for,whileなど使える
//引数は普通の変数のように扱える
void forFuction(int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("test\n");
	}
}

//関数の復習
int main(void)
{
	//function();


	int inputNum = 0;
	scanf_s("%d", &inputNum);
	//dispNumber(inputNum);
	//addNumber("inputNum = %d\n", inputNum);
	return 0;
}
*/