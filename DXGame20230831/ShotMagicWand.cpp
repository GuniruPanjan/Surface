#include "ShotMagicWand.h"
#include "Game.h"
#include "DxLib.h"
#include "SceneMain.h"
#include<cassert>

namespace
{
	//�萔�̒�`

	constexpr float kSpeed = 4.0f;  //�e�̈ړ����x

	//�V���b�g�̑傫��
	constexpr float kWidth = 4.0f;
	constexpr float kHeight = 4.0f;

	//�o���Ă����ߋ��̈ʒu���̐�
	constexpr int kPosLogNum = 8;

	
}

ShotMagicWand::ShotMagicWand()
{
	m_posLog.resize(kPosLogNum);
}

ShotMagicWand::~ShotMagicWand()
{
}

void ShotMagicWand::Init()
{
}

void ShotMagicWand::Update()
{
	if (m_isExist) return;

	//�ʒu�̃��O�����炷
	//for (int i = 1; i < m_posLog.size(); i++)
	for(int i = m_posLog.size() - 1; i >= 1; i--)
	{
		m_posLog[i] = m_posLog[i - 1];
	}
	//1�t���[���O�̏�������
	m_posLog[0] = m_pos;

	m_pos += m_vec;
	//�����蔻��̍X�V
	m_colRect.SetCenter(m_pos.x, m_pos.y, kWidth, kHeight);

	//��ʊO�ɏo������
	//�ߋ��̕\���ʒu���܂߂Ă��ׂĉ�ʊO�ɂł���I��
	bool isOut = false;
	if (m_pos.x < 0.0f - kWidth / 2) isOut = true;
	if (m_pos.x > Game::kScreenWidth + kWidth / 2) isOut = true;
	if (m_pos.x < 0.0f - kHeight / 2) isOut = true;
	if (m_pos.x > Game::kScreenHeight + kHeight / 2) isOut = true;
	//�`�F�b�N���̍��W����ʓ��Ȃ炱���ŏI��
	if (!isOut) return;

	//�ߋ����O����ʊO�ɂ��邩���`�F�b�N����
	for (int i = 0; i < m_posLog.size(); i++)
	{
		if (m_posLog[i].x < 0.0f - kWidth / 2) isOut = true;
		if (m_posLog[i].x > Game::kScreenWidth + kWidth / 2) isOut = true;
		if (m_posLog[i].x < 0.0f - kHeight / 2) isOut = true;
		if (m_posLog[i].x > Game::kScreenHeight + kHeight / 2) isOut = true;
		//�`�F�b�N���̍��W����ʓ��Ȃ炱���ŏI��
		if (!isOut) return;
	}

	//�����ɗ����Ƃ������Ƃ͉�ʊO�ɂ���
	m_isExist = false;

	if ((m_vec.x < 0.0f) &&   //���Ɉړ����Ă���G
		(m_pos.x < 0.0f - kWidth / 2))   //�������ʊO�ɏo��
	{
		m_isExist = false;
	}
	//�E�Ɉړ����Ă���G��"��ʉE���犮�S�ɏo�������G������
	if ((m_vec.x > 0.0f) &&   //�E�Ɉړ����Ă���G
		(m_pos.x > Game::kScreenWidth + kWidth / 2))   //�E�����ʊO�ɏo��
	{
		m_isExist = false;
	}
	//��Ɉړ����Ă���G��"��ʏォ�犮�S�ɏo�������G������
	if ((m_vec.y < 0.0f) &&   //��Ɉړ����Ă���G
		(m_pos.y < 0.0f - kHeight / 2))   //�ォ���ʊO�ɏo��
	{
		m_isExist = false;
	}
	//���Ɉړ����Ă���G��"��ʉ����犮�S�ɏo�������G������
	if ((m_vec.y > 0.0f) &&   //���Ɉړ����Ă���G
		(m_pos.y > Game::kScreenHeight + kHeight / 2))   //�������ʊO�ɏo��
	{
		m_isExist = false;
	}
}

void ShotMagicWand::Draw()
{
	if (!m_isExist) return;

#if false
	//�c���̕\��
	for (int i = 0; i < m_posLog.size(); i++)
	{
		int alpha = 255 - (10 * (i + 1));
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawBox(m_posLog[i].x - kWidth / 2, m_posLog[i].y - kHeight / 2,
			    m_posLog[i].x + kWidth / 2, m_posLog[i].y + kHeight / 2, GetColor(255, 255, 0), true);
	}
	//�\�����[�h�����ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//�e�̎���
	DrawBox(m_pos.x - kWidth / 2, m_pos.y - kHeight / 2,
		    m_pos.x + kWidth / 2,m_pos.y + kHeight / 2, GetColor(255,255,0),true);
    //test
	DrawLine(m_pos.x, m_pos.y, m_posLog[7].x, m_posLog[7].y, GetColor(255, 0, 0), kWidth);
#else
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	for (int i = 0; i < m_posLog.size(); i++)
	{
		for (int linenum = 0; linenum < 8; linenum++)
		{
			int startX = m_pos.x;
			int startY = m_pos.y;
			int endX = m_posLog[i].x;
			int endY = m_posLog[i].y;

			//�����͂���Ă��Ȃ����e
			//�������悭���邽�߂Ɏg���܂�
			float angle = GetRand(359) / DX_TWO_PI_F * 360.0f;
			float len = GetRand(4) - 2;
			startX += cosf(angle) * len;
			startY += sinf(angle) * len;
			angle = GetRand(359) / DX_TWO_PI_F * 360.0f;
			len = GetRand(4) - 2;
			endX += cosf(angle) * len;
			endY += sinf(angle) * len;

			DrawLine(startX, startY, endX, endY, GetColor(16, 4, 2), kWidth);
		}
		
	}
	//�\�����[�h�����ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
#endif
#ifdef _DEBUG
	//�e�̓����蔻��f�o�b�O�\��
	m_colRect.Draw(GetColor(0, 0, 0), false);
#endif
}

void ShotMagicWand::Start(Vec2 pos)
{
	//SceneMain�̐ݒ�Y��`�F�b�N
	assert(m_pMain);

	m_isExist = true;
	//�����ʒu�̐ݒ�
	m_pos = pos;

	//�ߋ��̏������������_�ł͏����ʒu�Ɠ����ɂ��Ă��܂�
	//�c�����ςȈʒu�ɕ\������Ȃ��悤�ɂ��邽��
	for (int i = 0; i < m_posLog.size(); i++)
	{
		m_posLog[i] = m_pos;
	}

	//������
	//m_vec.x = kSpeed;
	//m_vec.y = 0.0f;

	//��ԋ߂��G�̕����Ɉړ�����
	

	//�^�[�Q�b�g�ʒu
	//�e�̔��ˈʒu�����ԋ߂��ɂ���G�̍��W����������
	//SceneMain�Ɏ��������֐��𗘗p����
	const Vec2 target = m_pMain->GetNearEnemyPos(m_pos);

	//���ˈʒu����^�[�Q�b�g�Ɍ������x�N�g��
	Vec2 toTarget = target - m_pos;
	//���K�� toTarget���g�𐳋K��
	toTarget.normalize();
	//�e�̑��x��kSpeed��
	m_vec = toTarget * kSpeed;
}
