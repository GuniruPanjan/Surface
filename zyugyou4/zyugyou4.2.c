#include<stdio.h>

int main(void)
{
	int enemyhp = 100;  //敵のHP
	int playerMP = 50;  //プレイヤーのMP

	//連続攻撃魔法で敵を倒すまで攻撃する
	while (enemyhp > 0)
	{
		enemyhp -= 10;
		playerMP -= 10;
		printf("敵の残りhp: %d\n", enemyhp);
		printf("プレイヤーの残りMP: %d\n", playerMP);
		

		//MPがなくなったら強制終了
		if (playerMP <= 0)
		{
			printf("MP切れ！攻撃終了\n");
			break;
		}

		//敵に回避された
		if (0)
		{
			printf("よけられたので中断\n");
			break;
		}
		//他の敵の攻撃を受けた
		if (0)
		{
			printf("ほかの敵の攻撃を受けたので中断\n");
			break;
		}


	}   
	return 0;
}


/*
int main(void)
{
	//do-while文の説明
	//①処理を行う
	//②条件を満たしていたら①に戻る
	do 
	{
		printf("do-while文は必ず一度は実行します\n");
	} while (2 < 1);

	//while文の説明
	//①while文に入ったら条件チェックが行われる
	//②条件を満たしていたら処理を行う　満たしていないなら終了
	//①に戻る
	while (2 < 1)
	{
		printf("while文は？\n");
	}

	return 0;
}
*/






/*
int main(void)
{
	int num = 3;

	//true(真)　　　　0以外
	//false(偽)       0

	while (num)
	{
		printf("あと%d回繰り返します\n", num);
		num--;
	}

	if (num)
	{
		//num = 0の場合はここの処理は行われない
		//num != 0の場合ここの処理は行われる
	}


	return 0;
}





int main(void)
{
	int startCount = 4;
	int loopNum = 8;
	//初期化や継続条件にも変数を使える
	//for文ちょっと補足
	for (int i = 1; i <= 5; i++)
	{
		printf("繰り返し%d\n", i);
	}

	//while文
	int hp = 50;

	//HPが0以下になるまで攻撃され続ける
	while (hp > 0)
	{
		hp -= 5;
		printf("残りHP: %d\n", hp);
	}

	for (hp = 50; hp > 0; hp -= 5)
	{
		printf("残りHP: %d\n", hp);
	}

	//①while文に入ったら条件チェックが行われる
	//②条件を満たしていたら処理を行う　満たしていないなら終了
	//①に戻る






	//for文の練習
	printf("for文による繰り返しの練習です\n");

	int i;

	for (i = 1; i <= 5; i++)
	{
		printf("%d秒経過\n", i);
	}
	printf("%d秒経過\nロードローラーだッ！！\n", i);
	延々と繰り返す
	for (;;)
	{
		printf("ああああああああああああああああああああああああああ\n");
	}


}
	*/