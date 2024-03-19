#pragma once
#include<memory>

class PlayerBase
{
public:
	PlayerBase();
	virtual ~PlayerBase();

	//vitrual�Ōp������Ăяo��
	virtual void Init() = 0;  //�ŏ��ɏ���������
	virtual void Update() = 0; //���t���[���X�V�������s��
	virtual void Draw() = 0;  //���t���[���`�揈�����s��
	virtual void End() = 0;  //�I������

protected:
	//�v���C���[����������Ƃ��̏d�̓x�N�g��
	float m_gravity;
	//�v���C���[���}�~������Ƃ��̃x�N�g��
	float m_swoop;
	//�v���C���[���ړ�����Ƃ��̃x�N�g��
	float m_move;
	//�v���C���[�̃O���t�i�[�ϐ�
	int m_playergraph;

};

