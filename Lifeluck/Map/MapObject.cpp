#include "MapObject.h"

MapObject::MapObject():
	MapBushHandle(-1)
{
}

MapObject::~MapObject()
{
}

void MapObject::Init()
{
	MapBushModel = MV1LoadModel("MapData/BushModel.mv1");
}

void MapObject::Update()
{
}

void MapObject::Draw()
{
	MV1SetPosition(MapBushModel, VGet(0.0f, 100.0f, 0.0f));

	MV1DrawModel(MapBushModel);
}

void MapObject::End()
{
	//ƒƒ‚ƒŠ‰ğ•ú
	MV1DeleteModel(MapBushModel);
}
