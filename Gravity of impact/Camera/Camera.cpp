#include "Camera.h"
//�x�����W�A���ɕϊ�
#define D2R(deg) ((deg)*DX_PI_F/180.0f)


Camera::Camera()
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
	cameraPos = VGet(0.0f, 50.0f, -100.0f);

	//�J�����̃^�[�Q�b�g���W������
	cameraTarget = VGet(0.0f, 5.0f, 0.0f);

	//�J�����̃A���O�������ݒ�
	cameraAngle = VGet(D2R(-20.0f), 0.0f, 0.0f);

	SetCameraNearFar(1.0f, 500.0f);
}

void Camera::Update(Player& player)
{

	//���L�[
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT)
	{
		cameraAngle.y += D2R(1.0f);
	}
	//�E�L�[
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT)
	{
		cameraAngle.y -= D2R(1.0f);
	}
	//��L�[
	//if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP)
	//{
	//	cameraAngle.z += D2R(1.0f);
	//}
	////���L�[
	//if()

	//��̃x�N�g��
	VECTOR Direction = VGet(0.0f, 100.0f, -100.0f);

	//X����]�s��
	MATRIX matrixX = MGetRotX(cameraAngle.x);
	//Y����]�s��
	MATRIX matrixY = MGetRotY(cameraAngle.y);
	//Z����]�s��
	MATRIX matrixZ = MGetRotZ(cameraAngle.z);

	//�s��̍���
	MATRIX matrix = MMult(matrixX, matrixY);

	//��x�N�g�����s��ŕϊ�
	Direction = VTransform(Direction, matrix);

	//�J�������W�̓v���C���[���W���班���͂Ȃꂽ�Ƃ���
	cameraPos = VAdd(player.Playerpos, Direction);

	//���L�[
	//if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT)
	//{
	//	rotate(&cameraPos.x, &cameraPos.z, +cameraAngle, 0.0f, 0.0f);
	//}
	//�E�L�[
	//if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT)
	//{
	//	rotate(&cameraPos.x, &cameraPos.z, -cameraAngle, 0.0f, 0.0f);
	//}
	//��L�[
	//if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP)
	//{
	//	rotate(&cameraPos.y, &cameraPos.z, +cameraAngle, 0.0f, 0.0f);
	//}
	//���L�[
	//if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN)
	//{
	//	rotate(&cameraPos.y, &cameraPos.z, -cameraAngle, 0.0f, 0.0f);
	//}

	

	//�����_�̍��W�̓v���C���[���W�̏�����
	cameraTarget = VAdd(player.Playerpos, VGet(0.0f, 2.0f, 0.0f));

	SetCameraPositionAndTarget_UpVecY(cameraPos, cameraTarget);
	

	DrawFormatString(300, 0, 0xffffff, "%f", player.Playerpos.x);
	DrawFormatString(300, 20, 0xffffff, "%f", player.Playerpos.y);
	DrawFormatString(300, 40, 0xffffff, "%f", player.Playerpos.z);
}

void Camera::Draw()
{

	DrawFormatString(0, 0, 0xffffff, "%f", cameraPos.x);
	DrawFormatString(0, 20, 0xffffff, "%f", cameraPos.y);
	DrawFormatString(0, 40, 0xffffff, "%f", cameraPos.z);

	

	//SetCameraPositionAndAngle(cameraPos, kCameraDist, kCameraHeight, kCameraDist);
	
}

void Camera::End()
{
}
