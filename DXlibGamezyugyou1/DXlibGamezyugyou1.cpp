#include "DxLib.h"

//なぜわざわざクラスのメンバをprivateにするの？
//すべてpublicなら便利では？

//const  値をいじれないようにする
//値をいじれたほうが便利　→間違えていじる事を防ぐためにconstでそもそもいじれないようにする

//・クラスの処理はクラス自身にやらせる
//・外から勝手に値をいじれないようにする
//例.敵を非表示にしたい　勝手に画面外の座標に移動させる、みたいなことが発生する　→敵は生きているはずなのに画面に表示されない？といったバグ

class Enemy
{
public:
	//コントラクタ、デストラクタは特殊な事をしない限りpublic
	Enemy();
	~Enemy();

	//クラス外から使いたい（今回はWinMainで使う）ものはpublic
	void init();
	void update();
	void draw();

	//クラス外からメンバ変数を変更したい場合はpublicなメンバ関数を通す
	void setPos(int x, int y);

	//簡単な中身ならヘッダに直接書くことも多い
	void setPosX(int x) { m_posX = x; }
	void setPos(int y) { m_posY = y; }



private:
	//メンバ変数はすべてprivate
	int m_handle;
	int m_posX;
	int m_posY;
};

Enemy::Enemy() :
	m_handle(LoadGraph("data/ゲームキャラ２.png")),
	m_posX(320),
	m_posY(240)
{

}
//デストラクタ
Enemy::~Enemy()
{
	DeleteGraph(m_handle);
}
void Enemy::init()
{

}
void Enemy::draw()
{
	DrawGraph(m_posX, m_posY, m_handle, false);
}
void Enemy::setPos(int x,int y)
{
	//画面外に出ていたら戻す処理
	if (x < 0)   x = 0;
	if (x > 640)  x = 640;
	if (y < 0) y = 0;
	if (y > 480) y = 480;
	m_posX = x;
	m_posY = y;
}


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

	Enemy enemy;
	enemy.init();

	//敵の位置を変更する
	int x = 120;
	int y = 120;
	//今回は直接入れているが実際には色々処理を下した結果画面外になった
	x = -120;
	y = -120;
	enemy.setPos(x , y);
	//ゲームループ
	while (ProcessMessage() != 1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();


		//描画を行う前に画面をクリアする

		ClearDrawScreen();

		//ゲームの処理

		enemy.draw();

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

	DxLib_End();            //DXライブラリ使用


	return 0;				// ソフトの終了 
}