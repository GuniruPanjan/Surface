#pragma once
class Background
{
public:
	Background();
	~Background();

	void Finalize();
	void Init();
	void Draw();

	//�w�i�̉摜������ϐ�
	int BackGroundGraph;
	int RedTitle;
	
	//��ʂ�h�炷�ϐ�
	int BackX,BackY;
	//��ʂ�Ԃ�����
	int Red;

	//��ʂ��Â�����
	int Darken;
};

