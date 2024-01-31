#pragma once
class Explanation
{
public:
	Explanation();
	~Explanation();

	void ExplanationInit();
	void ExplanationUpdate();
	void ExplanationDraw();

	//à–¾—p‚Ì‰æ‘œ‚ğ“Ç‚İ‚Ş•Ï”
	int UnderKey = 0;
	int LeftKey = 0;
	int RightKey = 0;
	int LeftClick = 0;
	int RightClick = 0;
	int Mouse = 0;
	int Graph = 0;

	//‰æ‘œ‚Ì“§‰ß‹ï‡‚ğŒˆ‚ß‚é•Ï”
	int UK = 0;
	int LK = 0;
	int RK = 0;
};

