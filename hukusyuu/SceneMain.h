#pragma once
//#include "Player.h"
//���܂�w�b�_�[�t�@�C���Ńw�b�_�[�t�@�C����
//�C���N���[�h����͖̂]�܂����Ȃ�

class Player;

class SceneMain
{
public:
	SceneMain();      //�R���X�g���N�^�@�@���������m�ۂ��ꂽ�Ƃ��ɌĂ΂��֐�
	~SceneMain();     //�f�X�g���N�^�@�@�@���������m�ۂ����Ƃ��ɌĂ΂��֐�

	void Init();
	void Update();
	void Draw()const;        //�֐���const��t���邱�Ƃł��̊֐��̓�����
	                         //�����o�[�֐�


private:
	int m_frameCount;

	//Player�N���X�̖{�̂ł͂Ȃ��A
	//���̃|�C���^�݂̂������o�[�Ƃ��Ď���
	//Player m_player;
	Player* m_pPlayer;
};

