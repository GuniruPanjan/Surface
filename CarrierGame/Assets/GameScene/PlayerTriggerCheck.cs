using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerTriggerCheck : MonoBehaviour
{
    [HideInInspector] public bool isOn = false;

    private string playerTag = "Player";

    #region//ê⁄êGîªíË
    
    private void OnTriggerEnter2D(Collider2D collidion)
    {
        if(collidion.tag == playerTag)
        {
            isOn = true;
        }
    }

    // Update is called once per frame
    private void OnTriggerExit2D(Collider2D collidion)
    {
        isOn = false;
    }
    #endregion
}
