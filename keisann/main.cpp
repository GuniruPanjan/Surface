#include <iostream>

 
//��P��
void calcHpBar()
{
	constexpr int kMaxHp = 330;
	constexpr int kBarLen = 200;

	//HP�U�O�̎���HP�o�[�̒��������߂�
	int nowLen = 0;

	//HP����0.182 * int200 = int 36;
	//HP�������c���Ă��邩���v�Z����
	float rate = 60.0f / static_cast<float>(kMaxHp);
	std::cout << "�c��HP�̊���" << rate << std::endl;
	int barLen = kBarLen * rate;
	std::cout << "�o�[�̒���" << barLen << std::endl;

}
//��Q��
void calcFade()
{
	constexpr int kFadeInAlpha = 0;
	constexpr int kFadeOutAlpha = 255;
	constexpr int kFadeFrame = 60;

	//�t�F�[�h�C��������@�P�W�t���[���ʉ߂����Ƃ���a�����߂�
	int alpha = 0;

	//�t�F�[�h�����̐i�s�x�������ɕϊ�
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