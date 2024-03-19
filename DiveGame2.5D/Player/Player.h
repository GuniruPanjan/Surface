#pragma once
#include "PlayerBase.h"
#include "Rect.h"

class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	virtual void Init();  //�ŏ��ɏ���������
	virtual void Update(); //���t���[���s���X�V����
	virtual void Draw();  //���t���[���`�揈��
	virtual void End();  //�I������

	//�����蔻��̋�`
	Rect m_colRect;

private:
	//�v���C���[�̍��W
	float m_playerX, m_playerY;
};

