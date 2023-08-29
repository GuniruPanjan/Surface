using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.VisualScripting;

public class Camera : MonoBehaviour
{
    GameObject Player;

    private float PosY = 3.5f;    //ƒvƒŒƒCƒ„[‚Ì‘«Œ³‚ğŒ©‚¹‚é‚½‚ß

    void Start()
    {
        this.Player = GameObject.Find("player_1");

    }

    void Update()
    {
        Vector3 playerpos = this.Player.transform.position;
        transform.position = new Vector3(playerpos.x, playerpos.y + PosY, transform.position.z);





    }
}
