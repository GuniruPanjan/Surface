#include <iostream>

//�N���X�ƃ|�C���^
//��̍\���̂Ɠ���
class TestClass
{
public:
	TestClass();
	~TestClass();

	void print();
	//�����o�[�ϐ��͖{�����S�̂���private�ɂ���̂��]�܂�����
	//�����̓s���㍡���public��
public:
	//�����̓s����A�����o�[�͂SByte�̕ϐ��̂ݎg��
	int num0;     //4
	int num1;     //8
	float fnum0;  //12
	float fnum1;  //16

};
//�R���X�g���N�^
TestClass::TestClass():
	num0(10),
	num1(20),
	fnum0(30.0f),
	fnum1(40.0f)
{

}
//�f�X�g���N�^
TestClass::~TestClass()
{

}
//�����o�[�ϐ��̒l��\������
void TestClass::print()
{
	std::cout << "num1 = " << num1 << std::endl;
}


int main()
{
	//�N���X�̓�������ɂǂ̂悤�ɔz�u�����H
	TestClass testClass;

	//TestClass�̃f�[�^�T�C�Y�́H
	//sizeof���Z�q�����悤���ăT�C�Y���m�F����
	//�N���X�̏ꍇ���\���̂Ɠ������A�����o�ϐ��݂̂���������ɔz�u�����
	std::cout << "size =" << sizeof(testClass) << std::endl;

	//�N���X�̃����o�ϐ��ɃA�N�Z�X����
	//�h�b�g���Z�q���g�p����
	std::cout << "num0 =" << testClass.num0 << std::endl;
	//�N���X�̃����o�[�ϐ����Ă�
	testClass.print();
	//�N���X�̃|�C���^
	//�\���̂�int�^�̕ϐ��Ɠ���
	TestClass* ptestClass =  &testClass;
	//�|�C���^���烁���o�[�ϐ��ɃA�N�Z�X����
	//�\���̂Ɠ������A���[���Z�q���g�p����
	std::cout << "fnum0 = " << ptestClass->fnum1 << std::endl;
	//�����o�[�֐����Ă�
	//��������A���[���Z�q���g��
	ptestClass->print();




	return 0;

}

#if false
	//�ϐ��錾���s�����Ƃ��A��������ɕϐ���ۑ����邽�߂̗̈悪�m�ۂ����
	// ��������̂ǂ��ɔz�u����邩�͂킩��Ȃ�
	// �킩��Ȃ����z��͕K�����Ԃɕ���Ŋm�ۂ����
	// �\���̂͐錾�������Ԃɕ��ׂĊm�ۂ����

	//�ϐ��̐錾�@���������int�̃T�C�Y���̗̈悪�m�ۂ����
	int num = 4;
	//�z��̐錾�@int��3���������@�z��̓�������ɕ���Ŕz�u�����
	int tbl[3] = { 1,2,3 };

	//�\���̂̐錾 �\���̂̃����o�[�͍\���̂�錾�����Ƃ��ɕ��ׂ����ԂɃ������m�ۂ����
	StructTest test = 
	{
		10,     //num0
		20,     //num1
		30.0f,  //fnum0
		40.0f   //fnum1
	};
	//�\���̂̔z��
	StructTest testTbl[3];

	//�|�C���^�̐錾
	//�|�C���^���A�h���X��ۑ����邽�߂̕ϐ�
	//�f�[�^�^*�@�|�C���^���@�@�Ƃ������`���Ő錾����
	//int* pNum;   //���������Ȃ��ƃ|�C���^�̒��ɂǂ�Ȑ����������Ă��邩�킩��Ȃ�
	int* pNum = nullptr;    //�|�C���^��nullptr�ŏ���������̂���ʓI

	//int�^�̕ϐ�num�̃A�h���X���擾����pNum�ɕۑ�������
	pNum = &num;

	//pNum�̒��g�inum�̃A�h���X�j��\������
	std::cout << pNum << std::endl;

	//�A�h���XpNum�̒��ɓ����Ă��鐔�l��\������
	if (pNum != nullptr)     //nullptr�͂ǂ��������Ă��Ȃ��̂�nullptr�łȂ����Ƃ��m�F���Ă��珈������
	{
		*pNum = 10; // �|�C���^���Q�Ƃ����Ƀf�[�^���i�[����
		std::cout << (*pNum) << std::endl;   //�|�C���^���Q�Ƃ����̃f�[�^��\������
	}
	//�\���̌y�����K
	test.num0 = 16;
	std::cout << test.num0 << std::endl;



	//�\���̂̃|�C���^
	StructTest* pStructTest = &test;
	//pStructtest�̕\��
	std::cout << pStructTest << std::endl;
	//pStructTest���w���������g�̕\��
	//�\���̂̃|�C���^���炻�̃����o�[���Q�Ƃ������ꍇ�A
	//�h�b�g���Z�q(.)�ł͂Ȃ��A���[���Z�q(->)���g�p����
	std::cout << pStructTest->fnum0 << std::endl;

	return 0;
}
#endif