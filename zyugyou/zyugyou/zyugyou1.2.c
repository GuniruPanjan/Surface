#include<stdio.h>
int main(void)
{
	int a;
	int b;

	b = 5;
	
	a = ++b;

	//�����̗����a = b++�́@(a = b)++�Ə��������
	//�����̗����a = ++b�́@(a = ++b)�Ə��������
	printf("a�̒l��%d�ł�\n", a);
	printf("b�̒l��%d�ł�\n", b);

	return 0;
}