#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�e�X�g�̐��уf�[�^�\����
typedef struct Test
{
	int kokugo;
	int sansu;
	int rika;
	int syakai;
}Test;

//���k�̃f�[�^�\����
typedef struct Student
{
	int no;
	float height;
	float weight;
	//�\���̂��\���̂̃����o�[�Ƃ��Ď���
	Test exam;
}Student;

int main(void)
{
	Student student1;
	Student student2 = { 2, 169.5f, 54.5,{80, 70, 90, 65} };

	printf("��l�ڂ̐��k�̏o�Ȕԍ���%d�ł�\n", student2.no);
	printf("��l�ڂ̐��k�̐g����%f�ł�\n", student2.height);
	printf("��l�ڂ̐��k�̑̏d��%f�ł�\n", student2.weight);


	



	//student1.height = 170.5f;     //Student�\���̂̃����o�ɃA�N�Z�X

	//�����o�̍\���̂̎������o�ɃA�N�Z�X����
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

	printf("��l�ڂ̐��k�̏o�Ȕԍ���%d�ł�\n", student1.no);
	printf("��l�ڂ̐��k�̐g����%f�ł�\n", student1.height);
	printf("��l�ڂ̐��k�̑̏d��%f�ł�\n", student1.weight);

	return 0;
}

*/






/*
//���k�̃f�[�^�Ǘ��p�\���̂̒�`
typedef struct Student
{
	int no;
	float height;
	float weight;
}Student;

//typedef struct Student Gakusei;

int main(void)
{
	//�������Ȃ��̍\���̕ϐ��̐錾
	Gakusei student1 = { 1, 170.5f, 58.0f };
	//�������t���̍\���̐錾
	struct Student student2 = { 2, 169.0f, 54.5f };

	//�\���̂ɍ\���̂�������
	student1 = student2;

	//.�ō\���̂̃����Y�ɃA�N�Z�X����
	//student1.height = 170.5f;

	printf("��l�ڂ̐��k�̏o�Ȕԍ���%d�ł�\n", student1.no);
	printf("��l�ڂ̐��k�̐g���� % fcm�ł�\n", student1.height);
	printf("��l�ڂ̐��k�̑̏d��%fkg�ł�\n", student1.weight);


	return 0;
}
*/



/*�\���̂̎g����
int main(void)
{
//	int num;     //�^�� 
	//struct Student student1;     //struct �\���� �ϐ���;

	//�������t���̍\���̕ϐ��̐錾
	struct Student student1 = {1, 170.5f, 58.0f}

	//.���g�p���č\���̂̃����Y�ɃA�N�Z�X����
	student1.height = 170.5f;

	return 0;
}
*/