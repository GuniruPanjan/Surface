#include "DxLib.h"
#include <cmath>

//�~�̃f�[�^
typedef struct CircleData
{
	float x;
	float y;
	float radius;
	unsigned int color;
}CircleData;

//�Q�ƌ^
//�v���C���[������֐���
void updatePlayer(CircleData player)
{
	//�Q�[���̏���
	int mouseX;
	int mouseY;

	//�}�E�X�̈ʒu���擾����
	GetMousePoint(&mouseX, &mouseY);
	player.x = (float)mouseX;
	player.y = (float)mouseY;
	
}

//�~�̃f�[�^���Q�n���ē������Ă��邩���Ȃ����𔻒肷��֐�
bool isCollision(CircleData c0, CircleData c1)
{
	//�����蔻������

	float dx = c0.x - c1.x;
	float dy = c1.y - c1.y;
	float dist = sqrtf(dx * dx + dy * dy);
	//2���a�̍��v�Ƌ������r���ē�������Ƃ�
	if (dist < (c0.radius + c1.radius))
	{
		//�������Ă���
		return true;
	}
#if true
	    //�������Ă��Ȃ�
	    return false;
#else
	//if(true)�̏ꍇtrue��Ԃ��A�����ł͂Ȃ��ꍇfalse��Ԃ�
	return (dist <= (c0.radius + c1.radius));

#endif

}

//�~�̕`��
void drawCircle(CircleData data)
{
	DrawCircle(data.x, data.y, data.radius, data.color);
}

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

	//�~�̃f�[�^
	CircleData circle;
	circle.x = 320.0f;
	circle.y = 240.0f;
	circle.radius = 32.0f;
	circle.color = GetColor(255, 255, 255);

	//�v���C���[
	CircleData player;
	player.x = 0.0f;
	player.y = 0.0f;
	player.radius = 16;
	player.color = GetColor(255, 255, 255);

	//�Q�[�����[�v
	while (ProcessMessage() != 1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();


		//�`����s���O�ɉ�ʂ��N���A����

		ClearDrawScreen();

		//�v���C���[�Ɖ~�̕`��
		drawCircle(player);
		drawCircle(circle);

		bool isCol = isCollision(player, circle);
		if (isCol)
		{
			//�������Ă���ꍇ
			circle.color = GetColor(255, 0, 0);
		}
		else
		{
			//�������Ă��Ȃ��ꍇ
			circle.color = GetColor(255, 255, 255);
		}

		//��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66�~���b�o�߂���܂ő҂�

		}
	}

	DxLib_End();            //DX���C�u�����g�p


	return 0;				// �\�t�g�̏I�� 
}