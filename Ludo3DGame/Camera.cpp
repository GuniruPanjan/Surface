#include "Camera.h"

Camera::Camera():
	Near(0.1f),
	Far(1000.0f)
{
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(Near, Far);

	Position = VGet(0.0f, 10.0f, -20.0f);
	Target = VGet(0.0f, 10.0f, 0.0f);

	//(0,10,-20)�̎��_����(0,10,0)�̃^�[�Q�b�g������p�x�ɃJ������ݒu
	SetCameraPositionAndTarget_UpVecY(Position, Target);
}

Camera::~Camera()
{
}

void Camera::Init()
{
}

void Camera::Update()
{
	// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// ��������Ă������ɐi��
	if (Key & PAD_INPUT_UP)
	{
		Position.z += 1;
	}

	// ���������Ă����牺�ɐi��
	if (Key & PAD_INPUT_DOWN)
	{
		Position.z -= 1;
	}

	// �E�������Ă�����E�ɐi��
	if (Key & PAD_INPUT_RIGHT)
	{
		Position.x += 1;
	}

	// ���������Ă����獶�ɐi��
	if (Key & PAD_INPUT_LEFT)
	{
		Position.x -= 1;
	}

	//W�������Ă������ɐi��
	if (CheckHitKey(KEY_INPUT_W))
	{
		Position.y += 1;
	}

	//S�������Ă����牺�ɐi��
	if (CheckHitKey(KEY_INPUT_S))
	{
		Position.y -= 1;
	}


	//�J�����Ɉʒu�𔽉f
	SetCameraPositionAndTarget_UpVecY(Position, Target);
}

void Camera::Draw()
{
}
