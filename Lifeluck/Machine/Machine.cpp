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

	m_pos = Pos3(MachineX + 3.0f, 30.0f, MachineZ + 20.0f);
	m_size = Size(50.0f, 50.0f, 30.0f);
	m_rect.Init(m_pos, m_size);
}

void Machine::Update()
{
}

void Machine::Draw()
{
	float halfW = m_size.width * 0.5f;
	float halfH = m_size.height * 0.5f;
	float halfD = m_size.depth * 0.5f;

	float right = m_pos.x + halfW;
	float left = m_pos.x - halfW;
	float top = m_pos.y + halfH;
	float bottom = m_pos.y - halfH;
	float front = m_pos.z - halfD;
	float back = m_pos.z + halfD;

	// ���̐�
	DrawLine3D(VGet(left, bottom, front), VGet(right, bottom, front), m_color);
	DrawLine3D(VGet(left, top, front), VGet(right, top, front), m_color);
	DrawLine3D(VGet(left, bottom, back), VGet(right, bottom, back), m_color);
	DrawLine3D(VGet(left, top, back), VGet(right, top, back), m_color);
	// �c�̐�
	DrawLine3D(VGet(left, top, front), VGet(left, bottom, front), m_color);
	DrawLine3D(VGet(right, top, front), VGet(right, bottom, front), m_color);
	DrawLine3D(VGet(left, top, back), VGet(left, bottom, back), m_color);
	DrawLine3D(VGet(right, top, back), VGet(right, bottom, back), m_color);
	// �O��̐�
	DrawLine3D(VGet(left, top, front), VGet(left, top, back), m_color);
	DrawLine3D(VGet(left, bottom, front), VGet(left, bottom, back), m_color);
	DrawLine3D(VGet(right, top, front), VGet(right, top, back), m_color);
	DrawLine3D(VGet(right, bottom, front), VGet(right, bottom, back), m_color);

	//�|�W�V������ݒ��`�������
	SetPosition(MachineModel, MachineX, MachineY, MachineZ, MachineRotate);
}

void Machine::End()
{
	//���������
	MV1DeleteModel(MachineModel);
}

bool Machine::IsHit(const CapsuleCol& col)
{
	bool IsHit = m_rect.IsHit(col);

	if (IsHit)
	{
		m_color = 0x00ffff;
	}
	else
	{
		m_color = 0xffffff;
	}

	return IsHit;
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
