#include<stdio.h>

int main(void)
{
	int enemyhp = 100;  //�G��HP
	int playerMP = 50;  //�v���C���[��MP

	//�A���U�����@�œG��|���܂ōU������
	while (enemyhp > 0)
	{
		enemyhp -= 10;
		playerMP -= 10;
		printf("�G�̎c��hp: %d\n", enemyhp);
		printf("�v���C���[�̎c��MP: %d\n", playerMP);
		

		//MP���Ȃ��Ȃ����狭���I��
		if (playerMP <= 0)
		{
			printf("MP�؂�I�U���I��\n");
			break;
		}

		//�G�ɉ�����ꂽ
		if (0)
		{
			printf("�悯��ꂽ�̂Œ��f\n");
			break;
		}
		//���̓G�̍U�����󂯂�
		if (0)
		{
			printf("�ق��̓G�̍U�����󂯂��̂Œ��f\n");
			break;
		}


	}   
	return 0;
}


/*
int main(void)
{
	//do-while���̐���
	//�@�������s��
	//�A�����𖞂����Ă�����@�ɖ߂�
	do 
	{
		printf("do-while���͕K����x�͎��s���܂�\n");
	} while (2 < 1);

	//while���̐���
	//�@while���ɓ�����������`�F�b�N���s����
	//�A�����𖞂����Ă����珈�����s���@�������Ă��Ȃ��Ȃ�I��
	//�@�ɖ߂�
	while (2 < 1)
	{
		printf("while���́H\n");
	}

	return 0;
}
*/






/*
int main(void)
{
	int num = 3;

	//true(�^)�@�@�@�@0�ȊO
	//false(�U)       0

	while (num)
	{
		printf("����%d��J��Ԃ��܂�\n", num);
		num--;
	}

	if (num)
	{
		//num = 0�̏ꍇ�͂����̏����͍s���Ȃ�
		//num != 0�̏ꍇ�����̏����͍s����
	}


	return 0;
}





int main(void)
{
	int startCount = 4;
	int loopNum = 8;
	//��������p�������ɂ��ϐ����g����
	//for��������ƕ⑫
	for (int i = 1; i <= 5; i++)
	{
		printf("�J��Ԃ�%d\n", i);
	}

	//while��
	int hp = 50;

	//HP��0�ȉ��ɂȂ�܂ōU�����ꑱ����
	while (hp > 0)
	{
		hp -= 5;
		printf("�c��HP: %d\n", hp);
	}

	for (hp = 50; hp > 0; hp -= 5)
	{
		printf("�c��HP: %d\n", hp);
	}

	//�@while���ɓ�����������`�F�b�N���s����
	//�A�����𖞂����Ă����珈�����s���@�������Ă��Ȃ��Ȃ�I��
	//�@�ɖ߂�






	//for���̗��K
	printf("for���ɂ��J��Ԃ��̗��K�ł�\n");

	int i;

	for (i = 1; i <= 5; i++)
	{
		printf("%d�b�o��\n", i);
	}
	printf("%d�b�o��\n���[�h���[���[���b�I�I\n", i);
	���X�ƌJ��Ԃ�
	for (;;)
	{
		printf("����������������������������������������������������\n");
	}


}
	*/