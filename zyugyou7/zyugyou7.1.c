#include<stdio.h>






/*引数*/
//引数として渡されたxの値と
//それに１を足した値を表示するための関数
void f(int x)
{
	printf("渡された変数の値は%dです\n", x);
	x = x + 1;
	printf("1を足した値は%dになります\n", x);
	return;
}
int main(void)
{
	int num = 16;
	f(num);

	//↓みたいな流れの処理が行われている
	//{
	//	int x = num;
	//	printf("渡された変数の値は%dです\n", x);
	//	x++;
	//	printf("1を足した値は%dになります\n", x);
	//}

	printf("num = %d\n", num);

	return 0;
}






/*dispPrintf関数
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
*/