#pragma once
#include "SceneBase.h"
class SceneDeadBack : public SceneBase
{
public:
	SceneDeadBack();
	virtual ~SceneDeadBack();

	virtual void Init(); //�V�[���ɓ���Ƃ��̏���������
	virtual std::shared_ptr<SceneBase> Update(); //���t���[���s���X�V����
	virtual void Draw(); //���t���[���s���`�揈��
	virtual void End(); //�V�[���𔲂���Ƃ��̏I������

	//�I�ׂ�{�^���̈ʒu�ϐ�
	int SelectX, SelectY;

	//�I�ׂ�{�^���̕�
	int SelectWidth, SelectHight;

	//��L�[�Ɖ��L�[�̉����Ă锻��
	bool Up, Down;
};

