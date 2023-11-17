#include "SceneMain.h"
#include "DxLib.h"
#include "Player.h"
#include "Bg.h"
#include "Pad.h"
#include "Rect.h"

//登場する敵
//#include "EnemyBase.h"
#include "EnemyLeft.h"
#include "EnemyRight.h"
#include "EnemyToPlayer.h"

//登場するショット
#include "ShotMagicWand.h"

#include <cassert>

namespace
{
	//一度に登場できる敵の最大数
	constexpr int kEnemyMax = 64;
	//何フレームおきに敵が登場するか
	constexpr int kEnemyInterval = 20;

	//画面内に一度に出てくる弾の最大数
	constexpr int kShotMax = 20;
}

SceneMain::SceneMain()
	//m_enemyFrameCount(0)
{
	//グラフィックのロード
	m_playerHandle = LoadGraph("data/player.png");
	assert(m_playerHandle != -1);
	m_enemyHandle = LoadGraph("data/gamechara.png");
	assert(m_enemyHandle != -1);
	m_bgHandle = LoadGraph("data/bg.png");
	assert(m_bgHandle != -1);
	//プレイヤーのメモリ確保
	m_pPlayer = new Player(this);
	m_pPlayer->SetHandle(m_playerHandle);   //Playerにグラフィックのハンドルを渡す

	//敵のメモリ確保
	/*for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemyRight[i] = new EnemyRight;
		m_pEnemyRight[i]->SetHandle(m_enemyHandle);

		m_pEnemyToPlayer[i] = new EnemyToPlayer;
		m_pEnemyToPlayer[i]->SetHandle(m_enemyHandle);
		m_pEnemyToPlayer[i]->SetPlayer(m_pPlayer);
	}
	m_pEnemyLeft = new EnemyLeft;
	m_pEnemyLeft->SetHandle(m_enemyHandle);*/

	//背景のメモリ確保
	m_pBg = new Bg;
	m_pBg->SetHandle(m_bgHandle);

	//敵の準備
	//m_pEnemy(vector)何もしなければサイズは0

	//resize関数でkEnemyMaxだけデータを保存できるようにする
	m_pEnemy.resize(kEnemyMax);

	//いつもはコンストラクタでメモリを確保して
	//デストラクタで解放してください
	//ランダムにEnemyLeft,EnemyRight,EnemyToPlayerを確保したい
	//どれか分からないのであらかじめ確保することができない！
	//->動的にメモリを確保する Update()中に必要に応じて

	//初期状態ではメモリを確保していない事が分かるようにしておく
	//未使用状態にする nullptrを入れておく
	// size()で現在使用可能な要素数を取得可能
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		m_pEnemy[i] = nullptr;

		//m_pEnemyの中には何が入るか分からない
		//↓のいずれかが入る
		// 現時点ではどれが入るのか決定できない
		// new EnemyLeft;
		// new EnemyRight;
		// new EnemyToPlayer;

	}
	//ショットの準備
	m_pShot.resize(kShotMax);
	for (int i = 0; i < m_pShot.size(); i++)
	{
		m_pShot[i] = nullptr;  //未使用
	}

	//m_pEnemy[0] ~ m_pEnemy[63]
	//m_pShot = new ShotMagicWand;
	//SceneMainの関数を使いたいのでポインタを渡しておく
	//thisで自身のポインタを取得可能
	//m_pShot->SetMain(this);
}

SceneMain::~SceneMain()
{
	//メモリからグラフィックを削除
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_enemyHandle);
	DeleteGraph(m_bgHandle);
	//メモリの解放
	delete m_pPlayer;
	m_pPlayer = nullptr;

	delete m_pBg;
	m_pBg = nullptr;

	/*for (int i = 0; i < kEnemyNum; i++)
	{
		delete m_pEnemyRight[i];
		m_pEnemyRight[i] = nullptr;

		delete m_pEnemyToPlayer[i];
		m_pEnemyToPlayer[i] = nullptr;
	}
	delete m_pEnemyLeft;
	m_pEnemyLeft = nullptr;*/

	//メモリが確保されている敵を探して解放していく
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		//nullptr以外の物が入っているということはそこにポインタが入っている
		if (m_pEnemy[i] == nullptr)
		{
			delete m_pEnemy[i];
			m_pEnemy[i] = nullptr;  //未使用状態と分かるようにしておく

		}
	}

	m_pShot.resize(kShotMax);
	for (int i = 0; i < m_pShot.size(); i++)
	{
		if (m_pShot[i])
		{
			//nullptrではない場合
			delete m_pShot[i];
			m_pShot[i] = nullptr;
		}
	}

	//delete m_pShot;
	//m_pShot = nullptr;
}

