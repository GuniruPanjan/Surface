#pragma once
class SceneMgr
{
public:
	SceneMgr();
	~SceneMgr();

	void Init();
	void Update();
	void Draw();
	void End();

	typedef enum
	{
		m_Scene_Title,   //�^�C�g�����
		m_Scene_Game,    //�Q�[�����
		m_Scene_Result,  //���ʉ��

	}m_Scene;

	void SceneMgr_ChangeScene(m_Scene nextScene);

	static void SceneMgr_InitializeModule(m_Scene scene);
	static void SceneMgr_FinalizeModule(m_Scene FinalScene);

};

