#include "Rect.h"
#include "DxLib.h"

namespace
{
	//�����_���ɐ��������`�̃T�C�Y����
	constexpr int kWidthMin = 32;    //�ŏ���
	constexpr int kWidthMax = 128;   //�ő��

	constexpr int kHeightMin = 24;   //�ŏ���
	constexpr int kHeightMax = 96;   //�ő��
}


Rect::Rect() :
	m_posX(320),
	m_posY(240),
	m_width(64),
	m_height(64),
	m_color(GetColor(255, 255, 255)),
	m_isFill(false),
	m_isMouseTrase(false)
{

}

Rect::~Rect()
{
}

void Rect::Init()
{
}

void Rect::Update()
{
	//�}�E�X�Ǐ]�t���O��true�Ȃ�}�E�X�|�C���^�̈ʒu�Ɉړ�
	if (m_isMouseTrase)
	{
		GetMousePoint(&m_posX, &m_posY);
	}
}

void Rect::Draw()
{
	//���S���W�Ƌ�`�̕��A�������獶���XY���W�A�E����XY���W�����߂�
	int leftX = m_posX - m_width / 2;
	int rightX = m_posX + m_width / 2;
	int topY = m_posY - m_height / 2;
	int bottomY = m_posY + m_height / 2;

	DrawBox(GetLeft(), GetTop(),       //����̍��W
		GetRight(), GetBottom(),       //�E���̍��W
		m_color, m_isFill);
}

void Rect::SetRandom()
{
	m_posX = GetRand(640);
	m_posY = GetRand(480);
	m_width = GetRand(kWidthMax - kWidthMin) + kWidthMin;
	m_height = GetRand(kHeightMax - kHeightMin) + kHeightMin;
}

bool Rect::IsCollision(const Rect& target) const
{
	
	//���g�̊��S�ɍ��ɂ���ꍇ�͓������Ă��Ȃ�
	if (GetLeft() > target.GetRight())
	{
		return false;
	}
	//���g�̊��S�ɉ��ɂ���ꍇ�͓������Ă��Ȃ�
	if (GetBottom() < target.GetTop())
	{
		return false;
	}
	//���g�̊��S�ɉE�ɂ���ꍇ�͓������Ă��Ȃ�
	if (GetRight() < target.GetLeft())
	{
		return false;
	}
	//���g�̊��S�ɏ�ɂ���ꍇ�͓������Ă��Ȃ�
	if (GetTop() > target.GetBottom())
	{
		return false;
	}
	//���S�ɓ������Ă��Ȃ��p�^�[������菜����
	//�c������͓������Ă���
	return true;
}

int Rect::GetLeft() const
{
	
	return m_posX - m_width / 2;
}

int Rect::GetTop() const
{
	return  m_posY - m_height / 2;
}

int Rect::GetRight() const
{
	return m_posX + m_width / 2;
}

int Rect::GetBottom() const
{
	return  m_posY + m_height / 2;
}