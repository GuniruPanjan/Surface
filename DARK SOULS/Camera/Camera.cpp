#include "Camera.h"
//�x�����W�A���ɕϊ�
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Camera::Camera():
	m_cameraAngle(VGet(0.0f,0.0f,0.0f)),
	m_cameraPos(VGet(0.0f,0.0f,0.0f)),
	m_cameraTarget(VGet(0.0f,0.0f,0.0f)),
	input()
{
}

Camera::~Camera()
{
}

void Camera::Init()
{
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	//��ƂȂ�J�����̍��W
	m_cameraPos = VGet(0.0f, 50.0f, -100.0f);

	//�J�����̃^�[�Q�b�g���W������
	m_cameraTarget = VGet(0.0f, 5.0f, 0.0f);

	//�J�����̃A���O�������ݒ�
	m_cameraAngle = VGet(D2R(-20.0f), 0.0f, 0.0f);

	SetCameraNearFar(1.0f, 1000.0f);
}

void Camera::Update(Player& player, Enemy& enemy)
{
	GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

	//�G�����b�N�I�����ĂȂ��Ƃ�
	if (player.GetLock() == false)
	{
		//���L�[
		if (input.Rx < 0)
		{
			m_cameraAngle.y += D2R(1.0f);
		}
		//�E�L�[
		if (input.Rx > 0)
		{
			m_cameraAngle.y -= D2R(1.0f);
		}
		//��L�[
		if (input.Ry < 0)
		{
			//�J�������v���C���[�𒴂��Ȃ����炢�܂�
			if (m_cameraAngle.x <= 0.7f)
			{
				m_cameraAngle.x += D2R(1.0f);
			}

		}
		//���L�[
		if (input.Ry > 0)
		{
			//�J�������n�ʂɂ߂肱�܂Ȃ��悤��
			if (m_cameraPos.y >= 15.2f + player.GetPosY())
			{
				m_cameraAngle.x -= D2R(1.0f);
			}

		}

		//��̃x�N�g��
		VECTOR Direction = VGet(0.0f, 100.0f, -100.0f);

		//X����]�s��
		MATRIX matrixX = MGetRotX(m_cameraAngle.x);
		//Y����]�s��
		MATRIX matrixY = MGetRotY(m_cameraAngle.y);

		//�s��̍���
		MATRIX matrix = MMult(matrixX, matrixY);

		//��x�N�g�����s��ŕϊ�
		Direction = VTransform(Direction, matrix);

		//�J�������W�̓v���C���[���W���班���͂Ȃꂽ�Ƃ���
		m_cameraPos = VAdd(player.GetPos(), Direction);

		//�����_�̍��W�̓v���C���[���W�̏�����
		m_cameraTarget = VAdd(player.GetPos(), VGet(0.0f, 50.0f, 0.0f));
	}
	//���b�N�I�������Ƃ�
	else if (player.GetLock() == true)
	{
		//�����_�͓G�̍��W�ɂ���
		m_cameraTarget = VAdd(enemy.GetPos(), VGet(0.0f, 20.0f, 0.0f));

		//�v���C���[�ƃG�l�~�[��X���W�̍������߂�
		float X = enemy.GetPosX() - player.GetPosX();

		//�v���C���[�ƃG�l�~�[��Z���W�̍������߂�
		float Z = enemy.GetPosZ() - player.GetPosZ();

		//�p�x���o��
		float angle = atan2f(X, Z);

		//�G����v���C���[�ɐL�т��̃x�N�g�������߂�
		VECTOR pos = VSub(player.GetPos(), enemy.GetPos());
		
		//�x�N�g���̐��K��
	    VECTOR posTarget = VNorm(pos);

		posTarget.x *= 130.0f;
		posTarget.z *= 130.0f;

		//�J�������ǂꂾ���v���C���[�̍��W��荂������ݒ�
		posTarget.y = 80.0f;

		m_cameraAngle.y = angle;

		//�v���C���[�̍��W�ɋ��߂��x�N�g���𑫂��āA�J�����̍��W�Ƃ���
		m_cameraPos = VAdd(player.GetPos(), posTarget);
	}

	SetCameraPositionAndTarget_UpVecY(m_cameraPos, m_cameraTarget);
}

void Camera::Draw()
{
}

void Camera::End()
{
}
