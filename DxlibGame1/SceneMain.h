#pragma once
#include "Player.h"
#include "Enemy.h"

//ゲームシーンをクラス化する
class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void Update();
	void Draw();
	void End();     //シーンの終了

	//シーンを終了されるかどうか
	bool IsSceneEnd() const;

	bool IsCollison(const Player& player, const Enemy& enemy);

private:
	//画面内に同時に存在できる敵の最大数
	static constexpr int kEnemyMax = 16;

private:
	int m_playerHandle;    //プレイヤーのグラフィック
	int m_enemyHandle;     //敵のグラフィック

	int m_enemyStartSe;  //敵が登場するときの効果音

	Player m_player;   
	Enemy m_enemy[kEnemyMax];

	bool m_isGameOver;  //ゲームオーバーかどうかのフラグ
	bool m_isSceneEnd;  //シーンを終了する時にtrueにする
	int m_playFrameCount;

	//敵の生成制御
	int m_enemyCreateNum;    //今までに生成した敵の数
	int m_enemyWaitFrame;    //敵生成まで待ち時間

	int m_bgmHndle;

	//フェードイン、アウト
	int m_fadeAlpha;

};

