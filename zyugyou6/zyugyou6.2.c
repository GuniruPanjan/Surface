#include<stdio.h>



//"�֐������s����܂���\n"�ƕ\�����邽�߂̊֐�
void dispPrintf(void)
{
	printf("�֐������s����܂���\n");


	return;
}

int main(void)
{
	printf("�v���O�������J�n����܂���\n");
	dispPrintf();
	printf("�v���O�������I�����܂�\n");
	return 0;
}


/*
//GW�̉ۑ�
int main(void)
{
	int num;
	int sum = 0;

	for (int num = 1; num < 10; num++) {
		sum += num;
	}
	printf("1�`9�܂ł̍��v��%d�ł�\n", sum);

	return 0;
}
*/