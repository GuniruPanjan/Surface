#include "ShotBible.h"
#include "DxLib.h"
#include <cassert>

namespace
{
	//�V���b�g�̑傫��
	constexpr int kWidth = 16;
	constexpr int kHeight = 24;
	//�������Ă��������܂ł̃t���[����
	constexpr int kExistFrame = 60;

	//�v���C���[�̎������鎞�̔��a
	constexpr float kRadius = 100.0f;

	//�v���C���[����ς����Έʒu���f�[�^�Ƃ��Ď���
	const Vec2 kOffset[] =
	{
		Vec2 {kRadius,0.0f},    //�E
		Vec2 {0.0f,kRadius},    //��
		Vec2 {-kRadius,0.0f},   //��
		Vec2 {0.0f,-kRadius},   //��

	};

}

ShotBible::ShotBible():
	m_frameCount(0)
{
}

ShotBible::~ShotBible()
{
}

void ShotBible::Init()
{
}

void ShotBible::Update()
{
	if (!m_isExist) return;
	//�v���C���[�̃|�C���^���ݒ肳��Ă��Ȃ�
	assert(m_pPlayer);
	//��莞�Ԍo�߂����������
	m_frameCount++;
	if (m_frameCount > kExistFrame)
	{
		m_isExist = false;
		return; //�I�����m�肵����ȍ~�̏����͍s��Ȃ�
	}


	//�ړ�����
	//�v���C���[�̈ʒu�ɂ���ĕ\������ꏊ���ς��

	//index:kOffset�̉��Ԗڂ̃f�[�^���g����
	//_countof():�z��̗v�f�����擾����
	//int index = m_frameCount % _countof(kOffset);

	//������܂ł̐i�s�x�������ɕϊ�����
	float progress = static_cast<float>(m_frameCount) / static_cast<float>(kExistFrame);

	//�i�s�x*�v�f���ŉ��Ԗڂ̗v�f���g�p���邩���߂�
	int index = progress * _countof(kOffset);

	//kSffset[index]�@�Ɓ@�v���C���[�̈ʒu����ŏI�I�ȃV���b�g�̈ʒu�����肷��
	m_pos = m_pPlayer->GetPos();
}

void ShotBible::Draw()
{
	if (!m_isExist) return;
	DrawBox(m_pos.x - kWidth / 2, m_pos.y - kHeight / 2, m_pos.x + kWidth / 2, m_pos.y + kHeight / 2, GetColor(32, 32, 255), true);
}

void ShotBible::Start(Vec2 pos)
{
	m_isExist = true;

	m_pos = pos;
	m_frameCount = 0;
}
