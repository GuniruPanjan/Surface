using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObjectCollision : MonoBehaviour
{
    [Header("これに当たった時のプレイヤーのノックバック")] public float bound;

    [HideInInspector] public bool playertouch;
}
