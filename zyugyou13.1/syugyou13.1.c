#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TEST_NUM   5

//列挙体の復習
//一連のデータ（曜日など）をまとめて定数として定義するのに仕様する
//今回の例RPGのアイテム
//色々な種類があるが、
//回復アイテム、ダメージ、状態異常の回復、イベント、等のカテゴリに分けられる
typedef enum ItemType
{
	ITEM_TYPE_HEAL,       //回復アイテム           0

	ITEM_TYPE_DAMAGE,     //ダメージアイテム       1

	ITEM_TYPE_POWERUP,      //ステータスアップアイテムを追加    2

	ITEM_TYPE_RECOVER,    //状態異常の回復         2->3

	ITEM_TYPE_EVENT,      //イベントアイテム       3->4

	ITEM_TYPE_OTHER,      //特殊アイテム　アイテム毎の専用処理が必要  5

	ITEM_TYPE_NUM,        //アイテムのタイプの数　6
	                      //最後に定義しておけば
						  //アイテムタイプの種類が増えてもそれにあをせてこの中の値も変化する

}ItemType;

int main(void)
{
	printf("ソースコードのファイル名%s\n", __FILE__);
	printf("このprintfは%d行目に書かれている\n", __LINE__);

	printf("コンパイルを行った日:%s\n", __DATE__);
	printf("コンパイルを行った時間:%s\n", __TIME__);
	//int型:整数
	//float型:少数
	//chat型:半角1文字

	//ItemType型:enumで定義された値のうち、いずれかが入る

	ItemType item;
	item = ITEM_TYPE_HEAL;
	item = ITEM_TYPE_EVENT;
//	item = 16;   //ItemType,実はintなので入れる事はできるがよくない

	printf("enumが実は数字であることを確認\n");
	printf("ITEM_TYPE_RECOVER = %d\n", ITEM_TYPE_RECOVER);

	int tbl[ITEM_TYPE_NUM];

	for (int i = 0; i < ITEM_TYPE_NUM; i++)
	{
		switch (i)
		{
		case ITEM_TYPE_HEAL: //数字だと分かりずらい
			printf("HPを10回復\n");
			break;

		case ITEM_TYPE_DAMAGE:
			printf("敵に10ダメージ\n");
			break;

		case ITEM_TYPE_POWERUP:
			printf("最大HPが3上がった\n");
			break;

		case ITEM_TYPE_RECOVER:   //修正に対応しずらい
			printf("毒を回復\n");
			break;

		case ITEM_TYPE_EVENT:
			printf("使っても何も起こらない\n");
			break;
		case ITEM_TYPE_OTHER:
			printf("アイテムによっておこる効果が変わる\n");
			break;
		}
	}

	return 0;
}