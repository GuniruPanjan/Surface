using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Animations;

public class Unity : MonoBehaviour
{
    //public��t���邱�ƂŁA�G�f�B�^�ォ��l����͂ł���
    public string parameter = "";
    Animator animator;
    bool flag = false;
    // Start is called before the first frame update
    void Start()
    {
        animator = this.GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        //�t���O�̏�����
        flag = false;
        if(Input.GetKey("down"))
        {
            flag = true;
        }
        //�A�j���[�V�����̕ύX
        animator.SetBool(parameter,flag);
    }
}
