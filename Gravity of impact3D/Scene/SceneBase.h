#pragma once
#include<memory>

class SceneBase : std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase(){}
	virtual ~SceneBase(){}

	//virtual�Ōp������Ăяo��

	virtual void Init() = 0; //�V�[���ɓ���Ƃ��̏���������
	virtual std::shared_ptr<SceneBase> Update() = 0; //�V�[����ύX����Ƃ��|�C���^�̂��̂ɂ���
	//�V�[����ύX���Ȃ��ꍇ�͎��g�̃|�C���^
	virtual void Draw() = 0; //���t���[���s���`�揈��
	virtual void End() = 0; //�V�[���𔲂��鎞�̏I������
};

