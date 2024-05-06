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

void Map::Update(Player& player)
{
	//�}�b�v�̓����蔻����Ƃ�
	m_colrect.SetCenter(-230.0f, -225.0f, 220.0f, 450.0f, 220.0f, -450.0f);
}

void Map::Draw(Player& player)
{
	//3D�}�b�v�̐ݒu������
	MV1SetPosition(MapObject, MapPosition);

	//3D���f����`�悷��
	MV1DrawModel(MapObject);

	//�����蔻���`�悷��
	m_colrect.Draw(GetColor(255, 0, 0), false);

	//�v���C���[�ɓ������Ă����
	if (m_colrect.IsCollision(player.m_colrect) == true)
	{
		DrawString(200, 130, "�������Ă���", GetColor(255, 255, 255));
	}
}

void Map::End()
{
	MV1DeleteModel(MapObject);
}
