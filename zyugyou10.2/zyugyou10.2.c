#include<stdio.h>
#include<stdlib.h>  //rand()���g���̂ɕK�v
#include<time.h>

//�G�̐���萔�Ƃ��Ē�`
#define ENEMY_NUM 5

//�G��HP�̍ő�l�A�ŏ��l���}�N���Œ�`���A
// ���͈̔͂�HP�����������悤�Ƀv���O���������������Ă�������

//�z��Afor���ł̔z��̗��p�A
//#define�}�N���𗘗p�����z��T�C�Y�̎w��ɂ��Ă����炢
int main(void)
{
	//�����̂̓G��HP�������_���ɐ������ĕ\������
	srand((unsigned int)time(NULL));

	int enemyHP[ENEMY_NUM];
	int g;

	//�����_����HP��ݒ肷��
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//HP��50�ȏ�100�ȉ�
		enemyHP[i] = rand();
		g = enemyHP[i] % 130;

	}

	//�ݒ肵��HP��\������
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d�̖ځF%d\n", i + 1, g);
	}

	return 0;
}





/*


//define�}�N�����g�p����
//�v���v���Z�b�T���R���p�C���̑O�ɕ������u�������Ă����
//...�ƍ��͊o���Ă�����

//define�}�N���@��������̒u���������[�����w�肷�邱�Ƃ��ł���
//�w�肵������������Ɏw�肵�������ɕϊ�����

//������
//#define�u���������̕�����u��������̕�����
//�R���p�C������O��A��B�ɏ��������Ă����
#define ENEMY_NUM 5

//#define DEFAULT_HP50
//���̃}�N�����`�����ꍇ�A
//int playerHP = DEFAULT_HP;    ���������Ă�����...
//int PlayerHP = 50;      �R���p�C���O��DEFAULT_HP��50�ɒu�������Ă����

//����������#define�̈Ӗ������A
//���ۂɗ��p����Ƃ���
//�u�萔�v���`���鎞�ɂ悭���p����

//define�}�N���̒u�������O�̕������
//�E�S�đ啶��
//�E�P��ƒP��̊Ԃ�_�i�A���_�[�X�R�A�j�łȂ�
//�Ƃ������[���ɂȂ��Ă���̂���ʓI


//for���Ɣz��̑g�ݍ���
int main(void)
{
	//�G��HP�f�[�^���i�[���邽�߂̔z��
	int enemyHP[ENEMY_NUM];

	printf("�G��HP�̒l����͂��Ă�������\n");
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d�̖ڂ̓G��HP�͂����ł����H\n", i + 1);
		//�L�[�{�[�h����l����͂���
		scanf_s("%d", &enemyHP[i]);

	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d�̖ڂ̓G��HP��%d�ł�\n", i + 1, enemyHP[i]);
	}

	return 0;
}
*/



