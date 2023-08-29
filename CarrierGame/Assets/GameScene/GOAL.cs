using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GOAL : MonoBehaviour
{
    [Header("プレイヤーの判定")] public PlayerTriggerCheck playerCheck;
    void Update()
    {
        //プレイヤーが判定内に入ったら
        if (playerCheck.isOn)
        {
            if (GManager.instance != null)
            {
                SceneManager.LoadScene("GOALScene");
            }
        }
    }
}
