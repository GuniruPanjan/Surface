#include<stdio.h>


//演習
int main(void)
{
	int answer = 0;

	//1～100までの間に存在する7の倍数の合計を計算する
	//answer = 7 + 14 + 21 + 28 + 35
	//2パターンくらい方法を考える

	//7の倍数以外をはじく
	int sum = 0;
	int a;

	for (a = 0; a <= 100; a++)
	{
		if (a % 7 != 0)continue;
		sum += a;
	}
	printf("合計は%dです\n", sum);

	return 0;





	

}


/*
int main(void)
{
	int hp = 50;

	int damage = 8;

	//プレイヤーの防御力をチェックしてダメージ減らす
	damage -= 100;

	while (hp > 0)
	{
		hp -= damage;

		printf("残りHP:%d\n", hp);

		break;
	}


	//無限ループ
	while (1)        //while(1)で無限ループ
	{
		//条件をチェックして無限ループを抜ける
		if (1) {
			break;
		}
	}

}
*/
/*
//continue文
int main(void)
{
	//1から10までの足し算で3の倍数を除いた計算
	int sum = 0;
	int a;

	for (a = 0; a <= 10; a++)
	{
		printf("足そうとしている数 %d\n", a + 1);

		//3の倍数を足そうとしたときはそれを行わない
		if (a % 3 == 0)continue;
		sum += a;
	}
	printf("合計は%dです\n", sum);

	return 0;


	int answer = 1;
	//int answer = 0; //ループ回数を数える

	//1から10までの数を足し算して、答えを出力する

	//足し算を１０回行う
	for (int i = 1; i < 10; i++)
	{
		printf("ループ回数%d\n", i);

		//足し算を行う
		answer += i + 1;
	}
		printf("answer = %d\n", answer);





	
	//while文バージョン
		answer = 0;
		int addNum = 1; //足す数
		while (addNum <= 10)
	{
			answer += addNum;
			addNum++;
		
	}
		printf("answer = %d\n", answer);

	
}
*/


/* for文の復習
int main(void)
{
	//break文の復習
	int inputNum = 8;  //プレイヤーが入力した数字
	int count = 1;     //表示する数字
	while (1)
	{
		printf("数字:%d\n", count);
		//プレイヤーが入力した数字が表示されたら終了
		if (count == inputNum)
		{
			break;
		}
		//100まで表示されたら終了
		if (count >= 100)
		{
			break;
		}

		count++;

	}


	//while文だけではなくfot文も強制終了できる
	for (int i = 0; i < 100; i++)
	{
		int dispNum = count + 1;
		printf("number:%d\n", dispNum);

		//プレイヤーが入力した数字が表示されたら終了
		if (count == inputNum)
		{
			break;
		}
	}



	//do-while文の復習
	do {
		printf("do-while文は必ず一度は実行します\n\n");
	} while (2 < 1);

	while (2 < 1)
	{
		printf("while文は最初から条件を満たしてない場合、一度も実行されません\n\n");
	}




	//条件を満たすまで同じ処理を繰り返す　　while文
	int hp = 50;
	while (hp > 0)   //条件は終了条件ではなく継続条件
	{
		printf("ダメージを受けた！\n");
		hp -= 5;
		printf("残りHP:%d\n", hp);

	}
	printf("The Endってね★\n\n");

	//上のwhile文をfor文で書き換える
	for (int hp2 = 50; hp2 > 0;)
	{
		printf("ダメージを受けた！\n");
		hp2 -= 8;
		printf("残りHP:%d\n", hp);

	}
	printf("The Endってね★\n\n");


	//int i = 0; //ループ回数を数える

	//指定した回数同じ処理を繰り返す　for文
	for (int i = 0; i < 16; i++)
	{
		printf("%d回目のループ\n", i + 1);
		//同じ計算をする処理をまとめておく
		int dispNum = (i + 1);

		if (dispNum % 2 == 0)
		{
			printf("%dは偶数\n", dispNum );
		}
		else
		{
			printf("%dは奇数\n", dispNum );
		}

	}
	return 0;
}
*/