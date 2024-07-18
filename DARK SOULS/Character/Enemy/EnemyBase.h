#pragma once
#include "Character/CharacterBase.h"
#define ENEMY_NOW 1

class EnemyBase : public CharacterBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtual‚ÅŒp³æ‚ğŒÄ‚Ño‚·
	virtual void End();
	
protected:
	bool m_enemySearchFlag;  //“G‚Ìõ“Gƒtƒ‰ƒO

};

