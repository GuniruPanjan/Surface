#pragma once
class Background
{
public:
	Background();
	~Background();

	void Finalize();
	void Init();
	void Draw();

	//”wŒi‚Ì‰æ‘œ‚ğ“ü‚ê‚é•Ï”
	int BackGroundGraph;
	int RedTitle;
	
	//‰æ–Ê‚ğ—h‚ç‚·•Ï”
	int BackX,BackY;
	//‰æ–Ê‚ğÔ‚­‚·‚é
	int Red;

	//‰æ–Ê‚ğˆÃ‚­‚·‚é
	int Darken;
};

