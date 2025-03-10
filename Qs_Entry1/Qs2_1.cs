﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry
{
    internal class Qs2_1
    {
        static void Main(string[] args)
        {
            //クラスないでのstatic(静的メンバー)
            Console.WriteLine("[クラス内でのstatic(静的メンバー)]");
            //インスタンスの作成
            Enemy.CountEnemy();
            Enemy ene = new Enemy();
            Enemy.CountEnemy();
            Enemy ene1 = new Enemy();
            Enemy.CountEnemy();
            Enemy ene2 = new Enemy();
            Enemy.CountEnemy();
            //疑似的な削除
            Enemy.deleteEnemy(ref ene);
            Enemy.CountEnemy();
            Enemy.deleteEnemy(ref ene1);
            Enemy.CountEnemy();

            //staticクラス
            Console.WriteLine("[staticクラス]");
            Console.WriteLine(Math.Power(2,8));
            Console.WriteLine(Math.Power(2.8f, 8));

        }
    }

    public class Enemy
    {
        private static int s_enemyCount = 0;

        //コンストラクタ
        public Enemy() { s_enemyCount++; }

        //数を表示
        public static void CountEnemy()
        {
            Console.WriteLine("現在のエネミーの総数は：" + s_enemyCount);
        }

        public static void deleteEnemy(ref Enemy enemy)
        {
            //参照されなくなり
            //いずれはGC（ガベレージコレクタ）
            enemy = null;
            s_enemyCount--;

        }
    }

    static class Math
    {
        static private int s_itemp = 0;
        static private float s_ftemp = 0;

        //nのm乗の計算
        static public int Power(int n,int m)
        {
            s_itemp = 1;
            for(int i = 0; i < m; i++)
            {
                s_itemp *= n;
            }

            return s_itemp;
        }
        static public float Power(float n, float m)
        {
            s_ftemp = 1.0f;
            for (int i = 0; i < m; i++)
            {
                s_ftemp *= n;
            }

            return s_ftemp;
        }
    }
}
