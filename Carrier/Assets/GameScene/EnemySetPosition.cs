using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySetPosition : MonoBehaviour
{
    //�����ʒu
    private Vector3 startPosition;
    //�ړI�n
    private Vector3 destination;

    void Start()
    {
        //�����ʒu��ݒ�
        startPosition = transform.position;
        SetDestination(transform.position);
    }

    //�����_���Ȉʒu�̍쐬
    public void CreateRandomPosition()
    {
        //�����_����Vector2�̒l�𓾂�
        var randDestination = Random.insideUnitCircle * 8;
        //���ݒn�Ƀ����_���Ȉʒu�𑫂��ĖړI�n�Ƃ���
        SetDestination(startPosition + new Vector3(randDestination.x, 0, randDestination.y));
    }
}