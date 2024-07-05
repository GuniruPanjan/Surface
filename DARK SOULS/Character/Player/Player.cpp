#include "Player.h"

Player::Player():
	m_cameraAngle(0.0f),
	m_pad(0)
{
}

Player::~Player()
{
	//���������
	MV1DeleteModel(m_handle);
}

void Player::Init()
{
	//�v���C���[HP�̏�����
	m_hp = 150.0f;

	//�v���C���[�X�s�[�h������
	m_speed = 2.0f;

	m_modelSize = 0.4f;

	//�v���C���[�����f���ǂݍ���
	m_handle = MV1LoadModel("Data/Player/PlayerModel.mv1");

	//�v���C���[�̑傫����ς���
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));

	//�v���C���[���|�W�V�����ݒ�
	m_pos = VGet(m_posX, m_posY, m_posZ);
}

void Player::Update()
{
	//�p�b�h���͏���
	m_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}

void Player::Draw()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//3D���f���`��
	MV1DrawModel(m_handle);
}

void Player::End()
{
	//���������
	MV1DeleteModel(m_handle);
}
