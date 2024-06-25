#include "MapObject.h"

MapObject::MapObject()
{
	for (int i = 0; i < 4; i++)
	{
		MapWallModel[i] = -1;
	}
}

MapObject::~MapObject()
{
}

void MapObject::Init()
{
	MapObjectBushPosX = 1250.0f;
	MapObjectBushPosY = -100.0f;
	MapObjectBushPosZ = -850.0f;

	MapObjectWallPosX[0] = 1323.0f;
	MapObjectWallPosY = -650.0f;
	MapObjectWallPosZ[0] = -140.0f;

	MapObjectWallPosX[1] = 150.0f;
	MapObjectWallPosZ[1] = 1320.0f;

	MapObjectWallPosX[2] = -2415.0f;
	MapObjectWallPosZ[2] = -140.0f;

	MapObjectWallPosX[3] = 150.0f;
	MapObjectWallPosZ[3] = -2410.0f;

	MapObjectWallSize = 35.0f;


	MapBushModel = MV1LoadModel("MapData/BushModel.mv1");
	MapWallModel[0] = MV1LoadModel("MapData/wallstoneModel.mv1");

	MapWallModel[1] = MV1DuplicateModel(MapWallModel[0]);
	MapWallModel[2] = MV1DuplicateModel(MapWallModel[0]);
	MapWallModel[3] = MV1DuplicateModel(MapWallModel[0]);


	MapBushPos = VGet(MapObjectBushPosX, MapObjectBushPosY, MapObjectBushPosZ);
	MapWallPos[0] = VGet(MapObjectWallPosX[0], MapObjectWallPosY, MapObjectWallPosZ[0]);
	MapWallPos[1] = VGet(MapObjectWallPosX[1], MapObjectWallPosY, MapObjectWallPosZ[1]);
	MapWallPos[2] = VGet(MapObjectWallPosX[2], MapObjectWallPosY, MapObjectWallPosZ[2]);
	MapWallPos[3] = VGet(MapObjectWallPosX[3], MapObjectWallPosY, MapObjectWallPosZ[3]);


	//マップの壁のサイズ設定
	MV1SetScale(MapWallModel[0], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));
	MV1SetScale(MapWallModel[1], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));
	MV1SetScale(MapWallModel[2], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));
	MV1SetScale(MapWallModel[3], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));

	m_pos1 = Pos3(MapObjectWallPosX[0] + 1190.0f, 50.0f, MapObjectWallPosZ[0] + 140.0f);
	m_size1 = Size(2500.0f, 1000.0f, 2500.0f);
	m_pos2 = Pos3(MapObjectWallPosX[1] - 150.0f, 50.0f, MapObjectWallPosZ[1] + 1190.0f);
	m_size2 = Size(2500.0f, 1000.0f, 2500.0f);
	m_pos3 = Pos3(MapObjectWallPosX[2] - 100.0f, 50.0f, MapObjectWallPosZ[2] + 140.0f);
	m_size3 = Size(2500.0f, 1000.0f, 2500.0f);
	m_pos4 = Pos3(MapObjectWallPosX[3] - 150.0f, 50.0f, MapObjectWallPosZ[3] - 100.0f);
	m_size4 = Size(2500.0f, 1000.0f, 2500.0f);
	m_rect1.Init(m_pos1, m_size1);
	m_rect2.Init(m_pos2, m_size2);
	m_rect3.Init(m_pos3, m_size3);
	m_rect4.Init(m_pos4, m_size4);

}

void MapObject::Update()
{
}

