#include <stdio.h>

int main(void) 
{
	printf("4/21の授業\n");

	
	int hp = 100;
	printf("プレイヤーのHP:%d\n", hp + 10);

	int testNum = 16;   //テスト用の数字

	//四則演算を行った結果を表示する
	printf("プレイヤーのHP+%d: %d\n", testNum, hp + testNum);

	printf("プレイヤーのHP-%d: %d\n", testNum, hp - testNum);

	printf("プレイヤーのHP*%d: %d\n", testNum, hp * testNum);

	printf("プレイヤーのHP/%d: %d\n", testNum, hp / testNum);

	printf("プレイヤーのHP/%dの余り: %d\n", testNum, hp % testNum);

	//変数に値を代入する
	hp = 150;

	printf("プレイヤーのHP:%d\n", hp);

	//敵の攻撃力
	int enemyAttack = 20;

	//魔法を使って敵の攻撃力を減らす
	enemyAttack = enemyAttack / 2;
	printf("魔法を使用した！\n敵の攻撃力が%dになった！\n", enemyAttack);

	//ダメージを承りました　HPを減らしたい
	//HPをenemyAttack分減らしたい
	hp = hp - enemyAttack;
	printf("ダメージを%d受けた！\nプレイヤーのHP残り:%d\n", enemyAttack, hp);

	//HPの符号を反転する
	hp = -hp;
	printf("HP : %d\n", hp);
	hp = -hp;      //もう１度反転させて戻す
	printf("HP : %d\n", hp);




	return 0;

}