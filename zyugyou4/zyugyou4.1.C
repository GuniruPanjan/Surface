#include<stdio.h>


//繰り返し処理
int main(void)
{
	int hp = 100;  //火の無い灰

	int enemyNum = 4;    //敵の数

	int count = 0;  //繰り返し回数を数える
	for (count = 1; count <= 4; count++)
	{
		hp -= 20;  //攻撃を喰らった　HPを20減らす
		printf("%d体目の敵の攻撃！\n", count);
		printf("残りのHP: %d\n", hp);
	}

	printf("count = %d\n", count);

	/*
	//�@が実行される
	count = 1;
	//�A繰り返す条件をチェック
	count <= 4 //trueの場合繰り返す処理(�C）を実行する
		//falseの場合はfor文終わり
 //繰り返し条件を満たした場合は処理が行われる
		hp -= 20;  //攻撃を喰らった　HPを減らす
	printf("%d体目の敵の攻撃！\n", count);
	printf("残りHP: %d\n", hp);

	//�B命令を実行した後の処理が実行される
	count++;   //count = 2

	//�Aの条件チェックに戻る
	*/

	//for文の説明
	for (
		count = 1;      //�@for文に来た時に最初に実行される
		count <= 4;     //�A繰り返す条件
		count++        //�B繰り返し命令を実行した後に行われる処理
		) 
	{
		//この中身を繰り返す
	}

	return 0;

	/*
	//敵が4体
	hp -= 20;  //1体目の敵から攻撃をもらった　　HPを20減らす
	printf("残りHP: %d\n", hp);

	hp -= 20;  //2体目の敵から攻撃をもらった　　HPを20減らす
	printf("残りHP: %d\n", hp);

	hp -= 20;  //3体目の敵から攻撃をもらった　　HPを20減らす
	printf("残りHP: %d\n", hp);

	hp -= 20;  //4体目の敵から攻撃をもらった　　HPを20減らす
	printf("残りHP: %d\n", hp);

	hp -= 20;  //1体目の敵から攻撃をもらった　　HPを20減らす
	printf("残りHP: %d\n", hp);

	if (hp == 0)
	{
		printf("火の無い灰は死んでしまった\n");
	}

	*/
}





//if文、switch文の練習
/*
int main(void)
{









	
	int num = 1;
	int num2 = 0;

	if (num == 0 && num2 == 0)      //どっちも0
	{
		if (num == 0)
		{
			printf("インデントに気を付ける\n");
		}
		else if (num2 == 0)
		{

		}
		else
		{

		}
	}



	switch (num)
	{
	case 0:
		printf("numは%dです\n", num);
		if (num2 == 0)   //switch文の中にif文を書ける
		{


		}
		break;
	case 1:
		printf("numは%dです\n", num);
		break;
	case 2:
		printf("numは%dです\n", num);
		break;
	case 3:
		printf("numは%dです\n", num);
		break;
	}




	
	int num = 3;

	int num2 = 0;
	
	if (num == 0 && num2 == 0)         //num,num2共に0      and演算
	{
		printf("numは%dで、num2は%dです\n", num, num2);
	}
	else if (num == 0 || num2 ==0)       //num,num2のどちらかが()
	{
		printf("numは0もしくはnum2は0です\n");

	}
	else if(num == 1)
	{
		printf("numは1です\n");
	}
	else if (num == 2)
	{
		printf("numは2です\n");
	}
	else if (num == 3)
	{
		printf("numは3です\n");
	}
	else
	{
		printf("numは%dであり0でも1でも2でも3でもありません", num);
	}
	return 0;
	
}
*/