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
		printf("%d:�g��%fcm�̏d%fkg\n", stu[i].no,stu[i].height,stu[i].weight);
	}




	return 0;
}






/*
//typedef�Ō^���ɕʖ���t���邱�Ƃ��ł���
typedef struct Testscore
{
	int kokugo;
	int sansu;
	int rika;
	int syakai;
}Testscore;

//�\���̂̐錾
typedef struct StudentData
{
	int no;      //�o�Ȕԍ�
	float height;     //�g��
	float weight;     //�̏d

	Testscore score;   //�e�X�g�̓_��
}StudentDeta;

//���k�̃f�[�^��\������֐�
void dispStudentData(StudentDeta deta)
{
	printf("�o�Ȕԍ�%d\n", deta.no);
	printf(" �g��%f\n", deta.height);
	printf("�Z���̓_��%d\n", deta.score.sansu);

}

//���k�̔ԍ���ύX����֐�
//deta:�o�Ȕԍ���ύX���������k�̃f�[�^
//nextNo:�ǂ̏o�Ȕԍ��ɕύX��������
void changeStudentNo(StudentDeta* pDeta, int nextNo)
{
//	deta.no = nextNo;   //�^����ꂽ���k�̃f�[�^�̏o�Ȕԍ��������̒l�ɕύX����
	pDeta->no;
}

int main(void)
{
	int num = 10;  //�f�[�^�^�@�ϐ���

	//�\���̕ϐ��̐錾�Ə�����
	StudentDeta student1 = { 10, 155.5f, 45.8f, {50, 60, 70, 80 } };       //�f�[�^�^�@�ϐ����i�����j
	//�\���̂̃����o�ɃA�N�Z�X����
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
	changeStudentNo(&student2,99);    //���k�̏o�Ȕԍ���ύX
	dispStudentData(student2);       //�������ύX�ł��������m�F



	return 0;
}
*/