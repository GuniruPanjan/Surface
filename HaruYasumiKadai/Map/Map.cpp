#include "Map.h"
#include "Scene/SceneGoal.h"
#include "Scene/SceneChoice.h"

std::shared_ptr<SceneChoice> choice = std::make_shared<SceneChoice>();

Map::Map() :
	m_Graph(0),
	Time(0),
	MapTime(0),
	Scroll(0),
	MapGoal(false),
	MapDead(false),
	Scale(0.0f)
{
}

Map::~Map()
{
	DeleteGraph(m_Graph);

	MV1DeleteModel(Model);
}

void Map::Init()
{
	//�}�b�v�̃��[�h
	m_Graph = LoadGraph("date/Tail.png");

	//�X�N���[������������������
	Scroll = 0;

	//���ݎ��Ԃ𓾂�
	Time = GetNowCount();

	MapGoal = false;

	MapDead = false;

	Scale = 2.0f;

	//3Dmodel�ǂݍ���
	Model = MV1LoadModel("date/Doar.mv1");

	//�|�W�V�����ݒ�
	posmodel = VGet(200, 300, 0);
}

void Map::Update()
{
	//3DModel�|�W�V�����ݒ�
	MV1SetPosition(Model, posmodel);

	//3DModel�̃X�P�[���ݒ�
	MV1SetScale(Model, VGet(Scale, Scale, Scale));

	//�o�ߎ��Ԃ𓾂�
	MapTime = (GetNowCount() - Time) / 1000;

	//���Ԃ����ƃX�N���[������
	if (MapTime >= 10)
	{
		Scroll -= 1;
	}

}

void Map::Draw(Player& player)
{
	//3D���f���`��
	MV1DrawModel(Model);

	//�}�b�v��`��
	for (int i = 0; i < MAP_SIZE_WIDTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_HEIGHT; j++)
		{
			//�}�b�v�f�[�^��1��������`�悷��
			if (First_Map[j][i] == 1)
			{
				DrawGraph(i * MAPCHIP_WIDTH + Scroll, j * MAPCHIP_HEIGHT, m_Graph, true);
			}

			//�}�b�v�f�[�^��2��������S�[����`�悷��
			if (First_Map[j][i] == 2)
			{
				DrawGraph(i * MAPCHIP_WIDTH + Scroll, j * MAPCHIP_HEIGHT, m_Graph, true);

				//�����蔻�������
				m_colRectGoal.SetCenter(static_cast<float>(i * MAPCHIP_WIDTH + 15 + Scroll), static_cast<float>(j * MAPCHIP_HEIGHT + 15), static_cast<float>(MAPCHIP_WIDTH), static_cast<float>(MAPCHIP_HEIGHT));

				//�����蔻��`��
				m_colRectGoal.Draw(GetColor(255, 255, 255), false);

				//Player���S�[��������
				if (m_colRectGoal.IsCollision(player.m_colrect) == true)
				{
					MapGoal = true;
				}
			}

			//�}�b�v�f�[�^��0�������瓖���蔻�������
			if (First_Map[j][i] == 0)
			{
				m_colRect.SetCenter(static_cast<float>((i * MAPCHIP_WIDTH + 15) + Scroll), static_cast<float>(j * MAPCHIP_HEIGHT + 15), static_cast<float>(MAPCHIP_FALLX), static_cast<float>(MAPCHIP_FALLY));

				//�����蔻��`��
				//m_colRect->Draw(GetColor(255, 255, 255), false);

				//�}�b�v�Ŏ��񂾂�
				if (m_colRect.IsCollision(player.m_colrect) == true)
				{
					MapDead = true;
				}
			}
		}
	}

	

}

void Map::DrawBack(Player& player)
{
	//3D���f���`��
	MV1DrawModel(Model);

	//�}�b�v��`��
	for (int i = 0; i < MAP_SIZE_WIDTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_HEIGHT; j++)
		{
			//�}�b�v�f�[�^��1��������`�悷��
			if (First_Mapback[j][i] == 1)
			{
				DrawGraph(i * MAPCHIP_WIDTH + Scroll, j * MAPCHIP_HEIGHT, m_Graph, true);
			}

			//�}�b�v�f�[�^��3��������`�悷��
			if (First_Mapback[j][i] == 3)
			{
				m_colRect.SetCenter(static_cast<float>((i * MAPCHIP_WIDTH + 15) + Scroll), static_cast<float>(j * MAPCHIP_HEIGHT + 15), static_cast<float>(MAPCHIP_WIDTH), static_cast<float>(MAPCHIP_HEIGHT));
			}

			if (First_Mapback[j][i] == 2)
			{
				//�����蔻�������
				m_colRectGoal.SetCenter(static_cast<float>(i * MAPCHIP_WIDTH + 15 + Scroll), static_cast<float>(j * MAPCHIP_HEIGHT + 15), static_cast<float>(MAPCHIP_WIDTH), static_cast<float>(MAPCHIP_HEIGHT));

				//�����蔻��`��
				m_colRectGoal.Draw(GetColor(255, 255, 255), false);

				//Player���S�[��������
				if (m_colRectGoal.IsCollision(player.m_colrect) == true)
				{
					MapGoal = true;
				}
			}
		}
	}
}

