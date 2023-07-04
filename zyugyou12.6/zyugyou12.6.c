#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//テストの成績データ構造体
typedef struct Test
{
	int kokugo;
	int sansu;
	int rika;
	int syakai;
}Test;

//生徒のデータ構造体
typedef struct Student
{
	int no;
	float height;
	float weight;
	//構造体を構造体のメンバーとして持つ
	Test exam;
}Student;

int main(void)
{
	Student student1;
	Student student2 = { 2, 169.5f, 54.5,{80, 70, 90, 65} };

	printf("二人目の生徒の出席番号は%dです\n", student2.no);
	printf("二人目の生徒の身長は%fです\n", student2.height);
	printf("二人目の生徒の体重は%fです\n", student2.weight);


	



	//student1.height = 170.5f;     //Student構造体のメンバにアクセス

	//メンバの構造体の持つメンバにアクセスする
	//student1.exam.kokugo = 80;

	return 0;
}


/*
typedef struct Student
{
	int no;
	float height;
	float weight;

}Student;

int main(void)
{
	Student student1 = { 1, 170.5f, 58.0f };

	printf("一人目の生徒の出席番号は%dです\n", student1.no);
	printf("一人目の生徒の身長は%fです\n", student1.height);
	printf("一人目の生徒の体重は%fです\n", student1.weight);

	return 0;
}

*/






/*
//生徒のデータ管理用構造体の定義
typedef struct Student
{
	int no;
	float height;
	float weight;
}Student;

//typedef struct Student Gakusei;

int main(void)
{
	//初期化なしの構造体変数の宣言
	Gakusei student1 = { 1, 170.5f, 58.0f };
	//初期化付きの構造体宣言
	struct Student student2 = { 2, 169.0f, 54.5f };

	//構造体に構造体を代入する
	student1 = student2;

	//.で構造体のメンズにアクセスする
	//student1.height = 170.5f;

	printf("一人目の生徒の出席番号は%dです\n", student1.no);
	printf("一人目の生徒の身長は % fcmです\n", student1.height);
	printf("一人目の生徒の体重は%fkgです\n", student1.weight);


	return 0;
}
*/



/*構造体の使い方
int main(void)
{
//	int num;     //型名 
	//struct Student student1;     //struct 構造体 変数名;

	//初期化付きの構造体変数の宣言
	struct Student student1 = {1, 170.5f, 58.0f}

	//.を使用して構造体のメンズにアクセスする
	student1.height = 170.5f;

	return 0;
}
*/