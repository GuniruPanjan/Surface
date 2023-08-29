using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RecoveryItem : MonoBehaviour
{
    [Header("�񕜗�")] public int myHP;
    [Header("�v���C���[�̔���")] public PlayerTriggerCheck playerCheck;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        //�v���C���[��������ɓ�������
        if (playerCheck.isOn)
        {
            if (GManager.instance != null)
            {
                if(GManager.instance.PlayerHp < 100)
                {
                    GManager.instance.PlayerHp += myHP;
                    Destroy(this.gameObject);
                }
                
            }
        }
    }
}
