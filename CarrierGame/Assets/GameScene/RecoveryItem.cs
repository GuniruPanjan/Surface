using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RecoveryItem : MonoBehaviour
{
    [Header("回復量")] public int myHP;
    [Header("プレイヤーの判定")] public PlayerTriggerCheck playerCheck;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        //プレイヤーが判定内に入ったら
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
