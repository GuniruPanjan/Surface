#pragma once
#include "DxLib.h"


class Camera
{
public:
	Camera();
	virtual ~Camera();

	void Init();
	void Update();
	void Draw();

private:
	VECTOR Position;      //ポジション
	VECTOR Target;        //ターゲット
	//Near(最小距離)、Far(最大距離)
	float Near, Far;

};

