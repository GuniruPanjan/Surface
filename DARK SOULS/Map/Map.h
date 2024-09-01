#pragma once
#include "DxLib.h"
#include "Col/RectCol.h"
#include "Col/SphereCol.h"

class Map
{
public:
	Map();
	virtual ~Map();

	void Init();
	void Update();
	void Draw();
	void End();

	bool CapsuleIsHit(const CapsuleCol& col);
	bool CapsuleSaveHit(const CapsuleCol& col);

	int GetCollisionMap() { return m_collisionHandle; }
	bool GetRoomEntered() { return m_bossRoomEntered; }
	bool GetSavePossible() { return m_saveSpot; }
	VECTOR GetVectorMapPos() { return m_MapPosition; }

private:
	int m_handle;   //�}�b�v�̃f�[�^������ϐ�
	int m_collisionHandle;   //�}�b�v�̃R���W�����̃f�[�^������ϐ�
	float m_size;   //���f���̃T�C�Y�ϐ�
	float m_Xposition;    //X�|�W�V����
	float m_Yposition;    //Y�|�W�V����
	float m_Zposition;    //Z�|�W�V����
	float m_XCollisionposition;    //X�|�W�V����
	float m_YCollisionposition;    //Y�|�W�V����
	float m_ZCollisionposition;    //Z�|�W�V����
	bool m_bossRoomEntered;    //�{�X�����ɓ���������
	bool m_saveSpot;        //�񕜃X�|�b�g���g���锻��
	bool m_oneInit;         //��񂾂�����������
	VECTOR m_MapPosition;   //�}�b�v�̃|�W�V����
	VECTOR m_collisionMapPosition;   //�R���W�����̃|�W�V�����ݒ�

	//Col�̓����蔻��
	float m_sphereRadius;
	Pos3 m_rectPos;
	Pos3 m_spherePos;
	Size m_rectSize;
	RectCol m_rectCol;
	SphereCol m_sphereCol;
	unsigned int m_color = 0xffffff;
	unsigned int m_sphereColor = 0xffffff;
};

