#pragma once
#include "DxLib.h"
class Player
{
public:
	Player();
	virtual ~Player();

	void Load();
	void Delete();

	void Init();
	void Update();
	void Draw();

	void SetCameraAngle(float angle) { m_cameraAngle = angle; }

private:
	//アニメーションの進行
	//ループしたかどうかを返す
	bool UpdateAnim(int attackNo);
	
	//アニメーションの変更
	void ChangeAnim(int animIndex);

private:
	int m_modelHandle;  //モデルハンドル

	int m_currentAnimNo;    //現在のアニメーション
	int m_prevAnimNo;       //変更前のアニメーション
	float m_animBlendRate;  //アニメーション合成適合

	//表示情報
	VECTOR m_pos;
	float m_angle;

	//カメラ情報
	float m_cameraAngle;

	bool m_isAttack;   //攻撃中フラグ
};

