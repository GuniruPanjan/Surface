#pragma once
#include<iostream>
using namespace std;

//モンスターの基底クラス
class EnemyBase
{
public:
	EnemyBase(){}
	virtual ~EnemyBase() { cout << "Base" << endl; }

	//上書き(Override)したい関数の頭にvirtualを付ける

	//EnemyBaseというEnemyを生成することはない
	//なのでGetName()は必ず上書きしてほしい
	//絶対に上書きしてほしい関数は「純粋仮想関数」にする
	//純粋仮想関数は関数の最後に= 0;と書く
	//virtual const char* GetName() { return "名無し"; }
	virtual const char* GetName() = 0;

protected:
	int m_hp = 0;  //こんな初期化も可能
};

//スライム
class EnemySlime : public EnemyBase
{
public:
	EnemySlime(){}
	virtual ~EnemySlime() { cout << "Slime" << endl; }
	//スライムを継承してスライムベスを作る可能性がある
	//ので一応virtualにしておく
	virtual const char* GetName() override { return "スライム\n"; }
};

//ドラキー
class EnemyDorakey : public EnemyBase
{
public:
	EnemyDorakey(){}
	virtual ~EnemyDorakey(){}
	virtual const char* GetName() override { return "ドラキー\n"; }
};

//ドラゴン
class EnemyDoragon : public EnemyBase
{
public:
	EnemyDoragon(){}
	virtual ~EnemyDoragon(){}
	virtual const char* GetName() override { return "ドラゴン\n"; }
};
