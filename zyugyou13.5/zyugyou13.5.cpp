#include<iostream>
#include<cmath>     //�����֐�

//#include<stdio.h>
//#include<stlib.h>
//��  C++�ŏ�Ɋ܂܂��֐����g�������I
//#include<cstdio>
//#include<cstdiob>

//<cmath>
//���@C�ŏ�Ɋ܂܂��֐����g�������I
//<math.h>
using namespace std;

int main()
{
	//���p�O�p�`�̎Εӂ̒��������߂�v���O����
	double a, b;   //��ӂƍ���

	cout << "���p���͂��ނQ�ӂ̒�������͂��Ă������� >" << flush;
	cin >> a >> b;

	//�Εӂ̒������v�Z����
	double result = (a * a + b * b);     // sqrt(x)��x�̕����������߂�
	cout << "�Εӂ̒�����" << result << "�ł��B" << endl;

	//abs(x)      :x�̐�Βl�����߂�
	//float(x)    :�����_�ȉ��؂�̂�
	//cell(x)     :�����_�ȏ�؂�グ
	//fmod(x,y)   :x��y�Ŋ��������܂�
	//sqrt(x)     :x�̕�����
	//... ���@�@���ȏ�140�y�[�W�`�Q��

	return 0;
}

/*
//�l�n�����g�p�����֐�
void add_1(int x)
{
	x += 1;
}
//�|�C���^�n�����g�p�����֐�
void add_2(int* pX)
{
	//�Q�Ɛ悪�Ȃ��̂ŉ������Ȃ�
	if (pX == nullptr) return;
	*pX += 2;
}

//�Q�Ɠn�����g�p�����֐�
void add_3(int& x)
{
	//�K����������̕ϐ����Q�Ƃ��Ă���̂�
	//�`�F�b�N�Ȃǂ͕s�v
	x += 3;
}

int main()
{
	int num = 123;
	cout << "num = " << num << endl;

	add_1(num);   //�l�n��    num�͕ω����Ȃ�
	cout << "add_1:" << num << endl;

	add_2(&num);  //�|�C���^�n��   num�͕ω�����
	cout << "add_2:" << num << endl;

	add_3(num);   //�Q�Ɠn���@�@num�͕ω�����
	cout << "add_3:" << num << endl;

	//�Q�Ƃ��g���Ă݂�
	int& refNum = num;
	cout << "refNum = " << refNum << endl;

	refNum -= 100;
	cout << "num = " << num << endl;
	cout << "refNum = " << refNum << endl;

	refNum += 1000;
	cout << "num = " << num << endl;
	cout << "refNum = " << refNum << endl;

	//�Q�Ƃ̒��ӓ_�@�Q�Ɛ�̕ύX�͂ł��Ȃ�
	int num2 = 999;

	int* pNum = &num;
	pNum = &num2;

	//�Q�Ɛ�̕ύX�͂ł��Ȃ��͂������c
	refNum = num2;
	cout << "refNum = " << refNum << endl;

	//�Q�Ɛ�͕K�����������ɐݒ肷��
//	int& refNum2 = //ng �������ɎQ�Ɛ��ݒ肷��K�v������
	int& refNum2 = num2;    //�K���Q�Ɛ��ݒ肷��


	int* pNum2 = nullptr;    //�|�C���^�͐������ɏ������s�v
//	cout << "pNum2 = " << (*pNum2) << endl; //??
	//�|�C���^�͎Q�Ɛ悪�Ȃ��\��������


	return 0;
}
*/


/*
//��������a�ɕϊ�����֐�
//���a�ł͂Ȃ��N���w�肳�ꂽ�ꍇ0�ɂ���
void WesternToShouwa(int* x)
{
	if (1926 <= *x && *x <= 1989)  //1926�N�`1989�N�����a
	{
		*x -= 1925;
	}
	else
	{
		*x = 0;
	}
}

void Shouwa(void)
{
	int year;

	cout << "�������͂��Ă�������" << flush;
	cin >> year;     //�L�[�{�[�h���琔�l����͂���

	//  cout << "����" <<year << endl;     //�f�o�b�N�\��
	WesternToShouwa(&year);
	if (year != 0)
	{
		cout << "���̔N�͏��a" << year << "�N�ł��B" << endl;
	}
	else
	{
		cout << "���̔N�͏��a�ł͂���܂���B" << endl;
	}
}

int main()
{
	Shouwa();
	Shouwa();



	return 0;
}
*/