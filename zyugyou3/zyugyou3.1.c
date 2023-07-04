#include<stdio.h>

int main(void)
{

	//falseは0
	//trueは0以外
	if (4)
	{
		printf("実行される\n");

	}
	int keyNum = 0;
	if (keyNum)
	{
		printf("鍵待ってる　%d\n", keyNum);
	}
	else
	{
		printf("鍵持ってない\n");
	}




	int num = 0;
	int num2 = 1;

	//falseは0
	//trueは1

	printf("(num == 1)の中身を表示　%d\n", num == 1);     //false
	printf("(num == 0)の中身を表示　%d\n", num == 0);     //true

	printf("%d\n", num == 0 && num2 == 1); //true
	printf("%d\n", num == 0 || num2 == 0); //true

	printf("%d\n", num == 3 && num2 == 3); //false
	printf("%d\n", num == 3 || num2 == 3); //false

	//falseは0
	//trueは0以下

	int result = (num == 1);
	printf("result = %d\n", result);

	if (result)
	{
		printf("result:true\n");
	}
	else
	{
		printf("result:false\n");
	}







	return 0;
}








/*
//switch文
int main(void)
{
	int a = 7;
	int b = a % 3;       //aを３で割った余り

	printf("変数aの値は%dです\n", a);

	switch (b)
	{
	case 0:
		printf("変数aを３で割った余りは０です\n");
		break;
	case 1:
		printf("変数aを３で割った余りは１です\n");
		break;
	default:
		printf("変数aを３で割った余りは２です\n");
		break;
	}

	//if-elseを使って書き換え
	if (b == 0) {
		printf("変数aを３で割ったあまりは0です\n");
	}
	else if (b == 1) {
		printf("変数aを３で割ったあまりは1です\n");
	}
	else {
		printf("変数aを３で割ったあまりは2です\n");
	}

	//条件分岐いらないが？
	printf("変数aを3で割った余りは%dです\n", b);


}










//if文の復習
int main(void)
{
	
	
	int keyNum = 1;

	int playerPower = 60;

	
	if (keyNum >= 1) {
		//｛｝の中に好きなだけ処理をかける
		printf("扉が開いた\n");
		printf("鍵を%d個消費した\n", keyNum);
		keyNum--;  //鍵を一つ減らす
		printf("残りの鍵 : %d\n", keyNum);
	}
	else {
		printf("扉は開かない\n");
	}
	if (keyNum >= 1 || playerPower >= 50) {
		printf("扉２が開いた\n");
		
		if (playerPower >= 50) {
			
			printf("力ずくで扉を開けた\n");
		
		}
	
		else {
		
			printf("鍵で開けた\n");
		
			keyNum--;     //鍵を一つ減らす
		
			printf("残りの鍵 : %d\n", keyNum);
	}
	//インデントに気を付ける
	

}
	*/