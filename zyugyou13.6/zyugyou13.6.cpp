#include<iostream>
using namespace std;

//引数無し
void printMsg(void)
{
	cout << "キサマヲムッコロス" << endl;
}
/* NG戻り値が違うだけの同名関数は作成できない
void printMsg(void)
{
	cout << "キサマヲムッコロス:" << endl;
}
*/
//引数の数が違えば同じ関数名の関数を作成できる
//void prinatMsg(int metal)      //引数を省略した場合、引数無しと見分けがつかないのでNG
void prinatMsg(int num, int metal = 50)
{
	cout << "待たせたな:" << metal << endl;
}

/*void prinatMsg(int num)   //引数２つ＆２つめがデフォルト引数、と見分けがつかないのでNG
{
	cout << "num:" << num << endl;
}
*/

//C++では関数の引数にデフォルトの値を設定できる
struct Player
{
	int hp;
	int mp;

};
//仮引数の後に = 50のように省略した場合に設定される数値を指定できる
//これをデフォルト引数
//デフォルト引数が設定されている場合、引数を省略する事ができる
//省略した場合、仮引数には設定した値が入る
void initPlayer(Player& player, int hp = 100, int mp = 50)
{
	player.hp = hp;
	player.mp = mp;
}

	
	



int main()
{

	printMsg();
	printMsg(10);
	printMsg(10, 50);

#if false
	Player player;
	initPlayer(player);

	//キャラクター選択可能
	//100種類以上のキャラクターがいる
	//1体は体力自慢　　　HP200, MP0
	//1体は魔法使い　　　HP50, MP100
	//それ以外の98体は HP100, MP50

	cout << "HP:" << player.hp << endl;
	cout << "MP:" << player.mp << endl;

#endif



	return 0;
}