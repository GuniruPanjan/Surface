#pragma once
#include "DxLib.h"
class Player
{
public:
	Player();
	virtual ~Player();

	void Load();
	void Delete();

	void Init();
	void Update();
	void Draw();

	void SetCameraAngle(float angle) { m_cameraAngle = angle; }

private:
	//�A�j���[�V�����̐i�s
	//���[�v�������ǂ�����Ԃ�
	bool UpdateAnim(int attackNo);
	
	//�A�j���[�V�����̕ύX
	void ChangeAnim(int animIndex);

private:
	int m_modelHandle;  //���f���n���h��

	int m_currentAnimNo;    //���݂̃A�j���[�V����
	int m_prevAnimNo;       //�ύX�O�̃A�j���[�V����
	float m_animBlendRate;  //�A�j���[�V���������K��

	//�\�����
	VECTOR m_pos;
	float m_angle;

	//�J�������
	float m_cameraAngle;

	bool m_isAttack;   //�U�����t���O
};

