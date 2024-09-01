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
	int m_randomAction;    //�G�̃����_���s���𔻒f����ϐ�
	int m_animLeftWalking;   //�G�̍�����̃��[�V�����i�[�ϐ�
	int m_animRightWalking;   //�G�̉E����̃��[�V�����i�[�ϐ�
	float m_searchRadius;  //�~�̓����蔻��
	float m_distanceRadius;  //�~�̔��a
	float m_attackRadius;   //�U�����a
	float m_moveTurning;   //���v���ɐ��񂷂邽�߂̖@���x�N�g��
	float m_moveReverseTurning;  //�����v����ɐ��񂷂邽�߂̖@���x�N�g��
	float m_randomNextActionTime;   //���Ƀ����_���s�����邽�߂̎���
	Pos3 m_colSearchPos;  //���G�͈͂̓����蔻��
	Pos3 m_colDistancePos;   //��苗����ۂ��߂̔���
	Pos3 m_colAttackPos;    //�U���̓����蔻��
	SphereCol m_colSearch;  //�X�t�B�A�^�̓����蔻��
	SphereCol m_colDistance;  //��苗����ۂX�t�B�A�^�̓����蔻��
	SphereCol m_colAttack;   //�U���̓����蔻��

	//�{�X�����̕ϐ�
	int m_bossModelHandle;   //�{�X�̃��f���n���h��
	float m_bossSize;        //�{�X�̃��f���T�C�Y�ϐ�
	int m_bossAnimStand;     //�{�X�̗����A�j���[�V�����i�[�ϐ�
	int m_bossAnimDeath;     //�{�X�̎��S�A�j���[�V�����i�[�ϐ�
	int m_bossAnimWalk;      //�{�X�̕����A�j���[�V�����i�[�ϐ�
	int m_bossAnimAttack1;   //�{�X�̍U���A�j���[�V�����i�[�ϐ�
	int m_bossAnimAttack2;   //�{�X�̍U���A�j���[�V�����i�[�ϐ�
	int m_bossAnimAttack3;   //�{�X�̍U���A�j���[�V�����i�[�ϐ�
	int m_bossAnimation[ANIMATION];  //�{�X�̃A�j���[�V�����i�[�ϐ�
	float m_bossTotalAnimTime[ANIMATION];  //�{�X�̃A�j���[�V�����Đ�����
};

