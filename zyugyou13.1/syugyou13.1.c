#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TEST_NUM   5

//�񋓑̂̕��K
//��A�̃f�[�^�i�j���Ȃǁj���܂Ƃ߂Ē萔�Ƃ��Ē�`����̂Ɏd�l����
//����̗�RPG�̃A�C�e��
//�F�X�Ȏ�ނ����邪�A
//�񕜃A�C�e���A�_���[�W�A��Ԉُ�̉񕜁A�C�x���g�A���̃J�e�S���ɕ�������
typedef enum ItemType
{
	ITEM_TYPE_HEAL,       //�񕜃A�C�e��           0

	ITEM_TYPE_DAMAGE,     //�_���[�W�A�C�e��       1

	ITEM_TYPE_POWERUP,      //�X�e�[�^�X�A�b�v�A�C�e����ǉ�    2

	ITEM_TYPE_RECOVER,    //��Ԉُ�̉�         2->3

	ITEM_TYPE_EVENT,      //�C�x���g�A�C�e��       3->4

	ITEM_TYPE_OTHER,      //����A�C�e���@�A�C�e�����̐�p�������K�v  5

	ITEM_TYPE_NUM,        //�A�C�e���̃^�C�v�̐��@6
	                      //�Ō�ɒ�`���Ă�����
						  //�A�C�e���^�C�v�̎�ނ������Ă�����ɂ������Ă��̒��̒l���ω�����

}ItemType;

int main(void)
{
	printf("�\�[�X�R�[�h�̃t�@�C����%s\n", __FILE__);
	printf("����printf��%d�s�ڂɏ�����Ă���\n", __LINE__);

	printf("�R���p�C�����s������:%s\n", __DATE__);
	printf("�R���p�C�����s��������:%s\n", __TIME__);
	//int�^:����
	//float�^:����
	//chat�^:���p1����

	//ItemType�^:enum�Œ�`���ꂽ�l�̂����A�����ꂩ������

	ItemType item;
	item = ITEM_TYPE_HEAL;
	item = ITEM_TYPE_EVENT;
//	item = 16;   //ItemType,����int�Ȃ̂œ���鎖�͂ł��邪�悭�Ȃ�

	printf("enum�����͐����ł��邱�Ƃ��m�F\n");
	printf("ITEM_TYPE_RECOVER = %d\n", ITEM_TYPE_RECOVER);

	int tbl[ITEM_TYPE_NUM];

	for (int i = 0; i < ITEM_TYPE_NUM; i++)
	{
		switch (i)
		{
		case ITEM_TYPE_HEAL: //�������ƕ����肸�炢
			printf("HP��10��\n");
			break;

		case ITEM_TYPE_DAMAGE:
			printf("�G��10�_���[�W\n");
			break;

		case ITEM_TYPE_POWERUP:
			printf("�ő�HP��3�オ����\n");
			break;

		case ITEM_TYPE_RECOVER:   //�C���ɑΉ������炢
			printf("�ł���\n");
			break;

		case ITEM_TYPE_EVENT:
			printf("�g���Ă������N����Ȃ�\n");
			break;
		case ITEM_TYPE_OTHER:
			printf("�A�C�e���ɂ���Ă�������ʂ��ς��\n");
			break;
		}
	}

	return 0;
}