#pragma once

class Enemy
{
public:
	Enemy();
	~Enemy();

	void init();
	void update();
	void draw();

	//�����o�ϐ��𒼐ڕύX�������ꍇ��
	//public�ȃ����o�֐����o�R���ĕύX����
	//�s���Ȓl��ݒ肳�ꂽ�ꍇ�A�s������Ȃ��悤�ɂ�����ł���
	void setPosX(int x);
	int getPosX();   //�����o�ϐ��̒l���擾���邽�߂�get�֐�
	int getPosY();

	int getRadius();
	void setColor(unsigned int x);
	//�����o�ϐ���private
private:
	int m_posX;
	int m_posY;
	unsigned int Color;
	

};