#include<iostream>
#include"Class.h"
using namespace std;

namespace
{
	constexpr int kEnemyNum = 8;
}


int main()
{
	cout << "継承の復習" << endl;

	//基底クラスのポインタに
	//継承先のクラスのアドレスを入れることができる
	EnemyBase* pEnemy[kEnemyNum];

	for (int i = 0; i < kEnemyNum; i++)
	{
		//ランダムにスライムかメタルスライムを登録
		if (rand() % 2)
		{
			pEnemy[i] = new EnemySlime;
		}
		else
		{
			pEnemy[i] = new EnemyMetalSlime;
		}
	}
	//どの敵が入っていようとAttackのみでOK
	for (int i = 0; i < kEnemyNum; i++)
	{
		pEnemy[i]->Attack();
	}

	//Slime,MetalSlimeのどちらが入っていても
	//deleteのみでOK
	for (int i = 0; i < kEnemyNum; i++)
	{
		delete pEnemy[i];
	}

	/*pEnemy->Attack();
	pEnemy->DispHp();

	delete pEnemy;*/

	return 0;
}