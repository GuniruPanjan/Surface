#include<iostream>
#include <vector>
using namespace std;

//�I�u�W�F�N�g�w���̎O��v�f
//�@�J�v�Z����
//�A�p��
//�B�|�����[�t�B�Y��

//�Ȃ��J�v�Z��������̂��Ƃ�����
//1.�N���X�����̈��S�������߂邽��
//2.���p�ґ��ɑ΂��ĕ��S���y�����Ă���
//���J��������I�ɂ��ė��p���₷������

//�N���X(class)�ƍ\����(struct)�̈Ⴂ�͎��́A�f�t�H���g��private��public���̈Ⴂ�ł����Ȃ�

//class�̓f�t�H���g��private
//struct�̓f�t�H���g��public

//�p��->�e�q�֌W
//�q�͐e�̓������󂯌p���ł���B�q�͐e��is-a�̊֌W�ł���(is-a�͌p���֌W)

struct MonsterParameter
{
	int Life;
	int AttackPoint;
	int DefencePoint;
	void Clear()
	{
		Life = 0;
		AttackPoint = 0;
		DefencePoint = 0;
	}
private:
	int himitusu;
};

class Animal;

class Monster
{
	friend Animal;
private:
	//�O���Ɍ��J�������Ȃ��֐��iprivate�j
	//Monster���g�ł����Ăяo���Ȃ��֐�
	float DistanceToPlayer()
	{
		return 3.14f;
	}
public:
	//�O���Ɍ��J�������֐�(public)
	//Monster�̎����傪�Ăяo����֐�
	void Update()
	{
		cout << "�����X�^�[�X�V" << DistanceToPlayer() << endl;
	}
	virtual void Attack() = 0;

};

class Bat : public Monster
{
public:
	void Attack()
	{
		cout << "����" << endl;
	}
};

class Slime : public Monster
{
public:
	void Attack()
	{
		cout << "�n����" << endl;
	}
};

class Skeleton : public Monster
{
public:
	void Attack()
	{
		cout << "�؂�t��" << endl;
	}
};

class Doragon : public Monster
{
public:
	void Attack()
	{
		cout << "��" << endl;
	}
};

class WareWolf : public Monster
{
public:
	void Attack()
	{
		cout << "���݂�" << endl;
	}
};

class Animal
{
public:
	int GetAge() const
	{
		return age_;
	}

	virtual void Attack() = 0; //�������z�֐�

protected:
	int age_;
	Slime slime;
	
};
//�e�q�֌W�̎������Ӗ������J�v�Z���������Ƃ��āAprotected�Ƃ����̂�����܂�
//����́A�����̎q�N���X�ɂ͌��J���܂��A�Ƃ��������o�ɑ΂���
//�q�͐e��public������protected�����ɃA�N�Z�X�ł���
//�e��public�Ŏ�������Ă��郁���o�֐����͎q�Ŏ������Ȃ��Ă��q�̊֐��Ƃ��ČĂяo�������ł���
//�|�����[�t�B�Y���i���Ԑ��j
//���ʂ��Ă����Ă���֐����g��
//�p���̍l�����͉��Ɍ������āA�ǂ�ǂ�h�����Ă����Ƃ����l����������
//�|�����[�t�B�Y���̍l�����͋t�ɏ�Ɍ������Ăǂ�ǂ񒊏ۉ����Ă����Ƃ����l�����ł�
//�|�����[�t�B�Y���ɂ����̂Ȃ̂��Avirtual�w��q�ŁA�e�̊֐��̐擪�ɂ���

//�|�����[�t�B�Y���Ƃ́A�ꌾ�ł����ƁA��蒊�ۓI�ȊT�O�Ƃ��Ă܂Ƃ߂Ĉ�����悤�ɂ���d�g�݂ł�
//���������ɂ͐e�̊֐���virtual�����邱�ƂŁA���ۂ̓���͎q�Ɉϑ����邱�Ƃ��ł���
//virtual�@�߂�l�@�֐����i�j = 0;
//�Ƃ������Ɏ��������� = 0�Ə������ƂŁA�����͎������Ȃ��I�Ƃ�������񑩂ł���B���̊֐��̎����u�������z�֐��v�ƌ���
//�������������z�֐������N���X�͒P�̂ł͑��ݏo���܂���
//�p���Ƃ��āu�q�v�Ƃ��ăI�u�W�F�N�g�����Ȃ��Ƒ��݂ł��Ȃ�
//�܂��A�������z�֐��́u�q�ŕK���������Ȃ��Ƃ����܂���v�Ƃ������񂪐��܂�܂�

