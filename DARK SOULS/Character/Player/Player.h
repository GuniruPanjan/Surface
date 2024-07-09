#pragma once
#include "Character/CharacterBase.h"

class Player : public CharacterBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Animation(int& A, float& time, VECTOR& pos);
	void Draw();
	void End();

	void SetCameraAngle(float angle) { m_cameraAngle = angle; }

	VECTOR GetPos() { return m_pos; }
	float GetPosX() { return m_pos.x; }
	float GetPosY() { return m_pos.y; }
	float GetPosZ() { return m_pos.z; }

private:
	float m_cameraAngle;  //�J�������
	int m_moveAnimFrameIndex;  //�t���[������������
	int m_a;  //�������m�F�ϐ�
	int m_pad;  //�p�b�h���͏����ϐ�
	bool m_avoidance;   //�����͂𔻒f���邽�߂̕ϐ�
	VECTOR m_nowPos;   //���݂̃t���[���̍��W���擾����
};

