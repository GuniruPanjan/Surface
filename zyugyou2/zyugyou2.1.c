#include<stdio.h>
int main(void)
{
	int a = 79;

	if (a > 100)
		printf("�ϐ��͂P�O�O���傫���l�ł�\n");
	else if (a > 50)
		printf("�ϐ��͂T�O���傫���A�P�O�O�ȉ��̒l�ł�\n");
	else if (a >= 0)
		printf("�ϐ��͂O�ȏ�T�O�ȉ��̒l�ł�\n");
	else
		printf("�ϐ��̒l��%d�ł�\n", a);

	printf("�ϐ��̒l��%d�ł�\n", a);

	return 0;

	/*
	int a = 5;

	if (a % 2 == 0)
		printf("%d�͋����ł�\n", a);
	else
		printf("%d�͊�ł�\n", a);

	
	//���������Ă��鐔
	int keyNum = 0;
	//�L�����N�^�[�̃��x��
	int level = 10;

	//�����P�ȏ㎝���Ă�����J��
	if (keyNum >= 1)
		printf("�J��");

	else
		printf("�J���Ȃ�");

	//�����P�ȏ㎝���Ă��āA�v���C���[�̃��x�����T�O�ȏ�Ȃ�J��
	//�����ɏ����𖞂����K�v������
	//keyNum >= 1��true,level >=50���Ƃ���true�̏ꍇtrue�ɂȂ�
	if (keyNum >= 1 && level >= 50)
		printf("�J��\n");

	//|| : �_���a�@or���Z
	//�����P�ȏ㎝���Ă�����J��
	//�v���C���[�̃��x�����T�O�ȏ�Ȃ�͂����ŊJ��
	//�ǂ��炩�̏����𖞂�����ok
	//keyNum >= 1��true,level >= 50�̂ǂ��炩��true�̏ꍇ�ɂȂ�
	if (keyNum >= 1 || level >= 50)
		printf("�J��");

	//! :�_���ے�@not���Z
	//!�����@�@�@������true�̏ꍇfalse,������false�̏ꍇtrue�ɂȂ�
	//�����Ă��錮�̐����O�������Ȃ���false�̏ꍇ�J��
	if (!(keyNum <= 0))
		printf("�J��");


	�@�@�@�@true�̏ꍇ
	int a = -1;

	if (a < 0)
		printf("a�̒l�͕��̐��ł�\n");

	printf("a�̒l��%d�ł�\n", a);
	

	//        false�̏ꍇ
	int a = 1;

	//if(�������j    ��if(�������j�ɂ�;�͂���Ȃ�
	//��;
	
	if (a < 0)
		printf("a�̒l�͕��̐��ł�\n");

	printf("a�̒l��%d�ł�\n", a);

	*/


}