#pragma once
#include "Character/CharacterBase.h"
#define ENEMY_NOW 1  //�G�̔z��ŏo����

class Player;

class EnemyBase : public CharacterBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtual�Ōp������Ăяo��
	void Init() {};
	void Update() {};
	void Draw() {};
	virtual void End();
	
protected:
	bool m_enemySearchFlag;  //�G�̍��G�t���O
	bool m_enemyWait;    //�G����苗����ۂt���O
	int m_enemyWaitseeRandom;   //�G�l�~�[�̗l�q���s���̃����_����
	float m_searchRadius;  //�~�̓����蔻��
	float m_distanceRadius;  //�~�̔��a
	float m_moveTurning;   //���v���ɐ��񂷂邽�߂̖@���x�N�g��
	float m_moveReverseTurning;  //�����v����ɐ��񂷂邽�߂̖@���x�N�g��
	Pos3 m_colSearchPos;  //���G�͈͂̓����蔻��
	Pos3 m_colDistancePos;   //��苗����ۂ��߂̔���
	SphereCol m_colSearch;  //�X�t�B�A�^�̓����蔻��
	SphereCol m_colDistance;  //��苗����ۂX�t�B�A�^�̓����蔻��
};

