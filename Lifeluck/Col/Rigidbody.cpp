#include "Rigidbody.h"

void Rigidbody::HitMove(VECTOR& pos, VECTOR& move, VECTOR& oldpos, VECTOR& nowpos)
{
	VECTOR SlideVec;  //プレイヤーをスライドされるベクトル

	//進行方向ベクトルと壁の法線ベクトルに垂直なベクトルを算出
	SlideVec = VCross(move, pos);

	//元の移動成分から壁方向の移動成分を抜いたベクトル
	SlideVec = VSub(pos, SlideVec);

	//移動前の座標に足したものを新たな座標とする
	nowpos = VAdd(oldpos, SlideVec);

	nowpos = VGet(nowpos.x, 2.0f, nowpos.z);
}
