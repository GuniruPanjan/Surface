#include "Circle.h"
#include "DxLib.h"
#include <cmath>   //数学関数を使いたい

namespace
{
	//円の初期半径
	constexpr int kRadiuDefault = 64;
	//最小サイズ
	constexpr int kRadiusMin = 12;
}



//コンストラクタ　メンバ変数の初期化を行う
//コンストラクタでメンバ変数を初期化するときは
//コンストラクタ初期化子を使用する
Circle::Circle():
	m_posX(0),
	m_posY(0),
	m_radius(64),
	m_isLastMouseDown(false),
	m_isMouseIn(false),
	m_isExist(true)
{

	//rand()の時と使い勝手が違うので気を付ける
	//int num = rand() % 64;  //0~63
	//int num2 = GetRand(64);  //0~64
}

Circle::~Circle()
{

}

void Circle::init()
{
	m_posX = (GetRand(640 - m_radius * 2) + m_radius);
	m_posY = (GetRand(480 - m_radius * 2) + m_radius);
	m_isExist = true;
}

void Circle::update()
{
		

	//マウスがクリックされている状態を取得
	bool isClick = false;
	if ((GetMouseInput() & MOUSE_INPUT_LEFT))
	{

	}
	//円が存在しない場合は処理せず終了
	if (!m_isExist)
	{
		m_isLastMouseDown = isClick;
		return;
	}

	//マウスカーソルの位置取得
	int mouseX;
	int mouseY;
	GetMousePoint(&mouseX,&mouseY);

	//(float)num     :C言語風キャスト　　C++では使わない
	//static_cast<float>(num)   :C++のキャスト　static_以外使わない
	float dx =  static_cast<float>(mouseX - m_posX);
	float dy = static_cast<float>(mouseY - m_posY);

	if (sqrtf(dx * dx + dy * dy) < m_radius)
	{
		//マウスカーソルが円の中にある
		m_isMouseIn = true;
	}
	else
	{
		m_isMouseIn = false;
	}

	//クリックした判定
	if (isClick && !m_isLastMouseDown)
	{
		if (m_isMouseIn)   //カーソルが円の中にある状態でクリックした
		{
			//円を消す
			m_isExist = false;
		}
	}
	//このフレームのマウスの状態を覚えておく
	m_isLastMouseDown = isClick;

}

void Circle::draw()
{
	
	unsigned int color = GetColor(255,255,255);
	if (m_isMouseIn)
	{
		color = GetColor(255, 0, 0);

	}
	DrawCircle(m_posX, m_posY, m_radius, color, true);

	//座標を文字で表示する
	DrawFormatString(0, 0, GetColor(255, 255, 255), "pos(%d,%d)", m_posX, m_posY);

	
}

void Circle::smaller(int size)
{
	m_radius -= size;
	//サイズの下限を設定する
	if (m_radius < kRadiusMin)
	{
		m_radius = kRadiusMin;
	}
}
