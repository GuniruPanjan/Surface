#include "DxLib.h"

//クラスの宣言
class Enemy
{
//メンバ変数、メンバ関数にはprivate,publicという属性がある
//メンバ変数はすべてprivate:にしましょう！

	//public:もprivate:も書いてない場所にかいたメンバーはprivateメンバ
	int m_pri000;       //privateメンバ

	//private:よりも後に書いたメンバ（変数、関数）はprivateメンバ
private:
	int m_pri001;    //privateメンバ

	//public:よりも後に書いたメンバ（変数、関数）はpublicメンバ
public:
	int m_pub000;     //publicメンバ
	void pubFunc();   //publicメンバの関数
	//private:public:何度もかいてもよい
private:
	int m_pri002;
	void priFunc();
	//private
public:       //外部からのアクセス可能にする

	//メンバ変数名はそのプログラムを見た人が見ただけでこれはメンバ変数、
	//とわかるように名前を付けることが多い
	//私は変数名の前にm_を付けます           handle -> m_handle
	//ほかにも変数名の前に _ を付ける人や    handle -> _handle
	//変数名の最後に_を付ける人もいます      handle -> handle_
	//ルールはどれでもかまいませんが、必ず統一してください
	//チーム制作の場合はチームでどのようなルールにするか決めてください
	int m_handle;   //グラフィックハンドル
	int m_posX;     //X座標
	int m_posY;     //Y座標
	int m_moveX;    //X方向への移動量
	int m_moveY;    //Y方向への移動量

	//コンストラクタ
	//実体が作成されたとき（メモリが確保されたとき）自動的に呼ばれる関数
	//戻り値無し、クラス名と同じ関数名
	Enemy();
	//デストラクタ
	//メモリが解放されるとき自動的に呼ばれる関数
	//終了時に忘れずにやっておかないといけない
	//戻り値なし、引数も設定できない　関数名はクラス名の前に~を書く
	~Enemy();

	//クラスは構造体に加えてクラス内で関数を作成する事ができる
	//クラス内の関数をメンバ関数という

	void init();
	void update();
	void draw();
};

//Enemyクラスのコンストラクタ
Enemy::Enemy():m_posX(320),m_posY(240)


{
	//値を初期化したり、0クリアする
	//メンバ関数から同じクラス内のメンバ変数にアクセスできる
	//アクセスする際はenemy.handleのような書き方をしなくてもhandleのみでアクセスできる

	m_handle = LoadGraph("data/ゲームキャラ２.png");
	m_posX = 320;
	m_posY = 240;
	m_moveX = 0;
	m_moveY = 0;
}

//Enemyクラスのデストラクタ
Enemy::~Enemy()
{
	//終了時に忘れずにやっておかないといけない処理を書く
	DeleteGraph(m_handle);
}

//メンバ関数を実装したい時は関数名の前に クラス名::と書く
void Enemy::init()
{
	
}


void Enemy::draw()
{
	//クラス内からならprivateメンバ、publicメンバ共にアクセス可能
	m_pub000 = 10;
	pubFunc();

	m_pri000 = 100;
	priFunc();

	DrawGraph(m_posX, m_posY, m_handle, false);
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
	//メンバ関数の呼び出し
	//メンバ変数と同じく.(ドット)でつないでメンバ関数を呼び出す
	enemy.init();

	//publicメンバにはクラス外からアクセスできる
	//privateメンバにはクラス外からアクセスできない
	//クラス外？　そのクラスのメンバ関数内はクラス内、それ以外はクラス外
	//ここはEnemyのクラス外

	//public メンバにはアクセス可能　使用可能
	enemy.m_pub000 = 10;
	enemy.pubFunc();

	//privateメンバにはアクセス不可　使用不可

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