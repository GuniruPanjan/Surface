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
	PlayerZ(0.0f)
{
}

SceneGoal::~SceneGoal()
{
}

void SceneGoal::Init()
{
	//”wŒi‰æ‘œ“Ç‚İ‚İ
	GoalBack = LoadGraph("data/cloudy.png");

	//3Dƒ‚ƒfƒ‹“Ç‚İ‚İ
}

std::shared_ptr<SceneBase> SceneGoal::Update()
{
	//“ü—Í‚ÅƒV[ƒ“‘JˆÚ
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneTitle>();
	}

	return shared_from_this();  //©g‚Ìƒ|ƒCƒ“ƒ^‚ğ•Ô‚·
}

void SceneGoal::Draw()
{
	//”wŒi‰æ‘œ•`‰æ
	DrawGraph(0, 0, GoalBack, false);
}

void SceneGoal::End()
{
	//‰æ‘œ‰ğ•ú
	DeleteGraph(GoalBack);
}
