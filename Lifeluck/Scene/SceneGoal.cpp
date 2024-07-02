#include "SceneGoal.h"
#include "SceneTitle.h"

SceneGoal::SceneGoal():
    m_pad(0)
{
}

SceneGoal::~SceneGoal()
{
}

void SceneGoal::Init()
{
}

std::shared_ptr<SceneBase> SceneGoal::Update()
{
    //パッド入力所得
    m_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    //Aボタンを押したら
    if (m_pad & PAD_INPUT_1)
    {
        return std::make_shared<SceneTitle>();
    }

    return shared_from_this();  //自身のポインタを返す
}

void SceneGoal::Draw()
{
    DrawString(240, 300, "Goal", 0xffffff);
}

void SceneGoal::End()
{
}
