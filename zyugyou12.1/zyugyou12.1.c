#include<stdio.h>   //pritnf, scanf_s
#include<stdlib.h>    //rand(),srand()
#include<time.h>
#include<string.h> //文字列操作に便利な関数が用意されている

//文字列の連結
//"abc"と"def"を連結して"abcdef"という文字列に変更する
//何に使うの？

//ゲームではファイルパスの作成等に使ったりする
//ファイルパス？　　　　ファイルのコンピューター上の置き場所
//C:\Users\student\Desktop\fko2347045@stu.o-hara.ac.jp\プログラミング１\■課題.txt

//ゲームを作る時、たくさんのキャラクターのグラフィックが準備される
//"C:\" + キャラクター名 + "\img.png"
int main(void)
{
	char str1[100] = "Hello!";
	char str2[] = "C_Gengo";

	//(結合する文字列)
	strcat_s(str1, sizeof(str1));
}




/*
//sizeof演算子を利用する
//データ型や配列の合計バイト数を取得する事ができる
int main(void)
{
	int num[4];
	printf("実行環境ではint型は%dバイトです\n", sizeof num);
	//printf("実行環境ではchar型は%dバイトです\n", sizeof char);
	// printf("実行環境ではfloat型は%dバイトです\n", sizeof float);
	//charは１バイト
	//つまりstr[]のサイズが10バイトなら配列の要素数は10だと分かる
	//char str[] = "C_Gengo";

	//printf("配列strのバイト数は%dです\n", (int)sizeof(str));

	char str[100];
	printf("文字列を半角で入力してください\n");
	scanf_s("%s", str, 100);

	printf("配列strのバイト数は%dです\n", (int)sizeof(str));

	printf("文字列の長さは%dです\n", strlen(str));
	return 0;
}
*/


/*
//strlen()で文字列の長さを計測する
int main(void)
{
	char str[100];
	int length;

	printf("文字列を半角で入力してください\n");

	scanf_s("%s", str, 100);

	//strlen()関数　文字列の長さを取得するための関数
	//引数として文字列を指定する
	//文字列の長さを戻り値としてかえしてくれる
	length = strlen(str);

	//strlen()関数が返してくれる長さにNULL文字(\0)は含まれない
	printf("%sは%d文字です\n", str, length);

	return 0;
}
*/

/*
//scanf_s()を利用してキーボードから入力された文字を配列に格納する
int main(void)
{
	//キーボードから受け取る文字列を格納するための配列

	char str[100];

	printf("文字列を半角で入力してください\n");

	scanf_s("%s", str, 100);   //文字列の場合は&はいらないが受け取る文字列の数は書く必要がある
	printf("%sが入力されました\n", str);

	//参考　scanf_sで数値入力
	int num = 0;
	scanf_s("&d", &num);

	return 0;
}
*/


/*
//文字列の初期化
int main(void)
{
	int hp[] = { 10, 20, 30 };

	char str[8] = "C_Gengo";

	//str = "D_Gengo";  //エラー

	//printf(str);

	printf("文字列は%sです\n", str);

	return 0;
}
*/



/*
//文字列を配列に格納する
int main(void)
{
	char str[8];     //C_Gengo

	str[0] = 'C';
	str[1] = '_';
	str[2] = 'G';
	str[3] = 'e';
	str[4] = 'n';
	str[5] = 'g';
	str[6] = 'o';
	str[7] = '\0'; //文字列の最後にはNULL文字(\0)を入れる

	printf(str);    //printfでcharの配列を指定する場合は配列名のみを引数とする

	printf("\n");

	//文字列は実はchar型の配列でした
	//配列に１文字ずつ格納して\0までを１つの文字列とする
	char str2[5];
	str2[0] = 'A';
	str2[1] = 'B';
	str2[2] = '\0';    //文字列の途中？にNULL文字
	str2[3] = 'C';
	str2[4] = 'D';

	printf(str2);

	return 0;
}
*/





/*
int main(void)
{
	//'A' シングルクォーテーションの中に半角一文字
	//→文字　　　char型に保存する

	//"文字列"ダブルクォーテーションの中に文字複数
	//→文字列printf等で使用する
	//文字列はString、Textといった呼ばれ方をすることもある 

	//"A"ダブルクォーテーションの中に半角一文字
	//→これも文字列

	//今までもprintf()関数の引数として文字列を指定していた
	printf("表示したい文字列\n"); 

	return 0;
}
*/