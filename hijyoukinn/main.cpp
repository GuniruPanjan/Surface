#include<Dxlib.h>
#include<cassert>

//�f�o�b�O�͂܂��̓u���[�N�|�C���g�̎g�������o����
//�u���[�N�|�C���g�Œ��f����ƃ��[�J���ϐ����\������Ă邩�炨�����Ȓl����������
//�o�͂�����Ɖ��������s�����DxLib�����O��f���Ă����
//���f�����Ƃ��납��F10��1�s1�s���s���Ă���
//������Release���[�h�ł͗L���ł͂���܂���
//��́A�f�o�b�O��񂪂Ȃ����ߊ֐�����������Ȃ����l��������Ȃ�
//��ڂ́A�v���O���������ԂɎ��s����Ȃ�
//F11�Ŋ֐��̒��ɓ����Ă����i����̊֐�:���C�u�����̒��ɂ͓���Ȃ��j
//�f�o�b�O�J�[�\���̓h���b�O���Ĉړ��ł���
//�u���[�N���ɕϐ��Ƀ}�E�X�|�C���^�����킹��ƒ��g������邵�N���b�N�Œl�̕ύX���\
//�u���[�N�|�C���g�ŉE�N���b�N���āA������ǉ����邱�Ƃ��ł�������𖞂������Ƃ��ɂ̂݁A�����𒆒f����
//�f�[�^�u���[�N�|�C���g�Ƃ������̂����遨����̃������̓��e�������ς�������f
//��x���s���n�߂Ă��炶��Ȃ��ƃ������̔Ԓn���m�肵�Ȃ����ߎ��s���łȂ��Ɛݒu�ł��Ȃ�
//�v���O�����̂ǂ��œ��e�����������Ă�̂���������Ȃ����A�������Ă��邱�Ƃ����邻�������ꍇ�ɂ́A�f�[�^�u���C�N�|�C���g���L���ł�
//�Ăяo�����������p���悤�u���[�N�����Ƃ����

//Debug:�f�o�b�O���₷������ɒx���i�]�v�ȏ�񂪊܂܂�Ă���j
//Release:��������Ƀf�o�b�O���Â炢
//��Ƃ�GFF�ɒ�o����A�v����Release�Œ�o���܂��傤
//Debug��Release�͕ʁX�̐ݒ�ȂǂŒ��ӂ��悤
void Sub(int& left, const int& right)
{
	left = right;
}
void Function()
{
	int j = 0;
	for (int i = 0; i < 10000; i++)
	{
		j = i;
	}
}
//Warning�������Ă��v���O�����͓������A�ł��邾�����炻��
//main��WinMain���֐��Ȃ̂ŁA�߂�l���K�v�ł�
//0:����I��
//-1:�ُ�I��

//�Ώ��̂��Â炳�����L���O
//1.���s�͂ł��邵�A�N���b�V�����Ȃ��A�ł����삪��������
//2.������x���s���ē��삷�邯�ǁA���鎞�N���b�V������
//3.�����J�G���[
//4.�R���p�C���G���[
//�u�Ԉ���Ă���Ƃ��́A�l�דI�ɂł��ꍏ�������N���b�V�������悤�I�v
//Debug�̎��́A�ϋɓI�ɃN���b�V��������
//Release�̎��́A�N���b�V�������Ȃ���

//assert�֐�
//assert(������);
//���̏����̒��g���^�itrue�j�̎��ȊO�܂�U�ifalse�j�̎��ɐl�דI�ɃN���b�V���𔭐������܂�
//�o�O�ł͂Ȃ����u���炩�ɊԈ���Ă���󋵁v�ɑ΂��āA�N���b�V�����N�������߂Ɏg���܂�

int MyLoadGraph(const wchar_t* path)
{
	int handle = LoadGraph(path);
	assert(handle > 0);
	return handle;
}
//�R���\�[����Main�֐��@Windows��WinMain�֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{ 
	ChangeWindowMode(true);   //false�̓t���X�N���[���Atrue�͔�t���X�N���[��
	if (DxLib_Init() == -1)
	{
		//�������Ɏ��s������A�v���𗎂Ƃ�
		return -1;  //���̃A�v���ُ͈�I�����܂���
	}
	Function();

	//���͕\�������`���ɂ�2���̃X�N���[��������܂�
	//����������Ńt���b�v�i����ւ��j���s�����Ƃ�
	//��ʂ̂�������Ȃ����Ă��܂�
	//SetDrawScreen���̊֐���DxLib_Init()�ザ��Ȃ���
	//�L���ł͂Ȃ����ߒ��ӂ��Ă�������

	int a[] = {1,3,4,8,2,5,3,6,2 };

	auto result = SetDrawScreen(DX_SCREEN_BACK);

	a[5]++;

	Function();

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();
		ScreenFlip();
	}
	DxLib_End();
	return 0;  //���̃A�v���͐���I�����܂���
}