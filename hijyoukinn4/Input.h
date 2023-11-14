#pragma once
#include<array>
#include<string>
#include<map>
#include<unordered_map>

enum class InputType
{
	keybd, //�L�[�{�[�h
	pad//�p�b�h
};

using InputTable_t = std::map<std::string, std::map<InputType, int>>;

class KeyConfigScene;
//�Œ�z����Ȃ�ׂ�STL���g��
//char keystate[256];
//�����STL���g����
//std::array<char,256>
class Input
{
	friend KeyConfigScene; //�L�[�R���t�B�O����͊ی���
private:

	InputTable_t commandTable_;

	std::vector<std::string> exclusiveKeyConfigCommands;

	std::array<char, 256 >keyState_;
	std::array<char, 256 >lastkeyState_;

	/*std::map<std::string, std::map<InputType, int>> commandTable_;

	std::vector<std::string> exclusiveKeyConfigCommands;*/

	//�R�}���h�̓��͂��o���Ă���
	std::map<std::string, bool> inputDate_; //���݂̓���
	std::map<std::string, bool> lastinputDate_; //���O�̓���

	const InputTable_t GetCommandTable() const;

public:
	Input();
	/// <summary>
	/// ���͏����X�V����
	/// </summary>
	void Update();
	/// <summary>
	/// �w��̃R�}���h�������ꂽ�u�ԂȂ̂�
	/// </summary>
	/// <param name="command">�R�}���h������</param>
	/// <returns>true:�����ꂽ�u�� , false������ĂȂ�����������</returns>
	bool IsTriggered(const char* command)const;
};

