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

	LPCSTR font_path = "�A�v������.otf"; //�ǂݍ��ރt�H���g�t�@�C���p�X

	if (AddFontResource(font_path) > 0)
	{
		PostMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	}
	else
	{
		//�t�H���g�ǂݍ��݃G���[����
		MessageBox(NULL, "�t�H���g�ǂݍ��ݎ��s", "", MB_OK);
	}


}
