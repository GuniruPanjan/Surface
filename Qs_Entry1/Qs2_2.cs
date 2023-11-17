using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs2_2
    {
        static void Main(string[] args)
        {
            //インデクサ
            Console.WriteLine("[インデクサを持つクラス]");
            EnemyName enemyName = new EnemyName();
            enemyName[0] = "スライム";
            enemyName[1] = "ドラキー";
            enemyName[2] = "アトンベア";
            for(int i = 0; i < 3; i++)
            {
                Console.WriteLine(enemyName[i]);
            }

            //演算子オーバーロード
            Console.WriteLine("[演算子のオーバーロード]");
            Vector2 v1 = new Vector2(1.2f, 1.8f);
            Vector2 v2 = new Vector2(0.6f, 0.6f);
            Vector2 tempV;

            //オーバーロードの確認
            tempV = v1 + v2;
            Console.WriteLine("v1 + v2 : {0}", tempV.OutString());
            tempV = v1 - v2;
            Console.WriteLine("v1 - v2 : {0}", tempV.OutString());
            tempV = v1 * v2;
            Console.WriteLine("v1 * v2 : {0}", tempV.OutString());
            tempV = v1 / v2;
            Console.WriteLine("v1 / v2 : {0}", tempV.OutString());
        }
    }

    //インデクサを持つクラス
    public class EnemyName
    {
        private string[] name = new string[100];
        public string this[int i]
        {
            get { return name[i]; }
            set { name[i] = value; }
        }
    }
    //演算子のオーバーロード
    public class Vector2
    {
        private float _x = 0;
        private float _y = 0;

        public float X
        {
            get { return _x; }
        }
        public float Y
        {
            get { return _y; }
        }

        public Vector2() { }
        public Vector2(float x, float y)
        {
            this._x = x;
            this._y = y;
        }
        //演算子の左辺が第一引数、　右辺が第二引数
        //a + b => (a,b)
        public static Vector2 operator +(Vector2 v1, Vector2 v2)
        {
            return new Vector2(v1.X + v2.X, v1.Y + v2.Y);
        }
        public static Vector2 operator -(Vector2 v1, Vector2 v2)
        {
            return new Vector2(v1.X - v2.X, v1.Y - v2.Y);
        }
        //実数倍
        public static Vector2 operator *(Vector2 left, Vector2 right)
        {
            return new Vector2(left.X * right.X, left.Y * right.Y);
        }
        public static Vector2 operator /(Vector2 left, Vector2 right)
        {
            return new Vector2(left.X / right.X, left.Y / right.Y);
        }
    }
}
