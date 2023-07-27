using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Enemy : MonoBehaviour
{
    private CharacterController enemyController;
    private Animator animator;
    //目的地
    private Vector3 destination;
    //歩くスピード
    [SerializeField]
    private float walkSpeed = 1.0f;
    //速度
    private Vector3 velocity;
    //移動方向
    private Vector3 direction;
    //到着フラグ
    private bool arrived;
    //待ち時間
    [SerializeField]
    private float waitTime = 5f;
    //経過時間
    private float elapsedTime;

    void Start()
    {
        enemyController = GetComponent<CharacterController>();
        animator = GetComponent<Animator>();
        velocity = Vector3.zero;
        arrived = false;
        elapsedTime = 0f;
    }

    void Update()
    {
       if(!arrived)
        {
            if(enemyController.isGrounded)
            {
                velocity = Vector3.zero;
                animator.SerFloat("Speed", 2.0f);
                direction = (destination - transform.position).normalized;
                transform.LookAt(new Vector3(destination.x, transform.position.y, destination.z));
                velocity = direction * walkSpeed;
                Debug.Log(destination);
            }
            velocity.y += Physics.gravity.y * Time.deltaTime;
            enemyController.Move(velociy * Time.deltaTime);

            //目的地に到着したかどうかの判定
        }
    }
}
