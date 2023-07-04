//[1]�w�b�_�[���C���N���[�h����ꏊ

#include<stdio.h> //[1-1]�W�����o�̓w�b�_�[���C���N���[�h����
#include<conio.h> //[1-5]�R���\�[�����o�̓w�b�_�[���C���N���[�h����

//[2]�萔���`����ꏊ

//[3]�񋓒萔���`����ꏊ



//[3-1]�����X�^�[�̎�ނ��`����
enum
{
	MONSTER_PLAYER,  //[3-1-1]�v���C���[
	MONSTER_MAX      //[3-1-4]�����X�^�[�̎�ނ̐�
};

//[3-2]�L�����N�^�[�̎�ނ��`����
enum
{
	CHARACTER_PLAYER,    //[3-2-1]�v���C���[
	CHARACTER_MONSTER,   //[3-2-2]�����X�^�[
	CHARACTER_MAX        //[3-2-3]�L�����N�^�[�̎�ނ̐�
};

//[4]�\���̂�錾����ꏊ

//[4-1]�L�����N�^�[�̍\���̂�錾����
typedef struct
{
	int hp;        //[4-1-1]HP
	int maxhp;     //[4-1-2]�ő�HP
	int mp;        //[4-1-3]MP
	int maxmp;     //[4-1-4]�ő�MP
	char name[4 * 2 + 1];   //[4-1-6]���O
}CHARACTER;

//[5]�ϐ���錾����ꏊ

//[5-1]�����X�^�[�̃X�e�[�^�X�̔z���錾����
CHARACTER monsters[MONSTER_MAX] =
{
	//[5-1-1]MONSTER_PLAYER     �v���C���[
	{
		15,      //[5-1-2]int hp        HP
		15,      //[5-1-3]int maxhp     �ő�HP
		15,      //[5-1-4]int mp        MP
		15,      //[5-1-5]int maxmp     �ő�MP
		"�E��",  //[5-1-7]char name[4 * 2 + 1] ���O
	},
};

//[5-2]�L�����N�^�[�̔z���錾����
CHARACTER characters[CHARACTER_MAX];

//[6]�֐���錾����ꏊ

//[6-1]�Q�[��������������֐���錾����
void Init()
{
	//[6-1-1]�v���C���[�̃X�e�[�^�X������������
	characters[CHARACTER_PLAYER] = monsters[MONSTER_PLAYER];
}

//[6-2]�퓬�V�[���̉�ʂ�`�悷��֐���錾����
void DrawBattleScreen()
{
	//[6-2-2]�v���C���[�̖��O��\������
	printf("%s\n", characters[CHARACTER_PLAYER], name);
}


//[6-4]�퓬�V�[���̊֐���錾����
void Battle()
{
	//[6-4-4]�퓬�V�[���̉�ʂ�`�悷��֐����Ăяo��
	DrawBattleScreen();

	//[6-4-6]�L�[�{�[�h���͂�҂�
	_getch();

}


//[6-6]�v���O�����̎��s�J�n��錾����

int main()
{
	//[6-6-2]�Q�[��������������֐����Ăяo��
	Init();

	//[6-6-3]�퓬�V�[���̊֐����Ăяo��
	Battle();

}