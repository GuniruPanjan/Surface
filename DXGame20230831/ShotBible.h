#pragma once
#include "ShotBase.h"
class ShotBible : public ShotBase
{
public:
	ShotBible();
	virtual ~ShotBible();

	virtual void Init() override;

	virtual void Update() override;
	virtual void Draw() override;

	//�e���X�^�[�g������
	virtual void Start(Vec2 pos) override;

private:

	//�����Ԍo�߂�����������߂ɐ������Ă���̃t���[���𐔂���
	int m_frameCount;

	//�v���C���[���猩�Ăǂ̕����ɂ��邩
	float m_angle;
};
