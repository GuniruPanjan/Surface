#pragma once
#include "Scene.h"

class Input;
class SceneManager;

class PauseScene :public Scene
{
private:
	int frame_ = 0;
	//�X�V�����o�֐��|�C���^
	using UpdateFunc_t = void(PauseScene::*)(Input& input);
	UpdateFunc_t updateFunc_;
	//�`�惁���o�֐��|�C���^
	using DrawFunc_t = void(PauseScene::*)();
	DrawFunc_t drawFunc_;

	//�X�V�֐�
	void AppearInupdate(Input&); //�t�F�[�h�C�����
	void NoramalUpdate(Input& input);           //�ʏ���
	void DisappearUpdate(Input&);   //�ޏ���

	void FadeOutDraw(Input&);//�t�F�[�h�A�E�g���

	//�`��֐�
	void FadeDraw();//�g���k���`��
	void NormalDraw();//�ʏ�`��
public:
	PauseScene(SceneManager& manager);
	void Update(Input& input);
	void Draw();
};

