using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StartPos : MonoBehaviour
{
    [Header("�v���C���[�Q�[���I�u�W�F�N�g")] public GameObject Playerobj;
    [Header("�R���e�B�j���[�ʒu")] public GameObject[] ContinuPoint;

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
                Debug.Log("�v���C���[����Ȃ������A�^�b�`����Ă���");
            }
        }
        else
        {
            Debug.Log("�ݒ肪����ĂȂ�");
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
                Debug.Log("�R���e�B�j���[�|�C���g�̐ݒ肪����ĂȂ�");
            }
        }
    }
}
