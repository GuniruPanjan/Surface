#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Student
{
	int no;
	float height;
	float weight;
}Student;

int main(void)
{

	Student stu[3];

	stu[0].no = 1;
	stu[0].height = 160.0f;
	stu[0].weight = 55.5f;

	stu[1].no = 2;
	stu[1].height = 170.0f;
	stu[1].weight = 65.5;

	stu[2].no = 3;
	stu[2].height = 150.0f;
	stu[2].weight = 45.5f;


	for (int i = 0; i < 3; i++)
	{
		printf("%d:身長%fcm体重%fkg\n", stu[i].no,stu[i].height,stu[i].weight);
	}




	return 0;
}






/*
//typedefで型名に別名を付けることができる
typedef struct Testscore
{
	int kokugo;
	int sansu;
	int rika;
	int syakai;
}Testscore;

//構造体の宣言
typedef struct StudentData
{
	int no;      //出席番号
	float height;     //身長
	float weight;     //体重

	Testscore score;   //テストの点数
}StudentDeta;

//生徒のデータを表示する関数
void dispStudentData(StudentDeta deta)
{
	printf("出席番号%d\n", deta.no);
	printf(" 身長%f\n", deta.height);
	printf("算数の点数%d\n", deta.score.sansu);

}

//生徒の番号を変更する関数
//deta:出席番号を変更したい生徒のデータ
//nextNo:どの出席番号に変更したいか
void changeStudentNo(StudentDeta* pDeta, int nextNo)
{
//	deta.no = nextNo;   //与えられた生徒のデータの出席番号を引数の値に変更する
	pDeta->no;
}

int main(void)
{
	int num = 10;  //データ型　変数名

	//構造体変数の宣言と初期化
	StudentDeta student1 = { 10, 155.5f, 45.8f, {50, 60, 70, 80 } };       //データ型　変数名（同じ）
	//構造体のメンバにアクセスする
	student1.no = 7;
	student1.height = 160.5f;
	student1.weight = 55.5f;
	student1.score.kokugo = 50;
	student1.score.sansu = 60;
	student1.score.rika = 70;
	student1.score.syakai = 80;

	StudentDeta student2;

	student2 = student1;

	dispStudentData(student2);
	changeStudentNo(&student2,99);    //生徒の出席番号を変更
	dispStudentData(student2);       //正しく変更できたかを確認



	return 0;
}
*/