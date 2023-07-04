using System.Numerics;

namespace Csya_pukadai4._2
{
   
    internal class Program
    {
        static void Main(string[] args)
        {
            //インスタンスの作成
            Vector2 v1 = new Vector2(1.1f, 1.2f);
            Vector3 v2 = new Vector3(2.5f, 2.6f, 2.7f);
            Vector3 v3 = new Vector3(2.7f, 2.8f, 2.9f);
            Vector3 ans;

            //オーバーライド確認
            v1.Show();
            v1.Lenght();
            v2.Show();
            v2.Lenght();

            //計算と確認
            ans = Vector3.Add(v2, v3);
            ans.Show();
            ans = Vector3.Sub(v2, v3);
            ans.Show();
        }
        public class Vector3 : Vector2
        {
          
            float z;

            public Vector3()
            {
                z = 0;
            }

            public Vector3(float a, float b,float c)
            {
                x = a;
                y = b;
                z = c;
            }

            public override void Show()
            {
                Console.WriteLine("x:{0},y:{1},z:{2}",x , y, z);
            }
            public override void Lenght()
            {
                float ans;
                ans = x * x + y * y + z * z;
                ans = MathF.Sqrt(ans);
                Console.WriteLine("サイズ:{0}", ans);
            }


            public static Vector3 Add(Vector3 v1,Vector3 v2)
            {
                Vector3 ans = new Vector3();

                ans.x = v1.x + v2.x;
                ans.y = v1.y + v2.y;
                ans.z = v1.z + v2.z;

                return ans;
            }
            public static Vector3 Sub(Vector3 v1,Vector3 v2)
            {
                Vector3 ans = new Vector3();

                ans.x = v1.x - v2.x;
                ans.y = v1.y - v2.y;
                ans.z = v1.z - v2.z;


                return ans;
            }
        }

        public class Vector2
        {
            public float x, y;
           

            public Vector2()
            {
                x = 0;
                y = 0;
            }

            public Vector2(float a, float b)
            {
                x = a;
                y = b;
            }

            public virtual void Show()
            {
                Console.WriteLine("x:{0},y:{1}", x, y);
            }
            public virtual void Lenght()
            {
                float ans;
                ans = x * x + y * y;
                ans = MathF.Sqrt(ans);
                Console.WriteLine("サイズ:{0}",ans);

            }
        }

       
    }
}