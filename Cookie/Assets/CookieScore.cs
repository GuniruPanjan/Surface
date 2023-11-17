using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CookieScore : MonoBehaviour
{
    private Text scoreText = null;
    private int oldScore = 0;

    void Start()
    {
        scoreText = GetComponent<Text>();
        if(CookieManager.instance != null)
        {
            scoreText.text = "" + CookieManager.instance.Cookie;
        }
        else
        {
            Debug.Log("ゲームマネージャーがない");
            Destroy(this);
        }
    }

    void Update()
    {
        if(oldScore != CookieManager.instance.Cookie)
        {
            scoreText.text = "" + CookieManager.instance.Cookie;
            oldScore = CookieManager.instance.Cookie;
        }
    }
}
