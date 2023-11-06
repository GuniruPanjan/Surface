using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MOBCookie : MonoBehaviour
{
    void Update()
    {
        float dist = Vector3.Distance(new Vector3(0, 0, 0), transform.position);

       
        if(dist > 25.0f)
        {
            Destroy(this.gameObject);
        }
        
    }
}
