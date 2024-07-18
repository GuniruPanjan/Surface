#include "EnemyBase.h"

EnemyBase::EnemyBase():
	m_enemySearchFlag(false)
{
	//�G�̃��f���ǂݍ���
	m_handle = MV1LoadModel("Data/Enemy/EnemyModel.mv1");

	//�G�̃A�j���[�V�����ǂݍ���
	m_animStand = MV1LoadModel("Data/EnemyAnimation/WeakEnemyAnimation/WeakEnemyStand1.mv1");

	//�A�j���[�V�����A�^�b�`
	m_animation[0] = MV1AttachAnim(m_handle, 0, m_animStand, TRUE);

	//�A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);

	//�G�̃T�C�Y�ύX
	m_modelSize = 0.4f;
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));
	
}

EnemyBase::~EnemyBase()
{
	//���������
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
}

void EnemyBase::End()
{
	//���������
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);

}
