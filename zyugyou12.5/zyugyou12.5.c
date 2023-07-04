#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//定数を定義する
#define TAX 0.1
#define PRICE_NUM 5


void addTax(int* arrPrice)
{
	for (int i = 0; i < PRICE_NUM; i++)
	{
		//arrPrice[i] = arrPrice[i] * 1.08;
		arrPrice[i] *= (1.0 + TAX);
	}
}

int main(void)
{
	int Price[PRICE_NUM] = { 100, 500, 200 };
	addTax(Price);

	for (int i = 0; i < PRICE_NUM; i++)
	{
		printf("商品%dは、税込みで%d円です\n", i + 1, Price[i]);
	}

	return 0;
}


/*
//関数に配列を引数で渡す　　基本編
void dispHeight(float arrHeight[])
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d番の生徒の身長は%fcmです\n", i + 1, arrHeight[i]);
	}
}

int main(void)
{
	float height[3] = { 170.5f, 169.0f, 178.5f };

	dispHeight(height);   //配列名を渡す（実際には配列の先頭アドレス）
	return 0;
}
*/



/*
//関数内で呼び出し元の２つ以上の変数の中身を変更したい場合
//ポインタ渡しを使用する
void funcSwap(int* ptX, int* ptY)
{
	int tmp;
	tmp = *ptX;
	*ptX = *ptY;
	*ptY = tmp;
	return;
}

int main(void)
{
	int a = 3;
	int b = 5;
	printf("変数aの値は%dです\n", a);
	printf("変数bの値は%dです\n", b);

	printf("funcSwap関数により、変数aと変数bの値を入れ替えます\n");

	//関数を呼び出す
	funcSwap(&a, &b);

	printf("変数aの値は%dです\n", a);
	printf("変数bの値は%dです\n", b);

	return 0;
}
*/

/*
//引数として与えられた数値を２倍にする
void functionDouble(int* ptX)   //x : 仮引数     //ポインタ渡し
{
	//ポインタからその中身を参照したい
	//*(アドレス、ポインタ)
	printf("引数の中身 : %d\n", *ptX);

	(*ptX) = (*ptX) * 2;     //ポインタが指し示す中身を2倍にする

}

int funcDouble(int x)    //値渡し
{
	return x * 2;
}
//ポインタ渡し
int main(void)
{
	int a = 3;
	printf("functionDouble関数により、変数aを2倍にします\n");
	functionDouble(&a);     //a : 実引数

	printf("変数aの値は%dです\n", a);

	return 0;
}
*/

/*
int main(void)
{
	char* name[] = { "Tanaka","Satou","Suzuki"};

	for (int i = 0; i < 3; i++)
	{
		printf("文字列は%sです\n", name[i]);
	}
	return 0;
}
*/
/*
int main(void)
{

	//テキスト領域
	char* str = "C_Gengo";
	printf("strのアドレスは%pです\n", str);

	str = "abcde";
	printf("strのアドレスは%pです\n", str);

	//スタック領域に確保される変数のアドレスを確認
	int num = 0;
	printf("numのアドレスは%pです\n", &num);
	return 0;
}
*/


/*
int main(void)
{
	//文字列、は文字の配列
	char str1[] = "C_Gengo";     //8Byte
	char* str2 = "C_Gengo";

	//str1 = "abcd";    //ビルドエラー
	str2 = "abcd";    //エラーが起きない

	//文字列を表示したい場合、引数として文字列の先頭アドレスを渡していた！
	printf("str1は%sです\n", str1);
	printf("str2は%sです\n", str2);

	return 0;
}
*/





/*
int main(void)
{
	int num = 16;
	//変数のアドレス（メモリ上の置き場所）を取得できる    &変数名
	printf("num addr:%p\n", &num);

	//アドレスを記憶しておくための変数
	//ポインタ
	//データ型* 変数名；　　と宣言する
	int* ptA;
	ptA = &num;   //ポインタにnumのアドレスを代入


	//アドレス（とデータ型）があればその中身を参照できる
	//*(アドレスorポインタ)　　　で参照できる
	printf("ptAの参照先　%d\n", *ptA);

	//配列とアドレス、ポインタの関係
	int tbl[3] = { 10, 20, 30 };

	//配列名は配列の先頭アドレス
	printf("tblの先頭要素の中身 いままで         %d\n", tbl[0]);
	printf("tblの先頭要素の中身 アドレスから参照 %d\n", *tbl);

	printf("tbl[1]の中身 いままで                %d\n", tbl[1]);
	printf("tbl[1]の中身 アドレスから参照        %d\n", *(tbl + 1));

	return 0;
}
*/