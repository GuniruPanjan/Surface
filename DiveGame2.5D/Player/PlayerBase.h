#pragma once
#include<memory>

class PlayerBase
{
public:
	PlayerBase();
	virtual ~PlayerBase();

	//vitrualで継承先を呼び出す
	virtual void Init() = 0;  //最初に初期化処理
	virtual void Update() = 0; //毎フレーム更新処理を行う
	virtual void Draw() = 0;  //毎フレーム描画処理を行う
	virtual void End() = 0;  //終了処理

protected:
	//プレイヤーが落下するときの重力ベクトル
	float m_gravity;
	//プレイヤーが急降下するときのベクトル
	float m_swoop;
	//プレイヤーが移動するときのベクトル
	float m_move;
	//プレイヤーのグラフ格納変数
	int m_playergraph;

};

