#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//�萔���`����
#define TAX 0.1
#define PRICE_NUM 5


void addTax(int* arrPrice)
{
	for (int i = 0; i < PRICE_NUM; i++)
	{
		//arrPrice[i] = arrPrice[i] * 1.08;
		arrPrice[i] *= (1.0 + TAX);
	}
}

int main(void)
{
	int Price[PRICE_NUM] = { 100, 500, 200 };
	addTax(Price);

	for (int i = 0; i < PRICE_NUM; i++)
	{
		printf("���i%d�́A�ō��݂�%d�~�ł�\n", i + 1, Price[i]);
	}

	return 0;
}


/*
//�֐��ɔz��������œn���@�@��{��
void dispHeight(float arrHeight[])
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d�Ԃ̐��k�̐g����%fcm�ł�\n", i + 1, arrHeight[i]);
	}
}

int main(void)
{
	float height[3] = { 170.5f, 169.0f, 178.5f };

	dispHeight(height);   //�z�񖼂�n���i���ۂɂ͔z��̐擪�A�h���X�j
	return 0;
}
*/



/*
//�֐����ŌĂяo�����̂Q�ȏ�̕ϐ��̒��g��ύX�������ꍇ
//�|�C���^�n�����g�p����
void funcSwap(int* ptX, int* ptY)
{
	int tmp;
	tmp = *ptX;
	*ptX = *ptY;
	*ptY = tmp;
	return;
}

int main(void)
{
	int a = 3;
	int b = 5;
	printf("�ϐ�a�̒l��%d�ł�\n", a);
	printf("�ϐ�b�̒l��%d�ł�\n", b);

	printf("funcSwap�֐��ɂ��A�ϐ�a�ƕϐ�b�̒l�����ւ��܂�\n");

	//�֐����Ăяo��
	funcSwap(&a, &b);

	printf("�ϐ�a�̒l��%d�ł�\n", a);
	printf("�ϐ�b�̒l��%d�ł�\n", b);

	return 0;
}
*/

/*
//�����Ƃ��ė^����ꂽ���l���Q�{�ɂ���
void functionDouble(int* ptX)   //x : ������     //�|�C���^�n��
{
	//�|�C���^���炻�̒��g���Q�Ƃ�����
	//*(�A�h���X�A�|�C���^)
	printf("�����̒��g : %d\n", *ptX);

	(*ptX) = (*ptX) * 2;     //�|�C���^���w���������g��2�{�ɂ���

}

int funcDouble(int x)    //�l�n��
{
	return x * 2;
}
//�|�C���^�n��
int main(void)
{
	int a = 3;
	printf("functionDouble�֐��ɂ��A�ϐ�a��2�{�ɂ��܂�\n");
	functionDouble(&a);     //a : ������

	printf("�ϐ�a�̒l��%d�ł�\n", a);

	return 0;
}
*/

/*
int main(void)
{
	char* name[] = { "Tanaka","Satou","Suzuki"};

	for (int i = 0; i < 3; i++)
	{
		printf("�������%s�ł�\n", name[i]);
	}
	return 0;
}
*/
/*
int main(void)
{

	//�e�L�X�g�̈�
	char* str = "C_Gengo";
	printf("str�̃A�h���X��%p�ł�\n", str);

	str = "abcde";
	printf("str�̃A�h���X��%p�ł�\n", str);

	//�X�^�b�N�̈�Ɋm�ۂ����ϐ��̃A�h���X���m�F
	int num = 0;
	printf("num�̃A�h���X��%p�ł�\n", &num);
	return 0;
}
*/


/*
int main(void)
{
	//������A�͕����̔z��
	char str1[] = "C_Gengo";     //8Byte
	char* str2 = "C_Gengo";

	//str1 = "abcd";    //�r���h�G���[
	str2 = "abcd";    //�G���[���N���Ȃ�

	//�������\���������ꍇ�A�����Ƃ��ĕ�����̐擪�A�h���X��n���Ă����I
	printf("str1��%s�ł�\n", str1);
	printf("str2��%s�ł�\n", str2);

	return 0;
}
*/





/*
int main(void)
{
	int num = 16;
	//�ϐ��̃A�h���X�i��������̒u���ꏊ�j���擾�ł���    &�ϐ���
	printf("num addr:%p\n", &num);

	//�A�h���X���L�����Ă������߂̕ϐ�
	//�|�C���^
	//�f�[�^�^* �ϐ����G�@�@�Ɛ錾����
	int* ptA;
	ptA = &num;   //�|�C���^��num�̃A�h���X����


	//�A�h���X�i�ƃf�[�^�^�j������΂��̒��g���Q�Ƃł���
	//*(�A�h���Xor�|�C���^)�@�@�@�ŎQ�Ƃł���
	printf("ptA�̎Q�Ɛ�@%d\n", *ptA);

	//�z��ƃA�h���X�A�|�C���^�̊֌W
	int tbl[3] = { 10, 20, 30 };

	//�z�񖼂͔z��̐擪�A�h���X
	printf("tbl�̐擪�v�f�̒��g ���܂܂�         %d\n", tbl[0]);
	printf("tbl�̐擪�v�f�̒��g �A�h���X����Q�� %d\n", *tbl);

	printf("tbl[1]�̒��g ���܂܂�                %d\n", tbl[1]);
	printf("tbl[1]�̒��g �A�h���X����Q��        %d\n", *(tbl + 1));

	return 0;
}
*/