#include <iostream>

 
//第１問
void calcHpBar()
{
	constexpr int kMaxHp = 330;
	constexpr int kBarLen = 200;

	//HP６０の時のHPバーの長さを求める
	int nowLen = 0;

	//HPが約0.182 * int200 = int 36;
	//HPが何％残っているかを計算する
	float rate = 60.0f / static_cast<float>(kMaxHp);
	std::cout << "残りHPの割合" << rate << std::endl;
	int barLen = kBarLen * rate;
	std::cout << "バーの長さ" << barLen << std::endl;

}
//第２問
void calcFade()
{
	constexpr int kFadeInAlpha = 0;
	constexpr int kFadeOutAlpha = 255;
	constexpr int kFadeFrame = 60;

	//フェードインさせる　１８フレーム通過したときのaを求める
	int alpha = 0;

	//フェード処理の進行度を割合に変換
	float progress = 18.0f / static_cast<float>(kFadeFrame);
	float alphaRate = 1.0 - progress;
	alpha = kFadeOutAlpha * alphaRate;

	std::cout << "Fade" << alpha << std::endl;
}

int main()
{
	calcHpBar();

	calcFade();
}