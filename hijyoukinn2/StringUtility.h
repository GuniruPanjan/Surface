#pragma once
#include<string>
class StringUtility
{
public:

	/// <summary>
	/// 当たったかどうかを返す
	/// </summary>
	/// <param name="a">引数１</param>
	/// <param name="b">引数２</param>
	/// <param name="c">引数３</param>
	/// <returns></returns>
	bool Dummy(int a, int b, int c);

	/// <summary>
	/// マルチバイト文字列からワイド文字列への変換
	/// </summary>
	/// <param name="str">変換元のマルチバイト文字列</param>
	/// <returns>変換後のワイド文字列</returns>
	static std::wstring
		StringToWString(const std::string& str);
};

