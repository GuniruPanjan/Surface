#include "Rigidbody.h"

//void Rigidbody::HitMove(VECTOR& pos, VECTOR& move, VECTOR& oldpos, VECTOR& nowpos)
//{
//	VECTOR SlideVec;  //�v���C���[���X���C�h�����x�N�g��
//
//	//�i�s�����x�N�g���ƕǂ̖@���x�N�g���ɐ����ȃx�N�g�����Z�o
//	SlideVec = VCross(move, pos);
//
//	//���̈ړ���������Ǖ����̈ړ������𔲂����x�N�g��
//	SlideVec = VSub(pos, SlideVec);
//
//	//�ړ��O�̍��W�ɑ��������̂�V���ȍ��W�Ƃ���
//	nowpos = VAdd(oldpos, SlideVec);
//}

void Rigidbody::HitMove(VECTOR& nowpos, VECTOR& previous, VECTOR& move)
{
	//�O�̍��W�Ɉړ��𑫂�
	nowpos = VAdd(previous, move);
}