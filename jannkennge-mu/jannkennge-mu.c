#include<stdio.h>
#include<stdlib.h>     //rand,srand���g���̂ɕK�v
#include<time.h>       //time���g���̂ɕK�v

int main(int argc, void** argv)
{
	int hand;      //����񂯂�ŏo���Z�ϐ�
	int wincount = 0;  //�������񐔂𐔂���ϐ�
	int losecount = 0;   //�������񐔂𐔂���ϐ�
	int num = 0;     //�v���C���[�ɏ����̉񐔂�ς�������ϐ�

	printf("�����񐔂���͂��Ă�������\n");
	scanf_s("%d", &num);
	{
		printf("����񂯂�%d�񏟕��I\n", num);
	}
	printf("�O�[�F�O�@�p�[�F�P�@�`���L�F�Q\n");
	for (int a = 0; a < num; a++)   //������
	{


		scanf_s("%d", &hand);       //�v���C���[���̂���񂯂�

		if (hand == 0)
		{
			printf("���Ȃ��̓O�[���o���܂���\n");
		}
		else if (hand == 1)
		{
			printf("���Ȃ��̓p�[���o���܂���\n");
		}
		else if (hand == 2)
		{
			printf("���Ȃ��̓`���L�������܂���\n");
		}
		else
		{
			printf("���Ȃ��͏�����������܂���\n");
		}

		srand((unsigned int)time(NULL));          //�R���s���[�^�[���̂���񂯂�

		int randNum = 0;            
		for (int i = 0; i < 1; i++)
		{
			randNum = rand();

			if (randNum % 3 == 0)
			{
				printf("����̓O�[���o���Ă����I\n");
			}
			else if (randNum % 3 == 1)
			{
				printf("����̓p�[���o���Ă����I\n");
			}
			else if (randNum % 3 == 2)
			{
				printf("����̓`���L���o���Ă����I\n");
			}
		}

		           //��������

		

		if (hand == 0 && randNum % 3 == 2)
		{
			printf("���Ȃ��̏����I\n");
			wincount += 1;
		}
		else if (hand == 0 && randNum % 3 == 1)
		{
			printf("���Ȃ��̕���\n");
			losecount += 1;
		}
		else if (hand == 0 && randNum % 3 == 0)
		{
			printf("������\n");
			a -= 1;
		}
		else if (hand == 1 && randNum % 3 == 0)
		{
			printf("���Ȃ��̏����I\n");
			wincount += 1;
		}
		else if (hand == 1 && randNum % 3 == 2)
		{
			printf("���Ȃ��̕���\n");
			losecount += 1;
		}
		else if (hand == 1 && randNum % 3 == 1)
		{
			printf("������\n");
			a -= 1;
		}
		else if (hand == 2 && randNum % 3 == 1)
		{
			printf("���Ȃ��̏����I\n");
			wincount += 1;
		}
		else if (hand == 2 && randNum % 3 == 0)
		{
			printf("���Ȃ��̕���\n");
			losecount += 1;
		}
		else if (hand == 2 && randNum % 3 == 2)
		{
			printf("������\n");
			a -= 1;
		}
		else
		{
			printf("0, 1, 2,��ł��₪��[�I�I\n���Ȃ��̕���\n");
			losecount += 1;

		}

		if (wincount >= num / 2 + 1)      //���������ꍇ
		{
			printf("���Ȃ��̏����ł��I\n");
			break;
		}

		if (losecount >= num / 2 + 1)       //�s�k�����ꍇ
		{
			printf("���Ȃ��̕����ł�\nbite the dust!\n");
			break;
		}
		
	}

		



	
	
}


/*
//�����_���Ȑ��l�̐���
int main(void)
{

	//rand()�g�p����
	srand((unsigned int)time(NULL));   //0�b�Ɏ��s�����Ƃ���1�b�Ɏ��s�����Ƃ��ňႤ�T�C�R�����g��(�v���O�����̍ŏ��ɏ�������)


	int randNum = 0;  //�����_���ɐ������ꂽ���l��ۑ����邽�߂̕ϐ�

	for (int i = 0; i < 8; i++)
	{
	     randNum = rand();  //rand()�֐��̖߂�l��randNum�ɑ������
	//rand()�֐���0�`(65536/2)����Ȃ���0�`2�̒l���ق����Ȃ�%���Z�q�Ŋ���Z�̗]����o��
	     printf("�����_���Ȑ����F%d�@-> %d\n", randNum, randNum % 3);

	}

	//rand()�֐��̃C���[�W�̓T�C�R����U���ďo��ڂ̏��Ԃ����܂��Ă���֐�
	//srand()�֐��Ŏg�p����T�C�R���̔ԍ�


}
*/





/*
//scanf_s���g�p���ăL�[�{�[�h���琔�l����͂���
int main(void)
{

	//printf�������\�����邽�߂̊֐�
	printf("�������\������");

	//scanf_s�̓L�[�{�[�h����̓��͂��󂯂���邽�߂̊֐�
	int inputNum = 0;  //�v���C���[�����͂���������ۑ����邽�߂̕ϐ�
	scanf_s("%d", &inputNum);  //�L�[�{�[�h���琮���̓��͂��󂯂�t����

	printf("���͂��������F%d\n", inputNum);

	return 0;
}
*/