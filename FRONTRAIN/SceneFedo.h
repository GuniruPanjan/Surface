#pragma once
#include "DxLib.h"

class SceneFedo
{
public:
	SceneFedo();
	~SceneFedo();

	void Init();
	void Update();
	void StartUpdate();
	void UpdateInSetting();
	void UpdateIn();
	void DeadOut();
	void WhiteOut();
	void Draw();

	int c = 0, White, a;

	int end;

	int Out = 0;

	//スタート画面の変数
	bool Start, Setting, Explanation;

	//1回だけ実行するための変数
	bool LetGo = false;

	//スタート画面用の演出ハンドル
	int handle;

	//白い画面
	int WhiteHandle;

	int WhiteCount, WhiteTime;

	//カウント
	int Count;

	//不透明度
	int b;
};

