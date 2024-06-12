#pragma once
#include "MachineBase.h"
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

	/// <summary>
	/// �`���|�W�V�����ݒ������֐�
	/// </summary>
	/// <param name="handle"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	/// <param name="rotate"></param>
	void SetPosition(int handle, float x, float y, float z,float rotate);

private:
	//�}�V���̃|�W�V�����ݒ�
	VECTOR MachinePosition;
};

