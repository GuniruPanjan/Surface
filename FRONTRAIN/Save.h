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

	void SaveDraw(Point& point, TimeCount& timecount);

};

