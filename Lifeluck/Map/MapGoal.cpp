#include "MapGoal.h"

MapGoal::MapGoal():
	HouseHandle(-1),
	m_goal(false)
{
}

MapGoal::~MapGoal()
{
}

void MapGoal::Init()
{
	//3Dモデルの読み込み
	MapHouseModel = MV1LoadModel("MapData/HouseModel.mv1");

	MapHousePosX = 0.0f;
	MapHousePosY = -25.0f;
	MapHousePosZ = -1150.0f;

	MapHouseSize = 250.0f;

	//マップのスケール設定
	MV1SetScale(MapHouseModel, VGet(MapHouseSize, MapHouseSize, MapHouseSize));

	MapHousePos = VGet(MapHousePosX, MapHousePosY, MapHousePosZ);

	HouseHandle = MapHouseModel;

	m_pos = Pos3(MapHousePosX, 60.0f, MapHousePosZ);
	m_size = Size(100.0f, 100.0f, 170.0f);
	m_col.Init(m_pos, m_size);

	m_pos1 = Pos3(MapHousePosX - 65.0f, 50.0f, MapHousePosZ);
	m_size1 = Size(10.0f, 100.0f, 200.0f);
	m_col1.Init(m_pos1, m_size1);

	m_pos2 = Pos3(MapHousePosX + 65.0f, 50.0f, MapHousePosZ);
	m_size2 = Size(10.0f, 100.0f, 200.0f);
	m_col2.Init(m_pos2, m_size2);

	m_pos3 = Pos3(MapHousePosX - 50.0f, 50.0f, MapHousePosZ + 110.0f);
	m_size3 = Size(40.0f, 100.0f, 10.0f);
	m_col3.Init(m_pos3, m_size3);

	m_pos4 = Pos3(MapHousePosX + 50.0f, 50.0f, MapHousePosZ + 110.0f);
	m_size4 = Size(40.0f, 100.0f, 10.0f);
	m_col4.Init(m_pos4, m_size4);
}

void MapGoal::Update()
{

}

