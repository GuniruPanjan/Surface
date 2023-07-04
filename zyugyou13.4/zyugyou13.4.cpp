#include<iostream>
using namespace std;

//じゃんけんでプレイヤーが勝っているか判定する
//勝っていたらtrue,勝っていない（負け、引き分け）false
//bool型を返す関数の関数名 is XXXX
//isで始まる関数はbool型(true or false)を返すと関数名を見るだけで分かる
bool getWin(int player, int enemy)
{
	if (true)    //必ず勝つ
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	  //cout << "やあ、こんにちは。" << endl;

	cout << "2 + 2 = " << 2 + 2 << endl;
	cout << "1 - 5 = " << 1 - 5 << endl;
	cout << "2 * 9 = " << 2 * 9 << endl;
	cout << "9 / 3 = " << 9 / 3 << endl;
	cout << "9 / 2 = " << 9 / 2 << endl;

	//bool型：trueかfalseどちらかが入る
	//変数名もbool型の場合、頭にisを付ける事が多い
	//ポインタの場合pXXXと付けたように
	//isもこの変数がbool型だと分かるようにisをつける

	//int,float,char

	//bool型：trueかfalseのどちらかが入る
	bool flag;
	flag = true;       //flagにtrue（真）を代入
	flag = false;      //flagにfalse（偽）を代入

	//true:0以外
	//false:0

	if (flag)
	{
		//flag = trueの場合の処理
	}
	else
	{
		//flag = falseの場合の処理
	}





	return 0;
}