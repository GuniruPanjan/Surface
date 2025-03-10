#pragma once
#include "DxLib.h"
#include<memory>

class SceneBase : public std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase() {}

	virtual ~SceneBase(){}

	//virtualで継承先を呼び出す

	virtual void Init() = 0;
	virtual std::shared_ptr<SceneBase> Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

protected:
	//変数を入れる

};

