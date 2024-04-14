#pragma once
#include<memory>

class SceneBase : public std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase(){}
	virtual ~SceneBase(){}

	//virtual�Ōp������Ăяo��

	virtual void Init() = 0; //�V�[���ɓ���Ƃ��̏���������(�������z�֐��ɂ���)
	virtual std::shared_ptr<SceneBase> Update() = 0; //�V�[����ύX����ꍇ�͑J�ڐ�̃V�[���̃|�C���^
	                                   //�V�[���ύX���Ȃ��ꍇ�͎��g�̃|�C���^
	virtual void Draw() = 0;  //���t���[���s���`�揈��(�������z�֐��ɂ���)
	virtual void End() = 0; //�V�[���𔲂��鎞�̏I������(�������z�֐��ɂ���)

	//�t�F�[�h��������ϐ�
	int FeadColor = 0;

	//�t�F�[�h������ϐ�
	bool FeadPlus = false;
	bool FeadMinus = true;

	//�w�i�摜�p�̕ϐ�
	int TitleSceneGraph = 0;
	int ChoiceSceneGraph = 0;
	int GameSceneGraph = 0;
	int GoalSceneGraph = 0;
};

