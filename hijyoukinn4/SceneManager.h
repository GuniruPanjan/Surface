#pragma once
#include<memory>
#include <list>
class Input;
class Scene;
/// <summary>
/// �e�V�[���J�ڂƑ�����R���g���[������N���X
/// </summary>
class SceneManager
{
private:
	std::list<std::shared_ptr<Scene>> scene_;
	//Scene* scene_ = nullptr;
public:
	~SceneManager();
	/// <summary>
	/// �����Ă���V�[����Update�֐����Ăяo��
	/// </summary>
	/// <param name="input"></param>
	void Update(Input& input);
	/// <summary>
	/// �����Ă���V�[���̕`��Draw�֐����Ăяo��
	/// </summary>
	void Draw();
	/// <summary>
	/// ���ݎ��s���̃V�[���������Ŏw�肳�ꂽ�V�[���ɐ؂�ւ���
	/// </summary>
	/// <param name="nextScene">���̃V�[��</param>
	void ChangeScene(std::shared_ptr<Scene> nextScene);
	/// <summary>
	/// ���݂̃V�[���̏�ɃV�[����������܂�
	/// </summary>
	/// <param name="scene">��ɏ���������V�[��</param>
	void PushScene(std::shared_ptr<Scene> scene);
	/// <summary>
	/// ���݂̐擪�V�[�����|�b�v���܂�
	/// </summary>
	void PopScene();
};

