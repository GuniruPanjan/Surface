#include<stdio.h>   //pritnf, scanf_s
#include<stdlib.h>    //rand(),srand()
#include<time.h>
#include<string.h> //�����񑀍�ɕ֗��Ȋ֐����p�ӂ���Ă���

//������̘A��
//"abc"��"def"��A������"abcdef"�Ƃ���������ɕύX����
//���Ɏg���́H

//�Q�[���ł̓t�@�C���p�X�̍쐬���Ɏg�����肷��
//�t�@�C���p�X�H�@�@�@�@�t�@�C���̃R���s���[�^�[��̒u���ꏊ
//C:\Users\student\Desktop\fko2347045@stu.o-hara.ac.jp\�v���O���~���O�P\���ۑ�.txt

//�Q�[������鎞�A��������̃L�����N�^�[�̃O���t�B�b�N�����������
//"C:\" + �L�����N�^�[�� + "\img.png"
int main(void)
{
	char str1[100] = "Hello!";
	char str2[] = "C_Gengo";

	//(�������镶����)
	strcat_s(str1, sizeof(str1));
}




/*
//sizeof���Z�q�𗘗p����
//�f�[�^�^��z��̍��v�o�C�g�����擾���鎖���ł���
int main(void)
{
	int num[4];
	printf("���s���ł�int�^��%d�o�C�g�ł�\n", sizeof num);
	//printf("���s���ł�char�^��%d�o�C�g�ł�\n", sizeof char);
	// printf("���s���ł�float�^��%d�o�C�g�ł�\n", sizeof float);
	//char�͂P�o�C�g
	//�܂�str[]�̃T�C�Y��10�o�C�g�Ȃ�z��̗v�f����10���ƕ�����
	//char str[] = "C_Gengo";

	//printf("�z��str�̃o�C�g����%d�ł�\n", (int)sizeof(str));

	char str[100];
	printf("������𔼊p�œ��͂��Ă�������\n");
	scanf_s("%s", str, 100);

	printf("�z��str�̃o�C�g����%d�ł�\n", (int)sizeof(str));

	printf("������̒�����%d�ł�\n", strlen(str));
	return 0;
}
*/


/*
//strlen()�ŕ�����̒������v������
int main(void)
{
	char str[100];
	int length;

	printf("������𔼊p�œ��͂��Ă�������\n");

	scanf_s("%s", str, 100);

	//strlen()�֐��@������̒������擾���邽�߂̊֐�
	//�����Ƃ��ĕ�������w�肷��
	//������̒�����߂�l�Ƃ��Ă������Ă����
	length = strlen(str);

	//strlen()�֐����Ԃ��Ă���钷����NULL����(\0)�͊܂܂�Ȃ�
	printf("%s��%d�����ł�\n", str, length);

	return 0;
}
*/

/*
//scanf_s()�𗘗p���ăL�[�{�[�h������͂��ꂽ������z��Ɋi�[����
int main(void)
{
	//�L�[�{�[�h����󂯎�镶������i�[���邽�߂̔z��

	char str[100];

	printf("������𔼊p�œ��͂��Ă�������\n");

	scanf_s("%s", str, 100);   //������̏ꍇ��&�͂���Ȃ����󂯎�镶����̐��͏����K�v������
	printf("%s�����͂���܂���\n", str);

	//�Q�l�@scanf_s�Ő��l����
	int num = 0;
	scanf_s("&d", &num);

	return 0;
}
*/


/*
//������̏�����
int main(void)
{
	int hp[] = { 10, 20, 30 };

	char str[8] = "C_Gengo";

	//str = "D_Gengo";  //�G���[

	//printf(str);

	printf("�������%s�ł�\n", str);

	return 0;
}
*/



/*
//�������z��Ɋi�[����
int main(void)
{
	char str[8];     //C_Gengo

	str[0] = 'C';
	str[1] = '_';
	str[2] = 'G';
	str[3] = 'e';
	str[4] = 'n';
	str[5] = 'g';
	str[6] = 'o';
	str[7] = '\0'; //������̍Ō�ɂ�NULL����(\0)������

	printf(str);    //printf��char�̔z����w�肷��ꍇ�͔z�񖼂݂̂������Ƃ���

	printf("\n");

	//������͎���char�^�̔z��ł���
	//�z��ɂP�������i�[����\0�܂ł��P�̕�����Ƃ���
	char str2[5];
	str2[0] = 'A';
	str2[1] = 'B';
	str2[2] = '\0';    //������̓r���H��NULL����
	str2[3] = 'C';
	str2[4] = 'D';

	printf(str2);

	return 0;
}
*/





/*
int main(void)
{
	//'A' �V���O���N�H�[�e�[�V�����̒��ɔ��p�ꕶ��
	//�������@�@�@char�^�ɕۑ�����

	//"������"�_�u���N�H�[�e�[�V�����̒��ɕ�������
	//��������printf���Ŏg�p����
	//�������String�AText�Ƃ������Ă΂�������邱�Ƃ����� 

	//"A"�_�u���N�H�[�e�[�V�����̒��ɔ��p�ꕶ��
	//�������������

	//���܂ł�printf()�֐��̈����Ƃ��ĕ�������w�肵�Ă���
	printf("�\��������������\n"); 

	return 0;
}
*/