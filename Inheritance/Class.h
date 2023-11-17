#pragma once
#include<iostream>
using namespace std;

//�p���Ƃ͂���N���X
//����N���X����ɐV�����N���X����邱�Ƃ��ł���
//������p���Ƃ���

//�����ClassBase����ɐV�����N���X���쐬����
//��ɂȂ�N���X���������N���X�ƌĂ�
class ClassBase
{
public:
	ClassBase(int num = 0);

	ClassBase(int num):
		m_num(num)
	{
		cout << "ClassBase�̃R���X�g���N�^" << m_num << endl;
	}

	~ClassBase()
	{
		cout << "ClassBase�̃f�X�g���N�^" << m_num << endl;
	}

	void Func()
	{
		cout << "ClassBase::Func" << m_num << endl;
	}
	void Func1()
	{
		cout << "ClassBase::Func1" << m_num << endl;
	}void Func2()
	{
		cout << "ClassBase::Func2" << m_num << endl;
	}

	//private�ȃ����o�[�N���X�O����Q�Ƃł��Ȃ�
	//����͌p����̃N���X�ł����l
	//�p���N���X�����N���X�̎��ϐ���ύX�������ꍇ�͂悭����
private:
	//�ʒu����U���͂ȂǁA���N���X�Ɏ�������
	//�p����ł��ύX���s�������ϐ��͂�����ł�����

	//���������ꍇ��protected�Ő錾����
	//protected�ȕϐ��A�֐��̓N���X�O����͌����Ȃ���
	//�p����̃N���X����͊ς邱�Ƃ��ł���
protected:
	void ProtectedFunc()
	{
		cout << "protected�Ȋ֐�" << endl;
	}
	int m_num;

};

//ClassBase����ɐV�����N���X���쐬����
//ClassBase���p�����ĐV�����N���X���쐬����

//�N���X�̐錾���Ɍp�����ɂȂ�N���X���w�肷��K�v������
class ClassChild0 : public ClassBase
{
public:
	ClassChild0()
	{
		//���N���X�̃R���X�g���N�^�𖾎��I�ɌĂ΂Ȃ��ꍇ
		//�p����̃N���X�̃R���X�g���N�^�Ăяo���O��
		//���������̌p�������R���X�g���N�^���Ăяo�����
		cout << "ClassChild0�̃R���X�g���N�^" << endl;
	}
	ClassChild0(int num):
		ClassBase(num) //�p�����N���X�̃R���X�g���N�^���ݖ����I�ɌĂ�
	{
		cout << "ClassChild0�̈����t���R���X�g���N�^" << endl;
	}
	~ClassChild0()
	{
		cout << "ClassChild0�̃f�X�g���N�^" << endl;
	}

	void Func0()
	{
		cout << "ClassChild1�̓����Func0" << endl;
		m_num = 999;
		ProtectedFunc();
	}
};
