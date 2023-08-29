using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GManager : MonoBehaviour
{
    private Player p;
    public static GManager instance = null;
    public int continueNum;
    [Header("�X�R�A")]public int score;
    [Header("���݂�HP")]public int PlayerHp;
    [Header("�f�t�H���g��HP")] public int defaultPlayerHp;

    private AudioSource audiosource = null;

    //�X�^�[�g����ɌĂ�
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
        if(PlayerHp == 0)    //����������
        {
            
                Debug.Log("���S");
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
            Debug.Log("�I�[�f�B�I�\�[�X���ݒ肳��Ă��܂���");
        }
    }

    
}