void SceneMain::Init()
{
	assert(m_pPlayer);   // m_pPlayer == nullptrの場合止まる

	m_pPlayer->Init();
	/*for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemyRight[i]->Init();
		m_pEnemyToPlayer[i]->Init();
	}
	m_pEnemyLeft->Init();

	m_enemyFrameCount = 0;*/

	m_pBg->Init();
}

void SceneMain::End()
{
	
}

void SceneMain::Update()
{
	
	m_pPlayer->Update();
	/*for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemyRight[i]->Update();
		m_pEnemyToPlayer[i]->Update();
	}
	m_pEnemyLeft->Update();*/

	m_pBg->Update();

	Rect playerRect = m_pPlayer->GetColRect();

	//敵キャラクターを登場制御
//	m_enemyFrameCount++;
//	if (m_enemyFrameCount >= 60)
//	{
//		m_enemyFrameCount = 0;
//
//		for (int i = 0; i < kEnemyNum; i++)
//		{
//#if false
//			if (!m_pEnemyRight[i]->isExist())
//			{
//				m_pEnemyRight[i]->Start();
//				break;
//			}
//#else
//			if (!m_pEnemyToPlayer[i]->isExist())
//			{
//				m_pEnemyToPlayer[i]->Start();
//				break;
//			}
//#endif
//		}
//	}
//	//Test ボタンを押したとき登場する敵
//	if (Pad::isPadTrigger(PAD_INPUT_1))
//	{
//		m_pEnemyLeft->Start();
//	}
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (m_pEnemy[i])   //nullptrではないチェック
		{
			m_pEnemy[i]->Update();

			//使用済みの敵キャラクターを削除する必要がある
			if (!m_pEnemy[i]->isExist() )
			{
				//メモリを解放する
				delete m_pEnemy[i];
				m_pEnemy[i] = nullptr; //使っていないと分かれば解放
			}
			else
			{
				//存在している敵とプレイヤーのあたり判定
				Rect enemyRect = m_pEnemy[i]->GetColRect();
				if (playerRect.IsCollision(enemyRect))
				{
					//test
					//printfDx("当たっている\n");
					m_pPlayer->OnDamage();
				}
			}
		}
	}

	for (int i = 0; i < m_pShot.size(); i++)
	{
		//nullptrなら処理は行わない
		if (!m_pShot[i]) continue;

		m_pShot[i]->Update();
		//画面外に出たらメモリ解放
		if (!m_pShot[i]->isExist())
		{
			delete m_pShot[i];
			m_pShot[i] = nullptr;
		}
	}
	

	//敵キャラクターを登場させる
	//kEnemyIntervalフレーム経過するごとにランダムに敵を登場させる

	m_enemyInterval++;
	if (m_enemyInterval >= kEnemyInterval)
	{
		m_enemyInterval = 0;

		//ランダムに敵を選択
		switch (GetRand(2))
		{
		case 0:     //Left

			CreateEnemyLeft();

			break;
		case 1:     //Right

			CreateEnemyRight();

			break;
		default:
			//想定しない数字が　　ここにきたらバグ
			assert(false);
			break;
		case 2:     //ToPlayer

			CreateEnemyToPlayer();

			break;

			
		}
	}

	if (Pad::isPadTrigger(PAD_INPUT_1))
	{
		//m_pShot->Start(m_pPlayer->GetPos());
		for (int i = 0; i < m_pShot.size(); i++)
		{
			//使用中なら次のチェックへ
			if (m_pShot[i]) continue;

			//ここにきたということはm_pShot[i] == nullptr
			m_pShot[i] = new ShotMagicWand;

			m_pShot[i]->Init();
			m_pShot[i]->SetMain(this);
			m_pShot[i]->Start(m_pPlayer->GetPos());

			//1発のみせいせい
			break;
		}
	}

}

