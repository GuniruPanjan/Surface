#pragma once
#include<array>
#include<string>
#include<map>
#include<unordered_map>

enum class InputType
{
	keybd, //キーボード
	pad//パッド
};

using InputTable_t = std::map<std::string, std::map<InputType, int>>;

class KeyConfigScene;
//固定配列もなるべくSTLを使う
//char keystate[256];
//これもSTLを使うと
//std::array<char,256>
class Input
{
	friend KeyConfigScene; //キーコンフィグからは丸見え
private:

	InputTable_t commandTable_;

	std::vector<std::string> exclusiveKeyConfigCommands;

	std::array<char, 256 >keyState_;
	std::array<char, 256 >lastkeyState_;

	/*std::map<std::string, std::map<InputType, int>> commandTable_;

	std::vector<std::string> exclusiveKeyConfigCommands;*/

	//コマンドの入力を覚えておく
	std::map<std::string, bool> inputDate_; //現在の入力
	std::map<std::string, bool> lastinputDate_; //直前の入力

	const InputTable_t GetCommandTable() const;

public:
	Input();
	/// <summary>
	/// 入力情報を更新する
	/// </summary>
	void Update();
	/// <summary>
	/// 指定のコマンドが押された瞬間なのか
	/// </summary>
	/// <param name="command">コマンド文字列</param>
	/// <returns>true:押された瞬間 , false押されてないか押しっぱ</returns>
	bool IsTriggered(const char* command)const;
};

