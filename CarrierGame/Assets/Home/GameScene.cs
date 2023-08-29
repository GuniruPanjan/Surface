using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.SocialPlatforms.Impl;

public class GameScene : MonoBehaviour
{
    [Header("フェード")] public Fade fade;
    public void OnClickGameScene()  //ゲームシーンへ遷移する
    {
        Player.Players = 1;
        GManager.instance.PlayerHp = 100;
        GManager.instance.score = 0;
        EnemyFind.Find = 0;
        fade.StartFadeOut();
        
    }

    private void Update()
    {
        if(fade.IsFadeOutComplete())
        {
            SceneManager.LoadScene("GameScene1");
        }
    }
}
