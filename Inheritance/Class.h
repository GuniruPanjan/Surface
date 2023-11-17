#pragma once
#include<iostream>
using namespace std;

//継承とはあるクラス
//あるクラスを基に新しいクラスを作ることができる
//これを継承という

//今回はClassBaseを基に新しいクラスを作成する
//基になるクラスを事を基底クラスと呼ぶ
class ClassBase
{
public:
	ClassBase(int num = 0);

	ClassBase(int num):
		m_num(num)
	{
		cout << "ClassBaseのコンストラクタ" << m_num << endl;
	}

	~ClassBase()
	{
		cout << "ClassBaseのデストラクタ" << m_num << endl;
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

	//privateなメンバークラス外から参照できない
	//それは継承先のクラスでも同様
	//継承クラスが基底クラスの持つ変数を変更したい場合はよくある
private:
	//位置情報や攻撃力など、基底クラスに持たせて
	//継承先でも変更を行いたい変数はいくらでもある

	//そういう場合はprotectedで宣言する
	//protectedな変数、関数はクラス外からは見えないが
	//継承先のクラスからは観ることができる
protected:
	void ProtectedFunc()
	{
		cout << "protectedな関数" << endl;
	}
	int m_num;

};

//ClassBaseを基に新しいクラスを作成する
//ClassBaseを継承して新しいクラスを作成する

//クラスの宣言時に継承元になるクラスを指定する必要がある
class ClassChild0 : public ClassBase
{
public:
	ClassChild0()
	{
		//基底クラスのコンストラクタを明示的に呼ばない場合
		//継承先のクラスのコンストラクタ呼び出し前に
		//引数無しの継承元ｋコンストラクタが呼び出される
		cout << "ClassChild0のコンストラクタ" << endl;
	}
	ClassChild0(int num):
		ClassBase(num) //継承元クラスのコンストラクタをみ明示的に呼ぶ
	{
		cout << "ClassChild0の引数付きコンストラクタ" << endl;
	}
	~ClassChild0()
	{
		cout << "ClassChild0のデストラクタ" << endl;
	}

	void Func0()
	{
		cout << "ClassChild1の特殊なFunc0" << endl;
		m_num = 999;
		ProtectedFunc();
	}
};
