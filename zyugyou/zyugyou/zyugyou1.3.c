#include <stdio.h>
int main(void)
{
	int num1 = 8;      //整数:（負の値も使える）
	float num2 = 1.5f;     //float:  少数を使いたい
	char num3 = 'A';      //char:  文字（１文字）を扱いたい

	//キャストの例
	printf("(int)num2 = %d\n", (int)num2);

	printf("(float)num1 = %f\n", (float)num1);

	//int型にfloat型の値を代入

	printf("num1 = %.1f\n", num1 + num2);// num1 + num2はfloat

	int ans = num1 + num2;
	printf("ans = %d\n", ans);

	float ans2 = ans;
	printf("ans2 = %f\n", ans2);

	int num4 = 150;
	char num5 = 127;
	printf("num4 + num5 = %d\n", num4 + num5); //num4 + num5は

	return 0;
}