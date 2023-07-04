#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�萔
#define BUFF_NO 0      //�o�t����
#define BUFF_ATTCK 1    //�U���̓A�b�v
#define BUFF_SPEED 2    //�ړ����x�A�b�v
#define BUFF_DEF 3      //�h��̓A�b�v

//�v���C���[�ւ̃o�t�̎��
typedef enum Buff
{
	NONE,       //�Ȃ�
	ATTACK,      //�U����
	SPEED,      //�ړ����x
	DEF,        //�h���
}Buff;

//�X�e�[�^�X�A�b�v���������p��
typedef union BuffEffect
{
	int attack;   //�U���̓A�b�v��
	float speed;    //�ړ����x�㏸��
	int def;      //�h��̓A�b�v��
	//�c�@�@�@�@�@�@�@//�o�t�̎�ނ��������烁���o��������

}BuffEffect;

//�v���C���[�\����
typedef struct Player
{
	int hp;

	//�o�t���ʁi�X�e�[�^�X�A�b�v�j
	//�������̃X�e�[�^�X�A�b�v�����邪�A�i�U���́A�f�����Ȃǁj
	//��̂ݗL��
	//�V�����o�t�����ƌÂ��̂͏�����
	int buffType;  //0:�����@1:�U���̓A�b�v  2:�f�����A�b�v  3:�h��̓A�b�v

	Buff buffType;         //���݂̃o�t�̎��
	BuffEffect buffEffect;  //�X�e�[�^�X�A�b�v���

}Player;



int main(void)
{
	//�f�[�^�^
	//int�^�F����������
	//float�^�F�����������
	//char�^�F������������

	/*
	//�񋓑̂ł���Buff�^�F�񋓑̂Œ�`�����萔
	Buff bf;
	bf = NONE;
	bf = ATTACK;
	bf = SPEED;
	bf = DEF;
	bf = 10;      //�r���h�͒ʂ邪�悭�Ȃ�
	*/


	BuffEffect buff;
	buff.attack = 10;
	buff.speed = 10.0f;
	buff.def = 16;

	printf("buff.attack = %d\n", buff.attack);

	

	Player player;
	//������
	player.hp = 100;
	player.buffType = BUFF_NO;     //�������������A�萔���`����

	//�U���̓o�t
	player.buffType = BUFF_ATTCK;     //�U���̓A�b�v�ɐݒ�
	player.buffEffect.attack = 10;    //�U���͂̏㏸�ʂ�ݒ�

	//�ړ����x�o�t
	player.buffType = BUFF_SPEED;      //�ړ����x�A�b�v�ɐݒ�
	player.buffEffect.speed = 0.5f;      //�ړ����x�̏㏸�ʂ�ݒ�

	switch (player.buffType)
	{
	case NONE:
		printf("�\�̓A�b�v���Ă��Ȃ�\n");
		break;
	case ATTACK:
		printf("�U���͂�%d�オ���Ă���\n", player.buffEffect.attack);
		break;
	case SPEED:
		printf("�ړ����x��%f�オ���Ă���\n", player.buffEffect.speed);
		break;
	case DEF:
		printf("�h��͂�%d�オ���Ă���\n", player.buffEffect.def);
		break;
			
	}




	return 0;
}