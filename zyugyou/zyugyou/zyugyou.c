#include <stdio.h>

int main(void) 
{
	printf("4/21�̎���\n");

	
	int hp = 100;
	printf("�v���C���[��HP:%d\n", hp + 10);

	int testNum = 16;   //�e�X�g�p�̐���

	//�l�����Z���s�������ʂ�\������
	printf("�v���C���[��HP+%d: %d\n", testNum, hp + testNum);

	printf("�v���C���[��HP-%d: %d\n", testNum, hp - testNum);

	printf("�v���C���[��HP*%d: %d\n", testNum, hp * testNum);

	printf("�v���C���[��HP/%d: %d\n", testNum, hp / testNum);

	printf("�v���C���[��HP/%d�̗]��: %d\n", testNum, hp % testNum);

	//�ϐ��ɒl��������
	hp = 150;

	printf("�v���C���[��HP:%d\n", hp);

	//�G�̍U����
	int enemyAttack = 20;

	//���@���g���ēG�̍U���͂����炷
	enemyAttack = enemyAttack / 2;
	printf("���@���g�p�����I\n�G�̍U���͂�%d�ɂȂ����I\n", enemyAttack);

	//�_���[�W������܂����@HP�����炵����
	//HP��enemyAttack�����炵����
	hp = hp - enemyAttack;
	printf("�_���[�W��%d�󂯂��I\n�v���C���[��HP�c��:%d\n", enemyAttack, hp);

	//HP�̕����𔽓]����
	hp = -hp;
	printf("HP : %d\n", hp);
	hp = -hp;      //�����P�x���]�����Ė߂�
	printf("HP : %d\n", hp);




	return 0;

}