#pragma once
#include "Col/RectCol.h"
#include "Col/SphereCol.h"


class MachineBase
{
public:
	MachineBase(){}
	virtual ~MachineBase(){}

	SphereCol GetCol() { return m_col; }

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//�}�V���̃T�C�Y�ݒ�
	float MachineSize = 0.0f;

	//�L�����N�^�[�̈ړ��O�̍��W�擾
	VECTOR m_previous = VGet(0.0f, 0.0f, 0.0f);

protected:
	//�}�V���̃��f���i�[�ϐ�
	int MachineModel = 0;

	//�}�V���̉�]�ϐ�
	float MachineRotate = 0.0f;

	//�}�V���̍ő�G�l���M�[
	float m_machineMaxEnergy = 100.0f;

	//���܂�}�V���̃G�l���M�[
	float m_machineenergy = 0.0f;

	//���Ԃ��L�^���邽�߂̕ϐ�
	float time = 0.0f;

	//�����s���邽�߂̔���
	bool one = false;

	//�}�V���̍��W�ʒu
	float MachineX = 0.0f;
	float MachineY = 0.0f;
	float MachineZ = 0.0f;

	//�����蔻��p�����o�ϐ�
	Pos3 m_pos;
	Size m_size;
	RectCol m_rect;
	SphereCol m_col;
	float m_radius = 0.0f;

	unsigned int m_color = 0xffffff;
	unsigned int m_color1 = 0xffffff;
};

