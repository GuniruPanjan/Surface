#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int num = 11;
	int* ptA = &num;
	//ptAの中には変数numのアドレスが入っている

	//ptA(アドレス)から変数numの値を取得したい
	printf("ptAの中身 : %d\n", *ptA);

	int tbl[3] = { 12, 13, 14 };
	//配列の各要素のアドレスを取得したい
	//tbl[1]のアドレスを取得したい
//	&tbl[1];    //基本tbl[1]の前に&をつけてそのアドレスを取得する

//	tbl;     //配列名のみ　配列の先頭アドレス
//  tbl + 1;      //配列名（先頭アドレス）に1を足す      
	              //アドレスに1を足した場合、単純に1バイトずれるのではなく
	              //データサイズ1つ分ずれる

	//じゃあ、(配列名 + 要素番号)の書き方と
	//* を組み合わせて配列の指定した要素の中身

	printf("tbl[0]の値は%dです\n", tbl[0]);
	printf("*tblの値が%dです\n", *tbl);

	printf("tbl[1]の値は%dです\n", tbl[1]);
	printf("*(tbl + 1)の値は%dです\n", *(tbl + 1));

	printf("tbl[2]の値は%dです\n", tbl[2]);
	printf("*(tbl + 2)の値は%dです\n", *(tbl + 2));


	return 0;
}





/*
int main(void)
{

	int height[3] = { 170, 169, 178 };

	printf("int型のサイズは%dバイトです\n", sizeof(height[0]));


	//配列は必ずメモリ上に並んで配置される

	//配列名　実はアドレスです　配列全体の先頭アドレスを示している
	//int num[3];   numがアドレス　num[0]の先頭アドレスと同じ
	//アドレスなのでポインタに保存することができる
	//int *ptA = num;
	//num + 1?   アドレスに対して +1 してやると、そのデータサイズ分ずれたアドレスが示される
	//intなら4Byteなので4,charなら1Byteなので１ずつずれる

	printf("height[0]のアドレスは%pです\n", &height[0]);      //こっちはわかる
	//配列名だけ書くと配列の先頭アドレスを取得できる
	printf("heightの値は%pです\n", height);

	printf("height[1]のアドレスは%pです\n", &height[1]);
	//アドレス + 1等の計算を行うとそのデータサイズ分ずれたアドレスを取得できる
	printf("height + 1の値は%pです\n", height + 1);

	printf("height[2]のアドレスは%pです\n", &height[2]);
	printf("height + 2の値は%pです\n", height + 2);

	

	return 0;
}
*/





/*
void function(int num)
{
	printf("引数として渡された数字は%dです\n", num);
	printf("function内で使用できる変数numのアドレスは%pです\n", &num);

	num = 256;
}



int main(void)
{
	//メモリを確保する
	int num;
	char chr;

	//&変数名　でその変数の確保されているアドレスを所得できる
	printf("numはアドレス%pに確保されています\n", &num);

	num = 16;
	function(num);
	printf("num = %d\n", num);

	//アドレスを変数として保存するには？
	//アドレスはポインタに保存する
	int* ptA;          //int 4Byte, char, 4Byte     int*は？ → 8Byte(64bit)
	//%pで表示したとき、アドレスは16進数16桁で表示された
	//16進数一桁(0~f)は4ビットで表現可能(0000 ~ 1111)
	//つまり16進数16桁という事は4(bit) * 16(桁) = 64bit(8Byte)

	ptA = &num;        //numのアドレスをポインタ変数ptAに代入する
	printf("ptA = %p\n", ptA);

	//ポインタ(アドレス)からそこに格納されているデータの中身を参照する
	//どうやって？
	//アドレスの前に*をつける
	printf("ptAの中身は%dです\n", *ptA);

	return 0;
}
*/