#pragma once
#include "SceneBase.h"
class SceneSave : public SceneBase
{
public:
	SceneSave();
	virtual ~SceneSave();

	virtual void Init();  //�V�[���ɓ���Ƃ��̏���������
	virtual std::shared_ptr<SceneBase> Update(); //���t���[���s���X�V����
	virtual void Draw();  //���t���[���s���`�揈��
	virtual void End();  //�V�[���𔲂��鎞�̏I������
private:
	int m_frameCount;
};
