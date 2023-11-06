using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class dragonAnim : MonoBehaviour
{
    Animator anim;
    // Start is called before the first frame update
    void Start()
    {
        anim = GameObject.Find("dragonDown_0").GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey("up"))
        {
            anim.Play("dragonUp");
        }
        if (Input.GetKey("down"))
        {
            anim.Play("dragonDown");
        }
        if (Input.GetKey("left"))
        {
            anim.Play("dragonLeft");
        }
        if (Input.GetKey("right"))
        {
            anim.Play("dratonRight");
        }
    }
}
