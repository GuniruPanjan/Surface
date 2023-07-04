#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*〇×ゲームの作成*/
int main(void)
{
	int i;
	int player;
	int enemy;
	int MB;
	int a[3] = { 0, 1, 2 };
	int b[3] = { 3, 4, 5 };
	int c[3] = { 6, 7, 8 };

	printf("〇×ゲーム\n数字の場所に同じ数字を打ち込む\nプレイヤーは：〇\nコンピューターは：×\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d , ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d , ", b[i]);
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d , ", c[i]);
	}
	printf("\n");

	int field[5][5] =
	{
		{3,3,3,3,3},
		{3,0,0,0,3},
		{3,0,0,0,3},
		{3,0,0,0,3},
		{3,3,3,3,3},
	};
	for (int j = 0; j < 5; j++)
	{
		for (int h = 0; h < 5; h++)
		{
			switch (field[5][5])
			{
			    case 0: printf("　");     break;
				case 3: printf("□");    break;
			}
		}
		printf("\n");
	}

	scanf_s("%d", &player);




}


/*復習問題
int main(void)
{
	int i;
	int tmp;       //一時的にデータを保存する（tmp)
	int a[5] = { 0, 1, 2, 3, 4 };
	int b[5] = { 5, 6, 7, 8, 9 };

	for (i = 0; i < 5; i++)
	{
		tmp = a[i];

		a[i] = b[i];

		b[i] = tmp;
	}





	//a[]の中身を表示する　5,6,7,8,9が表示されればOK
	for (i = 0; i < 5; i++)
	{
		printf("a[%d]の値は%dです\n", i, a[i]);
	}

	//b[]の中身を表示する　0,1,2,3,4が表示されればOK
	for (i = 0; i < 5; i++)
	{
		printf("b[%d]の値は%dです\n", i, b[i]);
	}
	return 0;
}
*/



/*
int main(void)
{
	//一次元配列の宣言
	//int tbl[4] = {0, 1, 2, 3};

	//二次元配列の宣言
//型名　配列名[要素数][要素数]
	int tbl[3][4] = { {1, 2, 3, 4}, 
		              {5, 6, 7, 8}, 
		              {9, 10, 11, 12} };

	//tbl[0][0] = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
		printf("%d", tbl[i][j]);
		}
		printf("\n");

	}

	//2次元配列よりも大きな次元の配列（3次元、4次元）
	// を書く必要がある場合はプログラムの設計が悪い可能性が高い！
	// ↓
	// 簡単に言うと3次元以上の配列は書かない方がいい
	//int tbl[3][4][5][6][7];    //5次元配列の宣言

	return 0;
}
*/


/*
#include<stdio.h>
#include<stdlib.h>       //rand()を使うのに必要
#include<time.h>

//敵の数を定数として定義
#define ENEMY_NUM 10

//敵のHPの最小値、最大値をマクロで定義し、
//その範囲のHPが生成されるようにプログラムで定義し、
#define ENEMY_HP_MIN    50
#define ENEMY_HP_MAX    100

//定数を使用して定数を定義する
#define ENEMY_HP_RAND_RANGE (ENEMY_HP_MAX - ENEMY_HP_MIN + 1)

#define ENEMY_HP_RAND_RANGE 51

//ソースをパッと見ても何をやっているかわかりづらかったのでいい感じの関数名をつけておくと分かりやすい
int createRandomHp()
{
	return ENEMY_HP_MIN + rand() % ENEMY_HP_RAND_RANGE;
	//return ENEMY_HP_MIN + rand() % (ENEMY_HP_MAX - ENEMY_HP_MIN + 1)
}

//配列、for文での配列の利用、
//#defineマクロを利用した配列サイズの指定についておさらい
int main(void)
{
	//敵複数体のHPをランダムに生成して表示する
	srand((unsigned int)time(NULL));

	//配列で複数体分のHP用変数を準備する
	int enemyHp[ENEMY_NUM];

	//ランダムにHPを設定する
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//HPは50～100
		//50～100のランダムの範囲は？
		//0～2の範囲を生成、は以前やったそれを参考に
		//enemyHp[i] = 50;        //50で固定
		//enemyHp[i] = rand() % 101;    //0～100の範囲
		enemyHp[i] = 50 + rand() % 51;    //50 + (0～50)
	}

	//設定したHPを表示する
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d体目：%d\n", i + 1, enemyHp[i]);
	}
}
*/