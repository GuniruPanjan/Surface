#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Draw() const;

	void SetGraphHandle(int handle);

	//�G�L�����N�^�[�J�n�ʒu
	//��ʏォ�痎���n�߂�
	void Start();

	//���݂��邩�`�F�b�N
	bool isExist() const { return m_isExist; }

	//�����蔻����Ƃ邽�߂ɕK�v�ȏ���������������֐�
	float GetLeft() const;    //���̍��W
	float GetTop() const;     //��̍��W
	float GetRight() const;   //�E�̍��W
	float GetBottom() const;  //���̍��W



	void SetStartPos();

private:
	//�c���p�ɕۑ�����ʒu���̐�
	static constexpr int kPosLogFrame = 8;


private:
	int m_handle;
	//�O���t�B�b�N�̃T�C�Y
	int m_width;
	int m_height;

	//���݂��邩�t���O
	bool m_isExist;

	float m_posX[kPosLogFrame];
	float m_posY[kPosLogFrame];

	//�ړ���
	float m_moveY;
};

