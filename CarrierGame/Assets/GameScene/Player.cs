using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;

public class Player : MonoBehaviour
{
    [Header("殴られた時に鳴らす音")] public AudioClip AttackSE;

    Rigidbody2D rd;
    [SerializeField] GameObject Player1;
    private string enemyTag = "Enemy";
    public float speed;    //プレイヤーの梯子を上るスピード
    private Animator anim = null;          //アニメーション
    public static float playerspeed = 0.012f;      //プレイヤーのスピード
    private float playerjump = 0.1f;             //プレイヤーのジャンプ
    private BoxCollider2D box = null;
    public static int PlayerHP = 100;             //プレイヤーのHP
    public static int PlayerAttack = 10;          //プレイヤーの攻撃力
    private bool isDead = false;            //プレイヤーの死亡
    bool isCliming;     //梯子を上る判定
    public bool foot = true;      //接着しているかどうか
    public float distance;
    private bool isDown = false;   //死んだ時のアニメーション
    public LayerMask LaddarLayer;
    private bool nonDownAnim = false;
    private string deadAreaTag = "Dead";
    private MoveObject moveObj = null;
    private string MoveTag = "Move";
    private string GomiTag = "Gomi";
    public static int Players = 1;
    private int rightAttack = 0;
    private int leftAttack = 0;


    void Start()
    {
        anim = GetComponent<Animator>();

        rd = GetComponent<Rigidbody2D>();

        box = GetComponent<BoxCollider2D>();

        isCliming = false;
    }

    private void ReceiveDamage(bool downAnim)
    {
        if(isDown)
        {
            return;
        }
        else 
        {
            if(downAnim)
            {
                anim.Play("Player_Down");
            }
            else
            {
                nonDownAnim = true;
            }

            GManager.instance.HPnum();
            isDown = true;
        }
    }

    void Update()
    {
        if(!isDown)
        {
            Vector2 positiion = transform.position;

            if (Input.GetKey("left"))   //左方向に移動
            {

                transform.localScale = new Vector3(1, 1, 1);
                positiion.x -= playerspeed;
                anim.SetBool("run", true);
            }
            else if (Input.GetKey("right"))    //右方向に移動
            {

                transform.localScale = new Vector3(-1, 1, 1);
                positiion.x += playerspeed;
                anim.SetBool("run", true);
            }
            else
            {
                anim.SetBool("run", false);
            }

            if (rightAttack == 1)
            {
                rd.velocity = positiion * 3f;
                rightAttack = 0;
            }
            else if (leftAttack == 1)
            {
                rd.velocity = positiion * -3f;
                leftAttack = 0;
            }
            //else if (Input.GetKey("up") && foot)
            //{

            //    positiion.y += playerjump;
            //}

            float y = Input.GetAxisRaw("Vertical");

            RaycastHit2D hit = Physics2D.Raycast(transform.position, Vector2.up, 4, LaddarLayer);
            if (hit.collider != null)
            {
                if (y > 0)
                {
                    //梯子の判定をtrueにする
                    isCliming = true;
                }
            }
            else
            {
                isCliming = false;
            }


            if (isCliming)
            {
                rd.velocity = new Vector2(rd.velocity.x, y * speed);
                rd.gravityScale = 0;
            }
            else
            {
                rd.gravityScale = 70;
            }

            



            transform.position = positiion;


        }


    }

    public void FixedUpdate()
    {
        float xSpeed = transform.position.x;
        float ySpeed = transform.position.y;

        if(!isDown)
        {
            Vector2 addVelocity = Vector2.zero;
            if (moveObj != null)
            {
                addVelocity = moveObj.GetVelocity();
                rd.velocity += addVelocity;
            }
            
        }

       
    }

    #region//接触判定
    private void OnCollisionEnter2D(Collision2D collision)
    {

        if (collision.collider.tag == enemyTag)
        {
            this.rd.AddForce(transform.right * 5f);
            foreach (ContactPoint2D p in collision.contacts)
            {
                if (p.point.x > transform.position.x)
                {
                    GManager.instance.PlaySE(AttackSE);
                    GManager.instance.PlayerHp -= EnemyAttack.Damage;
                    Debug.Log("右から来た");
                    rightAttack = 1;
                }
                else if (p.point.x < transform.position.x)
                {
                    GManager.instance.PlaySE(AttackSE);
                    GManager.instance.PlayerHp -= EnemyAttack.Damage;
                    Debug.Log("左から来た");
                    leftAttack = 1;
                }

                if (GManager.instance.PlayerHp == 0)
                {
                    ReceiveDamage(true);
                    break;
                }

                
            }
        }
        else if(collision.collider.tag == MoveTag)
        {
            moveObj = collision.gameObject.GetComponent<MoveObject>();
        }
        else if(collision.collider.tag == GomiTag)
        {
            Debug.Log("ゴミ箱だ");
        }
    }
    #endregion

    

    private void OnCollisionExit2D(Collision2D collision)
    {
        if(collision.collider.tag == MoveTag)
        {
            moveObj = null;
        }
    }

    public bool IsContinreWaiting()
    {
        return IsDownAnimEnd() || nonDownAnim;
    }

    //ダウンアニメーションが完了されているかどうか
    private bool IsDownAnimEnd()
    {
        if(isDown && anim != null)
        {
            //アニメーターの状態の情報
            AnimatorStateInfo currentState = anim.GetCurrentAnimatorStateInfo(0);
            if(currentState.IsName("Player_Down"))
            {
                if(currentState.normalizedTime >= 1)
                {
                    return true;
                }
            }
        }
        return false;
    }

    public void ContinuePlayer()
    {
        SceneManager.LoadScene("GameOver");
        isDown = false;
        anim.Play("Player_Animation");
        nonDownAnim = false;

    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == deadAreaTag)
        {
            GManager.instance.PlayerHp -= 100;
            ReceiveDamage(false);
        }
    }

    private void OnTriggerStay2D(Collider2D collision)
    {
        if(collision.tag == GomiTag)
        {
            if(Input.GetKey("up"))
            {
                Players = 0;
                Debug.Log("隠れた");
                Player1.SetActive(false);
            }
        }
    }

    //トリガーと他のオブジェクトが接触
    //void OnTriggerEnter2D(Collider2D t)
    //{
    //    foot = true;
    //}

    ////トリガーと他のオブジェクトが離れた
    //void OnTriggerExit2D(Collider2D t)
    //{
    //    foot = false;
    //}
}
