#include<stdio.h>

//2�̒lx,y(int �ȉ����ׂĂ����j��n���Ă��̍��v��Ԃ��֐�
int add(int x, int y)
{
	int a = x + y;
	return a;
}

//2�̒lx,y��n���Ă��̍���Ԃ��֐��i�P���Ȉ����Z��OK�j
int sub(int x, int y)
{
	int b = x - y;
	return b;
}

//2�̒lx,y��n���Ă��̏�Z���ʂ�Ԃ��֐�
int mul(int x, int y)
{
	int c = x * y;
	return c;
}

//2�̒lx,y��n����x��y���Ԃ��֐�
int pow(int x, int y)
{
	int d = 1;
	for (int i = 0; i < y; i++)
	{
		d *= x;
	}

		return d;
}




int main(void)
{
	

	int x = 4;
	int y = 3;

	int result = add(4, 3); //�����add�֐����Ăяo��
	printf("add = %d\n", result);

	result = sub(4, 3);   //�����sub�֐����Ăяo��
	printf("sub = %d\n", result);

	result = mul(4, 3);   //�����mul�֐����Ăяo��
	printf("mul = %d\n", result);

	result = pow(4, 3);   //�����pow�֐����Ăяo��
	printf("pow = %d\n", result);

}

/*int total(int x, int y)
{
	int z = x + y;  //���v�l���v�Z����
	return z;
}

//�߂�l�̕׋�
int main(void)
{
	int a = total(1, 3);
	printf("���v��%d�ł�\n", a);
	return 0;
}
*/
/*2�̒l�̂����A�ǂ��炪�傫�������r����֐�
void bigger(int x, int y, float z)
{
	printf("z = %f\n", z);
	printf("2�̈����̂����A�傫���ق���\������\n");
	if (x > y)
	{
		printf("%d�̂ق����傫���ł�\n", x);
	}
	else
	{
		printf("%d�̂ق����傫���ł�\n", y);
	}
	return;
}


int main(void)
{
	bigger(1, 5, 3.14f);
	return 0;
}
*/
/*�֐�������
//1.����������������Ă���ꏊ����������ꍇ
//��.�Q�[���̏ꍇ�_���[�W�����Ȃ�
//�_���[�W����->HP�����炵�āA��ʂ�h�炵�āA�v���C���[���Ԃ��_�ł���
//�������������㏑���������ȁA�Ǝv������֐���

//2.�p�b�ƌ��ĉ�������Ă��邩������Ȃ�����
// �\�[�X�����Ă�������Ȃ������ɕ�����₷���֐��������Ă��
//float angle = acos (cross(dir, toEnemy));
//printf("angle = %f\n",angle);
//��
//void calcAngle(void) //�֐�����������p�x���v�Z���鏈�����ȁA�ƕ�����
//{
// float angle = acos(cross(dir, toEnemy));
// printf("angle = %f\n", angle);
//}

void function(void)
{
	printf("�����I");


	return;
}

//��������̊֐�
//�����ɉ������������s�����Ƃ��ł���
void dispNumber(int num)
{
	printf("num = %d\n", num);
	return 0;
}

//�֐��̒��œn���ꂽ����ύX����
void addNumber(int num)
{
	printf("num = %d\n", num);
	num += 10;
	printf("num + 10 = %d\n", num);
	return;
}

//�֐��̒���if,for,while�Ȃǎg����
//�����͕��ʂ̕ϐ��̂悤�Ɉ�����
void forFuction(int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("test\n");
	}
}

//�֐��̕��K
int main(void)
{
	//function();


	int inputNum = 0;
	scanf_s("%d", &inputNum);
	//dispNumber(inputNum);
	//addNumber("inputNum = %d\n", inputNum);
	return 0;
}
*/