#include "Machine.h"

Machine::Machine()
{
	MachinePosition = VGet(0.0f, 0.0f, 0.0f);
}

Machine::~Machine()
{
	//���������
	MV1DeleteModel(MachineModel);
}

void Machine::Init()
{
	//�}�V���ɗ��܂�ő�̃G�l���M�[��
	MachineMaxEnergy = 100.0f;

	MachineX = -200.0f;
	MachineY = -18.0f;
	MachineZ = 0.0f;

	MachineSize = 100.0f;
	MachineRotate = 1.58f;

	MachineModel = MV1LoadModel("MachineData/MachineModel.mv1");

	//���f���̃T�C�Y�ݒ�
	MV1SetScale(MachineModel, VGet(MachineSize, MachineSize, MachineSize));
}

void Machine::Update()
{
}

void Machine::Draw()
{
	//�|�W�V������ݒ��`�������
	SetPosition(MachineModel, MachineX, MachineY, MachineZ, MachineRotate);
}

void Machine::End()
{
	//���������
	MV1DeleteModel(MachineModel);
}

void Machine::SetPosition(int handle, float x, float y, float z,float rotate)
{
	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(handle, VGet(x, y, z));

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(handle, VGet(rotate, 0.0f, 0.0f));

	//3D���f���`��
	MV1DrawModel(handle);
}
