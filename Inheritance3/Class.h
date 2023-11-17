#pragma once
#include<iostream>
using namespace std;

//継承元となるクラス　基底クラス
//基底クラスのクラス名は~~Baseのような名前をつけられる事が多い
class EnemyBase
{
public:
	EnemyBase() :
		m_hp(0)
	{}
	//必ずデストラクタにはvirtualを付ける
	virtual ~EnemyBase(){}


	//virtualを付ける事で仮想関数にする
	//継承先に同じ名前、同じ引数の関数がある場合
	//その関数で上書きされる
	virtual void Attack() = 0; //=0で純粋仮想関数に
	//{　　　　　　　　　　　　//継承して　
	//	cout << "モンスターの攻撃" << endl;
	//}
	void DispHp()
	{
		cout << "HP:" << endl;
	}
private:
	int m_hp;
};

//EnemyBaseを継承して敵のクラスを作っていく
class EnemySlime : public EnemyBase
{
public:
	EnemySlime(){}
	virtual ~EnemySlime(){}

	virtual void Attack() override
	{
		cout << "体当たり" << endl;
	}

	//DispHpはすべてのモンスターで共通の処理なので
	//EnemyBaseに任せる（同じ関数を何度も書かない）
};

//EnemySlimeを継承してEnemyMetalSlimeを作る
class EnemyMetalSlime : public EnemySlime
{
public:
	EnemyMetalSlime(){}
	virtual ~EnemyMetalSlime(){}

	virtual void Attack() override
	{
		cout << "メラ" << endl;
	}
};