#pragma once
#include "Character/CharacterBase.h"
#define ENEMY_NOW 1  //“G‚Ì”z—ñ‚Åo‚·”

class Player;

class EnemyBase : public CharacterBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtual‚ÅŒp³æ‚ğŒÄ‚Ño‚·
	void Init() {};
	void Update() {};
	void Draw() {};
	virtual void End();
	
protected:
	bool m_enemySearchFlag;  //“G‚Ìõ“Gƒtƒ‰ƒO
	float m_searchRadius;  //‰~‚Ì“–‚½‚è”»’è
	Pos3 m_colSearchPos;  //õ“G”ÍˆÍ‚Ì“–‚½‚è”»’è
	SphereCol m_colSearch;  //ƒXƒtƒBƒAŒ^‚Ì“–‚½‚è”»’è
};

