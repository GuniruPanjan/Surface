#include "MapGround.h"

MapGround::MapGround():
	MapHandle(-1)
{
	for (int i = 0; i <= 50; i++)
	{
		BushHandle[i] = -1;
	}
}

MapGround::~MapGround()
{
}

void MapGround::Init()
{
	//3D���f���ǂݍ���
	GroundMapModel = MV1LoadModel("MapData/Ground.mv1");
	BushModel = MV1LoadModel("MapData/BushModel.mv1");

	//�}�b�v�̑傫���ݒ�
	MapSize = 5.0f;
	BushSize = 30.0f;

	MapPosX = 0.0f;
	MapPosY = -8.0f;
	MapPosZ = 0.0f;

	//�}�b�v�̃X�P�[���ݒ�
	MV1SetScale(GroundMapModel, VGet(MapSize, MapSize, MapSize));
	MV1SetScale(BushModel, VGet(BushSize, BushSize, BushSize));

	//�n���h���ɓn��
	MapHandle = GroundMapModel;

	for (int i = 0; i <= 50; i++)
	{
		BushHandle[i] = MV1DuplicateModel(BushModel);
	}
}

void MapGround::Update()
{
}

void MapGround::Draw()
{
	Mapplace(MapHandle, MapPosX, MapPosY, MapPosZ);

	MapWall(BushHandle, -1250.0f, 0.0f, 1250.0f, 50.0f, 0.0f);
}

void MapGround::End()
{
	MV1DeleteModel(GroundMapModel);
	MV1DeleteModel(BushModel);
}

void MapGround::Mapplace(int handle, float x, float y, float z)
{
	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(handle, VGet(x, y, z));
	
	//3D���f���`��
	MV1DrawModel(handle);
}

void MapGround::MapWall(int handle[], float x, float y, float z, float width, float depth)
{

	for (int i = 0; i <= 50; i++)
	{
		//3D���f���|�W�V�����ݒ�
		MV1SetPosition(handle[i], VGet(x + width * i, y, z + depth * i));

		//3D���f���`��
		MV1DrawModel(handle[i]);
	}
	


}
