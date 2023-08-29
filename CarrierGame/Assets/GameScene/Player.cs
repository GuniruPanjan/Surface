using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;

public class Player : MonoBehaviour
{
    [Header("����ꂽ���ɖ炷��")] public AudioClip AttackSE;

    Rigidbody2D rd;
    [SerializeField] GameObject Player1;
    private string enemyTag = "Enemy";
    public float speed;    //�v���C���[�̒�q�����X�s�[�h
    private Animator anim = null;          //�A�j���[�V����
    public static float playerspeed = 0.012f;      //�v���C���[�̃X�s�[�h
    private float playerjump = 0.1f;             //�v���C���[�̃W�����v
    private BoxCollider2D box = null;
    public static int PlayerHP = 100;             //�v���C���[��HP
    public static int PlayerAttack = 10;          //�v���C���[�̍U����
    private bool isDead = false;            //�v���C���[�̎��S
    bool isCliming;     //��q����锻��
    public bool foot = true;      //�ڒ����Ă��邩�ǂ���
    public float distance;
    private bool isDown = false;   //���񂾎��̃A�j���[�V����
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

            if (Input.GetKey("left"))   //�������Ɉړ�
            {

                transform.localScale = new Vector3(1, 1, 1);
                positiion.x -= playerspeed;
                anim.SetBool("run", true);
            }
            else if (Input.GetKey("right"))    //�E�����Ɉړ�
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
                    //��q�̔����true�ɂ���
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

    #region//�ڐG����
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
                    Debug.Log("�E���痈��");
                    rightAttack = 1;
                }
                else if (p.point.x < transform.position.x)
                {
                    GManager.instance.PlaySE(AttackSE);
                    GManager.instance.PlayerHp -= EnemyAttack.Damage;
                    Debug.Log("�����痈��");
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
            Debug.Log("�S�~����");
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

    //�_�E���A�j���[�V��������������Ă��邩�ǂ���
    private bool IsDownAnimEnd()
    {
        if(isDown && anim != null)
        {
            //�A�j���[�^�[�̏�Ԃ̏��
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
                Debug.Log("�B�ꂽ");
                Player1.SetActive(false);
            }
        }
    }

    //�g���K�[�Ƒ��̃I�u�W�F�N�g���ڐG
    //void OnTriggerEnter2D(Collider2D t)
    //{
    //    foot = true;
    //}

    ////�g���K�[�Ƒ��̃I�u�W�F�N�g�����ꂽ
    //void OnTriggerExit2D(Collider2D t)
    //{
    //    foot = false;
    //}
}
