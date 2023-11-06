using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Egg : MonoBehaviour
{
    [SerializeField] public GameObject egg;

    Vector3 _delPos, _pos, _plusDel;

    void Start()
    {
        //•‚Ìì¬
        _delPos = new Vector3(-1000.0f + 0.2f, -40.0f, 0.0f);
        _plusDel = new Vector3(0.2f, 0, 0);
        _pos = transform.position + _delPos;
    }


    public void OnClick()
    {
        if (CookieManager.instance.Cookie >= 800)
        {
            Instantiate(egg, _pos, Quaternion.identity);

            CookieManager.instance.Cookie -= 800;

            _pos += _plusDel;
        }

    }
}
