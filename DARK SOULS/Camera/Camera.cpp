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

void Camera::Update(Player& player)
{
	GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

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
	m_cameraTarget = VAdd(player.GetPos(), VGet(0.0f, 30.0f, 0.0f));

	SetCameraPositionAndTarget_UpVecY(m_cameraPos, m_cameraTarget);
}

void Camera::Draw()
{
}

void Camera::End()
{
}
