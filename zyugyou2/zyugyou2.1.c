#include<stdio.h>
int main(void)
{
	int a = 79;

	if (a > 100)
		printf("変数は１００より大きい値です\n");
	else if (a > 50)
		printf("変数は５０より大きく、１００以下の値です\n");
	else if (a >= 0)
		printf("変数は０以上５０以下の値です\n");
	else
		printf("変数の値は%dです\n", a);

	printf("変数の値は%dです\n", a);

	return 0;

	/*
	int a = 5;

	if (a % 2 == 0)
		printf("%dは偶数です\n", a);
	else
		printf("%dは奇数です\n", a);

	
	//鍵を持っている数
	int keyNum = 0;
	//キャラクターのレベル
	int level = 10;

	//鍵を１つ以上持っていたら開く
	if (keyNum >= 1)
		printf("開く");

	else
		printf("開かない");

	//鍵を１つ以上持っていて、プレイヤーのレベルが５０以上なら開く
	//同時に条件を満たす必要がある
	//keyNum >= 1がtrue,level >=50がともにtrueの場合trueになる
	if (keyNum >= 1 && level >= 50)
		printf("開く\n");

	//|| : 論理和　or演算
	//鍵を１つ以上持っていたら開く
	//プレイヤーのレベルが５０以上なら力ずくで開く
	//どちらかの条件を満たせばok
	//keyNum >= 1がtrue,level >= 50のどちらかがtrueの場合になる
	if (keyNum >= 1 || level >= 50)
		printf("開く");

	//! :論理否定　not演算
	//!条件　　　条件がtrueの場合false,条件がfalseの場合trueになる
	//持っている鍵の数が０よりも少ないがfalseの場合開く
	if (!(keyNum <= 0))
		printf("開く");


	　　　　trueの場合
	int a = -1;

	if (a < 0)
		printf("aの値は負の数です\n");

	printf("aの値は%dです\n", a);
	

	//        falseの場合
	int a = 1;

	//if(条件文）    ※if(条件文）には;はいらない
	//文;
	
	if (a < 0)
		printf("aの値は負の数です\n");

	printf("aの値は%dです\n", a);

	*/


}