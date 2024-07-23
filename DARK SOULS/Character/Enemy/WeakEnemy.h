#pragma once
#include "EnemyBase.h"

class WeakEnemy : public EnemyBase
{
public:
	WeakEnemy();
	virtual ~WeakEnemy();

	void Init();
	void Update();
	void Animation(float& time);
	void Draw();
	void End();

	bool isHit(const CapsuleCol& col);

	VECTOR GetPos() { return m_pos; }
	float GetPosX() { return m_pos.x; }
	float GetPosY() { return m_pos.y; }
	float GetPosZ() { return m_pos.z; }
	CapsuleCol GetCol() const { return m_col; }


private:
	unsigned int m_color = 0xffffff;

	//�����蔻��p�̃����o�ϐ�
	Pos3 m_colPos; //�����蔻��p�̃����o�ϐ�
	Vec3 m_vec;  //�����蔻��p�̃x�N�^�[�����o�ϐ�
	float m_len;  //����
	float m_radius;  //���a
	CapsuleCol m_col;  //�J�v�Z���̓����蔻��
};

