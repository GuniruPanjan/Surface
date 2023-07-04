#include "DxLib.h"

//定数
namespace
{
	//初期位置
	constexpr int kStartPosX = 200;
	constexpr int kStartPosY = 120;
	//移動速度
	constexpr int kSpeed = 2;
}

class Player
{
public:
	//グラフィックのロード
	int m_handle;    //グラフィックハンドル
	int m_posX;      //表示座標X
	int m_posY;      //表示座標Y

	//グラフィック反転フラグ
	bool m_IsTurn;   //左右反転フラグ

	//メンバ関数
	void init();     //初期化用の関数
	void update();   //毎フレームの更新
	void draw();     //描画

	//コンストラクタ　メモリを確保した時点で勝手に呼ばれる関数
	Player();          //引数無しコンストラクタ
	Player(int x, int y);  //引数で初期位置を設定できるコンストラクタ

	//デストラクタ　メモリを開放した時点で勝ってに呼ばれる関数
	~Player();
};


//Playerクラスのコンストラクタ
Player::Player()
{
	//グラフィックのロード
	m_handle = LoadGraph("data/huruhurubebi-.png");
	m_posX = 200;
	m_posY = 120;
	//グラフィック反転フラグ
	m_IsTurn = false;

}

Player::Player(int x, int y)
{
	//グラフィックのロード
	m_handle = LoadGraph("data/huruhurubebi-.png");
	m_posX = 200;
	m_posY = 120;
	//グラフィック反転フラグ
	m_IsTurn = false;
}

//Playerクラスのデストラクタ
Player::~Player()
{
	//メモリが開放されるときに必ず呼んでほしい処理を書く
	DeleteGraph(m_handle);
}

//initのメンバ関数の実装
void Player::init()
{
/*
	handle = LoadGraph("data/huruhurubebi-.png");
	posX = 200;
	posY = 120;
	IsTurn = false;
	*/
}

//updateのメンバ関数の実装
void Player::update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_UP)
	{
		//上キーが押されている
		m_posY -= kSpeed;  //上方向に移動する
	}
	if (pad & PAD_INPUT_DOWN)
	{
		//下キーが押されている
		m_posY += kSpeed;  //下方向に移動する
	}
	if (pad & PAD_INPUT_LEFT)
	{
		//左キーが押されている
		m_posX -= kSpeed;  //左方向に移動する
		m_IsTurn = false;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		//右キーが押されている
		m_posX += kSpeed;  //右方向に移動する
		m_IsTurn = true;
	}
}
//メンバ関数の実装
//関数名の前にクラス名::を書いてやってこのクラスのdarw関数です、と宣言する
void Player::draw()
{
	if (m_IsTurn)
	{
		DrawTurnGraph(m_posX, m_posY, m_handle, false);
	}
	else
	{
		DrawGraph(m_posX, m_posY, m_handle, false);
	}
}

/*
//プレイヤーの初期化
void initPlayer(Player& player)
{
	player.handle = LoadGraph("data/huruhurubebi-.png");
	player.posX = 200;
	player.posY = 120;

	player.IsTurn = false;
}
*/

/*
//プレイヤーの更新
void updatePlayer(Player& player)
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_UP)
	{
		//上キーが押されている
		player.posY -= kSpeed;  //上方向に移動する
	}
	if (pad & PAD_INPUT_DOWN)
	{
		//下キーが押されている
		player.posY += kSpeed;  //下方向に移動する
	}
	if (pad & PAD_INPUT_LEFT)
	{
		//左キーが押されている
		player.posX -= kSpeed;  //左方向に移動する
		player.IsTurn = false;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		//右キーが押されている
		player.posX += kSpeed;  //右方向に移動する
		player.IsTurn = true;
	}
}
*/
/*
//プレイヤーの描画
void drawPlayer(Player player)
{
	if (player.IsTurn)
	{
		DrawTurnGraph(player.posX, player.posY, player.handle, false);    //左右反転を表示
	}
	else
	{
		DrawGraph(player.posX, player.posY, player.handle, false);
	}
}
*/

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//プレイヤー
	Player player;
	//Player player_B(80, 120);    ちょっと古い
	Player player_B{ 80, 120 };
	
	//プレイヤーの初期化
	player.init();
	player_B.init();

	
	//ゲームループ
	while (ProcessMessage() != 1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();


		//描画を行う前に画面をクリアする

		ClearDrawScreen();

		//ゲームの処理

		player.update();
		player_B.update();
		
		//プレイヤーの描画
	//	drawPlayer(player);
		player.draw();
		player_B.draw();


		//画像を表記させる   DrawGraph
		//表記される画像を反転させる　　DrawTurnGraph
		

		//画面が切り替わるのを待つ
		ScreenFlip();

		//escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66ミリ秒経過するまで待つ

		}
	}

	//グラフィックをメモリから削除
	DeleteGraph(player.m_handle);

	DxLib_End();            //DXライブラリ使用


	return 0;				// ソフトの終了 
}