void SceneMain::Draw() const
{
	m_pBg->Draw();

	m_pPlayer->Draw();

	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (m_pEnemy[i])   //nullptrではないチェック
		{
			m_pEnemy[i]->Draw();
		}
	}
	for (int i = 0; i < m_pShot.size(); i++)
	{
		if (!m_pShot[i])  continue;
		m_pShot[i]->Draw();
	}
	/*for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemyRight[i]->Draw();
		m_pEnemyToPlayer[i]->Draw();
	}
	m_pEnemyLeft->Draw();*/

	//デバッグ表示
	DrawString(8, 8, "SceneMain", GetColor(255, 255, 255));

	//プレイヤーの座標をデバッグ表示する
	Vec2 playerPos = m_pPlayer->GetPos();
	DrawFormatString(8, 24, GetColor(255, 255, 255),
		"プレイヤーの座標(%.2f,%.2f)", playerPos.x, playerPos.y);

	//m_pShot->Draw();
}

Vec2 SceneMain::GetNearEnemyPos(Vec2 pos) const
{
	//敵がいない場合は適当な座標を返す
	Vec2 result{ 0,0 };
	//最初の敵チェック済みフラグ
	bool isFirst = true;

	//一番近い敵キャラクターの座標をrezultに入れる
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		//使われていない敵はチェックしない
		if (!m_pEnemy[i]) continue;

		//ここにきている時点でm_pEnem[i]はnullptr出ないことは確定

		//すでに消えることが確定している敵はチェックしない
		if (!m_pEnemy[i]->isExist()) continue;

		//posとm_pEnemy[i]の距離をチェックする

		if (!isFirst)
		{
			//1体目の敵
			//距離がいくら離れていようと現時点では一番近い敵
			result = m_pEnemy[i]->GetPos();
			isFirst = false;
		}
		else
		{
			//2体目の以降の敵
			//resultの中には一番近い敵の座標が入っている

			//今までチェックした中で一番近い敵との距離
			Vec2 toNear = result - pos; //posから暫定1位の座標に向かうベクトル
			//float minDist;

			//チェックする敵との距離
			Vec2 toEnemy = m_pEnemy[i]->GetPos() - pos; //posからチェック中の敵に向かうベクトル

			//処理を軽くするため距離の比較を行う場合は２乗で行う
			if (toNear.sqLength() > toEnemy.sqLength())
			{
				//今チェックしている敵への距離が暫定１位よりも短い場合
				//今チェックしている敵を暫定１位に
				result = m_pEnemy[i]->GetPos();
			}
			//暫定１位の方が今チェックしている敵より近い場合は何もしない

			//一番近い敵なら情報を更新

			//一番近い敵よりも遠い場合は何もしない

		}
	}
	//すべての敵のチェックを行ったのでこいつが１位で確定
	return result;
}

bool SceneMain::AddShot(ShotBase* pShot)
{
	for (int i = 0; i < m_pShot.size(); i++)
	{
		//使用中なら次のチェックへ
		if (m_pShot[i]) continue;

		//ここに来たということはm_pShot[i] == nullptr
		m_pShot[i] = pShot;
		//登録したら終了
		return false;
	}

	//ここに来た、ということはm_pShotにポインタを登録出来なかった
	delete pShot;
	return false;
}

void SceneMain::CreateEnemyLeft()
{
	//使われていない箱を探してそこにアドレスを保存する
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i]) //nullptrであることをチェックする
		{
			m_pEnemy[i] = new EnemyLeft;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);
			m_pEnemy[i]->Start();
			return;  //メモリ確保できたらその時点で終了
		}
	}
}

void SceneMain::CreateEnemyRight()
{
	//使われていない箱を探してそこにアドレスを保存する
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i]) //nullptrであることをチェックする
		{
			m_pEnemy[i] = new EnemyRight;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);
			m_pEnemy[i]->Start();
			return;  //メモリ確保できたらその時点で終了
		}
	}
}

void SceneMain::CreateEnemyToPlayer()
{
	//使われていない箱を探してそこにアドレスを保存する
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i]) //nullptrであることをチェックする
		{
			//Baseが持たない独自の関数を呼びたい
			EnemyToPlayer* pEnemy = new EnemyToPlayer;

			pEnemy->Init();
			pEnemy->SetHandle(m_enemyHandle);
			pEnemy->SetPlayer(m_pPlayer);  //pPlayerはEnemyToPlaeyrなので呼べる
			pEnemy->Start();

			//pEnemyはすぐ消えるのでm_pEnemyに確保したアドレスをコピーしておく
			m_pEnemy[i] = pEnemy;

			/*m_pEnemy[i] = new EnemyToPlayer;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);*/

			//Playerを設定する必要がある
			/*m_pEnemy[i]->SetHandle(m_pPlayer);

			m_pEnemy[i]->Start();*/

			return;  //一体分メモリ確保できたらその時点で終了
		}
	}
}
