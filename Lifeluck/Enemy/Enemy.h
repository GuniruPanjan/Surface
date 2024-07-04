#pragma once
#include "EnemyBase.h"
#include "Col/CapsuleCol.h"
#include "Col/RectCol.h"

class Enemy : public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void Update();
	void Draw();

	CapsuleCol GetCol() const { return m_col; }
	bool IsHit(const CapsuleCol& col);

	void End();

private:
	//�G�l�~�[�̃��[�V�����i�[�ϐ�
	int EnemyAnim[3];
	//���[�V�����̃g�[�^������
	float TotalTime[3];

	//�G�l�~�[�̃��[�V�����ǂݍ��ݕϐ�
	int EnemyWark;

	//�Đ�����
	float PlayTime;

	//�����蔻��p�����o�ϐ�
	Pos3 m_pos;
	Vec3 m_vec;
	Size m_size;
	float m_len;
	float m_radius;
	RectCol m_rect;
	CapsuleCol m_col;

	unsigned int m_color = 0xffffff;
};

