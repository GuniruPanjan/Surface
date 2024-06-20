#pragma once
#include "MapBase.h"
#include "Col/RectCol.h"


class MapObject : public MapBase
{
public:
	MapObject();
	virtual ~MapObject();

	void Init();
	void Update();
	void Draw();
	void End();
private:
	//ブッシュのハンドル
	int MapBushHandle;
	Pos3 m_pos1, m_pos2, m_pos3, m_pos4;
	Size m_size1, m_size2, m_size3, m_size4;
	RectCol m_rect1, m_rect2, m_rect3, m_rect4;
};

