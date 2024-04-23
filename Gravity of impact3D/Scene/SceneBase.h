#pragma once
#include<memory>

class SceneBase : std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase(){}
	virtual ~SceneBase(){}

	//virtualで継承先を呼び出す

	virtual void Init() = 0; //シーンに入るときの初期化処理
	virtual std::shared_ptr<SceneBase> Update() = 0; //シーンを変更するときポインタのものにする
	//シーンを変更しない場合は自身のポインタ
	virtual void Draw() = 0; //毎フレーム行う描画処理
	virtual void End() = 0; //シーンを抜ける時の終了処理
};

