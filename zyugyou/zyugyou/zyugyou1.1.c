#include <stdio.h>
int main(void)
{
	int hp = 100;
	
	//�_���[�W���󂯂�
	//hp = hp - 10;
	//������Z�q���g�p����������
	//HP��
	hp += 10;
	printf("HP:%d\n", hp);

	//�U�����󂯂�
	int enemyAttack = 20;
	
	hp -= enemyAttack;

	printf("HP:%d\n", hp);

	//�r�b�g�V�t�g������
	int shiftTest = 100;
	//0110 0100 �� 1100 1000�ɂ���
	printf("shiftTest %d\n", shiftTest << 1);  //���ɂP�r�b�g�V�t�g

	//0110 0100�@���@0011 0010�ɂ���
	printf("shiftTest %d\n", shiftTest >> 1); //�E�ɂP�r�b�g�V�t�g

	int num = 6;
	//�C���N�������g���Z�q�@�C���N�������g
	num++;    //num�ɂP�𑫂���num�ɑ������@num += 1, num = num+1�Ɠ���
	printf("num:%d\n", num);

	//�f�N�������g���Z�q�@�f�N�������g
	num--; //num����P��������num�ɑ������@num -= 1, num = num-1�Ɠ���
	printf("num:%d\n", num);


	return 0;
}