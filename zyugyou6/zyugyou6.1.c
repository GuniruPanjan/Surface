#include<stdio.h>


//�ۑ�
int main(void)
{
	int answer = 0;
	int sum = 0;
	int a;

	for (a = 0; a <= 100; a++)
	{
		if (a % 7 != 0)continue;
		sum += a;
	}
	printf("���v��%d�ł�\n", sum);

	//while����g���ď�������
	int addNum = 7;
	while (addNum <= 100)
	{
		answer += addNum;
		addNum += 7;
	}

	for (int i = 1; ; i++)
	{
		if ((7 * i) > 100) 
		{
			break;
	    }
		answer += (i * 7);
	}
	int baseNum = 1;
	while (1) {
		int addNum = 7 * baseNum;
		if (addNum > 100) {
			break;
		}
		answer += addNum;
		baseNum;
	}
	
}

/*
//break,continue�̕��K
int main(void)
{
	//�v���C���[��HP
	int playerHp = 50;
	//�G�̍U����
	int enemyAttack = 3;
	//�G�̍U����
	int enemyAttackNum = 10;

	//�G�̍U���񐔉�_���[�W����炤
	for (int i = 0; i < enemyAttackNum; i++)
	{
		printf("%d��ڂ̍U���I\n", i + 1);

		//���ڂ̍U�����󂯂�
		//������ڂ̍U�����������
		//�U���񐔂͊�̎��Ai�̒l�͋����@�t���܂��R��
		//i����̎���continue����
		if (i % 2 == 1)
		{
			printf("��������I\n");
		    continue;
		}
		playerHp -= enemyAttack;
		printf("�c��HP%d\n", playerHp);

		//hp��0�ɂȂ�����U������߂�
		if (playerHp <= 0)
		{
			printf("����ł��܂���\n");
			break;  //break�ŌJ��Ԃ��������I�ɂ�߂�
		}
	}

	while (1)
	{
		printf("�������[�v\n");
		if (1)
		{
			printf("�������[�v������\n");
			break;
		}
	}
}
*/
/*
//for���̕��K
int main(void)
{
	//���܂����񐔂��J��Ԃ��ꍇfor�g�����Ƃ�����
	for (
		int i = 0;  //for���̏���������
		i < 5;        //�J��Ԃ�����
		i++         //�p�������@�J��Ԃ���钆�g���I���������s�����
		) 
	{
		//�J��Ԃ���钆�g
	}

	//���ꂢ�ɏ�������
	int loopNum = 16;
	for (int i = 0; i < loopNum, i++);
	{
		printf("%d��ڂ̌J��Ԃ�\n", i + 1);
	}

	//��������̏����𖞂����܂ŌJ��Ԃ��ꍇwhile���g�����Ƃ�����
	int playerHp = 50;
	//�v���C���[��HP��0�ȉ��ɂȂ�܂Ń_���[�W���J��Ԃ��󂯂�
	while (playerHp > 0)
	{
	   playerHp -= 7;
	   printf("�c��HP %d\n", playerHp);

	}
}
*/
/*
//switch���̕��K
int main(void)
{
	int num = 5;
	switch (num)
	{
	case 0:
		printf("num��0\n");
		break;
	case 1:
		printf("num��1\n");
		break;
	case 2:
		printf("num��2\n");
		break;
	case 3:
		printf("num��3\n");
		break;
	case 4:
		printf("num��4\n");
		break;
	case 5:
		printf("num��5\n");
		break;
	default:
		printf("num�͂���ȊO\n");
		break;

	}

	return 0;
}
*/