#include <stdio.h>
int main(void)
{
	int num1 = 8;      //����:�i���̒l���g����j
	float num2 = 1.5f;     //float:  �������g������
	char num3 = 'A';      //char:  �����i�P�����j����������

	//�L���X�g�̗�
	printf("(int)num2 = %d\n", (int)num2);

	printf("(float)num1 = %f\n", (float)num1);

	//int�^��float�^�̒l����

	printf("num1 = %.1f\n", num1 + num2);// num1 + num2��float

	int ans = num1 + num2;
	printf("ans = %d\n", ans);

	float ans2 = ans;
	printf("ans2 = %f\n", ans2);

	int num4 = 150;
	char num5 = 127;
	printf("num4 + num5 = %d\n", num4 + num5); //num4 + num5��

	return 0;
}