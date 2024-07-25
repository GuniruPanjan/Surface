#pragma once
#include "Character/CharacterBase.h"
#define ENEMY_NOW 1  //�G�̔z��ŏo����

class Player;

class EnemyBase : public CharacterBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtual�Ōp������Ăяo��
	void Init() {};
	void Update() {};
	void Draw() {};
	virtual void End();
	
protected:
	bool m_enemySearchFlag;  //�G�̍��G�t���O
	float m_searchRadius;  //�~�̓����蔻��
	Pos3 m_colSearchPos;  //���G�͈͂̓����蔻��
	SphereCol m_colSearch;  //�X�t�B�A�^�̓����蔻��
};

