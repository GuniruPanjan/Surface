#include "DxLib.h"
#include <cmath>

//�����蔻������~�̐�
#define CIRCLE_NUM 3
//�~�̃f�[�^���\���̂ɂ܂Ƃ߂�
typedef struct CircleData
{
	//�����o�������ɏ���
	float x;//X���W
	float y;//Y���W
	float radius;//���a
	unsigned int color;//�F
}CircleData;

//�~�̃f�[�^��2�n���ē������Ă��邩�������Ă��Ȃ����𔻒肷��֐�
bool isCollision(CircleData c0, CircleData c1)
{
	//�����蔻����Ƃ�

		//1.�������肽���e�~�̒��S�̋��������߂�
		//x���W�̋��� (c0.x - c1.x)      2�悷��̂Ő�Βl�͂Ƃ�Ȃ��Ă�����
		//y���W�̋��� (c0.y - c1.y)
	float dx = c0.x - c1.x;
	float dy = c0.y - c1.y;
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
	//�ł���΂��̂܂�if���̏������̒��g��Ԃ��Ηǂ��̂ł�
	return (dist <= (c0.radius + c1.radius));

#endif
	
}

//�~�̕`��
void drawCircle(CircleData data)
{
	DrawCircle(data.x, data.y, data.radius, data.color);
}

//�Q�ƌ^�̕��K
//�v���C���[�𓮂����̂��֐���
//�֐����Ń}�E�X�J�[�\���̈ʒu�����A�����Ƃ��ēn���ꂽCircleData�̍��W�ɐݒ肷��
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
	CircleData circle[CIRCLE_NUM]; //�z���
	//�~�̃f�[�^�̏�����
	for (int i = 0; i < CIRCLE_NUM; i++)
	{

	circle[i].x = 160.0f * (i+1);
	circle[i].y = 240.0f;
	circle[i].radius = 32.0f;
	circle[i].color = GetColor(255, 255, 255);

	}

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

		

		



		//DrawCircle(mouseX, mouseY, 8, GetColor(255, 255, 255), true);

		drawCircle(player);
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			drawCircle(circle[i]);
		}

		//DrawCircle(320, 240, 32, GetColor(255, 255, 0),true);

		for (int i = 0; i < CIRCLE_NUM; i++)
		{


			bool isCol = isCollision(player, circle[i]);

			if (isCol)
			{
				//�������Ă���ꍇ
				circle[i].color = GetColor(255, 0, 0);
			}
			else
			{
				//�������Ă��Ȃ��ꍇ
				circle[i].color = GetColor(255, 255, 255);
			}
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