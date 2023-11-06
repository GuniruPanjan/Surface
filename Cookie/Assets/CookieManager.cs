using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CookieManager : MonoBehaviour
{
    [SerializeField] public  GameObject MOB;

    public static CookieManager instance = null;

    [Header("クッキー")] public int Cookie;

    private void Awake()
    {
        if(instance == null)
        {
            instance = this;
            DontDestroyOnLoad(this.gameObject);
        }
        else
        {
            Destroy(this.gameObject);
        }
    }

    public void Update()
    {
        int count = GameObject.FindGameObjectsWithTag("Cookie").Length;
        
        if(count >= 30)
        {
            Destroy(MOB);
        }
    }

}
