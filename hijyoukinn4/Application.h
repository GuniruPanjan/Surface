#pragma once

struct Size
{
	int w;
	int h;
};
/// <summary>
/// �A�v���P�[�V�����S�̂��Ǘ�����N���X
/// </summary>
class Application
{
private:
	Application();

	//�R�s�[����̋֎~
	Application(const Application& app) = delete;
	void operator = (const Application& app) = delete;

	/// <summary>
	/// �㏈�����s��
	/// </summary>
	void Terminate();
public:
	Size windowSize_;
	Application();
	//[�C���X�^���X] : ���������m�ۂ��č��������(��������H���Ԃ��Ă���)
	//static�֐� : ���̃N���X�̎��Ԃ��Ȃ��Ă��Ăׂ�֐�
	//���[�J��static�֐� : �ӂ��̓��[�J���ϐ��͊֐��𔲂���ƂƂ���
	//�������܂����Astatic�ϐ��͍폜����܂���
	//�A�v���P�[�V�������I���܂ő��݂�������

	//�V���O���g���N���X�̍���
	//�R���X�g���N�^��private�ɒu�����ƂŁA�I�u�W�F�N�g�𓮓I�ɐ����ł��Ȃ��悤�ɂ���
	//Application app;//�~
	//Application* app = new Aplication();//�~
	//Application& app = Application::GetInastance();//Ok
	//Application app = aaapplication::GetInstance();//�ʂ邯�ǃ_��
	//�Ȃ��_���Ȃ̂��A����͕ʂ̃A�h���X�ɃR�s�[���ł��Ă�


	/// <summary>
	/// Application�̃V���O���g���C���X�^���X�̎Q�Ƃ�Ԃ�
	/// </summary>
	/// <returns>Application�C���X�^���X</returns>
	static Application& GetInstance()
	{
		static Application instance;
		return instance;
	}

	bool Init();
	void Run();
	const Size& GetWindowSize() const;

};

