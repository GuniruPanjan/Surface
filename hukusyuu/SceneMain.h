#pragma once
//#include "Player.h"
//あまりヘッダーファイルでヘッダーファイルを
//インクルードするのは望ましくない

class Player;

class SceneMain
{
public:
	SceneMain();      //コンストラクタ　　メモリが確保されたときに呼ばれる関数
	~SceneMain();     //デストラクタ　　　メモリが確保されるときに呼ばれる関数

	void Init();
	void Update();
	void Draw()const;        //関数にconstを付けることでその関数の内部で
	                         //メンバー関数


private:
	int m_frameCount;

	//Playerクラスの本体ではなく、
	//そのポインタのみをメンバーとして持つ
	//Player m_player;
	Player* m_pPlayer;
};