void MapObject::Draw()
{
	float halfW = m_size1.width * 0.5f;
	float halfH = m_size1.height * 0.5f;
	float halfD = m_size1.depth * 0.5f;

	float halfW2 = m_size2.width * 0.5f;
	float halfH2 = m_size2.height * 0.5f;
	float halfD2 = m_size2.depth * 0.5f;

	float halfW3 = m_size3.width * 0.5f;
	float halfH3 = m_size3.height * 0.5f;
	float halfD3 = m_size3.depth * 0.5f;

	float halfW4 = m_size4.width * 0.5f;
	float halfH4 = m_size4.height * 0.5f;
	float halfD4 = m_size4.depth * 0.5f;

	float right = m_pos1.x + halfW;
	float left = m_pos1.x - halfW;
	float top = m_pos1.y + halfH;
	float bottom = m_pos1.y - halfH;
	float front = m_pos1.z - halfD;
	float back = m_pos1.z + halfD;

	float right2 = m_pos2.x + halfW;
	float left2 = m_pos2.x - halfW;
	float top2 = m_pos2.y + halfH;
	float bottom2 = m_pos2.y - halfH;
	float front2 = m_pos2.z - halfD;
	float back2 = m_pos2.z + halfD;

	float right3 = m_pos3.x + halfW;
	float left3 = m_pos3.x - halfW;
	float top3 = m_pos3.y + halfH;
	float bottom3 = m_pos3.y - halfH;
	float front3 = m_pos3.z - halfD;
	float back3 = m_pos3.z + halfD;

	float right4 = m_pos4.x + halfW;
	float left4 = m_pos4.x - halfW;
	float top4 = m_pos4.y + halfH;
	float bottom4 = m_pos4.y - halfH;
	float front4 = m_pos4.z - halfD;
	float back4 = m_pos4.z + halfD;

	MV1SetPosition(MapBushModel, MapBushPos);
	MV1SetPosition(MapWallModel[0], MapWallPos[0]);
	MV1SetPosition(MapWallModel[1], MapWallPos[1]);
	MV1SetPosition(MapWallModel[2], MapWallPos[2]);
	MV1SetPosition(MapWallModel[3], MapWallPos[3]);

	//3Dモデルの回転値をセットする
	MV1SetRotationXYZ(MapBushModel, VGet(1.57f, 0.0f, 0.0f));
	MV1SetRotationXYZ(MapWallModel[0], VGet(0.0f, 1.57f, 0.0f));
	MV1SetRotationXYZ(MapWallModel[2], VGet(0.0f, 1.57f, 0.0f));

	MV1DrawModel(MapWallModel[0]);
	MV1DrawModel(MapWallModel[1]);
	MV1DrawModel(MapWallModel[2]);
	MV1DrawModel(MapWallModel[3]);
	MV1DrawModel(MapBushModel);
	
#if true
	// 横の線
	DrawLine3D(VGet(left, bottom, front), VGet(right, bottom, front), m_color);
	DrawLine3D(VGet(left, top, front), VGet(right, top, front), m_color);
	DrawLine3D(VGet(left, bottom, back), VGet(right, bottom, back), m_color);
	DrawLine3D(VGet(left, top, back), VGet(right, top, back), m_color);
	// 縦の線
	DrawLine3D(VGet(left, top, front), VGet(left, bottom, front), m_color);
	DrawLine3D(VGet(right, top, front), VGet(right, bottom, front), m_color);
	DrawLine3D(VGet(left, top, back), VGet(left, bottom, back), m_color);
	DrawLine3D(VGet(right, top, back), VGet(right, bottom, back), m_color);
	// 前後の線
	DrawLine3D(VGet(left, top, front), VGet(left, top, back), m_color);
	DrawLine3D(VGet(left, bottom, front), VGet(left, bottom, back), m_color);
	DrawLine3D(VGet(right, top, front), VGet(right, top, back), m_color);
	DrawLine3D(VGet(right, bottom, front), VGet(right, bottom, back), m_color);

	// 横の線
	DrawLine3D(VGet(left2, bottom2, front2), VGet(right2, bottom2, front2), m_color);
	DrawLine3D(VGet(left2, top2, front2), VGet(right2, top2, front2), m_color);
	DrawLine3D(VGet(left2, bottom2, back2), VGet(right2, bottom2, back2), m_color);
	DrawLine3D(VGet(left2, top2, back2), VGet(right2, top2, back2), m_color);
	// 縦の線
	DrawLine3D(VGet(left2, top2, front2), VGet(left2, bottom2, front2), m_color);
	DrawLine3D(VGet(right2, top2, front2), VGet(right2, bottom2, front2), m_color);
	DrawLine3D(VGet(left2, top2, back2), VGet(left2, bottom2, back2), m_color);
	DrawLine3D(VGet(right2, top2, back2), VGet(right2, bottom2, back2), m_color);
	// 前後の線
	DrawLine3D(VGet(left2, top2, front2), VGet(left2, top2, back2), m_color);
	DrawLine3D(VGet(left2, bottom2, front2), VGet(left2, bottom2, back2), m_color);
	DrawLine3D(VGet(right2, top2, front2), VGet(right2, top2, back2), m_color);
	DrawLine3D(VGet(right2, bottom2, front2), VGet(right2, bottom2, back2), m_color);

	// 横の線
	DrawLine3D(VGet(left3, bottom3, front3), VGet(right3, bottom3, front3), m_color);
	DrawLine3D(VGet(left3, top3, front3), VGet(right3, top3, front3), m_color);
	DrawLine3D(VGet(left3, bottom3, back3), VGet(right3, bottom3, back3), m_color);
	DrawLine3D(VGet(left3, top3, back3), VGet(right3, top3, back3), m_color);
	// 縦の線
	DrawLine3D(VGet(left3, top3, front3), VGet(left3, bottom3, front3), m_color);
	DrawLine3D(VGet(right3, top3, front3), VGet(right3, bottom3, front3), m_color);
	DrawLine3D(VGet(left3, top3, back3), VGet(left3, bottom3, back3), m_color);
	DrawLine3D(VGet(right3, top3, back3), VGet(right3, bottom3, back3), m_color);
	// 前後の線
	DrawLine3D(VGet(left3, top3, front3), VGet(left3, top3, back3), m_color);
	DrawLine3D(VGet(left3, bottom3, front3), VGet(left3, bottom3, back3), m_color);
	DrawLine3D(VGet(right3, top3, front3), VGet(right3, top3, back3), m_color);
	DrawLine3D(VGet(right3, bottom3, front3), VGet(right3, bottom3, back3), m_color);

	// 横の線
	DrawLine3D(VGet(left4, bottom4, front4), VGet(right4, bottom4, front4), m_color);
	DrawLine3D(VGet(left4, top4, front4), VGet(right4, top4, front4), m_color);
	DrawLine3D(VGet(left4, bottom4, back4), VGet(right4, bottom4, back4), m_color);
	DrawLine3D(VGet(left4, top4, back4), VGet(right4, top4, back4), m_color);
	// 縦の線
	DrawLine3D(VGet(left4, top4, front4), VGet(left4, bottom4, front4), m_color);
	DrawLine3D(VGet(right4, top4, front4), VGet(right4, bottom4, front4), m_color);
	DrawLine3D(VGet(left4, top4, back4), VGet(left4, bottom4, back4), m_color);
	DrawLine3D(VGet(right4, top4, back4), VGet(right4, bottom4, back4), m_color);
	// 前後の線
	DrawLine3D(VGet(left4, top4, front4), VGet(left4, top4, back4), m_color);
	DrawLine3D(VGet(left4, bottom4, front4), VGet(left4, bottom4, back4), m_color);
	DrawLine3D(VGet(right4, top4, front4), VGet(right4, top4, back4), m_color);
	DrawLine3D(VGet(right4, bottom4, front4), VGet(right4, bottom4, back4), m_color);

#else
	DrawCube3D(VGet(left, top, back), VGet(right, bottom, front), m_color, 0, false);
#endif
}

void MapObject::End()
{
	//メモリ解放
	MV1DeleteModel(MapBushModel);
	MV1DeleteModel(MapWallModel[0]);
	MV1DeleteModel(MapWallModel[1]);
	MV1DeleteModel(MapWallModel[2]);
	MV1DeleteModel(MapWallModel[3]);
}

bool MapObject::IsHit(const CapsuleCol& col)
{
	bool IsHit = m_rect1.IsHit(col);
	bool IsHit2 = m_rect2.IsHit(col);
	bool IsHit3 = m_rect3.IsHit(col);
	bool IsHit4 = m_rect4.IsHit(col);


	//壁に当たると前の位置に戻る
	if (IsHit || IsHit2 || IsHit3 || IsHit4)
	{
		m_color = 0xff00ff;
	}
	else
	{
		m_color = 0xffffff;
	}

	return IsHit || IsHit2 || IsHit3 || IsHit4;
}
