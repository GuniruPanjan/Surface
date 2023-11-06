#pragma once
class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	//�O���t�B�b�N�̐ݒ�A���ƍ����̎擾���s��
	void SetGraphHandle(int handle);

	//�����蔻����Ƃ邽�߂ɕK�v�ȏ���������������֐�
	float GetLeft() const;    //���̍��W
	float GetTop() const;     //��̍��W
	float GetRight() const;   //�E�̍��W
	float GetBottom() const;  //���̍��W




	int GetposX() { return m_posX; }
	int GetposY() { return m_posY; }



private:
	int m_handle;
	//�O���t�B�b�N�̃T�C�Y
	int m_width;
	int m_height;

	float m_posX;
	float m_posY;

	bool m_isTurn;

};

