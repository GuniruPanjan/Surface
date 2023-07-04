#pragma once

class Circle
{
public:
	Circle(); //コンストラクタ　メモリが確保された時に自動的に呼ばれる関数
	~Circle();  //デストラクタ　メモリが解放された時に自動的に呼ばれる関数

	void init();    //初期化
	void update();    //毎フレーム実行される処理
	void draw();    //描画

	//メンバ変数の値を取得したい場合はpublic関数経由で行う
	bool isExist() { return m_isExist; }


	//円のサイズを小さくする
	void smaller(int size);

	//set,get関数は定番
	int getPosX() { return m_posX; }

	//メンバ変数は必ずprivateにする
private:
	//表示位置
	int m_posX;
	int m_posY;

	//半径
	int m_radius;

	//前のフレームに左クリックが押されている状態か
	bool m_isLastMouseDown;

	//マウスカーソルが円の中にあるか
	bool m_isMouseIn;

	//この円が存在しているか
	bool m_isExist;

};