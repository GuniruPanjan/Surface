#pragma once
#include<memory>
#include "Player/Player.h"
#include "Map/BlackHole.h"
#include "Map/Map.h"

class SceneBase : public std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase() {}
	virtual ~SceneBase() {}

	//virtualで継承先を呼び出す

	virtual void Init() = 0; //シーンに入るときの初期化処理(純粋仮想関数にする)
	virtual std::shared_ptr<SceneBase> Update() = 0; //シーンを変更する場合は遷移先のシーンのポインタ
	//シーン変更しない場合は自身のポインタ
	virtual void Draw() = 0;  //毎フレーム行う描画処理(純粋仮想関数にする)
	virtual void End() = 0; //シーンを抜ける時の終了処理(純粋仮想関数にする)

	//Playerを管理するポインタ
//std::shared_ptr<Player> player = std::make_shared<Player>();
	Player Play;

	//BlackHoleを管理するポインタ
	//std::shared_ptr<BlackHole> blackhole = std::make_shared<BlackHole>();
	BlackHole blackhole;

	//マップを管理するポインタ
	//std::shared_ptr<Map> map = std::make_shared<Map>();
	Map map;

	//フェードさせられる変数
	int FeadColor = 0;

	//フェードさせる変数
	bool FeadPlus = false;
	bool FeadMinus = true;

	//背景画像用の変数
	int TitleSceneGraph = 0;
	int ChoiceSceneGraph = 0;
	int GameSceneGraph = 0;
	int GoalSceneGraph = 0;
};


