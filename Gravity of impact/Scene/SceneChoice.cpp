#include "SceneChoice.h"
#include "DxLib.h"
#include "SceneGame.h"

SceneChoice::SceneChoice():
    m_frameCount(0)
{
}

SceneChoice::~SceneChoice()
{
    //�摜�̉��
    DeleteGraph(ChoiceBack);
}

void SceneChoice::Init()
{
    m_frameCount = 0;

    //�w�i�摜�ǂݍ���
    ChoiceBack = LoadGraph("data/cloudy.png");
}

std::shared_ptr<SceneBase> SceneChoice::Update()
{
    m_frameCount++;

    if (m_frameCount >= 60)
    {
        return std::make_shared<SceneGame>();
    }


    return shared_from_this();
}

void SceneChoice::Draw()
{
    //�w�i�摜�̈ʒu
    int ChoiceBackx, ChoiceBacky;
    ChoiceBackx = 0;
    ChoiceBacky = 0;

    //�w�i�摜�`��
    DrawGraph(ChoiceBackx, ChoiceBacky, ChoiceBack, true);

    DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", m_frameCount);
}

void SceneChoice::End()
{
}
