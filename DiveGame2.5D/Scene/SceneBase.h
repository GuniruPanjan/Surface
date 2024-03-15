#pragma once
#include<memory>

class SceneBase : public std::enable_shared_from_this<SceneBase> 
{
public:
	SceneBase(){}
	virtual ~SceneBase(){}

	//virtualで継承先を呼び出す

	virtual void Init() = 0; //シーンに入るときの初期化処理(純粋仮想関数にする)
	virtual std::shared_ptr<SceneBase> Update() = 0; //シーンを変更する場合は遷移先のシーンのポインタ
	                                   //シーン変更しない場合は自身のポインタ
	virtual void Draw() = 0;  //毎フレーム行う描画処理(純粋仮想関数にする)
	virtual void End() = 0; //シーンを抜ける時の終了処理(純粋仮想関数にする)
};


