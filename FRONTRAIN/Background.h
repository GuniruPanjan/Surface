#pragma once
class Background
{
public:
	Background();
	~Background();

	void Finalize();
	void Init();
	void Draw();

	int BackGroundGraph;
	int RedTitle;
	
	int BackX,BackY;
	int Red;

	int WaveCount;
};

