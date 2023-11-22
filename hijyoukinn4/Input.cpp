#include "Input.h"
#include<Dxlib.h>
#include<string>
#include<algorithm>

using namespace std;

const InputTable_t Input::GetCommandTable() const
{
	InputTable_t ret = commandTable_;
	for (const auto& ex : exclusiveKeyConfigCommands)
	{
		ret.erase(ex);
		//eraseとはそのキーに合致したものが消える
	}
	return ret;

	//const auto& ex = exclusiveKeyConfigCommands;
	// TODO: return ステートメントをここに挿入します
	/*std::remove_if(ret.begin(), ret.end(),
		[ex](const std::pair<const std::string,std::map<InputType,int>>& cmd) {
			for (const auto& str : ex) {
				if (str == cmd.first)
				{
					return true;
				}
			}
	        return false;
		});*/
}

Input::Input()
{
	commandTable_["OK"] = { {InputType::keybd, KEY_INPUT_RETURN},{InputType::pad,PAD_INPUT_A} };
	commandTable_["pause"] = { {InputType::keybd, KEY_INPUT_R}, {InputType::pad,PAD_INPUT_R } };
	commandTable_["keyconf"] = { {InputType::keybd, KEY_INPUT_K}, {InputType::pad,PAD_INPUT_L } };
	commandTable_["cancel"] = { {InputType::keybd, KEY_INPUT_ESCAPE},{InputType::pad,PAD_INPUT_B} };


	commandTable_["jump"] = { {InputType::keybd, KEY_INPUT_Z}, {InputType::pad,PAD_INPUT_C } };
	commandTable_["attack"] = { {InputType::keybd, KEY_INPUT_X}, {InputType::pad,PAD_INPUT_X } }; 

	

	commandTable_["up"] = { {InputType::keybd,KEY_INPUT_UP},{InputType::pad,PAD_INPUT_UP } };
	commandTable_["down"] = { {InputType::keybd,KEY_INPUT_DOWN},{InputType::pad,PAD_INPUT_DOWN } };
	commandTable_["left"] = { {InputType::keybd,KEY_INPUT_LEFT},{InputType::pad,PAD_INPUT_LEFT } };
	commandTable_["right"] = { {InputType::keybd,KEY_INPUT_RIGHT},{InputType::pad,PAD_INPUT_RIGHT } };


	exclusiveKeyConfigCommands = { "up","down" ,"left", "right" };

}

void Input::Update()
{
	lastinputDate_ = inputDate_; //直前入力をコピーしておく
	char keystate[256];
	//lastkeyState_ = keyState_;//前のフレームの情報を代入
	GetHitKeyStateAll(keystate);//現在の入力を取得
	int padstate = GetJoypadInputState(DX_INPUT_PAD1);

	//登録された情報とハードの情報を照らし合わせながら、
	//inputData_の内容を更新していく

	for (const auto& cmd : commandTable_)
	{
		auto& input = inputDate_[cmd.first];  //コマンドの名前から入力データを作る
		for (const auto& hardIO : cmd.second)
		{
			//キーボードのチェック
			input = false;
			if (hardIO.first == InputType::keybd)
			{
				if (keystate[hardIO.second])
				{
					input = true;
					break;
				}
		
			}
			else if (hardIO.first == InputType::pad)
			{
				if (padstate & hardIO.second)
				{
					input = true;
					break;
				}
				
			}
		}
	}
}

bool Input::IsTriggered(const char* command) const
{
	//inputDate_[command];
	auto it = inputDate_.find(command);
	if (it == inputDate_.end()) //要素がなかった
	{
		return false;
	}
	return (inputDate_.at(command) && !lastinputDate_.at(command));

	//return !lastkeyState_[KEY_INPUT_RETURN] && keyState_[KEY_INPUT_RETURN];
}

bool Input::IsPressing(const char* command) const
{
	auto it = inputDate_.find(command);
	if (it == inputDate_.end()) //要素がなかった
	{
		return false;
	}
	return inputDate_.at(command);
}

bool Input::IsReleased(const char* command) const
{
	return false;
}

void Input::Save(const std::string& path)
{
	FILE* fp;
	fopen_s(&fp, path.c_str(), "wp");//書き込み用で開く
	//ヘッダの書き込み
}
