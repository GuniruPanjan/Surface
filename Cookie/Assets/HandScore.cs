using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HandScore : MonoBehaviour
{
    [SerializeField] public GameObject MOB;

    [Header("スコア")] private int Score = 1;
    [Header("タイマー")] private float timer = 0.0f;

    void Update()
    {
        timer++;
        if(timer >= 500.0f)
        {
            CookieManager.instance.Cookie += Score;

            float x = Random.Range(-15.0f, 15.0f);
            float z = Random.Range(8.0f, 12.0f);

            //プレハブの初期位置
            Vector3 pos = new Vector3(x, 16.0f, z);

            Instantiate(MOB, pos, Quaternion.identity);

            timer = 0.0f;


        }
    }
}
