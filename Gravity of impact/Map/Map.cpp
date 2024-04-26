#include "Map.h"

Map::Map():
	MapObject(0),
	MapX(0.0f),
	MapY(0.0f),
	MapZ(0.0f),
	MapScale(0.0f)
{
	MapPosition = VGet(0.0f, 0.0f, 0.0f);
}

Map::~Map()
{
}

void Map::Init()
{
	//Map�̏������W���
	MapX = 0.0f;
	MapY = -470.0f;
	MapZ = 0.0f;

	//Map�̑傫���ݒ�
	MapScale = 12.0f;

	//3D���f���ǂݍ���
	MapObject = MV1LoadModel("data/MapCube.mv1");

	//Map�̑傫����ς���
	MV1SetScale(MapObject, VGet(MapScale, MapScale, MapScale));

	//�}�b�v�̏����z�u
	MapPosition = VGet(MapX, MapY, MapZ);
}

void Map::Update()
{

}

void Map::Draw()
{
	//3D�}�b�v�̐ݒu����
	MV1SetPosition(MapObject, MapPosition);

	//3D���f����`�悷��
	MV1DrawModel(MapObject);
}

void Map::End()
{
	MV1DeleteModel(MapObject);
}
