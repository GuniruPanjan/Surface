#pragma once
#include "EnemyBase.h"
#include "Vec2.h"
//�E����o������G�̃N���X
class EnemyRight : public EnemyBase
{
public:
	EnemyRight();
	virtual ~EnemyRight();

	//void Init();
	virtual void Update() override;
	//void Draw() const;

	//�����o�[�ϐ��ɃA�N�Z�X����
	//void SetHandle(int handle) { m_handle = handle; }

	//bool isExist() const { return m_isExist; }

	//�G�L�����N�^�[���X�^�[�g������
	virtual void Start() override;

private:
	//int m_handle;   //�O���t�B�b�N�̃n���h��

	//bool m_isExist; //���݂��邩�t���O(�g�p�����ǂ���)

	//float m_posX;
	//float m_posY;
	//�\���ʒu
	//Vec2 m_pos;
	//�ړ���  1�t���[��������̈ړ��x�N�g��������
	//Vec2 m_vec;
};

