#pragma once

class Player
{
public:
	Player();   //�������ɌĂ΂��
	~Player();  //�폜���ɌĂ΂��

	void init();     //������
	void update();   //���t���[���̍X�V����
	void draw();     //�`��

	//�������֐��̓w�b�_�[�ɒ��g����������
	int getPosX() { return m_posX; }
	int getPosY() { return m_posY; }

	int getRadius();

	//�����o�ϐ���private
private:
	int m_posX;
	int m_posY;

};