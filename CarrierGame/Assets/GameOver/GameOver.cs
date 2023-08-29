using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameOver : MonoBehaviour
{
    public void OnClickGameScene()  //ƒQ[ƒ€ƒV[ƒ“‚Ö‘JˆÚ‚·‚é
    {
        SceneManager.LoadScene("GameScene1");
    }
}
