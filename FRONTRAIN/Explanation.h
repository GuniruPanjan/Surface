#pragma once
class Explanation
{
public:
	Explanation();
	~Explanation();

	void FinalizeExplanation();
	void ExplanationInit();
	void ExplanationUpdate();
	void ExplanationDraw();

	//�����p�̉摜��ǂݍ��ޕϐ�
	int UnderKey = 0;
	int LeftKey = 0;
	int RightKey = 0;
	int LeftClick = 0;
	int RightClick = 0;
	int Mouse = 0;
	int Graph = 0;

	//�摜�̓��ߋ�����߂�ϐ�
	int UK = 0;
	int LK = 0;
	int RK = 0;

	//���F��`�悷��
	int WhiteColor;
};

