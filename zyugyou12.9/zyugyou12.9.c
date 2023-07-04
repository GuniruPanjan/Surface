#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定数
#define BUFF_NO 0      //バフ無し
#define BUFF_ATTCK 1    //攻撃力アップ
#define BUFF_SPEED 2    //移動速度アップ
#define BUFF_DEF 3      //防御力アップ

//プレイヤーへのバフの種類
typedef enum Buff
{
	NONE,       //なし
	ATTACK,      //攻撃力
	SPEED,      //移動速度
	DEF,        //防御力
}Buff;

//ステータスアップ情報を持つ共用体
typedef union BuffEffect
{
	int attack;   //攻撃力アップ量
	float speed;    //移動速度上昇量
	int def;      //防御力アップ量
	//…　　　　　　　//バフの種類が増えたらメンバも増える

}BuffEffect;

//プレイヤー構造体
typedef struct Player
{
	int hp;

	//バフ効果（ステータスアップ）
	//いくつかのステータスアップがあるが、（攻撃力、素早さなど）
	//一つのみ有効
	//新しいバフがつくと古いのは消える
	int buffType;  //0:無し　1:攻撃力アップ  2:素早さアップ  3:防御力アップ

	Buff buffType;         //現在のバフの種類
	BuffEffect buffEffect;  //ステータスアップ情報

}Player;



int main(void)
{
	//データ型
	//int型：整数を入れる
	//float型：少数をいれる
	//char型：文字を一つ入れる

	/*
	//列挙体であるBuff型：列挙体で定義した定数
	Buff bf;
	bf = NONE;
	bf = ATTACK;
	bf = SPEED;
	bf = DEF;
	bf = 10;      //ビルドは通るがよくない
	*/


	BuffEffect buff;
	buff.attack = 10;
	buff.speed = 10.0f;
	buff.def = 16;

	printf("buff.attack = %d\n", buff.attack);

	

	Player player;
	//初期化
	player.hp = 100;
	player.buffType = BUFF_NO;     //数字を書かず、定数を定義する

	//攻撃力バフ
	player.buffType = BUFF_ATTCK;     //攻撃力アップに設定
	player.buffEffect.attack = 10;    //攻撃力の上昇量を設定

	//移動速度バフ
	player.buffType = BUFF_SPEED;      //移動速度アップに設定
	player.buffEffect.speed = 0.5f;      //移動速度の上昇量を設定

	switch (player.buffType)
	{
	case NONE:
		printf("能力アップしていない\n");
		break;
	case ATTACK:
		printf("攻撃力が%d上がっている\n", player.buffEffect.attack);
		break;
	case SPEED:
		printf("移動速度が%f上がっている\n", player.buffEffect.speed);
		break;
	case DEF:
		printf("防御力が%d上がっている\n", player.buffEffect.def);
		break;
			
	}




	return 0;
}