#include <stdio.h>
int main(void)
{
	int hp = 100;
	
	//ダメージを受けた
	//hp = hp - 10;
	//代入演算子を使用した書き方
	//HP回復
	hp += 10;
	printf("HP:%d\n", hp);

	//攻撃を受けた
	int enemyAttack = 20;
	
	hp -= enemyAttack;

	printf("HP:%d\n", hp);

	//ビットシフトを試す
	int shiftTest = 100;
	//0110 0100 → 1100 1000にする
	printf("shiftTest %d\n", shiftTest << 1);  //左に１ビットシフト

	//0110 0100　→　0011 0010にする
	printf("shiftTest %d\n", shiftTest >> 1); //右に１ビットシフト

	int num = 6;
	//インクリメント演算子　インクリメント
	num++;    //numに１を足してnumに代入する　num += 1, num = num+1と同じ
	printf("num:%d\n", num);

	//デクリメント演算子　デクリメント
	num--; //numから１を引いてnumに代入する　num -= 1, num = num-1と同じ
	printf("num:%d\n", num);


	return 0;
}