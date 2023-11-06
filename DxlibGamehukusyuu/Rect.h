#pragma once
class Rect
{
public:
	Rect();
	~Rect();

	void Init();
	void Update();
	void Draw();

	//��ʓ��̃����_���Ȉʒu�Ƀ����_���ȑ傫���̋�`�f�[�^��ݒ肷��
	void SetRandom();

	//public�Ȋ֐��o�R�Ń����o�[�ϐ���ύX����
	void SetColor(unsigned int color) { m_color = color; }
	void SetFill(bool isFill) { m_isFill = isFill; }
	void SetMouseTrase(bool isTrase) { m_isMouseTrase = isTrase; }

	//�N���X�O������W��ύX����
	//void SetPosX(int x) { m_posX = x; }
	//void SetPosY(int y) { m_posY = y; }

	//�����蔻������p�ɏ㉺���E�̍��W���擾�ł���悤�ɂ���
	bool IsCollision(const Rect& target) const;
	int GetLeft() const; //X���W
	int GetTop() const; //Y���W
	int GetRight() const; 
	int GetBottom() const;

private:
	//���S���W�ƕ��A�����ŊǗ�����
	int m_posX;
	int m_posY;
	int m_width;
	int m_height;

	//�F
	unsigned int m_color;
	//�h��Ԃ��t���O
	bool m_isFill;

	//�}�E�X�Ǐ]�t���O
	bool m_isMouseTrase;
};

