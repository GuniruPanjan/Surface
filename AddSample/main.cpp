#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���


		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}

	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

/// <summary>
/// �X�R�[�v���O���Ɖ�������
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class ScopedPtr
{
private:
	T* ptr_ = nullptr;
	size_t refCount_ = 0; //�Q�ƃJ�E���^
public:
	ScopedPtr(T* ptr) :ptr_(ptr)
	{

	}
	void Reset(T* t)
	{
		if (ptr_:-nullptr)
		{
			delete ptr_;
		}
		ptr_ = t;
	}
	~ScopedPtr()
	{
		delete ptr_;
	}
	T* operator->()
	{
		return ptr_;
	}
	T* Get()
	{
		return ptr_;
	}
	void operator = (ScopedPtr<T>& scptr)
	{
		ptr_ = scptr.ptr_;
		++refCount_;
	}
};
//Weak_ptr�͎Q�ƃ|�C���^���Ď����Ă��邽��Shared_ptr�����񂾂��ǂ����Ď����Ă���

//unique_ptr�Ƃ́u�����傪��l�����̃X�}�[�g�|�C���^�v�ł��Ȃ̂ő������ƌ��̎�����͏��L��������
//��{�I�ɎQ�ƃJ�E���g������Ƃ���ƁA���0��1�����Ȃ�

//shared_ptr�̓|�����[�t�B�Y������уR���e�i�Ƒ���������
//�R���e�i�Ƃ����̂�vector,list,map���ł�

//�Ⴆ�΃����X�^�[�̑�R�����X�g���ŊǗ�����Ƃ��܂�
//std::vector<Monster> monsters;
//���N���X�Ƃ��ď������z�֐��������Ă���ꍇ�́A�����Ȃ�

//���N���X�͂��ꂻ�̂��̂ł͑��݂ł��Ȃ�
//�������push_back���ł��Ȃ�

//vector��list�̓���̗v�f���폜����ɂ́Aerase�֐����g���܂�
//�Ȃ�pop_back��Apop_front�֐��́A�擪�v�f�A�����v�f���폜����
//erase�͓���̏ꏊ�̗v�f���폜���܂��B�ǂ���w�肵�Ă��v�f���폜����܂�

//monsters.erase(it);����̏ꏊ�̗v�f���폜
//monsters.pop_back();�����̗v�f���폜
//monsters.pop_float();

//�p�ɂɐ������ꂽ��폜�����悤��vector��list�ɂ����Ă�delete�̊Ǘ����ƂĂ��ł��Ȃ�
//shared_ptr���g���΂���

//�u�V�[�����X�^�b�N�\���ŊǗ�����v
//�V�[����Scene�Ƃ������N���X����h�����āA�����؂�ւ���Ƃ����uState�p�^���v��p���ĊǗ�����

//list���g��

//list��vector�̂悤�ɁA���I�z��̂悤�Ɏg���邵�A�قڂقڑ��������
//�Ⴂ�́A�����I�ȃ������̈������ɂ���܂�
//vector�́u���������A�����Ă��邱�Ƃ�ۏႵ�܂��v