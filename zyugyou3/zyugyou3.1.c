#include<stdio.h>

int main(void)
{

	//false��0
	//true��0�ȊO
	if (4)
	{
		printf("���s�����\n");

	}
	int keyNum = 0;
	if (keyNum)
	{
		printf("���҂��Ă�@%d\n", keyNum);
	}
	else
	{
		printf("�������ĂȂ�\n");
	}




	int num = 0;
	int num2 = 1;

	//false��0
	//true��1

	printf("(num == 1)�̒��g��\���@%d\n", num == 1);     //false
	printf("(num == 0)�̒��g��\���@%d\n", num == 0);     //true

	printf("%d\n", num == 0 && num2 == 1); //true
	printf("%d\n", num == 0 || num2 == 0); //true

	printf("%d\n", num == 3 && num2 == 3); //false
	printf("%d\n", num == 3 || num2 == 3); //false

	//false��0
	//true��0�ȉ�

	int result = (num == 1);
	printf("result = %d\n", result);

	if (result)
	{
		printf("result:true\n");
	}
	else
	{
		printf("result:false\n");
	}







	return 0;
}








/*
//switch��
int main(void)
{
	int a = 7;
	int b = a % 3;       //a���R�Ŋ������]��

	printf("�ϐ�a�̒l��%d�ł�\n", a);

	switch (b)
	{
	case 0:
		printf("�ϐ�a���R�Ŋ������]��͂O�ł�\n");
		break;
	case 1:
		printf("�ϐ�a���R�Ŋ������]��͂P�ł�\n");
		break;
	default:
		printf("�ϐ�a���R�Ŋ������]��͂Q�ł�\n");
		break;
	}

	//if-else���g���ď�������
	if (b == 0) {
		printf("�ϐ�a���R�Ŋ��������܂��0�ł�\n");
	}
	else if (b == 1) {
		printf("�ϐ�a���R�Ŋ��������܂��1�ł�\n");
	}
	else {
		printf("�ϐ�a���R�Ŋ��������܂��2�ł�\n");
	}

	//�������򂢂�Ȃ����H
	printf("�ϐ�a��3�Ŋ������]���%d�ł�\n", b);


}










//if���̕��K
int main(void)
{
	
	
	int keyNum = 1;

	int playerPower = 60;

	
	if (keyNum >= 1) {
		//�o�p�̒��ɍD���Ȃ���������������
		printf("�����J����\n");
		printf("����%d�����\n", keyNum);
		keyNum--;  //��������炷
		printf("�c��̌� : %d\n", keyNum);
	}
	else {
		printf("���͊J���Ȃ�\n");
	}
	if (keyNum >= 1 || playerPower >= 50) {
		printf("���Q���J����\n");
		
		if (playerPower >= 50) {
			
			printf("�͂����Ŕ����J����\n");
		
		}
	
		else {
		
			printf("���ŊJ����\n");
		
			keyNum--;     //��������炷
		
			printf("�c��̌� : %d\n", keyNum);
	}
	//�C���f���g�ɋC��t����
	

}
	*/