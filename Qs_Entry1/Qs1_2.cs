using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs1_2
    {
        static void Main(string[] args)
        {
            //関数の作成
            int IADD(int a, int b) //intの足し算をする関数
            {
                int ans;
                ans = a + b;
                return ans;
            }
            float FADD(float a, float b) //intの足し算をする関数
            {
                float ans;
                ans = a + b;
                return ans;
            }
            //文字列の足し算
            string SADD(string a, string b)
            {
                string ans;
                ans = a + b;
                return ans;
            }
            //実行結果の確認
            Console.WriteLine("[関数の作成と実行（値渡し）]");
            Console.WriteLine("IADD:{0}+{1} = {2}", 3,2,IADD(3,2));
            Console.WriteLine("FADD:{0}-{1} = {2}", 3.2, 2.5, FADD(3.2f, 2.5f));
            Console.WriteLine("SADD:{0}+{1} = {2}","Hello","C#",SADD("Hello","C#"));

            //関数
            //refは事前の初期化処理が入ります
            int a = 1;
            float b = 1.1f;
            string c = "test";
            void CheckRefReference(ref int a,ref float b,ref string c)
            {
                a = 2;
                b = 3.2f;
                c = "tete";
            }
            //実行
            Console.WriteLine("[関数の作成と実行（参照渡し）]");
            Console.WriteLine("a:{0},b:{1},c:{2}", a, b, c);
            CheckRefReference(ref a, ref b, ref c); //refと付ける
            Console.WriteLine("a:{0},b:{1},c:{2}", a, b, c);

            //関数の作成と実行（out参照渡し）
            //事前に初期化が必要ない
            void CheckOutReference(out int a, out float b,out string c)
            {
                a = 8;
                b = 8.2f;
                c = "papas";
            }
            //実行
            Console.WriteLine("[関数の作成と実行（out参照渡し）]");
            //初期化せずに使える
            CheckOutReference(out int a2, out float b2, out string c2); //refと付ける
            Console.WriteLine("a:{0},b:{1},c:{2}", a2, b2, c2);

            //配列を扱う関数
            int ASum(int[] a)
            {
                int ans = 0;
                //合計の計算
                foreach (int s in a)
                {
                    ans += s;
                }

                a[1] = 0;

                return ans;
            }
            //実行
            Console.WriteLine("[配列を扱う関数（配列は参照渡し）]");
            int[] ar = { 1, 2, 3, 4 };
            Console.WriteLine("ASum:{0}", ASum(ar));
            //参照渡しなので、a[1]を書き換えるとar[1]も書き換えられ結果が変化している
            Console.WriteLine("ASum(2回目):{0}", ASum(ar));

            //可変引数の関数
            int ASum2(params int[] a)
            {
                int ans = 0;
                //合計の計算
                foreach(int s in a)
                {
                    ans += s;
                }
                return ans;
            }
            //実行
            Console.WriteLine("[可変引数の関数]");
            //いちいち配列を作ってそれを送らなくても配列変数として渡せる
            Console.WriteLine(ASum2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

            //オーバーロードの実行
            Console.WriteLine("[関数のオーバーロード]");
            Console.WriteLine(Add(1, 2));
            Console.WriteLine(Add(1, 2,3));
            Console.WriteLine(Add(1.1f, 2.1f));
            Console.WriteLine(Add(1.1f, 2.1f,3.1f));


        }

        //関数のオーバーロード
        //Main()内ではオーバーロードできないので外に出す
        static int Add(params int[] a)
        {
            int ans = 0;
            foreach(int s in a)
            {
                ans += s;
            }
            return ans;
        }
        static float Add(params float[] a)
        {
            float ans = 0;
            foreach(float s in a)
            {
                ans += s;
            }
            return ans;
        }
      
    }
}
