#include<iostream>
using namespace std;

//��������
void printMsg(void)
{
	cout << "�L�T�}�����b�R���X" << endl;
}
/* NG�߂�l���Ⴄ�����̓����֐��͍쐬�ł��Ȃ�
void printMsg(void)
{
	cout << "�L�T�}�����b�R���X:" << endl;
}
*/
//�����̐����Ⴆ�Γ����֐����̊֐����쐬�ł���
//void prinatMsg(int metal)      //�������ȗ������ꍇ�A���������ƌ����������Ȃ��̂�NG
void prinatMsg(int num, int metal = 50)
{
	cout << "�҂�������:" << metal << endl;
}

/*void prinatMsg(int num)   //�����Q���Q�߂��f�t�H���g�����A�ƌ����������Ȃ��̂�NG
{
	cout << "num:" << num << endl;
}
*/

//C++�ł͊֐��̈����Ƀf�t�H���g�̒l��ݒ�ł���
struct Player
{
	int hp;
	int mp;

};
//�������̌�� = 50�̂悤�ɏȗ������ꍇ�ɐݒ肳��鐔�l���w��ł���
//������f�t�H���g����
//�f�t�H���g�������ݒ肳��Ă���ꍇ�A�������ȗ����鎖���ł���
//�ȗ������ꍇ�A�������ɂ͐ݒ肵���l������
void initPlayer(Player& player, int hp = 100, int mp = 50)
{
	player.hp = hp;
	player.mp = mp;
}

	
	



int main()
{

	printMsg();
	printMsg(10);
	printMsg(10, 50);

#if false
	Player player;
	initPlayer(player);

	//�L�����N�^�[�I���\
	//100��ވȏ�̃L�����N�^�[������
	//1�̗͎̂͑����@�@�@HP200, MP0
	//1�͖̂��@�g���@�@�@HP50, MP100
	//����ȊO��98�̂� HP100, MP50

	cout << "HP:" << player.hp << endl;
	cout << "MP:" << player.mp << endl;

#endif



	return 0;
}