//C++�ł́Anew�œ��I�z����m�ۂ��邱�Ƃ��ł��܂����A�������₱�����ł�
//int* a= int[n];
//�œ��I�z������܂����A������������Ƃ���
//delete a;�ł͂��߂�delete[] a;�Ə����K�v������܂�
//��₱��������A�q�̎��Ƃł͓��I�z��͂��ׂ�vector���g��
//vector<int> a;�̏ꍇ�Adelete���Ȃ��Ă�����
class Dog : public Animal
{
public:
	Dog()
	{
		age_ = 2;
	}
	void Attack()
	{
		cout << "���݂�" << endl;
	}
};
class Cat : public Animal
{
public:
	Cat()
	{
		age_ = 3;
	}
	void Attack()
	{
		cout << "�Ђ�����" << endl;
	}
};
class Rabbit : public Animal
{
public:
	void Attack()
	{
		cout << "�҂��҂��" << endl;
	}
};


void RepeatAttack(Animal& animal, int rep)
{
	for (int i = 0; i < rep; i++)
	{
		animal.Attack();
	}
}

class A
{
	int a_;
	float b_;
	char* c_;
public:
	A() : a_(10),b_(3.14f),c_("HelloWorld")
	{

	}
	void OutPut()
	{
		cout << a_ << b_ << c_ << endl;
	}
};

int main()
{
	//�����R
	std::vector<Monster*> monsters;
	for (int i = 0; i < 10; i++)
	{
		monsters.push_back(new Slime());
		monsters.push_back(new Skeleton());
		monsters.push_back(new Doragon());
		monsters.push_back(new WareWolf());
	}

	//�����̖���
	for (auto monster : monsters)
	{
		monster->Attack();
	}
	

	Dog dog;
	Cat cat;
	//Animal animal; //�������z�֐��ɂȂ������Ƃő��݂�������Ȃ��Ȃ���
	Rabbit rabbit;

	cout << "dogage=" << dog.GetAge() << endl;
	cout << "catage=" << cat.GetAge() << endl;

	RepeatAttack(dog, 3);
	RepeatAttack(cat, 2);
	RepeatAttack(rabbit, 4);

	dog.Attack();
	cat.Attack();

	/*Monster monster;
	monster.Update();

	MonsterParameter mparameter;
	mparameter.Clear();*/

	int size = rand() % 10;
	int* a = new int[size];
	delete[] a;

	int* b = new int;
	delete b;

	std::vector<Monster*> monsters;
	monsters.push_back(new Slime());
	monsters.push_back(new Skeleton());
	monsters.push_back(new WareWolf());
	monsters.push_back(new Bat());
	monsters.push_back(new Doragon());


	return 0;
}
//�R�����g�̏�����
//�����Ƃ��āu�Ӑ}�v�������悤�ɂ���B
//�Ӑ}�Ƃ����̂́u�Ȃ�ł��̃R�[�h���������̂��v���킩��悤�ɂ���
//i++;//i���C���N�������g�~
//i++;//�z��̃C���f�b�N�X���������񂷂邽�߁Z

//���R�����g�ɉR�������Ȃ��悤�ɂ��Ă�������
//->�v���O�������A�b�v�f�[�g������A�R�����g���������Ă�������

//��{�I�ɂ̓R�����g�̏��������R�����A�N���X�錾����
//public�֐������́u�K���v�R�����g�����܂��傤
//�֐��̏��///�������ƁA�֐������̂���{�̂悤�Ȃ��̂���������
//����܂��̂ŁA����ɂ��������ăR�����g�������܂��傤

//��{�I��Windows��API�Ɋւ��ẮA�K���ŏI�I�ɂ�Microsoft�����̃��t�@�����X
//��ǂ݂܂��傤�B�Ԃ����Ⴏ����ł��B�Ӗ���������Ȃ��Ă�
//�����̂ŁA1��͖ڂ�ʂ��Ă����܂��傤�B�����

//������₷�����������Ă�T�C�g������