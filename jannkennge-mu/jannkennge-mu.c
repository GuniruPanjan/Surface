#include<stdio.h>
#include<stdlib.h>     //rand,srandを使うのに必要
#include<time.h>       //timeを使うのに必要

int main(int argc, void** argv)
{
	int hand;      //じゃんけんで出す技変数
	int wincount = 0;  //勝った回数を数える変数
	int losecount = 0;   //負けた回数を数える変数
	int num = 0;     //プレイヤーに勝負の回数を変えさせる変数

	printf("勝負回数を入力してください\n");
	scanf_s("%d", &num);
	{
		printf("じゃんけん%d回勝負！\n", num);
	}
	printf("グー：０　パー：１　チョキ：２\n");
	for (int a = 0; a < num; a++)   //勝負数
	{


		scanf_s("%d", &hand);       //プレイヤー側のじゃんけん↓

		if (hand == 0)
		{
			printf("あなたはグーを出しました\n");
		}
		else if (hand == 1)
		{
			printf("あなたはパーを出しました\n");
		}
		else if (hand == 2)
		{
			printf("あなたはチョキをだしました\n");
		}
		else
		{
			printf("あなたは勝負を放棄しました\n");
		}

		srand((unsigned int)time(NULL));          //コンピューター側のじゃんけん↓

		int randNum = 0;            
		for (int i = 0; i < 1; i++)
		{
			randNum = rand();

			if (randNum % 3 == 0)
			{
				printf("相手はグーを出してきた！\n");
			}
			else if (randNum % 3 == 1)
			{
				printf("相手はパーを出してきた！\n");
			}
			else if (randNum % 3 == 2)
			{
				printf("相手はチョキを出してきた！\n");
			}
		}

		           //勝負結果

		

		if (hand == 0 && randNum % 3 == 2)
		{
			printf("あなたの勝利！\n");
			wincount += 1;
		}
		else if (hand == 0 && randNum % 3 == 1)
		{
			printf("あなたの負け\n");
			losecount += 1;
		}
		else if (hand == 0 && randNum % 3 == 0)
		{
			printf("あいこ\n");
			a -= 1;
		}
		else if (hand == 1 && randNum % 3 == 0)
		{
			printf("あなたの勝利！\n");
			wincount += 1;
		}
		else if (hand == 1 && randNum % 3 == 2)
		{
			printf("あなたの負け\n");
			losecount += 1;
		}
		else if (hand == 1 && randNum % 3 == 1)
		{
			printf("あいこ\n");
			a -= 1;
		}
		else if (hand == 2 && randNum % 3 == 1)
		{
			printf("あなたの勝利！\n");
			wincount += 1;
		}
		else if (hand == 2 && randNum % 3 == 0)
		{
			printf("あなたの負け\n");
			losecount += 1;
		}
		else if (hand == 2 && randNum % 3 == 2)
		{
			printf("あいこ\n");
			a -= 1;
		}
		else
		{
			printf("0, 1, 2,を打ちやがれー！！\nあなたの負け\n");
			losecount += 1;

		}

		if (wincount >= num / 2 + 1)      //勝利した場合
		{
			printf("あなたの勝ちです！\n");
			break;
		}

		if (losecount >= num / 2 + 1)       //敗北した場合
		{
			printf("あなたの負けです\nbite the dust!\n");
			break;
		}
		
	}

		



	
	
}


/*
//ランダムな数値の生成
int main(void)
{

	//rand()使用準備
	srand((unsigned int)time(NULL));   //0秒に実行したときと1秒に実行したときで違うサイコロを使う(プログラムの最初に書き込む)


	int randNum = 0;  //ランダムに生成された数値を保存するための変数

	for (int i = 0; i < 8; i++)
	{
	     randNum = rand();  //rand()関数の戻り値をrandNumに代入する
	//rand()関数が0～(65536/2)じゃなくて0～2の値がほしいなら%演算子で割り算の余りを出す
	     printf("ランダムな数字：%d　-> %d\n", randNum, randNum % 3);

	}

	//rand()関数のイメージはサイコロを振って出る目の順番が決まっている関数
	//srand()関数で使用するサイコロの番号


}
*/





/*
//scanf_sを使用してキーボードから数値を入力する
int main(void)
{

	//printf文字列を表示するための関数
	printf("文字列を表示する");

	//scanf_sはキーボードからの入力を受けるつけるための関数
	int inputNum = 0;  //プレイヤーが入力した数字を保存するための変数
	scanf_s("%d", &inputNum);  //キーボードから整数の入力を受ける付ける

	printf("入力した数字：%d\n", inputNum);

	return 0;
}
*/