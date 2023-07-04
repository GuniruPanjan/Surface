#include<stdio.h>

int main(void)
{
	int num = 3;
	if (num % 2 == 0)
	{
		printf("%dは偶数です\n", num);
	}
	else
	{
		printf("%dは奇数です\n", num);
	}

	//条件の書き方
	int hp = 100;
	if (hp == 100)
	{      //hpと100がまったく同じ、を判定する
		printf("HPがピッタリ%d\n", hp);
	}
	if (hp != 100)   //hpが100ではない、を判定する
	{
		printf("HPが100ではない\n");
	}
	//HPが20以下ならピンチ
	if (hp <= 20)
	{     //20よりも小さい場合は(hp <20)
		printf("ピンチ\n");
	}
	//Hp80以上なら
	if (hp >= 80)
	{    //80よりも大きい場合は(hp > 80)
		printf("余裕\n");
	}

	//複数の条件を同時に判定する
	int mp = 50;
	//HPが50以上、MPが50以上両方を満たす
	if (hp >= 50 && mp >= 50)
	{
		printf("HP,MP両方50以上\n");
	}
	//HPが50以上、MPが50以上どちらかを満たす
	if (hp >= 50 || mp >= 50)
	{
		printf("HP,MPどちらか50以上\n");
	}
	//HPが50以上、ではない
	if (!(hp >= 50))
	{
		printf("HPが50以上ではない\n");
	}

	//if文のネスト
	//HPが50以上、MPが50以上両方を書き換える
	if (hp >= 50)
	{

	}

	//else if文
	if (hp >= 50)
	{
		printf("HPが50以上ではない\n");
	}
	else if (hp >= 25)
	{
		printf("HPが25以上\n");
	}
	else if (hp >= 10)
	{
		printf("HPが10以上\n");
	}
	else if (hp >= 5)
	{
		printf("HPが5以上\n");
	}
	else
	{
		printf("HPが5未満\n");
	}

	return 0;
}


/*
int main(void)
{
	// +:足し算
	// -:引き算
	// *:掛け算
	// /:割り算
	// %:割った余り
	printf("10+5 = %d\n", 10 + 5);
	//変数に対しても演算できる
	int num = 20;
	int num2 = 7;
	printf("%d + %d = %d\n", num, num2, num + num2);
	printf("%d - %d = %d\n", num, num2, num - num2);
	printf("%d * %d = %d\n", num, num2, num * num2);
	printf("%d / %d = %d\n", num, num2, num / num2);
	//printfで文字の%を表示したい場合は%%とする
	printf("%d % %d = %d\n", num, num2, num % num2);    

	//複合代入演算子
	int hp = 10;
	//ダメージを受けたのでHPを減らしたい
	hp -= 7;
	//回復したのでＨＰを増やしたい
	hp += 7;

	//1増やしたい、減らしたい場合の特殊な書き方
	hp++;   //hp += 1;と同じ
	++hp;   //hp++と同じ

	hp--;   //hp -= 1;と同じ

	return 0;
}
*/




/*
int main(void)
{
	// printfを使用して文字列を表示
	//\nは改行を表す
	printf("ゴールデンウィーク以来だね\n");

	//変数は　型名　変数名;　で宣言される
	int numInt = 10;               //int型　整数を扱う
	float numFloat = 1.23f;        //float型　少数を扱う
	                               //1.23fのfはfloatの少数であることを表す
	                               //1.23だけだとdoubleと認識される
	char numChar = 'B';            //char型文字を１文字扱う
	                               //半角１文字　　　　全角は不可
								   // 
	//変数名は半角英数と'_'を使用して名前をつける
	//iat 1num = 10;  //ng 変数名の先頭が数字
	//float num*float = 10.0;  //ng 使えない記号が入っている

	// = で代入を行う
	int test = 10;
	printf("test = %d\n", test);  //%dで整数を表示
	test = 50;
	printf("test = %d\n", test);

	printf("%d, %f, %c\n", numInt, numFloat, numChar);
	//代入する値は変数を指定できる
	test = numInt;          //int型にint型を代入
	printf("test = %d\n", test);
	test = numFloat;        //int型にfloat型をで代入
	printf("test = %d\n", test);    //少数点以下がなくなる


	return 0;   //main{}の終了



}
*/