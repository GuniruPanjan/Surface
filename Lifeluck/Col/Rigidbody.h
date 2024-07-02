#pragma once
#include "DxLib.h"

class Rigidbody
{
public:
	//void HitMove(VECTOR& pos, VECTOR& move, VECTOR& oldpos, VECTOR& nowpos);
	void HitMove(VECTOR& nowpos, VECTOR& previous, VECTOR& move);
};

