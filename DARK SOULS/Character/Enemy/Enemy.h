#pragma once
#include "EnemyBase.h"

/// <summary>
/// G‹›“G
/// </summary>
struct WeakEnemy : public EnemyBase
{
public:
	WeakEnemy();
	virtual ~WeakEnemy();

	void Init();
	void Update();
	void Draw();
	void End();
private:
};

/// <summary>
/// “G‚Ì‹““®‚âd—l
/// </summary>
class Enemy : public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void Update();
	void Draw();
	void End();

private:
	//“G‚Ì\‘¢‘Ì‚ğ”z—ñ‚Å“Ç‚İ‚İ
	//WeakEnemy enemy[ENEMY_NOW];
	std::shared_ptr<WeakEnemy> enemy[ENEMY_NOW];
};