void MapGoal::Draw()
{
	float halfW = m_size.width * 0.5f;
	float halfH = m_size.height * 0.5f;
	float halfD = m_size.depth * 0.5f;

	float halfW1 = m_size1.width * 0.5f;
	float halfH1 = m_size1.height * 0.5f;
	float halfD1 = m_size1.depth * 0.5f;

	float halfW2 = m_size2.width * 0.5f;
	float halfH2 = m_size2.height * 0.5f;
	float halfD2 = m_size2.depth * 0.5f;

	float halfW3 = m_size3.width * 0.5f;
	float halfH3 = m_size3.height * 0.5f;
	float halfD3 = m_size3.depth * 0.5f;

	float halfW4 = m_size4.width * 0.5f;
	float halfH4 = m_size4.height * 0.5f;
	float halfD4 = m_size4.depth * 0.5f;

	float right = m_pos.x + halfW;
	float left = m_pos.x - halfW;
	float top = m_pos.y + halfH;
	float bottom = m_pos.y - halfH;
	float front = m_pos.z - halfD;
	float back = m_pos.z + halfD;

	float right1 = m_pos1.x + halfW1;
	float left1 = m_pos1.x - halfW1;
	float top1 = m_pos1.y + halfH1;
	float bottom1 = m_pos1.y - halfH1;
	float front1 = m_pos1.z - halfD1;
	float back1 = m_pos1.z + halfD1;

	float right2 = m_pos2.x + halfW2;
	float left2 = m_pos2.x - halfW2;
	float top2 = m_pos2.y + halfH2;
	float bottom2 = m_pos2.y - halfH2;
	float front2 = m_pos2.z - halfD2;
	float back2 = m_pos2.z + halfD2;

	float right3 = m_pos3.x + halfW3;
	float left3 = m_pos3.x - halfW3;
	float top3 = m_pos3.y + halfH3;
	float bottom3 = m_pos3.y - halfH3;
	float front3 = m_pos3.z - halfD3;
	float back3 = m_pos3.z + halfD3;

	float right4 = m_pos4.x + halfW4;
	float left4 = m_pos4.x - halfW4;
	float top4 = m_pos4.y + halfH4;
	float bottom4 = m_pos4.y - halfH4;
	float front4 = m_pos4.z - halfD4;
	float back4 = m_pos4.z + halfD4;

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
	DrawLine3D(VGet(left1, bottom1, front1), VGet(right1, bottom1, front1), m_colorwall);
	DrawLine3D(VGet(left1, top1, front1), VGet(right1, top1, front1), m_colorwall);
	DrawLine3D(VGet(left1, bottom1, back1), VGet(right1, bottom1, back1), m_colorwall);
	DrawLine3D(VGet(left1, top1, back1), VGet(right1, top1, back1), m_colorwall);
	// 縦の線
	DrawLine3D(VGet(left1, top1, front1), VGet(left1, bottom1, front1), m_colorwall);
	DrawLine3D(VGet(right1, top1, front1), VGet(right1, bottom1, front1), m_colorwall);
	DrawLine3D(VGet(left1, top1, back1), VGet(left1, bottom1, back1), m_colorwall);
	DrawLine3D(VGet(right1, top1, back1), VGet(right1, bottom1, back1), m_colorwall);
	// 前後の線
	DrawLine3D(VGet(left1, top1, front1), VGet(left1, top1, back1), m_colorwall);
	DrawLine3D(VGet(left1, bottom1, front1), VGet(left1, bottom1, back1), m_colorwall);
	DrawLine3D(VGet(right1, top1, front1), VGet(right1, top1, back1), m_colorwall);
	DrawLine3D(VGet(right1, bottom1, front1), VGet(right1, bottom1, back1), m_colorwall);

	// 横の線
	DrawLine3D(VGet(left2, bottom2, front2), VGet(right2, bottom2, front2), m_colorwall);
	DrawLine3D(VGet(left2, top2, front2), VGet(right2, top2, front2), m_colorwall);
	DrawLine3D(VGet(left2, bottom2, back2), VGet(right2, bottom2, back2), m_colorwall);
	DrawLine3D(VGet(left2, top2, back2), VGet(right2, top2, back2), m_colorwall);
	// 縦の線
	DrawLine3D(VGet(left2, top2, front2), VGet(left2, bottom2, front2), m_colorwall);
	DrawLine3D(VGet(right2, top2, front2), VGet(right2, bottom2, front2), m_colorwall);
	DrawLine3D(VGet(left2, top2, back2), VGet(left2, bottom2, back2), m_colorwall);
	DrawLine3D(VGet(right2, top2, back2), VGet(right2, bottom2, back2), m_colorwall);
	// 前後の線
	DrawLine3D(VGet(left2, top2, front2), VGet(left2, top2, back2), m_colorwall);
	DrawLine3D(VGet(left2, bottom2, front2), VGet(left2, bottom2, back2), m_colorwall);
	DrawLine3D(VGet(right2, top2, front2), VGet(right2, top2, back2), m_colorwall);
	DrawLine3D(VGet(right2, bottom2, front2), VGet(right2, bottom2, back2), m_colorwall);

	// 横の線
	DrawLine3D(VGet(left3, bottom3, front3), VGet(right3, bottom3, front3), m_colorwall);
	DrawLine3D(VGet(left3, top3, front3), VGet(right3, top3, front3), m_colorwall);
	DrawLine3D(VGet(left3, bottom3, back3), VGet(right3, bottom3, back3), m_colorwall);
	DrawLine3D(VGet(left3, top3, back3), VGet(right3, top3, back3), m_colorwall);
	// 縦の線
	DrawLine3D(VGet(left3, top3, front3), VGet(left3, bottom3, front3), m_colorwall);
	DrawLine3D(VGet(right3, top3, front3), VGet(right3, bottom3, front3), m_colorwall);
	DrawLine3D(VGet(left3, top3, back3), VGet(left3, bottom3, back3), m_colorwall);
	DrawLine3D(VGet(right3, top3, back3), VGet(right3, bottom3, back3), m_colorwall);
	// 前後の線
	DrawLine3D(VGet(left3, top3, front3), VGet(left3, top3, back3), m_colorwall);
	DrawLine3D(VGet(left3, bottom3, front3), VGet(left3, bottom3, back3), m_colorwall);
	DrawLine3D(VGet(right3, top3, front3), VGet(right3, top3, back3), m_colorwall);
	DrawLine3D(VGet(right3, bottom3, front3), VGet(right3, bottom3, back3), m_colorwall);

	// 横の線
	DrawLine3D(VGet(left4, bottom4, front4), VGet(right4, bottom4, front4), m_colorwall);
	DrawLine3D(VGet(left4, top4, front4), VGet(right4, top4, front4), m_colorwall);
	DrawLine3D(VGet(left4, bottom4, back4), VGet(right4, bottom4, back4), m_colorwall);
	DrawLine3D(VGet(left4, top4, back4), VGet(right4, top4, back4), m_colorwall);
	// 縦の線
	DrawLine3D(VGet(left4, top4, front4), VGet(left4, bottom4, front4), m_colorwall);
	DrawLine3D(VGet(right4, top4, front4), VGet(right4, bottom4, front4), m_colorwall);
	DrawLine3D(VGet(left4, top4, back4), VGet(left4, bottom4, back4), m_colorwall);
	DrawLine3D(VGet(right4, top4, back4), VGet(right4, bottom4, back4), m_colorwall);
	// 前後の線
	DrawLine3D(VGet(left4, top4, front4), VGet(left4, top4, back4), m_colorwall);
	DrawLine3D(VGet(left4, bottom4, front4), VGet(left4, bottom4, back4), m_colorwall);
	DrawLine3D(VGet(right4, top4, front4), VGet(right4, top4, back4), m_colorwall);
	DrawLine3D(VGet(right4, bottom4, front4), VGet(right4, bottom4, back4), m_colorwall);

#else
	DrawCube3D(VGet(left, top, back), VGet(right, bottom, front), m_color, 0, false);
#endif


	//3Dモデルポジション設定
	MV1SetPosition(HouseHandle, MapHousePos);

	//3Dモデルの回転値をセットする
	MV1SetRotationXYZ(HouseHandle, VGet(0.0f, 3.14f, 0.0f));

	//3Dモデル描画
	MV1DrawModel(HouseHandle);
}

void MapGoal::End()
{
	//メモリ解放
	MV1DeleteModel(MapHouseModel);
}

bool MapGoal::IsHit(const CapsuleCol& col)
{
	bool IsHit = m_col.IsHit(col);

	if (IsHit)
	{
		m_color = 0xff00ff;

		//ゴールした
		m_goal = true;
	}
	else
	{
		m_color = 0xffffff;
	}

	return IsHit;
}

bool MapGoal::IsHitWall(const CapsuleCol& col)
{
	bool IsHit = m_col1.IsHit(col);
	bool IsHit2 = m_col2.IsHit(col);
	bool IsHit3 = m_col3.IsHit(col);
	bool IsHit4 = m_col4.IsHit(col);

	if (IsHit || IsHit2 || IsHit3 || IsHit4)
	{
		m_colorwall = 0xff00ff;
	}
	else
	{
		m_colorwall = 0xffffff;
	}

	return IsHit || IsHit2 || IsHit3 || IsHit4;
}