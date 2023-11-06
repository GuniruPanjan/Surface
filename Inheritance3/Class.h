#pragma once
#include<iostream>
using namespace std;

//�p�����ƂȂ�N���X�@���N���X
//���N���X�̃N���X����~~Base�̂悤�Ȗ��O�������鎖������
class EnemyBase
{
public:
	EnemyBase() :
		m_hp(0)
	{}
	//�K���f�X�g���N�^�ɂ�virtual��t����
	virtual ~EnemyBase(){}


	//virtual��t���鎖�ŉ��z�֐��ɂ���
	//�p����ɓ������O�A���������̊֐�������ꍇ
	//���̊֐��ŏ㏑�������
	virtual void Attack() = 0; //=0�ŏ������z�֐���
	//{�@�@�@�@�@�@�@�@�@�@�@�@//�p�����ā@
	//	cout << "�����X�^�[�̍U��" << endl;
	//}
	void DispHp()
	{
		cout << "HP:" << endl;
	}
private:
	int m_hp;
};

//EnemyBase���p�����ēG�̃N���X������Ă���
class EnemySlime : public EnemyBase
{
public:
	EnemySlime(){}
	virtual ~EnemySlime(){}

	virtual void Attack() override
	{
		cout << "�̓�����" << endl;
	}

	//DispHp�͂��ׂẴ����X�^�[�ŋ��ʂ̏����Ȃ̂�
	//EnemyBase�ɔC����i�����֐������x�������Ȃ��j
};

//EnemySlime���p������EnemyMetalSlime�����
class EnemyMetalSlime : public EnemySlime
{
public:
	EnemyMetalSlime(){}
	virtual ~EnemyMetalSlime(){}

	virtual void Attack() override
	{
		cout << "����" << endl;
	}
};