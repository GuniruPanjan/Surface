#include<stdio.h>

int main(void)
{
	//�|�P�����̃R���v���[�g�����v�Z������
	//�|�P�����̐���151���

	//�S�����@����
	//100%    1.0
	//50%     0.5
	//25%     0.25

	//���ݓo�^����Ă���|�P�����̐�
	int pokeNum = 120;
	float rate = 0.0f;
	//�R���v���[�g���̌v�Z
	rate = (float)pokeNum / 151;  //�قȂ�^���m�Ōv�Z���s���ۂɂ́A�L���X�g��p����

	printf("�R���v���[�g���@���@%f %%\n", rate * 100.0f);

	int a = 10 + 20;
	int b = 10 + 20 + 30;
	int c = b = a;



	return 0;
	/*
	//�����^�iint)�ɏ���������Ə����_�ȉ���������
	float numFloat = 1.999999f;
	int numInt = numFloat;
	printf("numInt = %d\n", numInt);


	//float�ɐ����̒l������
	numInt = 256;
	numFloat = numInt;
	printf("numFloat = %f\n", numFloat);

	//���������_�͌덷����������
	float floatTest = 0.0f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	floatTest = 0.1f;
	printf("floatTest = %f\n", floatTest);
	printf("floatTest = %1.16f\n", floatTest);



	//�ϐ�
	int hp = 100;

	hp = hp - 10;
	hp = hp + 5;

	hp -= 10;  //hp = hp - 10�Ɠ���

	hp--;  //�f�N�������g�@�ϐ��̒l���P���炵�Ă��̕ϐ��̒l�ɑ��
	hp++;  //�C���N�������g�@�ϐ��̒l���P���₵�Ă��̕ϐ��̒l�ɑ��

	++hp;
	--hp;

	hp = 10;
	int a = hp;
	hp++;
	printf("a = %d, hp = %d\n", a, hp);

	hp = 10;
	++hp;
	int b = hp;
	printf("b = %d, hp = %d\n", b, hp);

	int test = 10 + 10 * 3;
	printf("test = %d\n", test);

	test = (10 + 10) * 3;
	printf("test = %d\n", test);



	//�ϐ�
	int numInt = 10;     //����
	float numFloat = 1.2345f;   //����
	char numChar = 'z';    //����



	numInt = 10 + 10;  //���Z
	numInt = 10 - 10;  //���Z
	numInt = 10 * 10;  //��Z
	numInt = 10 / 10;  //���Z
	numInt = 10 % 10;  //�]�Z

	numInt = 53;

	printf("����Z�@%d/5=%d�]��@%d\n",
		numInt, numInt / 5, numInt % 5);



	printf("�������\������Ƃ���\nprintf("")\n");

	printf("������\������Ƃ��@%d\n", 10);

	printf("������\������Ƃ� %f\n", 1.234f);

	printf("�P������\������Ƃ��@%c\n", '��');

	printf("�����@%c\t �����@%d\t �����@%f\n", 'a', 64, 3.14f);
	*/
}