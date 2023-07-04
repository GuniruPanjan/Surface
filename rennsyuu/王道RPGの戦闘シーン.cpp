//[1]ヘッダーをインクルードする場所

#include<stdio.h> //[1-1]標準入出力ヘッダーをインクルードする
#include<conio.h> //[1-5]コンソール入出力ヘッダーをインクルードする

//[2]定数を定義する場所

//[3]列挙定数を定義する場所



//[3-1]モンスターの種類を定義する
enum
{
	MONSTER_PLAYER,  //[3-1-1]プレイヤー
	MONSTER_MAX      //[3-1-4]モンスターの種類の数
};

//[3-2]キャラクターの種類を定義する
enum
{
	CHARACTER_PLAYER,    //[3-2-1]プレイヤー
	CHARACTER_MONSTER,   //[3-2-2]モンスター
	CHARACTER_MAX        //[3-2-3]キャラクターの種類の数
};

//[4]構造体を宣言する場所

//[4-1]キャラクターの構造体を宣言する
typedef struct
{
	int hp;        //[4-1-1]HP
	int maxhp;     //[4-1-2]最大HP
	int mp;        //[4-1-3]MP
	int maxmp;     //[4-1-4]最大MP
	char name[4 * 2 + 1];   //[4-1-6]名前
}CHARACTER;

//[5]変数を宣言する場所

//[5-1]モンスターのステータスの配列を宣言する
CHARACTER monsters[MONSTER_MAX] =
{
	//[5-1-1]MONSTER_PLAYER     プレイヤー
	{
		15,      //[5-1-2]int hp        HP
		15,      //[5-1-3]int maxhp     最大HP
		15,      //[5-1-4]int mp        MP
		15,      //[5-1-5]int maxmp     最大MP
		"勇者",  //[5-1-7]char name[4 * 2 + 1] 名前
	},
};

//[5-2]キャラクターの配列を宣言する
CHARACTER characters[CHARACTER_MAX];

//[6]関数を宣言する場所

//[6-1]ゲームを初期化する関数を宣言する
void Init()
{
	//[6-1-1]プレイヤーのステータスを初期化する
	characters[CHARACTER_PLAYER] = monsters[MONSTER_PLAYER];
}

//[6-2]戦闘シーンの画面を描画する関数を宣言する
void DrawBattleScreen()
{
	//[6-2-2]プレイヤーの名前を表示する
	printf("%s\n", characters[CHARACTER_PLAYER], name);
}


//[6-4]戦闘シーンの関数を宣言する
void Battle()
{
	//[6-4-4]戦闘シーンの画面を描画する関数を呼び出す
	DrawBattleScreen();

	//[6-4-6]キーボード入力を待つ
	_getch();

}


//[6-6]プログラムの実行開始を宣言する

int main()
{
	//[6-6-2]ゲームを初期化する関数を呼び出す
	Init();

	//[6-6-3]戦闘シーンの関数を呼び出す
	Battle();

}