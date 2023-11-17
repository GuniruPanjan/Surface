#include "DxLib.h"

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

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理


		// 画面が切り替わるのを待つ
		ScreenFlip();

		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}

	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

/// <summary>
/// スコープを外れると解放される
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class ScopedPtr
{
private:
	T* ptr_ = nullptr;
	size_t refCount_ = 0; //参照カウンタ
public:
	ScopedPtr(T* ptr) :ptr_(ptr)
	{

	}
	void Reset(T* t)
	{
		if (ptr_:-nullptr)
		{
			delete ptr_;
		}
		ptr_ = t;
	}
	~ScopedPtr()
	{
		delete ptr_;
	}
	T* operator->()
	{
		return ptr_;
	}
	T* Get()
	{
		return ptr_;
	}
	void operator = (ScopedPtr<T>& scptr)
	{
		ptr_ = scptr.ptr_;
		++refCount_;
	}
};
//Weak_ptrは参照ポインタを監視しているためShared_ptrが死んだかどうか監視している

//unique_ptrとは「持ち主が一人だけのスマートポインタ」ですなので代入すると元の持ち主は所有権を失う
//基本的に参照カウントがあるとすると、常に0か1しかない

//shared_ptrはポリモーフィズムおよびコンテナと相性がいい
//コンテナというのはvector,list,map等です

//例えばモンスターの大軍をリスト等で管理するとします
//std::vector<Monster> monsters;
//基底クラスとして純粋仮想関数を持っている場合は、書けない

//基底クラスはそれそのものでは存在できない
//もちろんpush_backもできない

//vectorやlistの特定の要素を削除するには、erase関数を使います
//なおpop_backや、pop_front関数は、先頭要素、末尾要素を削除する
//eraseは特定の場所の要素お削除します。どれを指定しても要素が削除されます

//monsters.erase(it);特定の場所の要素を削除
//monsters.pop_back();末尾の要素を削除
//monsters.pop_float();

//頻繁に生成されたり削除されるようなvectorやlistにおいてはdeleteの管理がとてもできない
//shared_ptrを使えばいい

//「シーンをスタック構造で管理する」
//シーンをSceneという基底クラスから派生して、それを切り替えるという「Stateパタン」を用いて管理する

//listを使う

//listはvectorのように、動的配列のように使えるし、ほぼほぼ操作も同じ
//違いは、内部的なメモリの扱い方にあります
//vectorは「メモリが連続していることを保障します」