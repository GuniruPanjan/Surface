#pragma once
#include "Col/RectCol.h"


class MachineBase
{
public:
	MachineBase(){}
	virtual ~MachineBase(){}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//�}�V���̃��f���i�[�ϐ�
	int MachineModel = 0;

	//�}�V���̃T�C�Y�ݒ�
	float MachineSize = 0.0f;

	//�}�V���̉�]�ϐ�
	float MachineRotate = 0.0f;

	//�}�V���̍ő�G�l���M�[
	float MachineMaxEnergy = 0.0f;

	//�}�V���̍��W�ʒu
	float MachineX = 0.0f;
	float MachineY = 0.0f;
	float MachineZ = 0.0f;
protected:
	Pos3 m_pos;
	Size m_size;
	RectCol m_rect;

	unsigned int m_color = 0xffffff;
};

