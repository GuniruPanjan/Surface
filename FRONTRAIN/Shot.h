#pragma once

#define SHOT 30


class Shot
{
public:
	Shot();
	~Shot();

	void Init();
	void Update();
	void Draw();

	//�e�����邩�̃V���b�g�t���O
	bool ShotFlag;

	//�V���b�g�̈ʒu
	int X;
	int Y;

	//�V���b�g�̑傫�����m��
	int Wdit;
	int Hight;

	Shot* shot[SHOT];

private:
	int ShotGraph;
	
	
	
};

