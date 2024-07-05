#include "Font.h"
#include "DxLib.h"

Font::Font()
{
}

Font::~Font()
{
}

void Font::FontInit()
{

	LPCSTR font_path = "アプリ明朝.otf"; //読み込むフォントファイルパス

	if (AddFontResource(font_path) > 0)
	{
		PostMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	}
	else
	{
		//フォント読み込みエラー処理
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
	}


}
