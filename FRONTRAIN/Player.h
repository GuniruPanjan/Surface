#pragma once
class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	

private:
	int HP;
	int Speed;
	//�v���C���[�̉摜������ϐ�
	int playerGraph;

	//�v���C���[�̏����ʒu
	int PlayerX;
	int PlayerY;


	//�v���C���[�̕�
	int PlayerW;
	int PlayerH;

	bool PlayerShotFlag;
	
};

