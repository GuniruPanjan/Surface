#pragma once
#include "Col/RectCol.h"


class MachineBase
{
public:
	MachineBase(){}
	virtual ~MachineBase(){}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//マシンのモデル格納変数
	int MachineModel = 0;

	//マシンのサイズ設定
	float MachineSize = 0.0f;

	//マシンの回転変数
	float MachineRotate = 0.0f;

	//マシンの最大エネルギー
	float MachineMaxEnergy = 0.0f;

	//マシンの座標位置
	float MachineX = 0.0f;
	float MachineY = 0.0f;
	float MachineZ = 0.0f;
protected:
	Pos3 m_pos;
	Size m_size;
	RectCol m_rect;

	unsigned int m_color = 0xffffff;
};

