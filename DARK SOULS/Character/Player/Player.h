#pragma once
#include "Character/CharacterBase.h"
#include "Character/Enemy/Enemy.h"

class Player : public CharacterBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Action();
	void Animation(int& A, float& time, VECTOR& pos);
	void Draw();
	void End();

	//�J�v�Z�����m�̓����蔻��
	bool IsHit(const CapsuleCol& col);

	void SetCameraAngle(float angle) { m_cameraAngle = angle; }

	VECTOR GetPos() { return m_pos; }
	float GetPosX() { return m_pos.x; }
	float GetPosY() { return m_pos.y; }
	float GetPosZ() { return m_pos.z; }
	CapsuleCol GetCol() { return m_col; }


	bool GetLock() { return m_lockonTarget; }
	

private:
	float m_cameraAngle;  //�J�������
	bool m_lockonTarget;  //�^�[�Q�b�g���b�N�I������
	int m_moveAnimFrameIndex;  //�t���[������������
	int m_moveAnimShieldFrameIndex;  //�K�[�h����Ƃ��̃t���[������
	int m_a;  //�������m�F�ϐ�
	int m_pad;  //�p�b�h���͏����ϐ�
	XINPUT_STATE m_xpad;  //�p�b�h����
	int m_animRollAttack;  //�L���������[�f�B���O��ɍU������A�j���[�V����
	bool m_avoidance;   //�����͂𔻒f���邽�߂̕ϐ�
	bool m_nextAttack1;  //���̍U������
	bool m_nextAttack2;  //���̍U������
	VECTOR m_nowPos;   //���݂̃t���[���̍��W���擾����

	//�����蔻��p�̃����o�ϐ�
	Pos3 m_colPos; //�����蔻��p�̃����o�ϐ�
	Vec3 m_vec;  //�����蔻��p�̃x�N�^�[�����o�ϐ�
	float m_len;  //����
	float m_radius;  //���a
	CapsuleCol m_col;  //�J�v�Z���̓����蔻��

	unsigned int m_color = 0xffffff;   //�f�o�b�O�p�̐F�ύX
};

