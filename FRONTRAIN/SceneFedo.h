#pragma once
#include "DxLib.h"

class SceneFedo
{
public:
	SceneFedo();
	~SceneFedo();

	void Init();
	void Update();
	void StartUpdate();
	void UpdateInSetting();
	void UpdateIn();
	void DeadOut();
	void WhiteOut();
	void Draw();

	int c = 0, White, a;

	int end;

	int Out = 0;

	//�X�^�[�g��ʂ̕ϐ�
	bool Start, Setting, Explanation;

	//1�񂾂����s���邽�߂̕ϐ�
	bool LetGo = false;

	//�X�^�[�g��ʗp�̉��o�n���h��
	int handle;

	//�������
	int WhiteHandle;

	int WhiteCount, WhiteTime;

	//�J�E���g
	int Count;

	//�s�����x
	int b;
};

