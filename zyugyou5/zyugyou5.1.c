#include<stdio.h>


//���K
int main(void)
{
	int answer = 0;

	//1�`100�܂ł̊Ԃɑ��݂���7�̔{���̍��v���v�Z����
	//answer = 7 + 14 + 21 + 28 + 35
	//2�p�^�[�����炢���@���l����

	//7�̔{���ȊO���͂���
	int sum = 0;
	int a;

	for (a = 0; a <= 100; a++)
	{
		if (a % 7 != 0)continue;
		sum += a;
	}
	printf("���v��%d�ł�\n", sum);

	return 0;





	

}


/*
int main(void)
{
	int hp = 50;

	int damage = 8;

	//�v���C���[�̖h��͂��`�F�b�N���ă_���[�W���炷
	damage -= 100;

	while (hp > 0)
	{
		hp -= damage;

		printf("�c��HP:%d\n", hp);

		break;
	}


	//�������[�v
	while (1)        //while(1)�Ŗ������[�v
	{
		//�������`�F�b�N���Ė������[�v�𔲂���
		if (1) {
			break;
		}
	}

}
*/
/*
//continue��
int main(void)
{
	//1����10�܂ł̑����Z��3�̔{�����������v�Z
	int sum = 0;
	int a;

	for (a = 0; a <= 10; a++)
	{
		printf("�������Ƃ��Ă��鐔 %d\n", a + 1);

		//3�̔{���𑫂����Ƃ����Ƃ��͂�����s��Ȃ�
		if (a % 3 == 0)continue;
		sum += a;
	}
	printf("���v��%d�ł�\n", sum);

	return 0;


	int answer = 1;
	//int answer = 0; //���[�v�񐔂𐔂���

	//1����10�܂ł̐��𑫂��Z���āA�������o�͂���

	//�����Z���P�O��s��
	for (int i = 1; i < 10; i++)
	{
		printf("���[�v��%d\n", i);

		//�����Z���s��
		answer += i + 1;
	}
		printf("answer = %d\n", answer);





	
	//while���o�[�W����
		answer = 0;
		int addNum = 1; //������
		while (addNum <= 10)
	{
			answer += addNum;
			addNum++;
		
	}
		printf("answer = %d\n", answer);

	
}
*/


/* for���̕��K
int main(void)
{
	//break���̕��K
	int inputNum = 8;  //�v���C���[�����͂�������
	int count = 1;     //�\�����鐔��
	while (1)
	{
		printf("����:%d\n", count);
		//�v���C���[�����͂����������\�����ꂽ��I��
		if (count == inputNum)
		{
			break;
		}
		//100�܂ŕ\�����ꂽ��I��
		if (count >= 100)
		{
			break;
		}

		count++;

	}


	//while�������ł͂Ȃ�fot���������I���ł���
	for (int i = 0; i < 100; i++)
	{
		int dispNum = count + 1;
		printf("number:%d\n", dispNum);

		//�v���C���[�����͂����������\�����ꂽ��I��
		if (count == inputNum)
		{
			break;
		}
	}



	//do-while���̕��K
	do {
		printf("do-while���͕K����x�͎��s���܂�\n\n");
	} while (2 < 1);

	while (2 < 1)
	{
		printf("while���͍ŏ���������𖞂����ĂȂ��ꍇ�A��x�����s����܂���\n\n");
	}




	//�����𖞂����܂œ����������J��Ԃ��@�@while��
	int hp = 50;
	while (hp > 0)   //�����͏I�������ł͂Ȃ��p������
	{
		printf("�_���[�W���󂯂��I\n");
		hp -= 5;
		printf("�c��HP:%d\n", hp);

	}
	printf("The End���Ăˁ�\n\n");

	//���while����for���ŏ���������
	for (int hp2 = 50; hp2 > 0;)
	{
		printf("�_���[�W���󂯂��I\n");
		hp2 -= 8;
		printf("�c��HP:%d\n", hp);

	}
	printf("The End���Ăˁ�\n\n");


	//int i = 0; //���[�v�񐔂𐔂���

	//�w�肵���񐔓����������J��Ԃ��@for��
	for (int i = 0; i < 16; i++)
	{
		printf("%d��ڂ̃��[�v\n", i + 1);
		//�����v�Z�����鏈�����܂Ƃ߂Ă���
		int dispNum = (i + 1);

		if (dispNum % 2 == 0)
		{
			printf("%d�͋���\n", dispNum );
		}
		else
		{
			printf("%d�͊\n", dispNum );
		}

	}
	return 0;
}
*/