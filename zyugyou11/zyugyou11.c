#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*�Z�~�Q�[���̍쐬*/
int main(void)
{
	int i;
	int player;
	int enemy;
	int MB;
	int a[3] = { 0, 1, 2 };
	int b[3] = { 3, 4, 5 };
	int c[3] = { 6, 7, 8 };

	printf("�Z�~�Q�[��\n�����̏ꏊ�ɓ���������ł�����\n�v���C���[�́F�Z\n�R���s���[�^�[�́F�~\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d , ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d , ", b[i]);
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d , ", c[i]);
	}
	printf("\n");

	int field[5][5] =
	{
		{3,3,3,3,3},
		{3,0,0,0,3},
		{3,0,0,0,3},
		{3,0,0,0,3},
		{3,3,3,3,3},
	};
	for (int j = 0; j < 5; j++)
	{
		for (int h = 0; h < 5; h++)
		{
			switch (field[5][5])
			{
			    case 0: printf("�@");     break;
				case 3: printf("��");    break;
			}
		}
		printf("\n");
	}

	scanf_s("%d", &player);




}


/*���K���
int main(void)
{
	int i;
	int tmp;       //�ꎞ�I�Ƀf�[�^��ۑ�����itmp)
	int a[5] = { 0, 1, 2, 3, 4 };
	int b[5] = { 5, 6, 7, 8, 9 };

	for (i = 0; i < 5; i++)
	{
		tmp = a[i];

		a[i] = b[i];

		b[i] = tmp;
	}





	//a[]�̒��g��\������@5,6,7,8,9���\��������OK
	for (i = 0; i < 5; i++)
	{
		printf("a[%d]�̒l��%d�ł�\n", i, a[i]);
	}

	//b[]�̒��g��\������@0,1,2,3,4���\��������OK
	for (i = 0; i < 5; i++)
	{
		printf("b[%d]�̒l��%d�ł�\n", i, b[i]);
	}
	return 0;
}
*/



/*
int main(void)
{
	//�ꎟ���z��̐錾
	//int tbl[4] = {0, 1, 2, 3};

	//�񎟌��z��̐錾
//�^���@�z��[�v�f��][�v�f��]
	int tbl[3][4] = { {1, 2, 3, 4}, 
		              {5, 6, 7, 8}, 
		              {9, 10, 11, 12} };

	//tbl[0][0] = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
		printf("%d", tbl[i][j]);
		}
		printf("\n");

	}

	//2�����z������傫�Ȏ����̔z��i3�����A4�����j
	// �������K�v������ꍇ�̓v���O�����̐݌v�������\���������I
	// ��
	// �ȒP�Ɍ�����3�����ȏ�̔z��͏����Ȃ���������
	//int tbl[3][4][5][6][7];    //5�����z��̐錾

	return 0;
}
*/


/*
#include<stdio.h>
#include<stdlib.h>       //rand()���g���̂ɕK�v
#include<time.h>

//�G�̐���萔�Ƃ��Ē�`
#define ENEMY_NUM 10

//�G��HP�̍ŏ��l�A�ő�l���}�N���Œ�`���A
//���͈̔͂�HP�����������悤�Ƀv���O�����Œ�`���A
#define ENEMY_HP_MIN    50
#define ENEMY_HP_MAX    100

//�萔���g�p���Ē萔���`����
#define ENEMY_HP_RAND_RANGE (ENEMY_HP_MAX - ENEMY_HP_MIN + 1)

#define ENEMY_HP_RAND_RANGE 51

//�\�[�X���p�b�ƌ��Ă���������Ă��邩�킩��Â炩�����̂ł��������̊֐��������Ă����ƕ�����₷��
int createRandomHp()
{
	return ENEMY_HP_MIN + rand() % ENEMY_HP_RAND_RANGE;
	//return ENEMY_HP_MIN + rand() % (ENEMY_HP_MAX - ENEMY_HP_MIN + 1)
}

//�z��Afor���ł̔z��̗��p�A
//#define�}�N���𗘗p�����z��T�C�Y�̎w��ɂ��Ă����炢
int main(void)
{
	//�G�����̂�HP�������_���ɐ������ĕ\������
	srand((unsigned int)time(NULL));

	//�z��ŕ����̕���HP�p�ϐ�����������
	int enemyHp[ENEMY_NUM];

	//�����_����HP��ݒ肷��
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//HP��50�`100
		//50�`100�̃����_���͈̔͂́H
		//0�`2�͈̔͂𐶐��A�͈ȑO�����������Q�l��
		//enemyHp[i] = 50;        //50�ŌŒ�
		//enemyHp[i] = rand() % 101;    //0�`100�͈̔�
		enemyHp[i] = 50 + rand() % 51;    //50 + (0�`50)
	}

	//�ݒ肵��HP��\������
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d�̖ځF%d\n", i + 1, enemyHp[i]);
	}
}
*/