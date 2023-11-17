using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BGM : MonoBehaviour
{
    public void PlayBgm()
    {
        this.GetComponent<AudioSource>().Play();
    }

    public void StopBgm()
    {
        this.GetComponent<AudioSource>().Stop();
    }
}
