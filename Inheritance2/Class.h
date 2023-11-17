#pragma once
#include<iostream>
using namespace std;

//�����X�^�[�̊��N���X
class EnemyBase
{
public:
	EnemyBase(){}
	virtual ~EnemyBase() { cout << "Base" << endl; }

	//�㏑��(Override)�������֐��̓���virtual��t����

	//EnemyBase�Ƃ���Enemy�𐶐����邱�Ƃ͂Ȃ�
	//�Ȃ̂�GetName()�͕K���㏑�����Ăق���
	//��΂ɏ㏑�����Ăق����֐��́u�������z�֐��v�ɂ���
	//�������z�֐��͊֐��̍Ō��= 0;�Ə���
	//virtual const char* GetName() { return "������"; }
	virtual const char* GetName() = 0;

protected:
	int m_hp = 0;  //����ȏ��������\
};

//�X���C��
class EnemySlime : public EnemyBase
{
public:
	EnemySlime(){}
	virtual ~EnemySlime() { cout << "Slime" << endl; }
	//�X���C�����p�����ăX���C���x�X�����\��������
	//�̂ňꉞvirtual�ɂ��Ă���
	virtual const char* GetName() override { return "�X���C��\n"; }
};

//�h���L�[
class EnemyDorakey : public EnemyBase
{
public:
	EnemyDorakey(){}
	virtual ~EnemyDorakey(){}
	virtual const char* GetName() override { return "�h���L�[\n"; }
};

//�h���S��
class EnemyDoragon : public EnemyBase
{
public:
	EnemyDoragon(){}
	virtual ~EnemyDoragon(){}
	virtual const char* GetName() override { return "�h���S��\n"; }
};
