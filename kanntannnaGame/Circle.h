#pragma once

class Circle
{
public:
	Circle(); //�R���X�g���N�^�@���������m�ۂ��ꂽ���Ɏ����I�ɌĂ΂��֐�
	~Circle();  //�f�X�g���N�^�@��������������ꂽ���Ɏ����I�ɌĂ΂��֐�

	void init();    //������
	void update();    //���t���[�����s����鏈��
	void draw();    //�`��

	//�����o�ϐ��̒l���擾�������ꍇ��public�֐��o�R�ōs��
	bool isExist() { return m_isExist; }


	//�~�̃T�C�Y������������
	void smaller(int size);

	//set,get�֐��͒��
	int getPosX() { return m_posX; }

	//�����o�ϐ��͕K��private�ɂ���
private:
	//�\���ʒu
	int m_posX;
	int m_posY;

	//���a
	int m_radius;

	//�O�̃t���[���ɍ��N���b�N��������Ă����Ԃ�
	bool m_isLastMouseDown;

	//�}�E�X�J�[�\�����~�̒��ɂ��邩
	bool m_isMouseIn;

	//���̉~�����݂��Ă��邩
	bool m_isExist;

};