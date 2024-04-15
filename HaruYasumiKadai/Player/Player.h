#pragma once
#include "PlayerBase.h"

class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	virtual void Init();  //����������
	virtual void Update();  //�X�V�������s��
	virtual void Draw();  //�`�揈�����s��
	virtual void End();  //�I���������s��

	//Player�̎��S����
	bool PlayerDead;

private:
	//Player�̎΂߈ړ��̎��̑��x�𗎂Ƃ��ϐ�
	bool m_diagonalX, m_diagonalY;
};

