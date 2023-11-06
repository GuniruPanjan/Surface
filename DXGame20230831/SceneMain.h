#pragma once
#include<vector>
#include "Vec2.h"

class Player;
//class EnemyRight;
//class EnemyToPlayer;
//
//class EnemyLeft;

class EnemyBase;
class Bg;
class ShotBase;
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void Init();
	void End();
	void Update();
	void Draw() const;

	//����̍��W�����ԋ߂��ɂ���G�̍��W��Ԃ��֐�
	Vec2 GetNearEnemyPos(Vec2 pos) const;
	//�V���b�g��ǉ����� �o�^�ł��Ȃ������ꍇ��false��Ԃ�
	//�o�^�o���Ȃ������ꍇ�͓�����pShot�������
	bool AddShot(ShotBase* pShot);

//private:
//	static constexpr int kEnemyNum = 16;
private:
	//�G�L�����N�^�[�̐���
	void CreateEnemyLeft();
	void CreateEnemyRight();
	void CreateEnemyToPlayer();

private:
	//�O���t�B�b�N�n���h��
	int m_playerHandle;
	int m_enemyHandle;
	int m_bgHandle;

	//�v���C���[
	Player* m_pPlayer;

	//�G�L�����N�^�[
	//EnemyRight* m_pEnemyRight;
	/*EnemyRight* m_pEnemyRight[kEnemyNum];
	EnemyToPlayer* m_pEnemyToPlayer[kEnemyNum];

	EnemyLeft* m_pEnemyLeft;

	int m_enemyFrameCount;*/

	//�w�i
	Bg* m_pBg;

	//�G
	std::vector<EnemyBase*>m_pEnemy;   //�z��̃T�C�Y�͎��s���Ɍ��߂�i����̓R���X�g���N�^�j
	//EnemyBase* m_pEnemy[16];   //���܂ł̔z��

	//�V���b�g
	std::vector<ShotBase*> m_pShot;
	//ShotBase* m_pShot;

	//�G�̓o��Ԋu
	int m_enemyInterval;
};