/*
//�z��̊e�v�f���Q�Ƃ���printf�ŕ\������
//for���𗘗p���Ĕz��̒��g���ȒP�ɋL�q����
int main(void)
{
	//�z���錾���ď��������Ēl������
	int enemyHP[5] = { 100, 200, 300 };

	//printf("��Ԗڂ̓G��HP��%d�ł�\n", enemyHP[0]);
	//printf("�j�Ԗڂ̓G��HP��%d�ł�\n", enemyHP[1]);
	//printf("�O�Ԗڂ̓G��HP��%d�ł�\n", enemyHP[2]);
	//printf("�l�Ԗڂ̓G��HP��%d�ł�\n", enemyHP[3]);
	//printf("�ܔԖڂ̓G��HP��%d�ł�\n", enemyHP[4]);

	//for����p�����`�ɏ��������遫

	//5�̕���HP��\���������̂�5��J��Ԃ��������s��
	for (int i = 0; i < 5; i++)
	{
		//i�̒l�ƏI�������ɒ��ڂ���
		//�I������i < 5     5�̕����z��̗v�f���Ɠ���
		// i�̒l
		//1�T��:    i = 0;
		//2�T��:    i = 1;
		//3�T��:    i = 2;
		//4�T��:    i = 3;
		//5�T��:    i = 4;

		printf("%d�Ԗڂ̓G��HP��%d�ł�\n", i + 1, enemyHP[i]);
	}
	//for���̒��Ŏ��ۂɉ����s���邩�ڂ������Ă݂�
	{
		int i = 0;  //���̏������������s����
		//////////////////////////////////
		// if(i < 5)�𖞂����Ă���ΌJ��Ԃ��������s����
		//i = 0�̏�ԂŌJ��Ԃ��������s����
		printf("%d�Ԗڂ̓G��HP��%d�ł�\n", i + 1, enemyHP[i]);

		//�J��Ԃ������̂��Ƃ̏������s��
		i++;  //i��0 + 1�Ȃ̂�1
		//////////////////////////////////
		// if(i < 5)�𖞂����Ă���ΌJ��Ԃ��������s����
		//i = 1�̏�ԂŌJ��Ԃ��������s����
		printf("%d�Ԗڂ̓G��HP��%d�ł�\n", i + 1, enemyHP[i]);

		//�J��Ԃ������̂��Ƃ̏������s��
		i++;  //i��1 + 1�Ȃ̂�2
		//////////////////////////////////

		//...����

		//�J��Ԃ������̂��Ƃ̏������s��
		i++;  //i��4 + 1�Ȃ̂�5
		//////////////////////////////////
		
	}


	//�ʏ�̕ϐ��i�z��ł͂Ȃ��ϐ��j�̏ꍇ
	int playerHP = 500;
	printf("�v���C���[��HP��%d�ł�\n", playerHP);

	return 0;
}
*/





/*
//�z���錾���Ă����ɒl������
//�z��̗v�f���w�肵�Ēl������
//�������q�𗘗p���ď������Ɠ����ɒl������
int main(void)
{
	//�G�L�����N�^�[100�̕���HP���Ǘ�������
	//�z����g��

	//�^���@�z��[�v�f��];
	int enemyhp[100] = [100, 120, 240];
	//enemyhp[0] = 100;
	//enemyhp[1] = 120;
	//enemyhp[2] = 240;
	//enemyhp[3];
	//enemyhp[4];

	//�z��̐錾�Ɠ����ɏ��������s���ꍇ�͗v�f���ȗ��ł���
	//�ȗ������ꍇ�͏������q�̐����̗v�f���p�ӂ����
	int enemyMP[] = [20, 0, 80];         //�������q3�Ȃ̂ŗv�f����3�ɂȂ�
	//int enemyAttack[];     �v�f�����w�肵�ĂȂ��̂ŃG���[
	
	//�z��̗v�f���Ə������q�̐����Ⴄ�ꍇ�̋���
	
	// ���ӂ̕����v�f���������ꍇ�@����5�ɑ΂��ĉE��3
	// enemyAttck[3],enemyAttack[4]�ɂ�0������
	int enemyAttck[5] = { 10, 20, 30 };

	//�E�ӂ̂ق����v�f���������ꍇ����2�ɑ΂��ĉE��3
	// �R���p���G���[�r���h���ʂ�Ȃ�
	// int enemySpeed[2] = {100, 200, 300};    �G���[
	
	//ng�� 1�̔z��ɑ����̎�ނ̃f�[�^�����Ȃ�
	// ���L��ł́AHP�A�U���́A�h��͂�1�̔z��ɓ���Ă���
	int enemyData[9];
	enemyData[0] = 100;     //��̖ڂ̓G��HP
	enemyData[1] = 200;     //��̖ڂ̓G��HP
	enemyData[2] = 300;     //�O�̖ڂ̓G��HP

	enemyData[3] = 10;      //��̖ڂ̓G�̍U����
	enemyData[4] = 20;      //�j�̖ڂ̓G�̍U����
	enemyData[5] = 30;

	enemyData[6] = 10;      //��̖ڂ̓G�̖h���
	enemyData[7] = 20;
	enemyData[8] = 30;
	//�ʏ�̕ϐ�
	int playerHP = 20;    //�錾�Ɠ����ɏ�����
	playerHP = 3;
	

	return 0;
}
*/