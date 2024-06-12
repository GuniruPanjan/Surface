#include "Machine.h"

Machine::Machine()
{
	MachinePosition = VGet(0.0f, 0.0f, 0.0f);
}

Machine::~Machine()
{
	//メモリ解放
	MV1DeleteModel(MachineModel);
}

void Machine::Init()
{
	//マシンに溜まる最大のエネルギー量
	MachineMaxEnergy = 100.0f;

	MachineX = -200.0f;
	MachineY = -18.0f;
	MachineZ = 0.0f;

	MachineSize = 100.0f;
	MachineRotate = 1.58f;

	MachineModel = MV1LoadModel("MachineData/MachineModel.mv1");

	//モデルのサイズ設定
	MV1SetScale(MachineModel, VGet(MachineSize, MachineSize, MachineSize));
}

void Machine::Update()
{
}

void Machine::Draw()
{
	//ポジションや設定や描画をする
	SetPosition(MachineModel, MachineX, MachineY, MachineZ, MachineRotate);
}

void Machine::End()
{
	//メモリ解放
	MV1DeleteModel(MachineModel);
}

void Machine::SetPosition(int handle, float x, float y, float z,float rotate)
{
	//3Dモデルポジション設定
	MV1SetPosition(handle, VGet(x, y, z));

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(handle, VGet(rotate, 0.0f, 0.0f));

	//3Dモデル描画
	MV1DrawModel(handle);
}
