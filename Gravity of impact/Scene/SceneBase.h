#pragma once
#include<memory>

class SceneBase : public std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase():
		GameBack(0),
		ChoiceBack(0),
		TitleBack(0),
		Titlelogo(0)
	{}
	virtual ~SceneBase(){}

	//virtual‚ÅŒp³æ‚ğŒÄ‚Ño‚·

	virtual void Init() = 0;
	virtual std::shared_ptr<SceneBase> Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//ƒV[ƒ“‚Ì”wŒi‰æ‘œŠi”[•Ï”
	int GameBack, ChoiceBack, TitleBack;

	//ƒ^ƒCƒgƒ‹ƒƒSŠi”[•Ï”
	int Titlelogo;
};

