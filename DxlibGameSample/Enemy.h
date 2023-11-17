#pragma once

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Draw() const;     //const�֐��̒��ł̓����o�[�ϐ���ύX�ł��Ȃ�

	//�O���t�B�b�N��ݒ�
	void SetHandle(int Handle);

	//�����ʒu�̐ݒ�@��ʓ��Ƀ����_���ɔz�u����
	//�O���t�B�b�N�̃T�C�Y�����ĉ�ʓ��Ɏ��܂�悤�ɂ���̂�
	//SetHandle()���Ă���Ă�
	void SetStartPos();
private:
	int m_handle;      //�O���t�B�b�N�n���h��
	int m_graphWidth;      //�O���t�B�b�N�̕�
	int m_graphHeight;      //�O���t�B�b�N�̍���

	int m_posX;
	int m_posY;

	int m_moveX;    //�ړ�����
	
};