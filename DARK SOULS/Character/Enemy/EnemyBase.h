#pragma once
#include "Character/CharacterBase.h"
#define ENEMY_NOW 1

class EnemyBase : public CharacterBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtual�Ōp������Ăяo��
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//���f���n���h���̏���
	
protected:
	bool m_enemySearchFlag;  //�G�̍��G�t���O

};

