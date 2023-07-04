using System.Numerics;

namespace Csya_pukadai4._1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //インスタンスの作成
            Vector2 v1 = new Vector2();
            Vector2 v2 = new Vector2(1.2f,1.5f);
            Vector2 ans;
            //確認
            v1.Show();
            v2.Show();
            //計算
            ans = Vector2.Add(v1, v2);
            ans.Show();
            ans = Vector2.Sub(v1, v2);
            ans.Show();
            //長さの表示
            ans.Lenght();
        }
        public class Vector2
        {
            //メンバ変数
            float x = 0, y = 0;

            public Vector2() { }
            
            public Vector2(float a, float b)
            {
                x = a;
                y = b;
            }

            public static Vector2 Add(Vector2 v1,Vector2 v2)
            {
                Vector2 ans = new Vector2();

                ans.x = v1.x + v2.x;
                ans.y = v1.y + v2.y;


                return ans;
            }

            public static Vector2 Sub(Vector2 v1,Vector2 v2)
            {
                Vector2 ans = new Vector2();

                ans.x = v1.x - v2.x;
                ans.y = v1.y - v2.y;

                return ans;
            }

            public void Show()
            {
                Console.WriteLine("x:{0},y:{1}", x, y);
            }

            public void Lenght()
            {
                float ans = 0;
                //長さの2乗を出す
                ans = x * x + y * y;
                ans = MathF.Sqrt(ans);
                Console.WriteLine("サイズ：{0}", ans);
            }
        }

        
    }
}