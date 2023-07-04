using System.Reflection.Metadata;

namespace Csya_pukadai1._2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //インスタンスの作成
            User u1 = new User();
            User u2 = new User();
            //代入
            u1.name = "tanaka";
            u1.age = 18;
            u1.score = 88.2f;
            u2.name = "sato";
            u2.age = 20;
            u2.score = 78.2f;
            //確認
            u1.Show();
            u2.Show();
        }

        public class User
        {
            //メンバ変数
            public string name = "";
            public int age = 0;
            public float score = 0.0f; 

            public void Show(string  name, int  age,float  score)
            {
                Console.WriteLine("name:{0}、age:{1}、score{2}", name, age, score);
            }
        }


    }
}