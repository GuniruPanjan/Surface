#pragma once
#include "Rect.h"
#include<memory>



class PlayerBase
{
public:
	PlayerBase();
	virtual ~PlayerBase() {}

	//virtual�Ōp������Ăяo��

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//Player�̃X�s�[�h
	float PlayerSpeed;
	//Player�̉摜�ۑ�
	int PlayerGraph;
	//Player��X,Y���W
	float PlayerX, PlayerY;
	//Player�̃X�N���[��
	float PlayerScroll;

	//Player�̓����蔻�蕝
	int PlayerWidth, PlayerHeight;

	//Rect���Ǘ�����|�C���^
	Rect m_colrect;
};

