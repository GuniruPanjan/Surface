#include "MapGround.h"

MapGround::MapGround() :
	MapHandle(-1)
{
	
}

MapGround::~MapGround()
{
}

void MapGround::Init()
{
	//3D���f���ǂݍ���
	GroundMapModel = MV1LoadModel("MapData/Ground.mv1");

	//�}�b�v�̑傫���ݒ�
	MapSize = 5.0f;

	MapPosX = 0.0f;
	MapPosY = -8.0f;
	MapPosZ = 0.0f;

	//�}�b�v�̃X�P�[���ݒ�
	MV1SetScale(GroundMapModel, VGet(MapSize, MapSize, MapSize));

	MapPos = VGet(MapPosX, MapPosY, MapPosZ);

	//�n���h���ɓn��
	MapHandle = GroundMapModel;
}

void MapGround::Update()
{
}

void MapGround::Draw()
{
	//3D�}�b�v�̃|�W�V�����ݒ�
	MV1SetPosition(MapHandle, MapPos);

	//3D�}�b�v�̕`��
	MV1DrawModel(MapHandle);
	
}

void MapGround::End()
{
	MV1DeleteModel(GroundMapModel);
}

