#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 3

//マクロを宣言しているだけ
//DEBUGというマクロがある、ということを利用する
#define DEBUG

int main(void)
{
	float sum = 0;
	int test[NUM];

	for (int i = 0; i < NUM; i++)
	{
		printf("%d番目の生徒の点数を入力してください\n", i + 1);
		scanf_s("%d", &test[i]);
	}


	for (int i = 0; i < NUM; i++)
	{
#ifdef DEBUG
		printf("%d番目の生徒は&d点です\n", i + 1, test[i]);
#endif
		sum += test[i];
	}

#ifndef DEBUG
	printf("DEBUGが定義されていません\n");
#endif 

	printf("%d人の平均点は%f点です\n", NUM, sum / 3);
	return 0;
}