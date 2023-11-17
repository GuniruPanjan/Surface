using JetBrains.Annotations;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEditor.PlayerSettings;

public class Cookie : MonoBehaviour
{
    [SerializeField] public GameObject MOB;

    [Header("加算するスコア")] public int ScoreCookie;
    [Header("タイマー")] private float timer = 10;
    [Header("回転")] private float angle = 0;
    
    

    public Vector3 scale, delSize, delMo;

    void Start()
    {
        //サイズスピードを入れておく
        delSize = new Vector3(0.1f, 0.1f, 0.1f);
        //初期サイズ
        delMo = new Vector3(3, 3, 3);
        
    }

    void FixedUpdate()
    {
        timer++;
        if (timer <= 10.0f)
        {
            this.transform.localScale += delSize;
        }
        
    }

    public void OnPointerClick()
    {
        
        gameObject.transform.localScale = new Vector3(scale.x, scale.y, scale.z);

        CookieManager.instance.Cookie += ScoreCookie;

        float x = Random.Range(-15.0f, 15.0f);
        float z = Random.Range(8.0f, 12.0f);

        //プレハブの初期位置
        Vector3 pos = new Vector3(x, 16.0f, z);

        Instantiate(MOB, pos, Quaternion.identity);

        timer = 0;
    }
}
