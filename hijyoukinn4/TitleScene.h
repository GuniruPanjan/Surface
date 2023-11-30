#pragma once
#include "Scene.h"
#include "Geometry.h"
#include<list>
/// <summary>
/// �^�C�g���V�[���N���X
/// </summary>
class TitleScene : public Scene
{
private:
	struct Bomb
	{
		int handle;
		Position2 pos;
		int frame = 0;
		bool isDead = false;
		Bomb(int h, const Position2& p) :handle(h), pos(p) {};
	};
	int handle_ = 0;
	int frame = 0;
	//�X�V�����o�֐��|�C���^
	void(TitleScene::* updateFunc_)(Input& input);
	//�`�惁���o�֐��|�C���^
	using DrawFunc_t = void(TitleScene::*)();
	DrawFunc_t drawFunc_;

	//�X�V�֐�
	void FadeInupdate(Input&); //�t�F�[�h�C�����
	void NoramalUpdate(Input& input);           //�ʏ���

	void FadeOutDraw(Input&);//�t�F�[�h�A�E�g���

	//�`��֐�
	void FadeDraw();//�t�F�[�h���`��
	void NormalDraw();//��t�F�[�h�`��

public:
	TitleScene(SceneManager& manager);
	~TitleScene();
	void Update(Input& input);
	void Draw();
};

