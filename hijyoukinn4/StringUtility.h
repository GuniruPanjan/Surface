#pragma once
#include<string>
class StringUtility
{
public:

	/// <summary>
	/// �����������ǂ�����Ԃ�
	/// </summary>
	/// <param name="a">�����P</param>
	/// <param name="b">�����Q</param>
	/// <param name="c">�����R</param>
	/// <returns></returns>
	bool Dummy(int a, int b, int c);

	/// <summary>
	/// �}���`�o�C�g�����񂩂烏�C�h������ւ̕ϊ�
	/// </summary>
	/// <param name="str">�ϊ����̃}���`�o�C�g������</param>
	/// <returns>�ϊ���̃��C�h������</returns>
	static std::wstring
		StringToWString(const std::string& str);
};

