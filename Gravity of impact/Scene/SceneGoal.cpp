#include "SceneGoal.h"
#include "SceneTitle.h"
#include "DxLib.h"

SceneGoal::SceneGoal():
	Map(0),
	Player(0),
	MapX(0.0f),
	MapY(0.0f),
	MapZ(0.0f),
	PlayerX(0.0f),
	PlayerY(0.0f),
	PlayerZ(0.0f),
	SceneChange(false)
{
}

SceneGoal::~SceneGoal()
{
}

void SceneGoal::Init()
{
	//フェードの初期化
	fedo->Init();

	//背景画像読み込み
	GoalBack = LoadGraph("data/cloudy.png");

	//3Dモデル読み込み
}

std::shared_ptr<SceneBase> SceneGoal::Update()
{
	//フェードを行う
	fedo->Update();

	//入力でシーン遷移
	if (CheckHitKeyAll())
	{
		//フェードアウトを行う
		fedo->Fedo = true;

		SceneChange = true;
	}

	//シーン遷移
	if (fedo->Start <= 0 && SceneChange == true)
	{
		return std::make_shared<SceneTitle>();
	}

	return shared_from_this();  //自身のポインタを返す
}

void SceneGoal::Draw()
{
	//背景画像描画
	DrawGraph(0, 0, GoalBack, false);

	//フェード
	fedo->Draw();
}

void SceneGoal::End()
{
	//画像解放
	DeleteGraph(GoalBack);
}
