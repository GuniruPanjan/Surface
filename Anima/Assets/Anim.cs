using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Anim : MonoBehaviour
{
    GameObject one, two, three, four;
    int count;

    void Start()
    {
        one = GameObject.Find("1_0");
        two = GameObject.Find("2_0");
        three = GameObject.Find("3_0");
        four = GameObject.Find("4_0");
        one.SetActive(true);
        two.SetActive(false);
        three.SetActive(false);
        four.SetActive(false);
        count = 0;
    }

    void FixedUpdate()
    {
        if(count < 12)
        {
            one.SetActive(true);
            two.SetActive(false);
            three.SetActive(false);
            four.SetActive(false);
        }
        else if(count < 24)
        {
            one.SetActive(false);
            two.SetActive(true);
            three.SetActive(false);
            four.SetActive(false);
        }
        else if(count < 36)
        {
            one.SetActive(false);
            two.SetActive(false);
            three.SetActive(true);
            four.SetActive(false);
        }
        else if(count < 48)
        {
            one.SetActive(false);
            two.SetActive(false);
            three.SetActive(false);
            four.SetActive(true);
        }
        else
        {
            count = 0;
        }
        count++;
    }
}
