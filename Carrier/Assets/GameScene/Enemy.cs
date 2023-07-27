using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Enemy : MonoBehaviour
{
    private CharacterController enemyController;
    private Animator animator;
    //�ړI�n
    private Vector3 destination;
    //�����X�s�[�h
    [SerializeField]
    private float walkSpeed = 1.0f;
    //���x
    private Vector3 velocity;
    //�ړ�����
    private Vector3 direction;
    //�����t���O
    private bool arrived;
    //�҂�����
    [SerializeField]
    private float waitTime = 5f;
    //�o�ߎ���
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

            //�ړI�n�ɓ����������ǂ����̔���
        }
    }
}
