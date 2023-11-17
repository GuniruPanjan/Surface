#include<iostream>
#include <vector>
#include "Application.h"

//����(10/6)��邱��
//�@Application�V���O���g���N���X�����
//�A���Ԃ������΁AState�p�^�[���ɂ��V�[���J�ڂ����

//�V���O���g��(Singleton)�N���X�Ƃ͉���
//�A�v���P�[�V�������ň�����C���X�^���X���Ȃ����Ƃ�ۏႷ��N���X
//�ǂ�����ł����̃C���X�^���X�ɃA�N�Z�X�ł���
//�V���O���g���N���X�Ƃ́u���s�V�̂悢�O���[�o���I�u�W�F�N�g�v�ł���
using namespace std;
//�z���int a[10];�@���̎�a[7] = 7[a] = *(a+7)�ł�
//���́A�z��̖��O�Ƃ����͔̂z��̂��߂Ɋm�ۂ��ꂽ�������̃A�h���X�����Ă���ϐ��ł��B�܂�|�C���^�ƈꏏ�ł�
//�����Ō���+7�́A7�o�C�g�̂��Ƃ���Ȃ�
//+7��+7*4 = +28�ɕϊ�����܂��l��Ɍ����Ȃ��Ƃ����
//���̌���7�Ԗڂ̗v�f���������Ă���Ƃ������ɂȂ�܂�
//2�����z���1�����z��ł�
//2�����z��ł���������1�����I�ɘA�����Ă��邽��

struct Object
{
	int a;
	int b;
	int c;
};

void CreateObject(int a, int b, int c, Object** obj)
{
	*obj = new Object();
	(*obj)->a = a;
	(*obj)->b = b;
	(*obj)->c = c;
}

int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

string Add(string a, string b)
{
	return a + b;
}

//�e���v���[�g�֐�
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

//�e���v���[�g�N���X
template<typename T>
class Array
{
private:
	T array_[10];
public:
	Array()
	{
		float start = 3.14f;
		for (T& a : array_)
		{
			a = start;
			start += 0.1f;
		}
	}
	void Output()
	{
		for (const T& a : array_)
		{
			cout << a << endl;
		}
	}

};



