#pragma once

struct Size
{
	int w;
	int h;
};
/// <summary>
/// アプリケーション全体を管理するクラス
/// </summary>
class Application
{
private:
	Application();

	//コピー代入の禁止
	Application(const Application& app) = delete;
	void operator = (const Application& app) = delete;

	/// <summary>
	/// 後処理を行う
	/// </summary>
	void Terminate();
public:
	Size windowSize_;
	Application();
	//[インスタンス] : メモリを確保して作った実態(メモリを食いつぶしている)
	//static関数 : そのクラスの実態がなくても呼べる関数
	//ローカルstatic関数 : ふつうはローカル変数は関数を抜けるとともに
	//解放されますが、static変数は削除されません
	//アプリケーションが終わるまで存在し続ける

	//シングルトンクラスの作り方
	//コンストラクタをprivateに置くことで、オブジェクトを動的に生成できないようにする
	//Application app;//×
	//Application* app = new Aplication();//×
	//Application& app = Application::GetInastance();//Ok
	//Application app = aaapplication::GetInstance();//通るけどダメ
	//なぜダメなのか、これは別のアドレスにコピーができてる


	/// <summary>
	/// Applicationのシングルトンインスタンスの参照を返す
	/// </summary>
	/// <returns>Applicationインスタンス</returns>
	static Application& GetInstance()
	{
		static Application instance;
		return instance;
	}

	bool Init();
	void Run();
	const Size& GetWindowSize() const;

};

