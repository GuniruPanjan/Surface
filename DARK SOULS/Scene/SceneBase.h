#pragma once
#include "DxLib.h"
#include<memory>

class SceneBase : public std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase() {}

	virtual ~SceneBase(){}

	//virtual�Ōp������Ăяo��

	virtual void Init() = 0;
	virtual std::shared_ptr<SceneBase> Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

protected:
	//�ϐ�������

};

