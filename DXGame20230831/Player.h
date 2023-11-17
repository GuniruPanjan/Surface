#pragma once
#include "Vec2.h"
#include "Rect.h"

class SceneMain;
class Player
{
public:
	Player(SceneMain* pMain);
	~Player();

	void Init();
	void Update();
	void Draw() const;

	//�����o�[�ϐ��ɃA�N�Z�X����
	void SetHandle(int handle) { m_handle = handle; }
	//�v���C���[�̌��݈ʒu���擾����
	Vec2 GetPos() const { return m_pos; }
	//�v���C���[�̂����蔻����擾����
	Rect GetColRect() const { return m_colRect; }

	//���@�̏�̔��˃t���[���J�E���g
	int m_magicWandFrame;

	//�v���C���[���_���[�W���󂯂�
	void OnDamage();

public:
	//�����Ă����
	enum Dir
	{
		kDirDown,   //��
		kDirLeft,   //��
		kDirRight,   //�E
		kDirUp,     //��
	};

private:
	SceneMain* m_pMain;

	int m_handle;   //�O���t�B�b�N�̃n���h��
	//�\���ʒu
	Vec2 m_pos;
	//�����蔻��̋�`
	Rect m_colRect;

	float m_posX;
	float m_posY;
	//�����Ă������
	Dir m_dir;
	//�����A�j���[�V����
	int m_warkAnimFrame;
	int m_warkAnimCount;

	//�_���[�W���󂯂Ă���̃t���[����
	//���i�͂O
	//�����������Ƀt���[������ݒ肵��
	//�ȍ~�t���[�����炵�Ă���
	int m_damageFrame;
};

