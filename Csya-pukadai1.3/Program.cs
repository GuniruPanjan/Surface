using System.IO.Pipes;
using System.Numerics;

namespace Csya_pukadai1._3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //インスタンスの作成
            Vector2 a = new Vector2();
            Vector2 b = new Vector2();
            Vector2 c;
            Vector2 d;
            //数値の代入
            a.X = 1.2f;
            a.Y = 1.8f;
            b.X = 1.6f;
            b.Y = 2.2f;
            //確認
            a.Show();
            b.Show();
            //足し算
            c = Vector2.Add(a, b);
            c.Show();
            //引き算
            d = Vector2.Sub(a, c);
            d.Show();
        }

    }

    public class Vector2
    {
        //メンバ変数
        public float X = 0.0f;
        public float Y = 0.0f;

        //メンバ関数

        static public Vector2 Add(Vector2 v1,Vector2 v2)
        {
            Vector2 ans = new Vector2();
            ans.X = v1.X + v2.X;
            ans.Y = v1.Y + v2.Y;
            return ans;
        }
        static public Vector2 Sub(Vector2 v1, Vector2 v2)
        {
            Vector2 nam = new Vector2();
            nam.X = v1.X - v2.X;
            nam.Y = v1.Y - v2.Y;
            return nam;

        }
        public void Show()
        {
           
            Console.WriteLine("X:{0}, Y:{1}\n", X, Y);

        }
    }

}