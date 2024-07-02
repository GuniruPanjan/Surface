#pragma once
#include "Col/RectCol.h"
#include "Col/SphereCol.h"


class MachineBase
{
public:
	MachineBase(){}
	virtual ~MachineBase(){}

	SphereCol GetCol() { return m_col; }

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//マシンのサイズ設定
	float MachineSize = 0.0f;

	//キャラクターの移動前の座標取得
	VECTOR m_previous = VGet(0.0f, 0.0f, 0.0f);

protected:
	//マシンのモデル格納変数
	int MachineModel = 0;

	//マシンの回転変数
	float MachineRotate = 0.0f;

	//マシンの最大エネルギー
	float m_machineMaxEnergy = 100.0f;

	//溜まるマシンのエネルギー
	float m_machineenergy = 0.0f;

	//時間を記録するための変数
	float time = 0.0f;

	//一回実行するための判定
	bool one = false;

	//マシンの座標位置
	float MachineX = 0.0f;
	float MachineY = 0.0f;
	float MachineZ = 0.0f;

	//当たり判定用メンバ変数
	Pos3 m_pos;
	Size m_size;
	RectCol m_rect;
	SphereCol m_col;
	float m_radius = 0.0f;

	unsigned int m_color = 0xffffff;
	unsigned int m_color1 = 0xffffff;
};

