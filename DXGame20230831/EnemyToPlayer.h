#pragma once
#include "EnemyBase.h"
#include "Vec2.h"

class Player;
//�����ʒu���甭�������Ƃ��̃v���C���[�ʒu�Ɍ������Ĉړ�����
class EnemyToPlayer : public EnemyBase
{
public:
	EnemyToPlayer();
	virtual ~EnemyToPlayer();

	//void Init();
	virtual void Update() override;
	//void Draw() const;

	//�����o�[�ϐ��ɃA�N�Z�X����
	//void SetHandle(int handle) { m_handle = handle; }
	void SetPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }

	//bool isExist() const { return m_isExist; }

	//�G�L�����N�^�[���X�^�[�g������
	virtual void Start() override;

private:
	//int m_handle;   //�O���t�B�b�N�̃n���h��

	//bool m_isExist; //���݂��邩�t���O(�g�p�����ǂ���)

	Player* m_pPlayer;

	//float m_posX;
	//float m_posY;
	//�\���ʒu
	//Vec2 m_pos;
	//�ړ���  1�t���[��������̈ړ��x�N�g��������
	//Vec2 m_vec;
};

