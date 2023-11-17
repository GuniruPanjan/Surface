using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerSetActive : MonoBehaviour
{
    [SerializeField] GameObject Player1;
    public void Update()     //プレイヤーを出すためのスクリプト
    {
        if (Player.Players == 0)
        {
            Debug.Log("出る？");
            if (Input.GetKey("left"))
            {
                Debug.Log("出た");
                Player1.SetActive(!false);
                Player.Players = 1;
            }
            else if (Input.GetKey("right"))
            {
                Debug.Log("出た");
                Player1.SetActive(!false);
                Player.Players = 1;
            }
        }

    }
}
