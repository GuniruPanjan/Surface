using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GOAL : MonoBehaviour
{
    [Header("�v���C���[�̔���")] public PlayerTriggerCheck playerCheck;
    void Update()
    {
        //�v���C���[��������ɓ�������
        if (playerCheck.isOn)
        {
            if (GManager.instance != null)
            {
                SceneManager.LoadScene("GOALScene");
            }
        }
    }
}
