#include<stdio.h>



//"関数が実行されました\n"と表示するための関数
void dispPrintf(void)
{
	printf("関数が実行されました\n");


	return;
}

int main(void)
{
	printf("プログラムが開始されました\n");
	dispPrintf();
	printf("プログラムを終了します\n");
	return 0;
}


/*
//GWの課題
int main(void)
{
	int num;
	int sum = 0;

	for (int num = 1; num < 10; num++) {
		sum += num;
	}
	printf("1～9までの合計は%dです\n", sum);

	return 0;
}
*/