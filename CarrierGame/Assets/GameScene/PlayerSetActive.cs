using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEditor.Experimental.GraphView.GraphView;

public class PlayerSetActive : MonoBehaviour
{
    [SerializeField] GameObject Player1;
    public void Update()     //�v���C���[���o�����߂̃X�N���v�g
    {
        if (Player.Players == 0)
        {
            Debug.Log("�o��H");
            if (Input.GetKey("left"))
            {
                Debug.Log("�o��");
                Player1.SetActive(!false);
                Player.Players = 1;
            }
            else if (Input.GetKey("right"))
            {
                Debug.Log("�o��");
                Player1.SetActive(!false);
                Player.Players = 1;
            }
        }

    }
}
