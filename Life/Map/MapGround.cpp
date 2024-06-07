#include "MapGround.h"

MapGround::MapGround():
	MapHandle(-1)
{
}

MapGround::~MapGround()
{
}

void MapGround::Init()
{
	//3D���f���ǂݍ���
	MapModel = MV1LoadModel("MapData/Ground.mv1");

	//�}�b�v�̑傫���ݒ�
	MapSize = 5.0f;

	MapPosX = 0.0f;
	MapPosY = -8.0f;
	MapPosZ = 0.0f;

	//�}�b�v�̃X�P�[���ݒ�
	MV1SetScale(MapModel, VGet(MapSize, MapSize, MapSize));

	//�n���h���ɓn��
	MapHandle = MapModel;
}

void MapGround::Update()
{
}

void MapGround::Draw()
{
	Mapplace(MapHandle, MapPosX, MapPosY, MapPosZ);

}

void MapGround::End()
{
	MV1DeleteModel(MapModel);
}

void MapGround::Mapplace(int handle, float x, float y, float z)
{
	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(handle, VGet(x, y, z));
	
	//3D���f���`��
	MV1DrawModel(handle);
}
