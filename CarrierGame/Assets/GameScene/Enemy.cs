using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UIElements;
using UnityEngine.AI;
using static UnityEngine.GraphicsBuffer;


public class Enemy : MonoBehaviour
{
    private Animator anim = null;   //�A�j���[�V����
    private Vector2 pos;
    public int num = 1;

    [Header("�Œ�ړ��ʒu")] public int MinX = 0;
    [Header("�ō��ړ��ʒu")] public int MaxX = 0;

    public GameObject player;

    void Start()
    {
        anim = GetComponent<Animator>();
    }


    void Update()
    {
        pos = transform.position;

        if(EnemyFind.Find == 0)
        {
            anim.SetBool("EnemyRun", false);
            //�i�|�C���g�j�}�C�i�X�������邱�Ƃŋt�����Ɉړ�����
            transform.Translate(transform.right * Time.deltaTime * 7 * num);

            if (pos.x < MinX)
            {
                transform.localScale = new Vector3(-1, 1, 1);
                num = 1;
            }
            else if (pos.x > MaxX)
            {
                transform.localScale = new Vector3(1, 1, 1);
                num = -1;
            }
            
        }
        else if(EnemyFind.Find == 1)
        {
            //Debug.Log("��������");
            transform.position = Vector2.MoveTowards(transform.position, player.transform.position, 11 * Time.deltaTime);
            anim.SetBool("EnemyRun", true);
        }



    }

}
       
       
    





