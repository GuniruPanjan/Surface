#include "SceneManager.h"
#include"Scene.h"

//push_back;�����ɒǉ�
//push_front;�擪�ɒǉ�
//pop_back;�������폜
//pop_front;�擪���폜
//front();�擪�̗v�f�ւ̎Q�Ƃ��擾
//back();�����̗v�f�ւ̎Q�Ƃ��擾
SceneManager::~SceneManager()
{
	delete scene_;
}
void SceneManager::Update(Input& input)
{
	//�����̂ݎ��s
	scene_.back()->Update(input);
}

void SceneManager::Draw()
{
	//�擪���珇�ɕ`��
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
	

	if (scene_ != nullptr)//�O�̃V�[������������
	{
		delete scene_;//������Ă���
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
