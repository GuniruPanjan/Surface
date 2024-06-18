#include "MapGoal.h"

MapGoal::MapGoal():
	HouseHandle(-1)
{
}

MapGoal::~MapGoal()
{
}

void MapGoal::Init()
{
	//3D���f���̓ǂݍ���
	MapHouseModel = MV1LoadModel("MapData/HouseModel.mv1");

	MapHousePosX = 0.0f;
	MapHousePosY = -25.0f;
	MapHousePosZ = -1150.0f;

	MapHouseSize = 250.0f;

	//�}�b�v�̃X�P�[���ݒ�
	MV1SetScale(MapHouseModel, VGet(MapHouseSize, MapHouseSize, MapHouseSize));

	MapHousePos = VGet(MapHousePosX, MapHousePosY, MapHousePosZ);

	HouseHandle = MapHouseModel;
}

void MapGoal::Update()
{

}

void MapGoal::Draw()
{
	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(HouseHandle, MapHousePos);

	//3D���f���̉�]�l���Z�b�g����
	MV1SetRotationXYZ(HouseHandle, VGet(0.0f, 3.14f, 0.0f));

	//3D���f���`��
	MV1DrawModel(HouseHandle);
}

void MapGoal::End()
{
	//���������
	MV1DeleteModel(MapHouseModel);
}
