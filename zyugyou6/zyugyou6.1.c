#include<stdio.h>


//課題
int main(void)
{
	int answer = 0;
	int sum = 0;
	int a;

	for (a = 0; a <= 100; a++)
	{
		if (a % 7 != 0)continue;
		sum += a;
	}
	printf("合計は%dです\n", sum);

	//while文わ使って書き換え
	int addNum = 7;
	while (addNum <= 100)
	{
		answer += addNum;
		addNum += 7;
	}

	for (int i = 1; ; i++)
	{
		if ((7 * i) > 100) 
		{
			break;
	    }
		answer += (i * 7);
	}
	int baseNum = 1;
	while (1) {
		int addNum = 7 * baseNum;
		if (addNum > 100) {
			break;
		}
		answer += addNum;
		baseNum;
	}
	
}

/*
//break,continueの復習
int main(void)
{
	//プレイヤーのHP
	int playerHp = 50;
	//敵の攻撃力
	int enemyAttack = 3;
	//敵の攻撃回数
	int enemyAttackNum = 10;

	//敵の攻撃回数回ダメージを喰らう
	for (int i = 0; i < enemyAttackNum; i++)
	{
		printf("%d回目の攻撃！\n", i + 1);

		//奇数回目の攻撃を受ける
		//偶数回目の攻撃を回避する
		//攻撃回数は奇数の時、iの値は偶数　逆もまた然り
		//iが奇数の時にcontinueする
		if (i % 2 == 1)
		{
			printf("回避した！\n");
		    continue;
		}
		playerHp -= enemyAttack;
		printf("残りHP%d\n", playerHp);

		//hpが0になったら攻撃をやめる
		if (playerHp <= 0)
		{
			printf("死んでしまった\n");
			break;  //breakで繰り返しを強制的にやめる
		}
	}

	while (1)
	{
		printf("無限ループ\n");
		if (1)
		{
			printf("無限ループ抜ける\n");
			break;
		}
	}
}
*/
/*
//for文の復習
int main(void)
{
	//決まった回数を繰り返す場合for使うことが多い
	for (
		int i = 0;  //for文の初期化処理
		i < 5;        //繰り返し条件
		i++         //継続処理　繰り返される中身が終わった後実行される
		) 
	{
		//繰り返される中身
	}

	//きれいに書き直し
	int loopNum = 16;
	for (int i = 0; i < loopNum, i++);
	{
		printf("%d回目の繰り返し\n", i + 1);
	}

	//何かしらの条件を満たすまで繰り返す場合whileを使うことが多い
	int playerHp = 50;
	//プレイヤーのHPが0以下になるまでダメージを繰り返し受ける
	while (playerHp > 0)
	{
	   playerHp -= 7;
	   printf("残りHP %d\n", playerHp);

	}
}
*/
/*
//switch文の復習
int main(void)
{
	int num = 5;
	switch (num)
	{
	case 0:
		printf("numは0\n");
		break;
	case 1:
		printf("numは1\n");
		break;
	case 2:
		printf("numは2\n");
		break;
	case 3:
		printf("numは3\n");
		break;
	case 4:
		printf("numは4\n");
		break;
	case 5:
		printf("numは5\n");
		break;
	default:
		printf("numはそれ以外\n");
		break;

	}

	return 0;
}
*/