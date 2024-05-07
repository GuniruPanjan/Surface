#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneChoice.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	//タイトルロゴを読み込む
	Titlelogo = LoadGraph("data/GravityImpactロゴ.png");
}

std::shared_ptr<SceneBase> SceneTitle::Update()
{
	//入力でシーン遷移
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneChoice>();
	}

	return shared_from_this();  //自身のポインタを返す
}

void SceneTitle::Draw()
{
	//タイトルロゴの初期位置
	int Titlelogox, Titlelogoy;

	Titlelogox = 0;
	Titlelogoy = -100;

	DrawString(205, 300, "Push Any Button", GetColor(255, 255, 255));

	//タイトルロゴを書く
	DrawGraph(Titlelogox, Titlelogoy, Titlelogo, true);
}

void SceneTitle::End()
{
}
