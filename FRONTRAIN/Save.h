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

//�n�C�X�R�A�p�̍\����
typedef struct
{
	int Distance;    //�ړ�����
	int Point;       //�|�C���g
	int Time;        //�o�ߎ���
}save_hiscore_t;

class Save
{
public:
	Save();
	~Save();

	void FinalizeSave();
	void SaveInit();

	void SaveDate(Point& point, TimeCount& timecount);

	int GetHiScore(void);

	void SaveInput();
	void NameOutPut();

	void SaveLoad();
	void SaveHiscoreLoad();

	save_data_t save_date;

	save_hiscore_t save_hiscore;

	bool Start = false;
	bool end = false;

	int name; //�Z�[�u�̖��O���͕ۑ��ϐ��錾
	int White;  //�F�̐錾

	char String[20];  //���O�o��

	int hiscore = 0;   //�n�C�X�R�A

	//�T�E���h�p�i�[�ϐ�
	int Soundname;

};

