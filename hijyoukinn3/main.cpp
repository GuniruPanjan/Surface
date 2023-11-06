#include<iostream>
#include <vector>
using namespace std;

//オブジェクト指向の三大要素
//①カプセル化
//②継承
//③ポリモーフィズム

//なぜカプセル化するのかというと
//1.クラス内部の安全性を高めるため
//2.利用者側に対して負担を軽減している
//公開情報を限定的にして利用しやすくする

//クラス(class)と構造体(struct)の違いは実は、デフォルトがprivateかpublicかの違いでしかない

//classはデフォルトがprivate
//structはデフォルトがpublic

//継承->親子関係
//子は親の特徴を受け継いでいる。子は親とis-aの関係である(is-aは継承関係)

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
	//外部に公開したくない関数（private）
	//Monster自身でしか呼び出せない関数
	float DistanceToPlayer()
	{
		return 3.14f;
	}
public:
	//外部に公開したい関数(public)
	//Monsterの持ち主が呼び出せる関数
	void Update()
	{
		cout << "モンスター更新" << DistanceToPlayer() << endl;
	}
	virtual void Attack() = 0;

};

class Bat : public Monster
{
public:
	void Attack()
	{
		cout << "鳴き声" << endl;
	}
};

class Slime : public Monster
{
public:
	void Attack()
	{
		cout << "溶かす" << endl;
	}
};

class Skeleton : public Monster
{
public:
	void Attack()
	{
		cout << "切り付け" << endl;
	}
};

class Doragon : public Monster
{
public:
	void Attack()
	{
		cout << "炎" << endl;
	}
};

class WareWolf : public Monster
{
public:
	void Attack()
	{
		cout << "噛みつき" << endl;
	}
};

class Animal
{
public:
	int GetAge() const
	{
		return age_;
	}

	virtual void Attack() = 0; //純粋仮想関数

protected:
	int age_;
	Slime slime;
	
};
//親子関係の時だけ意味を持つカプセル化属性として、protectedというのがあります
//これは、自分の子クラスには公開します、というメンバに対して
//子は親のpublic属性とprotected属性にアクセスできる
//親にpublicで実装されているメンバ関数ｋは子で実装しなくても子の関数として呼び出す事ができる
//ポリモーフィズム（多態性）
//共通してもっている関数を使う
//継承の考え方は下に向かって、どんどん派生していくという考え方だった
//ポリモーフィズムの考え方は逆に上に向かってどんどん抽象化していくという考え方です
//ポリモーフィズムにつきものなのが、virtual指定子で、親の関数の先頭につける

//ポリモーフィズムとは、一言でいうと、より抽象的な概念としてまとめて扱えるようにする仕組みです
//それをするには親の関数にvirtualをつけることで、実際の動作は子に委託することができる
//virtual　戻り値　関数名（） = 0;
//という風に実装をせず = 0と書くことで、自分は実装しない！という事を約束できる。この関数の事を「純粋仮想関数」と言う
//ただし純粋仮想関数を持つクラスは単体では存在出来ません
//継承として「子」としてオブジェクト化しないと存在できない
//また、純粋仮想関数は「子で必ず実装しないといけません」という制約が生まれます

//C++では、newで動的配列を確保することもできますが、解放がややこしいです
//int* a= int[n];
//で動的配列を作れますが、これを解放するときは
//delete a;ではだめでdelete[] a;と書く必要があります
//ややこしいから、子の授業では動的配列はすべてvectorを使う
//vector<int> a;の場合、deleteしなくてもいい
class Dog : public Animal
{
public:
	Dog()
	{
		age_ = 2;
	}
	void Attack()
	{
		cout << "噛みつき" << endl;
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
		cout << "ひっかき" << endl;
	}
};
class Rabbit : public Animal
{
public:
	void Attack()
	{
		cout << "ぴょんぴょん" << endl;
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
	//魔王軍
	std::vector<Monster*> monsters;
	for (int i = 0; i < 10; i++)
	{
		monsters.push_back(new Slime());
		monsters.push_back(new Skeleton());
		monsters.push_back(new Doragon());
		monsters.push_back(new WareWolf());
	}

	//魔王の命令
	for (auto monster : monsters)
	{
		monster->Attack();
	}
	

	Dog dog;
	Cat cat;
	//Animal animal; //純粋仮想関数になったことで存在を許されなくなった
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
//コメントの書き方
//原則として「意図」を書くようにする。
//意図というのは「なんでそのコードを書いたのか」がわかるようにする
//i++;//iをインクリメント×
//i++;//配列のインデックスを順次巡回するため〇

//★コメントに嘘を書かないようにしてください
//->プログラムがアップデートしたら、コメントも見直してください

//基本的にはコメントの書き方自由だが、クラス宣言側の
//public関数だけは「必ず」コメントを入れましょう
//関数の上で///を書くと、関数説明のお手本のようなものが自動生成
//されますので、それにしたがってコメントを書きましょう

//基本的にWindowsのAPIに関しては、必ず最終的にはMicrosoft公式のリファレンス
//を読みましょう。ぶっちゃけ難しいです。意味が分からなくても
//いいので、1回は目を通しておきましょう。慣れろ

//分かりやすい説明をしてるサイトも多い