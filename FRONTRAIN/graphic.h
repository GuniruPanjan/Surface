#pragma once

//ヘッダファイル読み込み
#include "DxLib.h"

#define GraFxInfinity    -99999 //無限継続

//エラー
#define ImageLoadErrCap   "が読み込みませんでした"
#define ImageLoadErrTitle  "画像読み込みエラー"

//文字列の長さ
#define ImagePathStrMax 256
#define ImageErrStrMax 512

//画像ファイルのパス
#define GraphicPathTitleButton

//列挙型
enum Graphic_Align
{
	GraAlignTopL,   //画像の基準点で上左揃え
	GraAlitnTopC,   //画像の基準点で上中央揃え
	GraAlignTopR,   //画像の基準点で上右揃え

	GraAlignBottomL,  //画像の基準点で下左揃え
	GraAlignBottomC,  //画像の基準点で下中央揃え
	GraAlignBottomR,  //画像の基準点で下右揃え

	GraAlignAllCenter,  //画像の基準点で上下も左右も中央揃え
};

//描画の効果
enum Graphic_Fx
{
	GraFxBlink,  //点滅
	GraFxFadeIn,  //透明〜不透明
	GraFxFadeOut,   //不透明→透明
	GraFxFadeInOut,   //不透明←→透明
	GraFxNone   //通常描画
};

//画像構造体のコア部分
typedef struct _GraphicCore
{
	char Path[ImagePathStrMax];   //パス

	POINT pos;    //画像の基準点(通常は左上)
	int Width = 0;   //幅
	int Height = 0;  //高さ

	RECT Coll;      //矩形の当たり判定
	RECT CollMargin;  //矩形の当たり判定を挟める

	Graphic_Align Align = GraAlignTopL; //揃え方向

	float Rate = 1.0f;      //拡大率
	float Angle = 0.0f;     //角度

	BOOL IsDraw = FALSE;    //描画するか?

	BOOL IsFxStartFlg = FALSE;  //描画エフェクトフラグ
	Graphic_Fx Fx = GraFxNone;   //描画エフェクトの種類
	int FxMillTime = 0;    //エフェクト時間カウント
	int FxMillTimeMax = 0;   //エフェクト時間カウントMAX
	int FxInterMillTime = 0;  //エフェクト時間カウント
	int FxInterMillTimeMax = 0;  //エフェクト時間カウントMAX
	float Alpha = 0.0f;   //透明度(0.0〜1.0を入れること)
}GraphicCore;

//画像構造体
typedef struct _Graphic
{
	GraphicCore c;     //コア
	int Handle = -1;   //ハンドル
}Graphic;

//外部グローバル変数
extern Graphic TitleButton;  //タイトルボタン

//外部プロトタイプ宣言
extern BOOL Graphic_Init(VOID);     //読み込み・ハンドル生成
extern VOID Graphic_End(VOID);     //後始末
extern VOID GraphicLoadErrMessage(const char* path);   //読み込みエラーメッセージ

extern Graphic LoadGraphic(const char* path, POINT point, RECT margin, Graphic_Align align);  //読み込み
extern VOID DrawGraphic(Graphic* graphic);       //描画
extern VOID DeleteGraphic(Graphic graphic);      //解放

extern VOID ReMakeCollRect(Graphic* graphic);    //当たり判定の矩形を再生成

extern VOID GraphicFxStart(Graphic* graphic, Graphic_Fx Fx, int MillTime, int MillInterval);   //エフェクト開始
