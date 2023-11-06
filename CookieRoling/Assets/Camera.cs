using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
    private GameObject Player;
    private Vector3 offset;

    void Start()
    {
        this.Player = GameObject.Find("Sphere");

        offset = transform.position - Player.transform.position;
    }

    void Update()
    {
        transform.position = Player.transform.position + offset;
    }
}
