#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//列挙体
//定数をまとめて定義するのに便利
/*
#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define TRI 5
#define SAT 6
*/

typedef enum Week
{
	SUN,    //内部的には０
	MON,    //1
	TUE,    //2
	WED,
	THU,
	FRI,    //5
	SAT,    //6

	
}Week;

typedef enum Item
{
	ITEM_YAKUSOU,
	ITEM_DOKUKESISOU,
	ITEM_KAGI,
	ITEM_KAGAMI,
	ITEM_MANGETUSOU,

	ITEM_KIND
}Item;


int main(void)
{
	printf("ここは%d行目です\n", __LINE__);
	printf("コンパイル日は%sです\n", __DATE__);
	printf("コンパイル時間は%sです\n", __TIME__);

	/*
	Item item;
	item = ITEM_YAKUSOU;

	int price[ITEM_KIND] =
	{
		16,    //ITEM_YAKUSOU
		20,    //ITEM_DOKUKESISOU
		100,   //ITEM_KAGI
		1000,  //ITEM_KAGAMI
		40,    //ITem_MANGETUSOU
	};

	printf("全てのアイテムの値段を表示します\n");
	for (int i = 0; i < ITEM_KIND; i++)
	{
		printf("%d円\n", price[i]);
	}
	*/
	/*
	//int型：整数
	//float型：少数
	//char型：文字

	//列挙体Week:Weekで定義した定数が入る
	Week wk = SUN;
	wk = MON;

	switch (wk)
	{
	case SUN:
		printf("日曜日なので休みです\n");
		break;
	case MON:
		printf("月曜日なので仕事です\n");
		break;
	case TUE:
		printf("火曜日なので仕事です\n");
		break;
	case WED:
		printf("水曜日なので仕事です\n");
		break;
	case THU:
		printf("木曜日なので仕事です\n");
		break;
	case FRI:
		printf("金曜日なので仕事です\n");
		break;
	case SAT:
		printf("土曜日なので午前のみ仕事です\n");
		break;
	}
	*/
	

	return 0;
}