#pragma once
#include "Point.h"
#include "TimeCount.h"

//�Z�[�u�f�[�^�̍\����
typedef struct
{
	int Distance;     //�ړ�����
	int Point;        //�|�C���g
	int Time;         //�o�ߎ���
}save_data_t;

class Save
{
public:
	Save();
	~Save();

	void SaveInit();

	void SaveDate(Point& point, TimeCount& timecount);

	void SaveInput();

	void SaveLoad();

	save_data_t save_date;

	bool Start = false;
	bool end = false;

	int name; //�Z�[�u�̖��O���͕ۑ��ϐ��錾
	int White;  //�F�̐錾

	//�T�E���h�p�i�[�ϐ�
	int Soundname;

};

