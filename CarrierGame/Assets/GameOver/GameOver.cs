using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameOver : MonoBehaviour
{
    public void OnClickGameScene()  //�Q�[���V�[���֑J�ڂ���
    {
        SceneManager.LoadScene("GameScene1");
    }
}
