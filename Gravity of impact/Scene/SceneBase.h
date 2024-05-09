#pragma once
#include "SceneFedo.h"
#include<memory>

class SceneBase : public std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase():
		GameBack(0),
		ChoiceBack(0),
		TitleBack(0),
		GoalBack(0),
		Titlelogo(0)
	{}
	virtual ~SceneBase(){}

	//virtualで継承先を呼び出す

	virtual void Init() = 0;
	virtual std::shared_ptr<SceneBase> Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//シーンの背景画像格納変数
	int GameBack, ChoiceBack, TitleBack, GoalBack;

	//タイトルロゴ格納変数
	int Titlelogo;

	//Sceneのフェードを管理するポインタ
	std::shared_ptr<SceneFedo> fedo = std::make_shared<SceneFedo>();
};

