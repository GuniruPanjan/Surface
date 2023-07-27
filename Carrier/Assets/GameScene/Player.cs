using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public static float playerspeed = 0.01f;      //プレイヤーのスピード
    private float playerjump = 0.02f;             //プレイヤーのジャンプ

    public static int PlayerHP = 100;             //プレイヤーのHP
    public static int PlayerAttack = 10;          //プレイヤーの攻撃力

    void Update()
    {
        Vector2 positiion = transform.position;

        if(Input.GetKey("left"))
        {
            positiion.x -= playerspeed; 
        }
        else if(Input.GetKey("right"))
        {
            positiion.x += playerspeed; 
        }
        else if(Input.GetKey("up"))
        {
            positiion.y += playerjump; 
        }


        transform.position = positiion;
    }
}
