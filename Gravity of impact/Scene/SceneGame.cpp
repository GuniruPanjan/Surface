#include "SceneGame.h"
#include "SceneGoal.h"
#include "DxLib.h"

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
	//���������
	DeleteSoundMem(SoundGame);
}

void SceneGame::Init()
{
	player->Init();

	camera->Init();

	map->Init();

	enemy->Init();

	//�w�i�̉摜�ǂݍ���
	GameBack = LoadGraph("data/cloudy.png");

	//�w�iBGM�ǂݍ���
	SoundGame = LoadSoundMem("BGM�ESE/Garden_Farm.mp3");
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	player->SetCameraAngle(camera->cameraAngle.y);
	player->Update();

	camera->Update(*player);

	map->Update(*player, *enemy);

	//�v���C���[�����񂾂�
	if (player->PlayerDead == true)
	{
		enemy->Init();  //������

		player->PlayerDead = false;  //Player�̎��S�����false�ɖ߂�
	}
	//�v���C���[�������Ă�����
	else if (player->PlayerDead == false)
	{
		enemy->Update(*player);
	}
	

	//�T�E���h�Đ�
	PlaySoundMem(SoundGame, DX_PLAYTYPE_LOOP, FALSE);

	//�S�[���V�[���ɑJ�ڂ���
	if (map->Goal == true)
	{
		return std::make_shared<SceneGoal>();
	}

	return shared_from_this();
}

void SceneGame::Draw()
{
	//�w�i��`��
	DrawGraph(0, 0, GameBack, false);

	map->Draw(*player, *enemy);

	player->Draw();

	enemy->Draw();

	camera->Draw();
}

void SceneGame::End()
{
	//�ǂݍ��񂾉摜�f�[�^���
	DeleteGraph(GameBack);

	map->End();

	player->End();

	enemy->End();

	camera->End();
}
