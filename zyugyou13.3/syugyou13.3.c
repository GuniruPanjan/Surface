#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 3

//�}�N����錾���Ă��邾��
//DEBUG�Ƃ����}�N��������A�Ƃ������Ƃ𗘗p����
#define DEBUG

int main(void)
{
	float sum = 0;
	int test[NUM];

	for (int i = 0; i < NUM; i++)
	{
		printf("%d�Ԗڂ̐��k�̓_������͂��Ă�������\n", i + 1);
		scanf_s("%d", &test[i]);
	}


	for (int i = 0; i < NUM; i++)
	{
#ifdef DEBUG
		printf("%d�Ԗڂ̐��k��&d�_�ł�\n", i + 1, test[i]);
#endif
		sum += test[i];
	}

#ifndef DEBUG
	printf("DEBUG����`����Ă��܂���\n");
#endif 

	printf("%d�l�̕��ϓ_��%f�_�ł�\n", NUM, sum / 3);
	return 0;
}