#pragma once
#include "Scene.h"
#include<unordered_map>
class KeyConfigScene:public Scene
{
private:
	int frame_ = 0;

	std::unordered_map<int, std::string> keynameTable_;
	std::unordered_map<int, std::string> padnameTable_;

	std::vector<std::string> menuItems_; //����̏����ɃR�}���h����ׂ邽�߂̔z��
	int currentLineIndex_ = 0; //���ݍs�̃C���f�b�N�X
	bool isEditingNow_ = false; //���ҏW���Ȃ̂�
	bool isEditRequestButton_ = false; //���ҏW���Ȃ̂�

	Input& input_; //input�N���X�̎Q��
	InputTable_t keyCommandTable_;
	//�X�V�����o�֐��|�C���^
	using UpdateFunc_t = void(KeyConfigScene::*)(Input& input);
	UpdateFunc_t updateFunc_;
	//�`�惁���o�֐��|�C���^
	using DrawFunc_t = void(KeyConfigScene::*)();
	DrawFunc_t drawFunc_;

	//�X�V�֐�
	void AppearInupdate(Input&); //�t�F�[�h�C�����
	void NoramalUpdate(Input& input);           //�ʏ���
	void DisappearUpdate(Input&);   //�ޏ���
	void EditUpdate(Input&); //�ҏW���

	void FadeOutDraw(Input&);//�t�F�[�h�A�E�g���

	//�`��֐�
	void FadeDraw();//�g���k���`��
	void NormalDraw();//�ʏ�`��

	void DrawCommandList();//�e�L�X�g�`��
	void CommitCurrentKeySetting();


	std::string GetKeyName(int keycode);

public:
	KeyConfigScene(SceneManager& manager,Input& input);
	void Update(Input& input);
	void Draw();
};

