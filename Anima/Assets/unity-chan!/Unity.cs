using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Animations;

public class Unity : MonoBehaviour
{
    //publicを付けることで、エディタ上から値を入力できる
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
        //フラグの初期化
        flag = false;
        if(Input.GetKey("down"))
        {
            flag = true;
        }
        //アニメーションの変更
        animator.SetBool(parameter,flag);
    }
}
