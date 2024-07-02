#include "Machine.h"
#include "Col/Rigidbody.h"

Machine::Machine():
	m_completemachine(0)
{
	MachinePosition = VGet(0.0f, 0.0f, 0.0f);
}

Machine::~Machine()
{
	//メモリ解放
	MV1DeleteModel(MachineModel);
}

void Machine::Init()
{
	//マシンに溜まる最大のエネルギー量
	m_machineMaxEnergy = 100.0f;

	MachineX = -200.0f;
	MachineY = -18.0f;
	MachineZ = 0.0f;

	MachineSize = 100.0f;
	MachineRotate = 1.58f;

	MachineModel = MV1LoadModel("MachineData/MachineModel.mv1");

	//モデルのサイズ設定
	MV1SetScale(MachineModel, VGet(MachineSize, MachineSize, MachineSize));

	m_pos = Pos3(MachineX + 3.0f, 30.0f, MachineZ + 18.0f);
	m_size = Size(40.0f, 50.0f, 20.0f);
	m_radius = 80.0f;
	m_rect.Init(m_pos, m_size);
	m_col.Init(m_pos, m_radius);

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

	//円の当たり判定
	DrawSphere3D(m_pos.GetVector(), m_radius, 16, m_color1, 0xffffff, false);

#else
	DrawCube3D(VGet(left, top, back), VGet(right, bottom, front), m_color, 0, false);
#endif

	//ポジションや設定や描画をする
	SetPosition(MachineModel, MachineX, MachineY, MachineZ, MachineRotate);

	DrawFormatString(200, 200, 0xffffff, "Time:%f", time);
	DrawFormatString(200, 300, 0xffffff, "Energy:%f", m_machineenergy);
}

void Machine::End()
{
	//メモリ解放
	MV1DeleteModel(MachineModel);
}

void Machine::MachineEnergy(float giveenergy)
{
	time++;

	if (m_machineMaxEnergy >= m_machineenergy)
	{
		if(time >= 300.0f)
		{
			m_machineenergy += giveenergy;

			time = 0;
		}
		
	}
	else if (m_machineenergy >= 100.0f)
	{
		//マシンが完成したら数を増やす
		if (one)
		{
			m_completemachine++;
		}
	}
}

bool Machine::IsHit(const CapsuleCol& col, Player& player)
{
	bool IsHit = m_rect.IsHit(col);

	Rigidbody rigidbody;

	if (IsHit)
	{
		m_color = 0x00ffff;

		rigidbody.HitMove(player.PlayerPos, m_previous, player.GetMove());
	}
	else
	{
		m_color = 0xffffff;

		/*当たる前の座標を入れたい*/
		//プレイヤーの前の座標を入れる
		m_previous = player.PlayerPos;
	}

	return IsHit;
}

bool Machine::IsHitCapsule(const CapsuleCol& col, Player& player)
{
	bool IsHit = m_col.IsHitCapsule(col);

	if (IsHit)
	{
		m_color1 = 0x00ffff;

		//充電できるようになる
		player.GetCan(true);

		//充電していたら
		if (player.GetCharging())
		{
			MachineEnergy(player.GiveEnergy());
		}
	}
	else
	{
		m_color1 = 0xffffff;

		//充電できないようになる
		player.GetCan(false);
	}

	return IsHit;
}

void Machine::SetPosition(int handle, float x, float y, float z,float rotate)
{
	//3Dモデルポジション設定
	MV1SetPosition(handle, VGet(x, y, z));

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(handle, VGet(rotate, 0.0f, 0.0f));

	//3Dモデル描画
	MV1DrawModel(handle);
}
