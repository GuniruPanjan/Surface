#pragma once
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void Updete();
	void Draw();
	void End();

private:
	//�萔�̒�`
	enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindMain,
		kSceneKindResult,
	};

private:
	//���ݎ��s���̃V�[��
	SceneKind m_runScene;
	

	// SceneManager�ŊǗ�����e�V�[��
	SceneTitle m_title;
	SceneMain m_main;
	SceneResult m_result;

};