int main()
{
	/*int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	cout << a[7] << endl;
	cout << 7[a] << endl;
	cout << *(a + 7) << endl;*/

	constexpr int row = 3;
	constexpr int col = 4;
	Array<int> iarray;
	Array<float> farray;

	iarray.Output();
	farray.Output();

	////����͒��g��int�^�̓��I�z��
	//std::vector<int> ivec;
	////����͒��g��float�^�̓��I�z��
	//std::vector<float> fvec;
	////����͒��g��string�^�̓��I�z��
	//std::vector<string> svec;
	////����͒��g��Enemy�^�̓��I�z��
	//std::vector<Enemy> enemies;

	//int a[10];
	//int idx = rand() % 20;
	//a[10] = 3;

	vector<int> array_ = { 1,2,3,4,5 };
	array_[5] = 9;
	for (auto& a : array_)
	{
		cout << a << endl;
	}

	//list��vector�Ŗ�������vector��OK

	string str = "Hello,World,Fukuoka";
	cout << str << endl;
	auto idx = str.find(',');
	cout << str.substr(idx + 1) << endl;

	int idx = 0;
	do
	{
		int nidx = str.find(',', idx);
		cout << str.substr(idx) << endl;
		idx = nidx + 1;
		nidx = str.find(',', idx);
		if (idx == std::string::npos)
		{
			break;
		}
		cout << str.substr(idx, nidx - idx) << endl;
		++nidx;
	} while (idx != std::string::npos);

	//string��char�^�̓��I�z��ɕ֗��Ȋ֐��𑫂��������̂���

	//cout << str.rfind('o') << endl;

	cout << str.length() << endl;
	cout << str << endl;

	Add(1, 2);
	Add(3.14f, 2.7f);

	Add(string("Hello"), string("World"));

	const char* bgPath = "bg.png";
	

	//Unicode�ȑO:�}���`�o�C�g������<-char*�ŕ\���\
	//Unicode�ȍ~:���C�h������<-wchar_t*�ŕ\���\
	//string�̃��C�h�����o�[�W������wstring�ł�
	 
	//cout << a[idx] << endl;

	/*cout << Add(row, col) << endl;
	cout << Add(3.14f, 2.71f) << endl;
	cout << Add(string("Hello"), string("World")) << endl;*/

	/*int b[row][col] = {{1,2,3,4}, {5,6,8,7}, {12,11,10,9}};
	int c[row * col] = { 1,2,3,4,5,6,8,7,12,11,10,9 };*/
	//cout << c[2*col+2] << endl;
	/*cout << b[2][2] << endl;
	cout << b[0][10] << endl;*/

	//cout << "abcdefghi"[3] << endl;
	//cout << 3["abcdefghi"] << endl;

	//float a = 3.14f;
	//int b = 5;
	//cout << *((int*)&a) << endl;
	//cout << b << endl;

	//std::vector<int>a = { 1,2,3,4,5 };
	//int& b = a[3];
	//cout << b << endl;
	////a = { 2,4,6,8,10 };
	//a.push_back(20);
	//cout << b << endl;

	//��₱�����^
	//union UniTest
	//{
	//	int a;     //4�o�C�g
	//	float b;   //4�o�C�g
	//	char c[4]; //4�o�C�g
	//};
	//struct StTest
	//{
	//	int a;     //4�o�C�g
	//	float b;   //4�o�C�g
	//	char c[4]; //4�o�C�g
	//};

	//struct BitField
	//{
	//	int a : 1;
	//	int b : 2;
	//	int c : 3;
	//	int d : 4;
	//	int e : 6;
	//	int f : 16;
	//};
	//BitField bf;
	//cout << sizeof(bf) << endl;
	/*UniTest u;
	StTest st;*/
	/*cout << sizeof(u) << endl;
	cout << sizeof(st) << endl;*/

	/*u.b = 3.14f;

	cout << u.b << endl;
	cout << u.a << endl;
	cout << u.c << endl;*/

	/*std::vector<std::string> strList;

	int a[4] = { 1,2,3,4 };
	int b[4];*/

	//b = a;//a��b���w�������Ă���̂̓A�h���X�Ȃ̂�

	/*struct Array
	{
		int array[4];
	};

	Array c = { 1,2,3,4 };
	Array d;

	d = c;
	for (auto& e : d.array)
	{
		e *= 2;
	}
	for (auto e : c.array)
	{
		cout << e;
	}
	cout << endl;
	for (auto e : c.array)
	{
		cout << e;
	}
	cout << endl;*/

	/*class Vector
	{
	private:
		int array_[10];
	public:
		void operator = (Vector& v)
		{
			for (int i = 0; i < _countof(array_); i++)
			{
				array_[i] = v.array_[i];
			}
		}
	};

	std::vector<int> a = { 1,2,3,4,5 };
	std::vector<int> b;
	b = a;

	for (auto& c : b)
	{
		c *= 2;
	}
	for (auto c : a)
	{
		cout << c;
	}

	struct Alignment
	{
		int a;
		char b;
	};
	struct Alignment2
	{
		char a;
		int b;
	};
	struct Alignment3
	{
		char a;
		char b;
	};*/

	/*cout << sizeof(char) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(Alignment) << endl;
	cout << sizeof(Alignment2) << endl;
	cout << sizeof(Alignment3) << endl;*/

	/*char* c = 0;
	int* b = 0;

	c++;
	b++;

	cout << (unsigned int)c << endl;
	cout << (unsigned int)b << endl;

	Object* obj;
	CreateObject(1, 2, 3, &obj);

	cout << (unsigned int)obj << endl;*/

	//������ɂ́A�ʏ�̕����ƃ��C�h������2��ނ�����܂�
	//�ʏ�̕����񃊃e�����́Achar*�ŕ\����""�_�u���N�H�[�g��OK
	//���C�h�����񃊃e�����́Awchar_t*�ŕ\���� L""�̂悤��L�����ɕK�v�ł�

//�@C++�ɒu����e���v���[�g
//�A
//�Bstring��char�^�����ǂ������̂ł�
//�CC/C++�̕�����^�ɂ̓}���`�o�C�g�����ƃ��C�h����������

//�}���`�o�C�g�����FShift-JIS(SJIS)
//���C�h����:Unicode(UTF-8)
//�v���W�F�N�g�̐ݒ��Unicode�ɂ��Ă��Acpp�̃e�L�X�g�t�@�C���̎d�l���̂��̂�SJIS�ɂȂ��Ă���
//�}���`�o�C�g�����Fchar*, string
//���C�h�����Fwchar_t*,wstring
//���ꂽ���݂̂��ϊ�������ɂ�Widndows�֐����g���K�v������܂�
//MultiByteTowideChar�Ƃ����֐����g��
//�����̃v���W�F�N�g��StringUtility�Ƃ����N���X�����
//static�֐��΂���̃N���X��new�Ȃǂ�����K�v���Ȃ�

//�N���X��public�����o�֐��ɂ́u�K���v�R�����g��t���悤
//public�����o�֐����g���̂́A���p�ґ��ł��i�����ł͂Ȃ��l���g���j
//�R�����g�̓w�b�_���ɏ�����

//Microsoft��API�̃}�j���A���̓ǂݕ�
//[in]�Ə�����Ă��畁�ʂ̃p�����[�^�i�l�������������Ȃ��j
//[out]�Ə�����Ă���A�|�C���^��n���ď����������鎖�����҂��܂�
//[oprional]�́A���̈����������Ă�������inullptr��0�ł����삷��j��\��
//UNIT = unsigned int
//DWORD = uint32_t = 4�o�C�g�����Ȃ��̐����^�̎��ł�
//LPCCH = LP�̓|�C���^�̎��ACCH = (C�����char�^)->const char*������
//LPWSTR = WSTR�̓��C�h�����̎��A����̃|�C���^�ɓ����
//�Ƃɂ���MS�̃}�j���A��������Ȃ�t����

	return 0;
}