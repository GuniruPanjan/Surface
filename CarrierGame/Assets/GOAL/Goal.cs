using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class Goal : MonoBehaviour
{
    [SerializeField] GameObject low;
    [SerializeField] GameObject normal;
    [SerializeField] GameObject high;
    [SerializeField] GameObject GOAL;
    // Start is called before the first frame update
    void Start()
    {
        if(GManager.instance.score <= 30)
        {
            low.SetActive(!false);
        }
        else if(GManager.instance.score <= 60)
        {
            normal.SetActive(!false);
        }
        else if(GManager.instance.score <= 90)
        {
            high.SetActive(!false);
        }
        else if(GManager.instance.score == 100)
        {
            GOAL.SetActive(!false);
        }
        
    }
}
