#include "StringUtility.h"
#include<cassert>
#include "windows.h"

std::wstring 
StringUtility::StringToWString(const std::string& str)
{
	//in : ��񑤂�string
	//out : �߂�l��wstiring



	std::wstring ret;//�ŏI�I�ɕԂ����C�h������

	//1��ڂ̌Ăяo��
	int result = MultiByteToWideChar(
		CP_ACP,   //�R�[�h�y�[�W
		0,        //�����̎�ނ��w�肷��t���O
		str.data(),   //�}�b�v��������̃A�h���X
		str.length(), //�}�b�v��������̃o�C�g��
		nullptr,      //�}�b�v�惏�C�h�����������o�b�t�@�̃A�h���X
		0);           //�o�b�t�@�̃T�C�Y

	//��x�ڂ̌Ăяo���̖߂�l���A�ϊ��㕶����̕����񐔂ɂȂ��Ă��܂�

	//�W���̓���ȏ�����
	//��{�I�ɂ͐������r�b�g����\���Ă���Ǝv���Ă�������
	//�擪��u�����Ă�����̂́A�����Ȃ�(unsigned)��\���Ă��܂�
	uint8_t a; //8bit�����Ȃ�
	int8_t b;  //8bit��������
	uint16_t c;//16bit�����Ȃ�
	int16_t d; //16bit��������
	uint32_t e;//32bit�����Ȃ�
	int32_t f; //32bit��������
	byte g;    //


	assert(result >= 0);

	ret.resize(result);//�󂯎��镶����̃o�b�t�@���m�ۂ���
	return std::wstring();
}
