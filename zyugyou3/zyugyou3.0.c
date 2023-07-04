#include<stdio.h>

int main(void)
{
	//鍵をいくつ持っているか
	int keyNum = 0;
	//プレイヤーのパワー
	int playerPower = 10;

	//true（真）の場合、if()の次の１行が実行される
	//false（偽）の場合、if()の次の１行は実行されない
	if (keyNum >= 1)
		printf("扉１が開いた！\n");
	else
		printf("扉１は開かない\n");

	//鍵があれば鍵で開けることができる    if(keyNum >= 1)
	//力ずくで開けることができる          if(playerPower >= 50)
	//どちらかの手段で扉を突破する
	//|| : 論理和 or 演算
	if (keyNum >= 1 || playerPower >= 50)
		printf("扉２が開いた！\n");
	else
		printf("扉２が開かなかった\n");

	//鍵があれば鍵で開けることができる　if(keyNum >= 1)
	//力がないと門番が認めてくれない　if(playerPower >= 50)
	//鍵を持っていて、力がないと扉を開けない
	//両方の条件を満たす必要がある

	//&& : 論理積　and  演算
	//if (keyNum >= 1 && playerPower >= 50)
		//printf("扉３が開いた！\n");

	//else
		//printf("あんたのちからじゃ死んじまうよ\n");

	//鍵を持っていない場合開かない

	//else ifを使用して条件分岐を書く
	if (!(keyNum >= 1))
		printf("扉は開かない\n");

	if(keyNum <= 0)
		printf("扉３を開ける鍵を持っていない\n");
	else if(playerPower < 50)
		printf("扉３の門番がちからを認めてくれない\n");
	else
		printf("扉３が開いた\n");






	return 0;
	//キャストの復習
	/*
	int numInt = 10;

	float numFloat = 1.234f;

	double numDouble = 12.35;

	numInt = (int)numFloat;  //分かっててfloatのデータをintに突っ込んでいる

	printf("numInt = %d\n", numInt);   //小数点以下はなくなっている

	//ポケモンゲット率を計算する

	//何パーセントか、を表示する場合も普通内部では割愛で管理される
	//百分率　　割合
	//100%       1.0
	//50.12%     0.5012
	//12.35     0.1235
	float getRate = 0.0f;

	int getNum = 32;          //持っているポケモンの種類
	int pokemonTotal = 151;       //ポケモンの種類
	getRate = (float) getNum / (float)pokemonTotal;         //ポケモンのゲット率（割合）
	printf("getRate = %f\n", getRate);
	*/
}