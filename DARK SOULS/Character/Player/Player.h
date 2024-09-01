#pragma once
#include "Character/CharacterBase.h"


class Player : public CharacterBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Action();
	void Animation(float& time, VECTOR& pos);
	void HitObj(Map& map);
	void SaveAction(Map& map);
	void Draw();
	void End();

	//�J�v�Z�����m�̓����蔻��
	bool IsCapsuleHit(const CapsuleCol& col, const CapsuleCol& col1);
	bool isSphereHit(const SphereCol& col, const SphereCol& col1, const SphereCol& col2, const SphereCol& col3, float damage, float bossdamage);

	void SetCameraAngle(float angle) { m_cameraAngle = angle; }

	VECTOR GetPos() { return m_pos; }
	float GetPosX() { return m_pos.x; }
	float GetPosY() { return m_pos.y; }
	float GetPosZ() { return m_pos.z; }
	float GetDamage() { return m_attack; }
	CapsuleCol GetCapsuleCol() { return m_capsuleCol; }
	SphereCol GetSphereCol() { return m_sphereCol; }

	bool GetLock() { return m_lockonTarget; }
	bool GetRest() { return m_restAction; }
	bool SetRest(bool rest) { return m_restAction = rest; }
	bool GetDeath() { return m_death; }

	//UI�ɕK�v�ȕϐ�
	float GetHp() { return m_hp; }
	float GetStamina() { return m_stamina; }

private:
	float m_cameraAngle;  //�J�������
	float m_updatePosX;   //X���W�X�V�p�ϐ�
	float m_updatePosY;   //Y���W�X�V�p�ϐ�
	float m_updatePosZ;   //Z���W�X�V�p�ϐ�
	float m_stamina;      //�X�^�~�i
	int m_animHeel;       //�񕜃A�j���[�V�������
	int m_recoveryNumber;     //�񕜂ł���񐔕ϐ�
	float m_recoberyAmount;   //�񕜗�
	float m_heel;             //hp�ɑ����񕜗�
	bool m_recoberyAction;    //�񕜒��̔���
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
	bool m_pushButton;   //�{�^���̓��͂���񂾂��󂯎�邽�߂̔���
	bool m_avoidanceNow;   //����ł���t���[���������f����ϐ�
	bool m_restAction;    //�񕜂��ł���悤�ɂȂ锻��
	bool m_dashMove;     //�_�b�V�����Ă锻�f�p�ϐ�
	bool m_staminaBroke;   //�X�^�~�i�؂ꔻ��
	VECTOR m_nowPos;   //���݂̃t���[���̍��W���擾����
	VECTOR m_bounceMove;   //�����o�����߂̕ϐ�

	unsigned int m_color = 0xffffff;   //�f�o�b�O�p�̐F�ύX

	//���x���֌W
	int m_hpLevel;       //HP���x��
	int m_staminaLevel;    //�X�^�~�i���x��
};

