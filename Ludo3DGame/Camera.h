#pragma once
#include "DxLib.h"


class Camera
{
public:
	Camera();
	virtual ~Camera();

	void Init();
	void Update();
	void Draw();

private:
	VECTOR Position;      //�|�W�V����
	VECTOR Target;        //�^�[�Q�b�g
	//Near(�ŏ�����)�AFar(�ő勗��)
	float Near, Far;

};

