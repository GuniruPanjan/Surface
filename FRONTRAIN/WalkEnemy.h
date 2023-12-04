#pragma once
#include "EnemyBase.h"
#include "Player.h"

class Player;
class Shot;

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init();
	void Update(Player& player, Shot& shot, WalkEnemy& enemy);
	void Draw(int ScrollX);

	EnemyBase Base;

	int WalkEnemyGraph;

	//�G�̌��ݒn
	float WalkEnemyX, WalkEnemyY;

	//�G�̑傫��
	int WalkEnemyWidth, WalkEnemyHeight;

	//�G�l�~�[�̑傫���擾����ϐ�
	int WalkEnemyW, WalkEnmeyH;

	//�G�l�~�[�̃X�s�[�h
	float WalkEnemySpeed;
};

