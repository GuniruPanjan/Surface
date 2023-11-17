#include<iostream>
#include "Class.h"
using namespace std;

namespace
{
	//一度に登場する敵の最大数
	constexpr int kEnemyMax = 8;
}

//ドラゴンクエスト戦闘画面の実装を書き換える
int main()
{
	cout << "継承を活用する" << endl;

	EnemySlime slime;
	cout << slime.GetName() << endl;
	cout << slime.EnemyBase::GetName() << endl;

	//EnemyBaseにはどの敵でも入れる事ができるので
	//一度に登場する最大数準備しておけばOK
	EnemyBase* pEnemy[kEnemyMax];
	for (int i = 0; i < kEnemyMax; i++)
	{
		pEnemy[i] = nullptr;
	}

	//出てくる敵のメモリ確保
	pEnemy[0] = new EnemySlime;
	pEnemy[1] = new EnemyDorakey;
	pEnemy[2] = new EnemyDoragon;

	for (int i = 0; i < kEnemyMax; i++)
	{
		//pEnemy[i] == nullptrの場合、以降の処理を行わず次のループへ
		if (!pEnemy[i])continue;

		cout << pEnemy[i]->GetName() << "があらわれた！" << endl;

		
	}

	//確保した敵のメモリ解放
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
//継承を活用して↓のをもっとスマートに書く
int main()
{
	cout << "継承を活用する" << endl;

	//EnemySlime型のポインタにはEnemySlimeを、
	//EnemyDorakey型のポインタにはEnemyDorakeyを入れていた（ほかも同様）
	//ポインタの型とその指し示す先のデータ型は一致していないいけない

	//継承を行ってクラスを作成した場合、
	//基底クラスのポインタに継承先のポインタを格納することができる

	//EnemyBase* pEnemy = new EnemyBase; //今まで：ポインタと実際に確保するデータ型一致
	EnemyBase* pEnemy = new EnemySlime;  //基底クラスのポインタにその継承先のポインタを格納

	delete pEnemy;
	pEnemy = nullptr;

	return 0;
}
#endif


#if false
int main()
{
	cout << "継承を利用する" << endl;

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
	//モンスターの種類が増えると
	//メモリの確保は現れたモンスターの分のみすればよいが
	//ポインターはモンスターの種類*一度に現れる数準備しないといけない？

	//モンスターがそれぞれ1体ずつ現れる
	pSlime[0] = new EnemySlime;
	pDorakey[0] = new EnemyDorakey;
	pDoragon[0] = new EnemyDoragon;


	cout << pSlime[0]->GetName() << "があらわれた！" << endl;
	cout << pDorakey[0]->GetName() << "があらわれた！" << endl;
	cout << pDoragon[0]->GetName() << "があらわれた！" << endl;

	return 0;
}
#endif