using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public static float playerspeed = 0.01f;      //�v���C���[�̃X�s�[�h
    private float playerjump = 0.02f;             //�v���C���[�̃W�����v

    public static int PlayerHP = 100;             //�v���C���[��HP
    public static int PlayerAttack = 10;          //�v���C���[�̍U����

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
