#include "Player.h"
#include "DxLib.h"
#include<cmath>

namespace
{
	//���f���̃t�@�C����
	const char* const kPlayerModelFilename = "date/Knight.mv1";

	//�A�j���[�V�����ԍ�
 	constexpr int KIdleAnimIndex = 1;    //�ҋ@
 //   constexpr int KIdleAnimIndex = 2;    //�ҋ@
	constexpr int KAttackAnimIndex = 30; //�U��

	//�A�j���[�V�����̐؂�ւ��ɂ�����t���[����
	constexpr float kAnimChangeFrame = 8.0f;
	constexpr float kAnimChageRateSpeed = 1.0f / kAnimChangeFrame;

	//�A�i���O�X�e�B�b�N�ɂ��ړ��֘A
	constexpr float kMaxSpeed = 0.05f;        //�v���C���[�̍ő�ړ����x
	constexpr float kAnalogRangeMin = 0.1f;   //�A�i���O�X�e�B�b�N�̓��͔���͈�
	constexpr float kAnalogRangeMax = 0.8f;
	constexpr float kAnglogInputMax = 1000.0f;   //�A�i���O�X�e�B�b�N������͂����x�N�g���̍ő�

}

Player::Player():
	m_modelHandle(-1),
	m_currentAnimNo(-1),
	m_prevAnimNo(-1),
	m_animBlendRate(0.0f),
	m_isAttack(false),
	m_cameraAngle(0.0f),
	m_angle(0.0f)
{
	
}

Player::~Player()
{
}

void Player::Load()
{
	m_modelHandle = MV1LoadModel(kPlayerModelFilename);
}

void Player::Delete()
{
	//���\�[�X��������������
	MV1DeleteModel(m_modelHandle);
	m_modelHandle = -1;
}

void Player::Init()
{
	//�ҋ@�A�j���[�V������ݒ�
	m_currentAnimNo = MV1AttachAnim(m_modelHandle, KIdleAnimIndex, -1, false);
	m_prevAnimNo = -1;
	m_animBlendRate = 1.0f;

	//�v���C���[�̏����ʒu�ݒ�
	m_pos = VGet(0.0f, 0.0f, 0.0f);
	MV1SetPosition(m_modelHandle, m_pos);

	m_isAttack = false;
}

void Player::Update()
{
	//�A�j���[�V�����̐؂�ւ�
	if (m_prevAnimNo != -1)
	{
		m_animBlendRate = kAnimChageRateSpeed;
		if (m_animBlendRate >= 1.0f) m_animBlendRate = 1.0f;

		//�ύX��̃A�j���[�V����������ݒ肷��
		MV1SetAttachAnimBlendRate(m_modelHandle, m_prevAnimNo, 1.0f - m_animBlendRate);
		MV1SetAttachAnimBlendRate(m_modelHandle, m_currentAnimNo, m_animBlendRate);

	}

	//�A�j���[�V������i�߂�
	bool isLoop = UpdateAnim(m_currentAnimNo);
	UpdateAnim(m_prevAnimNo);
	
	//�{�^������������U���A�j���[�V�������Đ�����
	if (!m_isAttack)
	{
		int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (pad & PAD_INPUT_1)
		{
			m_isAttack = true;
			
			ChangeAnim(KAttackAnimIndex);
		}
		else
		{
			//�A�i���O�X�e�B�b�N���g���Ĉړ�
			int analogX = 0;
			int analogY = 0;

			GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

			//�A�i���O�X�e�B�b�N�̓��͂�10%�`80%�͈̔͂��g�p����
			// 
			//�x�N�g���̒������ő��1000�ɂȂ�
			//�v���C���[�̍ő�ړ����x��0.01f / frame

			VECTOR move = VGet(analogX, 0.0f, -analogY);    //�x�N�g���̒�����0�`1000
			                                                //0.00�`0.01�̒����ɂ���
			//�x�N�g���̒������擾����
			float len = VSize(move);
			//�x�N�g��������0.0�`1.0�̊����ɕϊ�����
			float rate = len / kAnglogInputMax;

			//�A�i���O�X�e�B�b�N�����Ȕ͈͂����O����
			rate = (rate - kAnalogRangeMin) / (kAnalogRangeMax - kAnalogRangeMin);
			rate = min(rate, 1.0f);
			rate = max(rate, 0.0f);

			//���x������ł���̂ňړ��x�N�g���ɔ��f����
			move = VNorm(move);
			float speed = kMaxSpeed * rate;

			move = VScale(move, speed);

			//�J�����̂���ꏊ(�p�x)����
			//�R���g���[���ɂ��ړ����������肷��
			MATRIX mtx = MGetRotY(-m_cameraAngle - DX_PI_F / 2);
			move = VTransform(move, mtx);

			//�ړ���������v���C���[�̌������������肷��
			//�ړ����ĂȂ��ꍇ(�[���x�N�g��)�̏ꍇ�͕ύX���Ȃ�
			if (VSquareSize(move) > 0.0f)
			{
				m_angle = -atan2f(move.z, move.x) - DX_PI_F / 2;
			}


			m_pos = VAdd(m_pos, move);
		}
	}
	else
	{
		//�U���A�j���[�V�������I��������ҋ@�A�j���[�V�������Đ�����
		if (isLoop)
		{
			m_isAttack = false;
			
			ChangeAnim(KIdleAnimIndex);
		}
	}

	MV1SetPosition(m_modelHandle, m_pos);
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle, 0.0f));
}

void Player::Draw()
{
	//���f���̕`��
	MV1DrawModel(m_modelHandle);
}

bool Player::UpdateAnim(int attackNo)
{
	//�A�j���[�V�������ݒ肳���
	if (attackNo == -1) return false;

	//�A�j���[�V������i�s������
	float now = MV1GetAttachAnimTime(m_modelHandle, attackNo);
	now += 0.5f;

	//���ݍĐ����̃A�j���[�V�����̑��J�E���g���擾����
	float total = MV1GetAttachAnimTotalTime(m_modelHandle, attackNo);
	bool isLoop = false;
	while (now >= total)
	{
		now -= total;
		isLoop = true;
	}
	//�i�߂����Ԃɐݒ�
	MV1SetAttachAnimTime(m_modelHandle, attackNo, now);

	return isLoop;
}

void Player::ChangeAnim(int animIndex)
{
	//����ɌÂ��A�j���[�V�������A�^�b�`����Ă���ꍇ�͂��̎��_�ō폜���Ă���
	if (m_prevAnimNo != -1)
	{
		MV1DetachAnim(m_modelHandle, m_prevAnimNo);
	}

	//���ݍĐ����̑ҋ@�A�j���[�V�����͕ύX�O�̃A�j���[�V����������
	m_prevAnimNo = m_currentAnimNo;

	//�ύX��̃A�j���[�V�����Ƃ��čU���A�j���[�V���������߂Đݒ肷��
	m_currentAnimNo = MV1AttachAnim(m_modelHandle, KAttackAnimIndex, -1, false);

	//�؂�ւ��̏K���͕ύX�O�̃A�j���[�V�������Đ�������Ԃɂ���
	m_animBlendRate = 0.0f;

	//�ύX�O�̃A�j���[�V����100
	MV1SetAttachAnimBlendRate(m_modelHandle, m_prevAnimNo, 1.0f - m_animBlendRate);

	MV1SetAttachAnimBlendRate(m_modelHandle, m_currentAnimNo, m_animBlendRate);
}
