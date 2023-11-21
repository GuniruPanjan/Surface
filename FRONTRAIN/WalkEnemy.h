#pragma once
#include "EnemyBase.h"
#include "Player.h"
class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init();
	void Update(Shot& shot);
	void Draw();

	int WalkEnemyGraph;

	//�G�̌��ݒn
	int WalkEnemyX, WalkEnemyY;

	//�G�l�~�[�̑傫���擾����ϐ�
	int WalkEnemyW, WalkEnmeyH;
};

