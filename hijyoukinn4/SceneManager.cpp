#include "SceneManager.h"
#include"Scene.h"

//push_back;末尾に追加
//push_front;先頭に追加
//pop_back;末尾を削除
//pop_front;先頭を削除
//front();先頭の要素への参照を取得
//back();末尾の要素への参照を取得
SceneManager::~SceneManager()
{
	delete scene_;
}
void SceneManager::Update(Input& input)
{
	//末尾のみ実行
	scene_.back()->Update(input);
}

void SceneManager::Draw()
{
	//先頭から順に描画
	for (auto& scene : scene_)
	{
		scene->Draw();
	}
	scene_.back()->Draw();
}

void SceneManager::ChangeScene(std::shared_ptr<Scene> nextScene)
{
	if (scene_.empty())
	{
		scene_.push_back(nextScene);
	}
	else
	{
		scene_.back() = nextScene;

	}
	

	if (scene_ != nullptr)//前のシーンがあったら
	{
		delete scene_;//解放しておく
	}
	scene_ = nextScene;
}

void SceneManager::PushScene(std::shared_ptr<Scene> scene)
{
	scene_.push_back(scene);
}

void SceneManager::PopScene()
{
	scene_.pop_back();
}
