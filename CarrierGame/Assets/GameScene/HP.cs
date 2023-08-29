using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class HP : MonoBehaviour
{
    private Text HPText = null;
    private int oldHPNum = 0;
    // Start is called before the first frame update
    void Start()
    {
        HPText = GetComponent<Text>();
        if (GManager.instance != null)
        {
            HPText.text = "HP:" + GManager.instance.PlayerHp;
        }
        else
        {
            Debug.Log("ゲームマネージャーないじゃん");
            Destroy(this);
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (oldHPNum != GManager.instance.PlayerHp)
        {
            HPText.text = "HP:" + GManager.instance.PlayerHp;
            oldHPNum = GManager.instance.PlayerHp;
        }
    }
}
