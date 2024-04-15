#pragma once
#include "SceneBase.h"
class SceneChoice : public SceneBase
{
public:
	SceneChoice();
	virtual ~SceneChoice();

	virtual void Init(); //�V�[���ɓ���Ƃ��̏���������
	virtual std::shared_ptr<SceneBase> Update(); //���t���[���s���X�V����
	virtual void Draw(); //���t���[���s���`�揈��
	virtual void End(); //�V�[���𔲂��鎞�̏I������

	//�X�e�[�W�̗����\����
	bool front, back;

private:

	//�����̈ʒu�ϐ�
	int X, Y;

	//���Ԃ��v������ϐ�
	int Time, TimeNow;

	//��L�[�Ɖ��L�[�̕ϐ�
	bool Up, Down;

	//�I�ԃ|�C���g
	int Select;
};

