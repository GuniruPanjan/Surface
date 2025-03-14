#pragma once
#include "MachineBase.h"
#include "Player/Player.h"
#include "DxLib.h"

class Machine : public MachineBase
{
public:
	Machine();
	virtual ~Machine();

	void Init();
	void Update();
	void Draw();
	void End();

	//マシンのエネルギー関係の関数
	void MachineEnergy(float giveenergy);

	bool IsHit(const CapsuleCol& col, Player& player);
	bool IsHitCapsule(const CapsuleCol& col, Player& player);

	/// <summary>
	/// 描画やポジション設定をする関数
	/// </summary>
	/// <param name="handle"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	/// <param name="rotate"></param>
	void SetPosition(int handle, float x, float y, float z,float rotate);

private:
	//マシンのポジション設定
	VECTOR MachinePosition;
	//マシンの完成した数
	int m_completemachine;
};

