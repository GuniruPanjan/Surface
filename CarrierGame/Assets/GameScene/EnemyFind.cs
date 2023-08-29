using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Events;


public class EnemyFind : MonoBehaviour
{
    [SerializeField] GameObject BGM1;
    [SerializeField] GameObject BGM2;
    public static int Find = 0;
    void OnTriggerEnter2D(Collider2D other)
    {
       
        if (other.gameObject.tag == "Player")
        {
            Find = 1;
            BGM1.SetActive(false);
            BGM2.SetActive(!false);
        }
       
    }

    void OnTriggerExit2D(Collider2D other)
    {
        if(other.gameObject.tag == "Player")
        {
            Find = 0;
            Debug.Log("å©é∏Ç¡ÇΩÅc");
            BGM1.SetActive(!false);
            BGM2.SetActive(false);
        }
        else if(GManager.instance.PlayerHp <= 0)
        {
            Find = 0;
        }
       
    }
}
