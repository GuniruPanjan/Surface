#include<iostream>
using namespace std;

//C�̒萔��`�̍�@�@�@�@�Y��Ă���
//#define NUM 3

//C++���g���ۂ͂��̒�`���g��
//C++���萔��`
//const int kArraySize = 5;

//����IC++�̒萔��`
namespace
{
	constexpr int kConstexprNum = 3;         //constexpr:�萔���`���邽�߂ɏ������ꂽ����
	                                         //�R���p�C�����_�Œl���܂��Ă���ꍇ�͂�����
	const int kConstNum = 3;                 //const:�ϐ��̕ύX��s�\�ɂ��邽�߂̏�����
	                                         //�ŏ��Ɍ��߂��l����ύX�ł��Ȃ��Ƃ��������𗘗p����
	                                         //�萔��`�Ɏg�p���Ă���
}

//�萔��`�̂܂Ƃ�
//namespace�i�������O��ԁ@���O���ݒ肳��Ă��Ȃ�namespace�j�̒��ɓ����
//�������O��Ԃ̒��ɏ����Ă���ϐ���萔�A�֐��͂��̃\�[�X�R�[�h�ł̂ݗL��

namespace
{
	//��{�I�ɒ萔��constexpr�Œ�`����
	//�萔����google�̃R�[�f�B���O�K�񏀋�
	//�萔���̖����K���͂ق��̃��[�����ǂ��Ȃ炻��ł������K�����ꂷ�邱��
	constexpr int kNum = 16;
	
	constexpr int kDoublNum = kNum * 2;       //�萔���g�p���Ē萔���`���邱�Ƃ��\
	constexpr float kFloatNum = 12.25f;   // int�ȊO��OK

	//�����蔻��̃T�C�Y
	constexpr float kRadius = 8.0f;
}    //namespace�I�����Z�~�R�����s�v

namespace
{
	constexpr int kEnemyNum = 16;
}

//�ʏ��namespace�̏�����
//namespace�̌�ɖ��O��ݒ肷��
namespace Test
{
	int num = 10;
}

//��������`�Ƃ��Ē�`������
const char* const kConstText = "�萔�Ƃ��Ē�`���ꂽ������";
const char* const kFileName = "data/image.ping";    //�t�@�C�������`����

//pNum�̎Q�Ɛ�ύX�s��
//pNum�̒��g�Œ�ł͂Ȃ� �������͂ł���Ƃ�����
void func(const int* pNum)
{

}

int main()
{
	/*
	int tbl[kArraySize] = { 10,20,30 };
	for (int i = 0; i < kArraySize; i++)
	{
		cout << tbl[i] << endl;
	}

	cout << kConstText << endl;
	*/

	//const�͏������ł���
	const int constNum = rand() % 16;
	//�ォ��ύX�͂ł��Ȃ�
	//constNum = 10;

	//�R���p�C���������_�Œl�����܂�Ȃ�
	//constexpr int constexprNum = rand() & 16;

	//�萔��`��constexpr���g��
	//����ȊO�̕ύX���Ăق����Ȃ��l��const���g��
	return 0;
}

/*
//�g���̔z����킽���Ă��ꂼ��̕W���̏d��\������֐��@�g��-105��\������
//�ϐ�����|�C���^�̐錾�O��const��t���邱�Ƃł��̒��g��ύX���邱�Ƃ��ł��Ȃ��Ȃ�
void dispStandardWaight(const int height[])
{
	cout << "�W���̏d" << endl;
	for (int i = 0; i < 3; i++)
	{
		int stdWeight = height[i] - 105;
		cout << i + 1 << ":" << stdWeight << endl;
	}
}

//�g����\������֐�
void dispHeight(const int height[])
{
	cout << "�g��" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ":" << height[i] << endl;
	}

	
}

struct Test
{
	int testData0;
	int testData1;

};

//�|�C���^��Q�Ƃ�const�ɂ���Ƃ��̃����o�[�ύX�ł��Ȃ��Ȃ�
void testFunc(const Test& pTest)
{
	pTest.testData0 = 100;
	pTest.testData1 = 100;
}

int main()
{
	Test test;
	testFunc(test);

#if false
	//�R�l���ɐg���f�[�^
	int height[3] = { 170,180,190 };

	//�W���̏d��\������
	dispStandardWaight(height);

	//�g���f�[�^��\������
	dispHeight(height);

#endif




	return 0;
}
*/