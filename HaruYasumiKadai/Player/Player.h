#pragma once
#include "PlayerBase.h"

class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	virtual void Init();  //����������
	virtual void InitBack();  //���̏���������
	virtual void Update();  //�X�V�������s��
	virtual void UpdateBack();  //���̍X�V����
	virtual void Draw();  //�`�揈�����s��
	virtual void DrawBack();  //���̕`�揈�����s��
	virtual void End();  //�I���������s��
	virtual void EndBack();  //���̏I���������s��

	//Player�̎��S����
	bool PlayerDead;

	//Player�̃W�����v��
	float PlayerJumpPower;

	//Player�̃W�����v�t���O
	bool PlayerJump;

	//Player�̏d��
	float PlayerGravity;

private:
	//Player�̎΂߈ړ��̎��̑��x�𗎂Ƃ��ϐ�
	bool m_diagonalX, m_diagonalY;
};

