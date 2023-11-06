using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    float x = 0;
    float y = 0;
    float z = 0;

    [Header("‘¬‚³")] public float Speed = 0.01f;
    [Header("ƒWƒ…ƒ“ƒv")] public float jumpPower;

    private Rigidbody rigidbody;

    Vector3 Pow;

    void Start()
    {
        rigidbody = GetComponent<Rigidbody>();
    }

    void FixedUpdate()
    {
        Pow = new Vector3(x, y, z);

        z += Speed;

        

        rigidbody.AddForce(Pow);

        

    }

    void Update()
    {
        if (Input.GetMouseButton(0))
        {
            rigidbody.velocity = Vector3.up * jumpPower;
        }
        else if(Input.GetMouseButton(1))
        {
            rigidbody.velocity = Vector3.left; 
        }

    }
}
