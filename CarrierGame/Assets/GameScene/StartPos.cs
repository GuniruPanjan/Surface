using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StartPos : MonoBehaviour
{
    [Header("プレイヤーゲームオブジェクト")] public GameObject Playerobj;
    [Header("コンティニュー位置")] public GameObject[] ContinuPoint;

    private Player p;
    // Start is called before the first frame update
    void Start()
    {
        if(Playerobj != null && ContinuPoint != null && ContinuPoint.Length > 0)
        {
            Playerobj.transform.position = ContinuPoint[0].transform.position;

            p = Playerobj.GetComponent<Player>();
            if(p == null)
            {
                Debug.Log("プレイヤーじゃない物がアタッチされている");
            }
        }
        else
        {
            Debug.Log("設定が足りてない");
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(p != null && p.IsContinreWaiting())
        {
            if(ContinuPoint.Length > GManager.instance.continueNum)
            {
                Playerobj.transform.position = ContinuPoint[GManager.instance.continueNum].transform.position;
                p.ContinuePlayer();
            }
            else
            {
                Debug.Log("コンティニューポイントの設定が足りてない");
            }
        }
    }
}
