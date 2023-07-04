#include<stdio.h>
int main(void)
{
	int a;
	int b;

	b = 5;
	
	a = ++b;

	//処理の流れはa = b++は　(a = b)++と処理される
	//処理の流れはa = ++bは　(a = ++b)と処理される
	printf("aの値は%dです\n", a);
	printf("bの値は%dです\n", b);

	return 0;
}