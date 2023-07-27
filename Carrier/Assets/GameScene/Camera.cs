using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
public class Camera : MonoBehaviour
{
    GameObject Player;

    private float PosY = 3.5f;    //ÉvÉåÉCÉÑÅ[ÇÃë´å≥Çå©ÇπÇÈÇΩÇﬂ

    void Start()
    {
        this.Player = GameObject.Find("Player");
        
    }

    void Update()
    {
        Vector3 playerpos = this.Player.transform.position;
        transform.position = new Vector3(playerpos.x, playerpos.y + PosY, transform.position.z);

       
       


    }


}
