#pragma once

class Physics final
{
public:
	void Update();  //�X�V(�o�^�I�u�W�F�N�g�̕����ړ�)
private:
	//�ʒu�␳�A����
	void FixNextPosition() const;
	void FixPosition();
};

