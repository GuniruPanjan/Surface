#include<stdio.h>






/*����*/
//�����Ƃ��ēn���ꂽx�̒l��
//����ɂP�𑫂����l��\�����邽�߂̊֐�
void f(int x)
{
	printf("�n���ꂽ�ϐ��̒l��%d�ł�\n", x);
	x = x + 1;
	printf("1�𑫂����l��%d�ɂȂ�܂�\n", x);
	return;
}
int main(void)
{
	int num = 16;
	f(num);

	//���݂����ȗ���̏������s���Ă���
	//{
	//	int x = num;
	//	printf("�n���ꂽ�ϐ��̒l��%d�ł�\n", x);
	//	x++;
	//	printf("1�𑫂����l��%d�ɂȂ�܂�\n", x);
	//}

	printf("num = %d\n", num);

	return 0;
}






/*dispPrintf�֐�
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
*/