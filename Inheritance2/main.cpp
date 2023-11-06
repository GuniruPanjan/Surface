#include<iostream>
#include "Class.h"
using namespace std;

namespace
{
	//��x�ɓo�ꂷ��G�̍ő吔
	constexpr int kEnemyMax = 8;
}

//�h���S���N�G�X�g�퓬��ʂ̎���������������
int main()
{
	cout << "�p�������p����" << endl;

	EnemySlime slime;
	cout << slime.GetName() << endl;
	cout << slime.EnemyBase::GetName() << endl;

	//EnemyBase�ɂ͂ǂ̓G�ł�����鎖���ł���̂�
	//��x�ɓo�ꂷ��ő吔�������Ă�����OK
	EnemyBase* pEnemy[kEnemyMax];
	for (int i = 0; i < kEnemyMax; i++)
	{
		pEnemy[i] = nullptr;
	}

	//�o�Ă���G�̃������m��
	pEnemy[0] = new EnemySlime;
	pEnemy[1] = new EnemyDorakey;
	pEnemy[2] = new EnemyDoragon;

	for (int i = 0; i < kEnemyMax; i++)
	{
		//pEnemy[i] == nullptr�̏ꍇ�A�ȍ~�̏������s�킸���̃��[�v��
		if (!pEnemy[i])continue;

		cout << pEnemy[i]->GetName() << "�������ꂽ�I" << endl;

		
	}

	//�m�ۂ����G�̃��������
	for (int i = 0; i < kEnemyMax; i++)
	{
		if (pEnemy[i])
		{
			delete pEnemy[i];
			pEnemy[i] = nullptr;
		}
	}
}



#if false
//�p�������p���ā��̂������ƃX�}�[�g�ɏ���
int main()
{
	cout << "�p�������p����" << endl;

	//EnemySlime�^�̃|�C���^�ɂ�EnemySlime���A
	//EnemyDorakey�^�̃|�C���^�ɂ�EnemyDorakey�����Ă����i�ق������l�j
	//�|�C���^�̌^�Ƃ��̎w��������̃f�[�^�^�͈�v���Ă��Ȃ������Ȃ�

	//�p�����s���ăN���X���쐬�����ꍇ�A
	//���N���X�̃|�C���^�Ɍp����̃|�C���^���i�[���邱�Ƃ��ł���

	//EnemyBase* pEnemy = new EnemyBase; //���܂ŁF�|�C���^�Ǝ��ۂɊm�ۂ���f�[�^�^��v
	EnemyBase* pEnemy = new EnemySlime;  //���N���X�̃|�C���^�ɂ��̌p����̃|�C���^���i�[

	delete pEnemy;
	pEnemy = nullptr;

	return 0;
}
#endif


#if false
int main()
{
	cout << "�p���𗘗p����" << endl;

	/*EnemySlime* pSlime[8];
	for (int s = 0; s < 8; s++)
	{
		pSlime[s] = new EnemySlime;
	}
	EnemyDorakey* pDorakey[8];
	for (int d = 0; d < 8; d++)
	{
		pDorakey[d] = new EnemyDorakey;
	}
	EnemyDoragon* pDoragon[3];
	for (int d = 0; d < 3; d++)
	{
		pDoragon[d] = new EnemyDoragon;
	}*/
	EnemySlime* pSlime[8];
	EnemyDorakey* pDorakey[8];
	EnemyDoragon* pDoragon[3];
	//�����X�^�[�̎�ނ��������
	//�������̊m�ۂ͌��ꂽ�����X�^�[�̕��݂̂���΂悢��
	//�|�C���^�[�̓����X�^�[�̎��*��x�Ɍ���鐔�������Ȃ��Ƃ����Ȃ��H

	//�����X�^�[�����ꂼ��1�̂������
	pSlime[0] = new EnemySlime;
	pDorakey[0] = new EnemyDorakey;
	pDoragon[0] = new EnemyDoragon;


	cout << pSlime[0]->GetName() << "�������ꂽ�I" << endl;
	cout << pDorakey[0]->GetName() << "�������ꂽ�I" << endl;
	cout << pDoragon[0]->GetName() << "�������ꂽ�I" << endl;

	return 0;
}
#endif