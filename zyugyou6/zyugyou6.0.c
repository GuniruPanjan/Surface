#include<stdio.h>

int main(void)
{
	int num = 3;
	if (num % 2 == 0)
	{
		printf("%d�͋����ł�\n", num);
	}
	else
	{
		printf("%d�͊�ł�\n", num);
	}

	//�����̏�����
	int hp = 100;
	if (hp == 100)
	{      //hp��100���܂����������A�𔻒肷��
		printf("HP���s�b�^��%d\n", hp);
	}
	if (hp != 100)   //hp��100�ł͂Ȃ��A�𔻒肷��
	{
		printf("HP��100�ł͂Ȃ�\n");
	}
	//HP��20�ȉ��Ȃ�s���`
	if (hp <= 20)
	{     //20�����������ꍇ��(hp <20)
		printf("�s���`\n");
	}
	//Hp80�ȏ�Ȃ�
	if (hp >= 80)
	{    //80�����傫���ꍇ��(hp > 80)
		printf("�]�T\n");
	}

	//�����̏����𓯎��ɔ��肷��
	int mp = 50;
	//HP��50�ȏ�AMP��50�ȏ㗼���𖞂���
	if (hp >= 50 && mp >= 50)
	{
		printf("HP,MP����50�ȏ�\n");
	}
	//HP��50�ȏ�AMP��50�ȏ�ǂ��炩�𖞂���
	if (hp >= 50 || mp >= 50)
	{
		printf("HP,MP�ǂ��炩50�ȏ�\n");
	}
	//HP��50�ȏ�A�ł͂Ȃ�
	if (!(hp >= 50))
	{
		printf("HP��50�ȏ�ł͂Ȃ�\n");
	}

	//if���̃l�X�g
	//HP��50�ȏ�AMP��50�ȏ㗼��������������
	if (hp >= 50)
	{

	}

	//else if��
	if (hp >= 50)
	{
		printf("HP��50�ȏ�ł͂Ȃ�\n");
	}
	else if (hp >= 25)
	{
		printf("HP��25�ȏ�\n");
	}
	else if (hp >= 10)
	{
		printf("HP��10�ȏ�\n");
	}
	else if (hp >= 5)
	{
		printf("HP��5�ȏ�\n");
	}
	else
	{
		printf("HP��5����\n");
	}

	return 0;
}


/*
int main(void)
{
	// +:�����Z
	// -:�����Z
	// *:�|���Z
	// /:����Z
	// %:�������]��
	printf("10+5 = %d\n", 10 + 5);
	//�ϐ��ɑ΂��Ă����Z�ł���
	int num = 20;
	int num2 = 7;
	printf("%d + %d = %d\n", num, num2, num + num2);
	printf("%d - %d = %d\n", num, num2, num - num2);
	printf("%d * %d = %d\n", num, num2, num * num2);
	printf("%d / %d = %d\n", num, num2, num / num2);
	//printf�ŕ�����%��\���������ꍇ��%%�Ƃ���
	printf("%d % %d = %d\n", num, num2, num % num2);    

	//����������Z�q
	int hp = 10;
	//�_���[�W���󂯂��̂�HP�����炵����
	hp -= 7;
	//�񕜂����̂łg�o�𑝂₵����
	hp += 7;

	//1���₵�����A���炵�����ꍇ�̓���ȏ�����
	hp++;   //hp += 1;�Ɠ���
	++hp;   //hp++�Ɠ���

	hp--;   //hp -= 1;�Ɠ���

	return 0;
}
*/




/*
int main(void)
{
	// printf���g�p���ĕ������\��
	//\n�͉��s��\��
	printf("�S�[���f���E�B�[�N�ȗ�����\n");

	//�ϐ��́@�^���@�ϐ���;�@�Ő錾�����
	int numInt = 10;               //int�^�@����������
	float numFloat = 1.23f;        //float�^�@����������
	                               //1.23f��f��float�̏����ł��邱�Ƃ�\��
	                               //1.23��������double�ƔF�������
	char numChar = 'B';            //char�^�������P��������
	                               //���p�P�����@�@�@�@�S�p�͕s��
								   // 
	//�ϐ����͔��p�p����'_'���g�p���Ė��O������
	//iat 1num = 10;  //ng �ϐ����̐擪������
	//float num*float = 10.0;  //ng �g���Ȃ��L���������Ă���

	// = �ő�����s��
	int test = 10;
	printf("test = %d\n", test);  //%d�Ő�����\��
	test = 50;
	printf("test = %d\n", test);

	printf("%d, %f, %c\n", numInt, numFloat, numChar);
	//�������l�͕ϐ����w��ł���
	test = numInt;          //int�^��int�^����
	printf("test = %d\n", test);
	test = numFloat;        //int�^��float�^���ő��
	printf("test = %d\n", test);    //�����_�ȉ����Ȃ��Ȃ�


	return 0;   //main{}�̏I��



}
*/