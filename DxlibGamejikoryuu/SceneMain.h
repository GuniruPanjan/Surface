#pragma once
#include "Player.h"
#include "Enemy.h"

class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void Update();
	void Draw();
	void End();     //�V�[���̏I��

	//�V�[�����I������邩�ǂ���
	bool IsSceneEnd() const;

	bool IsCollison(const Player& player, const Enemy& enemy);

private:
	//��ʓ��ɓ����ɑ��݂ł���G�̍ő吔
	static constexpr int kEnemyMax = 16;

private:
	int m_playerHandle;    //�v���C���[�̃O���t�B�b�N
	int m_enemyHandle;     //�G�̃O���t�B�b�N

	Player m_player;
	Enemy m_enemy[kEnemyMax];

	bool m_isGameOver;  //�Q�[���I�[�o�[���ǂ����̃t���O
	bool m_isSceneEnd;  //�V�[�����I�����鎞��true�ɂ���
	int m_playFrameCount;

	//�G�̐�������
	int m_enemyCreateNum;    //���܂łɐ��������G�̐�
	int m_enemyWaitFrame;    //�G�����܂ő҂�����

	//�t�F�[�h�C���A�A�E�g
	int m_fadeAlpha;
};

