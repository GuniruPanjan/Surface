#include<stdio.h>
#include<stdlib.h>  //rand()を使うのに必要
#include<time.h>

//敵の数を定数として定義
#define ENEMY_NUM 5

//敵のHPの最大値、最小値をマクロで定義し、
// その範囲のHPが生成されるようにプログラムを書き換えてください

//配列、for文での配列の利用、
//#defineマクロを利用した配列サイズの指定についておさらい
int main(void)
{
	//複数体の敵のHPをランダムに生成して表示する
	srand((unsigned int)time(NULL));

	int enemyHP[ENEMY_NUM];
	int g;

	//ランダムのHPを設定する
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//HPは50以上100以下
		enemyHP[i] = rand();
		g = enemyHP[i] % 130;

	}

	//設定したHPを表示する
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d体目：%d\n", i + 1, g);
	}

	return 0;
}





/*


//defineマクロを使用する
//プリプロセッサ→コンパイルの前に文字列を置き換えてくれる
//...と今は覚えておこう

//defineマクロ　→文字列の置き換えルールを指定することができる
//指定した文字をさらに指定した文字に変換する

//書き方
//#define置き換え元の文字列置き換え先の文字列
//コンパイルする前にAをBに書き換えてくれる
#define ENEMY_NUM 5

//#define DEFAULT_HP50
//↑のマクロを定義した場合、
//int playerHP = DEFAULT_HP;    こう書いておくと...
//int PlayerHP = 50;      コンパイル前にDEFAULT_HPを50に置き換えてくれる

//↑が厳密な#defineの意味だが、
//実際に利用するときは
//「定数」を定義する時によく利用する

//defineマクロの置き換え前の文字列は
//・全て大文字
//・単語と単語の間を_（アンダースコア）でつなぐ
//というルールになっているのが一般的


//for文と配列の組み合せ
int main(void)
{
	//敵のHPデータを格納するための配列
	int enemyHP[ENEMY_NUM];

	printf("敵のHPの値を入力してください\n");
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d体目の敵のHPはいくつですか？\n", i + 1);
		//キーボードから値を入力する
		scanf_s("%d", &enemyHP[i]);

	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d体目の敵のHPは%dです\n", i + 1, enemyHP[i]);
	}

	return 0;
}
*/



/*
//配列の各要素を参照してprintfで表示する
//for文を利用して配列の中身を簡単に記述する
int main(void)
{
	//配列を宣言して初期化して値を入れる
	int enemyHP[5] = { 100, 200, 300 };

	//printf("一番目の敵のHPは%dです\n", enemyHP[0]);
	//printf("ニ番目の敵のHPは%dです\n", enemyHP[1]);
	//printf("三番目の敵のHPは%dです\n", enemyHP[2]);
	//printf("四番目の敵のHPは%dです\n", enemyHP[3]);
	//printf("五番目の敵のHPは%dです\n", enemyHP[4]);

	//for文を用いた形に書き換える↓

	//5体分のHPを表示したいので5回繰り返し処理を行う
	for (int i = 0; i < 5; i++)
	{
		//iの値と終了条件に注目する
		//終了条件i < 5     5の部分配列の要素数と同じ
		// iの値
		//1週目:    i = 0;
		//2週目:    i = 1;
		//3週目:    i = 2;
		//4週目:    i = 3;
		//5週目:    i = 4;

		printf("%d番目の敵のHPは%dです\n", i + 1, enemyHP[i]);
	}
	//for文の中で実際に何が行われるか詳しく見てみる
	{
		int i = 0;  //文の初期化処理が行われる
		//////////////////////////////////
		// if(i < 5)を満たしていれば繰り返し処理が行われる
		//i = 0の状態で繰り返し処理が行われる
		printf("%d番目の敵のHPは%dです\n", i + 1, enemyHP[i]);

		//繰り返し処理のあとの処理を行う
		i++;  //iは0 + 1なので1
		//////////////////////////////////
		// if(i < 5)を満たしていれば繰り返し処理が行われる
		//i = 1の状態で繰り返し処理が行われる
		printf("%d番目の敵のHPは%dです\n", i + 1, enemyHP[i]);

		//繰り返し処理のあとの処理を行う
		i++;  //iは1 + 1なので2
		//////////////////////////////////

		//...中略

		//繰り返し処理のあとの処理を行う
		i++;  //iは4 + 1なので5
		//////////////////////////////////
		
	}


	//通常の変数（配列ではない変数）の場合
	int playerHP = 500;
	printf("プレイヤーのHPは%dです\n", playerHP);

	return 0;
}
*/





/*
//配列を宣言してそこに値を入れる
//配列の要素を指定して値を入れる
//初期化子を利用して初期化と同時に値を入れる
int main(void)
{
	//敵キャラクター100体分のHPを管理したい
	//配列を使う

	//型名　配列名[要素数];
	int enemyhp[100] = [100, 120, 240];
	//enemyhp[0] = 100;
	//enemyhp[1] = 120;
	//enemyhp[2] = 240;
	//enemyhp[3];
	//enemyhp[4];

	//配列の宣言と同時に初期化を行う場合は要素数省略できる
	//省略した場合は初期化子の数分の要素が用意される
	int enemyMP[] = [20, 0, 80];         //初期化子3つなので要素数は3になる
	//int enemyAttack[];     要素数を指定してないのでエラー
	
	//配列の要素数と初期化子の数が違う場合の挙動
	
	// 左辺の方が要素数が多い場合　左辺5に対して右辺3
	// enemyAttck[3],enemyAttack[4]には0が入る
	int enemyAttck[5] = { 10, 20, 30 };

	//右辺のほうが要素数が多い場合左辺2に対して右辺3
	// コンパルエラービルドが通らない
	// int enemySpeed[2] = {100, 200, 300};    エラー
	
	//ng例 1つの配列に多くの種類のデータを入れない
	// 下記例では、HP、攻撃力、防御力を1つの配列に入れている
	int enemyData[9];
	enemyData[0] = 100;     //一体目の敵のHP
	enemyData[1] = 200;     //二体目の敵のHP
	enemyData[2] = 300;     //三体目の敵のHP

	enemyData[3] = 10;      //一体目の敵の攻撃力
	enemyData[4] = 20;      //ニ体目の敵の攻撃力
	enemyData[5] = 30;

	enemyData[6] = 10;      //一体目の敵の防御力
	enemyData[7] = 20;
	enemyData[8] = 30;
	//通常の変数
	int playerHP = 20;    //宣言と同時に初期化
	playerHP = 3;
	

	return 0;
}
*/