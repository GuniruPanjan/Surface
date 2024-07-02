#pragma once
#include "MapBase.h"
#include "Col/RectCol.h"

class MapGoal : public MapBase
{
public:
	MapGoal();
	virtual ~MapGoal();

	void Init();
	void Update();
	void Draw();
	void End();

	bool IsHit(const CapsuleCol& col);
	bool IsHitWall(const CapsuleCol& col);

	//m_goal変数を返す
	bool GetGoal() { return m_goal; }
private:
	//ハウスモデルのハンドル
	int HouseHandle;
	Pos3 m_pos, m_pos1, m_pos2, m_pos3, m_pos4;
	Size m_size, m_size1, m_size2, m_size3, m_size4;
	RectCol m_col, m_col1, m_col2, m_col3, m_col4;

	unsigned int m_color = 0xffffff;
	unsigned int m_colorwall = 0xffffff;

	//ゴールしたかを判断するための変数
	bool m_goal;

};

