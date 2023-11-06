#include "SceneMain.h"
#include "DxLib.h"
#include "Game.h"
#include <cassert>

namespace
{
	//ゲームオーバー時に表示する文字列
	const char* const kGameOverString = "GAME OVER";

	//敵の生成間隔（フレーム数）
	constexpr int kEnemyDefaultWaitFrame = 60;
	//敵の最短生成間隔
	constexpr int kEnemyWaitFrameMin = 3;
	//敵の生成間隔を敵何体生成するたびに短くするか
	constexpr int kEnemyWaitFrameChangeNum = 5;
	//一度生成間隔を短くする時に何フレーム短くするか
	constexpr int kEnemyWaitFrameChangeFrame = 1;

}

SceneMain::SceneMain():
	m_playerHandle(-1),
	m_enemyHandle(-1),
	m_enemyStartSe(-1),
	m_bgmHndle(-1),
	m_player(),    //クラスを初期化するとき、()の中にはコンストラクタの引数を入れる
	               //Playerクラスに関してはコンストラクタに引数がないので()でOK
	m_enemy(),
	m_isGameOver(false),
	m_isSceneEnd(false),
	m_playFrameCount(0),
	m_enemyCreateNum(0),
	m_enemyWaitFrame(0),
	m_fadeAlpha(255)      //不透明で初期化
{
}

SceneMain::~SceneMain()
{
	
}

void SceneMain::Init()
{
	//BGMの読み込み
	m_bgmHndle = LoadSoundMem("data/Sound/30m.rarara.mp3");

	//BGMの再生
	PlaySoundMem(m_bgmHndle, DX_PLAYTYPE_LOOP);


	ChangeFont("ＭＳ ゴシック");
	
	//グラフィックのロード
	int m_playerHandle= LoadGraph("data/gamechara.png");
	assert(m_playerHandle != -1);    //グラフィックのロードに失敗
	int m_enemyHandle = LoadGraph("data/ゲームキャラ２.png");
	assert(m_enemyHandle != -1);     //グラフィックのロードに失敗

	//サウンドのロード
	//m_enemyStartSe = LoadSoundMem("data/Sound/30m.rarara.mp3");

	m_player.Init();
	m_player.SetGraphHandle(m_playerHandle);

	for (int i = 0; i < kEnemyMax; i++)
	{
		m_enemy[i].Init();
		m_enemy[i].SetGraphHandle(m_enemyHandle);
		m_enemy[i].SetStartPos();
	}

	//各種変数の初期化
	m_isGameOver = false;
	m_isSceneEnd = false;
	m_playFrameCount = 0;
	m_enemyCreateNum = 0;
	m_enemyWaitFrame = 0;

	m_fadeAlpha = 255;
	
}

void SceneMain::Update()
{

	
	//ゲームオーバーなら各処理を行わず、即Update()を終了させる
	if (m_isGameOver)
	{
		if (m_isSceneEnd)
		{
			//フェードアウト
			m_fadeAlpha += 8;
			if (m_fadeAlpha > 255 )
			{
				m_fadeAlpha = 255;
			}
		}
		int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if(pad & PAD_INPUT_1)
		{
			m_isSceneEnd = true;
		}
		return;
	}

	//フェードイン
	m_fadeAlpha -= 8;
	if (m_fadeAlpha < 0)
	{
		m_fadeAlpha = 0;
	}

	m_playFrameCount++;

	m_player.Update();
	for (int i = 0; i < kEnemyMax; i++)
	{
		m_enemy[i].Update();
		if (IsCollison(m_player, m_enemy[i]))
		{
			m_isGameOver = true;
		}
	}

	//一定間隔で敵を生成
	m_enemyWaitFrame++;

	
	//敵を一定数生成するたびに敵の生成間隔が短くなる
	int waitFrame = kEnemyDefaultWaitFrame;
	waitFrame -= (m_enemyCreateNum / kEnemyWaitFrameChangeNum) * kEnemyWaitFrameChangeFrame;
	//一番短い生成間隔のチェック
	if (waitFrame < kEnemyWaitFrameMin) waitFrame = kEnemyWaitFrameMin;

	if(m_enemyWaitFrame >= kEnemyDefaultWaitFrame)
	{
		for (int i = 0; i < kEnemyMax; i++)
		{
			//m_enemy[i].isExist()がfalseの場合存在していない
			if (!m_enemy[i].isExist())
			{
				m_enemyCreateNum++;
				m_enemyWaitFrame = 0;
				m_enemy[i].Start();

				//PlaySoundMem(m_enemyStartSe,DX_PLAYTYPE_BACK);

				break; //1体生成したら終了
			}
		}
		
	}
	
}

void SceneMain::Draw()
{
	m_player.Draw();
	for (int i = 0; i < kEnemyMax; i++)
	{
		m_enemy[i].Draw();
	}
	

	//生存期間を表示
	//分：秒.ミリ秒
	int milliSec = m_playFrameCount * 1000 / 60;
	int sec = (milliSec / 1000) % 60;
	int min = (milliSec / 1000) / 60;
	milliSec %= 1000;    //ミリ秒の部分のみ残す

	//文字列の横幅取得
	int strWidth = GetDrawFormatStringWidth("%d:%d.%d", min, sec, milliSec);

	DrawFormatString(Game::kScreenWidth / 2 - strWidth / 2, 8, GetColor(255, 255, 255), "%d:%d.%d", min, sec, milliSec);

	for (int i = 0; i < kEnemyMax; i++)
	{
		if (IsCollison(m_player, m_enemy[i]))
		{
			//画面中央にゲームオーバー表示

			//表示する文字の横幅を取得する
			//GetDrawStringWidth(char* String, int StrLen);
			int len = strlen(kGameOverString);
			int width = GetDrawStringWidth("GAMEOVER", 14);
			int height = GetFontSize();

			DrawString(Game::kScreenWidth / 2 - width / 2, Game::kScreenHeigth / 2 - height / 2, "GAMEOVER", GetColor(255, 32, 32));
		}
	}
	
	//フェードの描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,m_fadeAlpha);        //半透明で表示開始
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeigth, GetColor(255, 255, 255), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      //不透明にしておく
}

void SceneMain::End()
{
	//BGMを止める
	StopSoundMem(m_bgmHndle);

	//BGMをメモリから削除
	DeleteSoundMem(m_bgmHndle);

	DeleteGraph(m_playerHandle);
	DeleteGraph(m_enemyHandle);
}


bool SceneMain::IsSceneEnd() const
{
	return m_isSceneEnd && (m_fadeAlpha >= 255);
}

//当たっている場合trueを返す(return true;する)
//当たっていない場合falseを返す(return false;する)
bool SceneMain::IsCollison(const Player& player, const Enemy& enemy)
{
	if (!enemy.isExist())	return false;
	bool isCollison = true;   //当たったフラグ

	//プレイヤーよりも完全に左側にいる場合は当たっていない
	//プレイヤー左端よりも左に敵に右端がある場合は当たっていない
	if (player.GetLeft() > enemy.GetRight())
	{
		return false;  //確実に当たっていないのでfalseを返す
	}

	if (player.GetBottom() < enemy.GetTop())
	{
		return false;
	}

	if (player.GetRight() < enemy.GetLeft())
	{
		return false;
	}

	if (player.GetTop() > enemy.GetBottom())
	{
		return false;
	}
	return true;
}
