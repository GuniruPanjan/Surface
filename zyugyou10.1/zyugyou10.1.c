#include<stdio.h>  //printf(),scanf_s()���̃v���g�^�C�v�錾��������Ă���
//#include<stdio.h>  //rand(),srand()���̃v���g�^�C�v�錾��������Ă���
#include"zyugyou10.h"



//���K���7-2
void showAverage(int val1, int val2)   //val:value�̗��@�@�l
{
	int i;
	float f;
	i = (val1 + val2);
	//�����Ōv�Z����Ə����_�ȉ����؂�̂Ă���
	//�L���X�g���g���ď����_�܂ŋ��߂�
	f = (float)i / 2.0f;          //���ς����߂�
	printf("1�ڂ̒l��%d�ł��B\n", val1);
	printf("2�ڂ̒l��%d�ł��B\n", val2);
	printf("2�̒l�̕��ϒl�́A%f�ł��B\n", f);
}

//���K���V�|�P
void transSeconds(int sec)
{
	int aHour, aMin, aSec;

	aHour = sec / (60 * 60);  //���Ԃ����߂�
	aMin = (sec % (60 * 60)) / (aHour * 60);   //�������߂�
	aSec = (sec % (60 * 60)) % (aHour * 60);    //�b�����߂�

	printf("%d�b�́A%d����%d��%d�b�ł�\n", sec, aHour, aMin, aSec);

	return;
}

int main(void)
{
	int timeSec = 5000;

	transSeconds(timeSec);  //�����Ƃ��ĕb����n���i���̗�ł�5000�b�j

	return 0;
}










/*
void f(void)
{
	static int num = 0;
	num++;
	printf("f�֐����Ă΂ꂽ�̂�%d��ڂł�\n", num);
}







int main(void)
{
	f();
	f();
	f();
	f();

	return 0;
}
*/

/*
//�ϐ��̒l�ɑ����Z������
void add(int baseNum, int addNum)
{

	return (baseNum + addNum);
}

int main(void)
{
	int num = 0;

	printf("num = %d\n", num);

	 add(num, 5);

	printf("num = %d\n", num);

	return 0;
}
*/


/*
int a = 1;

void f(void)
{
	int a = 1;
	printf("�֐��̒��̕ϐ�a�̒l��%d�ł�\n", a);
	return;
}

int main(void)
{
	int a = 2;
	printf("main�֐��̒��̕ϐ��̒l��%d�ł�\n", a);
	f();
	return 0;
}
*/

/*�O���[�o���ϐ��ƃ��[�J���ϐ�
int a = 1;          //�O���[�o���ϐ�

void f(void)
{
	int b;        //���[�J���ϐ�
//  printf("�֐�f�̒���a�̒l��%d�ł�\n", a);
	printf("�֐�f�̒���a�̒l��%d�ł�\n", b);
	return;
}



int main(void)
{
	int c;
	printf("main�֐��̒���a�̒l��%d�ł�\n", a);
	f();

	for (int i = 0; i < 5; i++)
	{
		printf("i = %d\n", i);
	}
	return 0;       //���[�J���ϐ�
}
*/