#pragma once
#include "SceneBase.h"
class SceneGameBack : public SceneBase
{
public:
	SceneGameBack();
	virtual ~SceneGameBack();

	virtual void Init(); //�V�[���ɓ���Ƃ��̏���������
	virtual std::shared_ptr<SceneBase> Update(); //���t���[���s���X�V����
	virtual void Draw(); //���t���[���s���`�揈��
	virtual void End(); //�V�[���𔲂���Ƃ��̏I������

	//���Ԃ𑪂�
	int Time;

	//���ݎ��Ԃ𓾂�
	int TimeNow;
};

