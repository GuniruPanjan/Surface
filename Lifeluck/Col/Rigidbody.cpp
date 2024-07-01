#include "Rigidbody.h"

void Rigidbody::HitMove(VECTOR& pos, VECTOR& move, VECTOR& oldpos, VECTOR& nowpos)
{
	VECTOR SlideVec;  //�v���C���[���X���C�h�����x�N�g��

	//�i�s�����x�N�g���ƕǂ̖@���x�N�g���ɐ����ȃx�N�g�����Z�o
	SlideVec = VCross(move, pos);

	//���̈ړ���������Ǖ����̈ړ������𔲂����x�N�g��
	SlideVec = VSub(pos, SlideVec);

	//�ړ��O�̍��W�ɑ��������̂�V���ȍ��W�Ƃ���
	nowpos = VAdd(oldpos, SlideVec);

	nowpos = VGet(nowpos.x, 2.0f, nowpos.z);
}
