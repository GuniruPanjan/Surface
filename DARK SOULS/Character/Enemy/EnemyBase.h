#pragma once
#include "Character/CharacterBase.h"

class EnemyBase : public CharacterBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtual�Ōp������Ăяo��
	virtual void Init();
	virtual void Update();
	virtual void Draw();

	//���f���n���h���̏���
	
protected:
	bool m_enemySearchFlag;  //�G�̍��G�t���O

};

