#pragma once
#include "SceneBase.h"
class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void Init(); //�V�[���ɓ���Ƃ��̏���������
	virtual std::shared_ptr<SceneBase> Update(); //���t���[���s���X�V����
	virtual void Draw(); //���t���[���s���`�揈��
	virtual void End(); //�V�[���𔲂���Ƃ��̏I������
};


