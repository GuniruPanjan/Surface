using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GManager : MonoBehaviour
{
    private Player p;
    public static GManager instance = null;
    public int continueNum;
    [Header("スコア")]public int score;
    [Header("現在のHP")]public int PlayerHp;
    [Header("デフォルトのHP")] public int defaultPlayerHp;

    private AudioSource audiosource = null;

    //スタートより先に呼ぶ
    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(this.gameObject);
        }
        else
        {
            Destroy(this.gameObject);
        }
    }

    private void Start()
    {
        audiosource = GetComponent<AudioSource>();
    }

    public void HPnum()
    {
        if(PlayerHp <= 0)    //初期化する
        {
            
                Debug.Log("死亡");
                PlayerHp = 100;
                score = 0;
                EnemyFind.Find = 0;
    
        }
    }

    public void PlaySE(AudioClip clip)
    {
        if(audiosource != null)
        {
            audiosource.PlayOneShot(clip);
        }
        else
        {
            Debug.Log("オーディオソースが設定されていません");
        }
    }

    
}
