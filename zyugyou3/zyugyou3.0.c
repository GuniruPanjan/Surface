#include<stdio.h>

int main(void)
{
	//�������������Ă��邩
	int keyNum = 0;
	//�v���C���[�̃p���[
	int playerPower = 10;

	//true�i�^�j�̏ꍇ�Aif()�̎��̂P�s�����s�����
	//false�i�U�j�̏ꍇ�Aif()�̎��̂P�s�͎��s����Ȃ�
	if (keyNum >= 1)
		printf("���P���J�����I\n");
	else
		printf("���P�͊J���Ȃ�\n");

	//��������Ό��ŊJ���邱�Ƃ��ł���    if(keyNum >= 1)
	//�͂����ŊJ���邱�Ƃ��ł���          if(playerPower >= 50)
	//�ǂ��炩�̎�i�Ŕ���˔j����
	//|| : �_���a or ���Z
	if (keyNum >= 1 || playerPower >= 50)
		printf("���Q���J�����I\n");
	else
		printf("���Q���J���Ȃ�����\n");

	//��������Ό��ŊJ���邱�Ƃ��ł���@if(keyNum >= 1)
	//�͂��Ȃ��Ɩ�Ԃ��F�߂Ă���Ȃ��@if(playerPower >= 50)
	//���������Ă��āA�͂��Ȃ��Ɣ����J���Ȃ�
	//�����̏����𖞂����K�v������

	//&& : �_���ρ@and  ���Z
	//if (keyNum >= 1 && playerPower >= 50)
		//printf("���R���J�����I\n");

	//else
		//printf("���񂽂̂����炶�ᎀ�񂶂܂���\n");

	//���������Ă��Ȃ��ꍇ�J���Ȃ�

	//else if���g�p���ď������������
	if (!(keyNum >= 1))
		printf("���͊J���Ȃ�\n");

	if(keyNum <= 0)
		printf("���R���J���錮�������Ă��Ȃ�\n");
	else if(playerPower < 50)
		printf("���R�̖�Ԃ��������F�߂Ă���Ȃ�\n");
	else
		printf("���R���J����\n");






	return 0;
	//�L���X�g�̕��K
	/*
	int numInt = 10;

	float numFloat = 1.234f;

	double numDouble = 12.35;

	numInt = (int)numFloat;  //�������Ă�float�̃f�[�^��int�ɓ˂�����ł���

	printf("numInt = %d\n", numInt);   //�����_�ȉ��͂Ȃ��Ȃ��Ă���

	//�|�P�����Q�b�g�����v�Z����

	//���p�[�Z���g���A��\������ꍇ�����ʓ����ł͊����ŊǗ������
	//�S�����@�@����
	//100%       1.0
	//50.12%     0.5012
	//12.35     0.1235
	float getRate = 0.0f;

	int getNum = 32;          //�����Ă���|�P�����̎��
	int pokemonTotal = 151;       //�|�P�����̎��
	getRate = (float) getNum / (float)pokemonTotal;         //�|�P�����̃Q�b�g���i�����j
	printf("getRate = %f\n", getRate);
	*/
}