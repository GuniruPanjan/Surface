#pragma once
class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();
};

