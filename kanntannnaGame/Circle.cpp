#include "Circle.h"
#include "DxLib.h"
#include <cmath>   //���w�֐����g������

namespace
{
	//�~�̏������a
	constexpr int kRadiuDefault = 64;
	//�ŏ��T�C�Y
	constexpr int kRadiusMin = 12;
}



//�R���X�g���N�^�@�����o�ϐ��̏��������s��
//�R���X�g���N�^�Ń����o�ϐ�������������Ƃ���
//�R���X�g���N�^�������q���g�p����
Circle::Circle():
	m_posX(0),
	m_posY(0),
	m_radius(64),
	m_isLastMouseDown(false),
	m_isMouseIn(false),
	m_isExist(true)
{

	//rand()�̎��Ǝg�����肪�Ⴄ�̂ŋC��t����
	//int num = rand() % 64;  //0~63
	//int num2 = GetRand(64);  //0~64
}

Circle::~Circle()
{

}

void Circle::init()
{
	m_posX = (GetRand(640 - m_radius * 2) + m_radius);
	m_posY = (GetRand(480 - m_radius * 2) + m_radius);
	m_isExist = true;
}

void Circle::update()
{
		

	//�}�E�X���N���b�N����Ă����Ԃ��擾
	bool isClick = false;
	if ((GetMouseInput() & MOUSE_INPUT_LEFT))
	{

	}
	//�~�����݂��Ȃ��ꍇ�͏��������I��
	if (!m_isExist)
	{
		m_isLastMouseDown = isClick;
		return;
	}

	//�}�E�X�J�[�\���̈ʒu�擾
	int mouseX;
	int mouseY;
	GetMousePoint(&mouseX,&mouseY);

	//(float)num     :C���ꕗ�L���X�g�@�@C++�ł͎g��Ȃ�
	//static_cast<float>(num)   :C++�̃L���X�g�@static_�ȊO�g��Ȃ�
	float dx =  static_cast<float>(mouseX - m_posX);
	float dy = static_cast<float>(mouseY - m_posY);

	if (sqrtf(dx * dx + dy * dy) < m_radius)
	{
		//�}�E�X�J�[�\�����~�̒��ɂ���
		m_isMouseIn = true;
	}
	else
	{
		m_isMouseIn = false;
	}

	//�N���b�N��������
	if (isClick && !m_isLastMouseDown)
	{
		if (m_isMouseIn)   //�J�[�\�����~�̒��ɂ����ԂŃN���b�N����
		{
			//�~������
			m_isExist = false;
		}
	}
	//���̃t���[���̃}�E�X�̏�Ԃ��o���Ă���
	m_isLastMouseDown = isClick;

}

void Circle::draw()
{
	
	unsigned int color = GetColor(255,255,255);
	if (m_isMouseIn)
	{
		color = GetColor(255, 0, 0);

	}
	DrawCircle(m_posX, m_posY, m_radius, color, true);

	//���W�𕶎��ŕ\������
	DrawFormatString(0, 0, GetColor(255, 255, 255), "pos(%d,%d)", m_posX, m_posY);

	
}

void Circle::smaller(int size)
{
	m_radius -= size;
	//�T�C�Y�̉�����ݒ肷��
	if (m_radius < kRadiusMin)
	{
		m_radius = kRadiusMin;
	}
}
