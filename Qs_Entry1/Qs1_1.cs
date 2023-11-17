using System;

namespace Qs_Entry1
{
    internal class Qs1_1
    {
        static void Main(string[] args)
        {
            //コーディング規約に関して（Main関数内）

            //変数の宣言と初期化
            //デバッグでは勝手に初期化されますが、
            //リリースだと初期化されないので初期化処理はしておきましょう

            //int
            int ansInt = 0, tempInt = 0;
            //long
            long ansLong = 0, tempLong = 0;
            //float
            float ansFloat = 0, tempFloat = 0;
            //double
            double ansDouble = 0, tempDouble = 0;
            //decimal型
            decimal ansDecimal = 0, tempDecimal = 0;
            //char型
            char ansChar = '\0', tempChar = '\0';
            //string型
            string ansString = "", tempString = "";


            //変数の代入
            ansInt = 1;
            ansLong = 1L;
            ansFloat = 1.0f;
            ansDouble = 1.0;
            ansDecimal = 1.0m;
            ansChar = 'あ';
            ansString = "あいうえお";

            //データの表示
            Console.WriteLine("[データの表示（基本）]");
            //改行して
            Console.WriteLine("hey");
            //改行せずに
            Console.WriteLine("hey1");
            Console.WriteLine("hey2");
            Console.WriteLine("");  //改行用

            //基本の計算
            //五足演算
            int ans = 0, vall = 9, val2 = 2;
            //足し算
            ans = vall + val2;
            Console.WriteLine(ans);
            //引き算
            ans = vall - val2;
            Console.WriteLine(ans);
            //掛け算
            ans = vall * val2;
            Console.WriteLine(ans);
            //割り算
            ans = vall / val2;
            Console.WriteLine(ans);
            //余り計算
            ans = vall % val2;
            Console.WriteLine(ans);

            //配列の作成
            //通常の作成
            int[] ar; //この段階では単なる参照を持てる変数
            ar = new int[5];//5個データを入れる配列を作っている
            //初期化と作成を同時に行う
            int[] ar2 = new int[5];
            //中身も同時に作る
            int[] ar3 = { 1, 2, 3, 4, 5 };

            //配列の使い方
            Console.WriteLine("[配列の使い方]");
            ar[0] = 1; ar[1] = 2; ar[2] = 3;
            Console.WriteLine("ar[0]:{0},ar[1]:{1},ar[2]:{2}", ar[0], ar[1], ar[2]);
            Console.WriteLine("配列のサイズ:{0}", ar.Length);

            //条件分岐（if文）
            Console.WriteLine("[条件分岐（if文）]");
            Console.Write("数値を入力してください");
            //int.Parse()は文字列を整数に変換するメソッド
            int num = int.Parse(Console.ReadLine());
            if (num == 0)
            {
                Console.WriteLine("入力された値は0です");

            }
            else if (num == 1)
            {
                Console.WriteLine("入力された値は1です");
            }
            else
            {
                Console.WriteLine("入力された値は0~1以外です");
            }

            //条件分岐（switch文）
            Console.WriteLine("[条件分岐（switch文）]");
            Console.WriteLine("数値を入力してください");
            num = int.Parse(Console.ReadLine());
            //    switch (num)
            //    {
            //                 case0:
            //case1:
            //case2:
            //    Console.WriteLine("0~2です");
            //    break;
            //case3:
            //    Console.WriteLine("3です");
            //    break;
            //    default:
            //    Console.WriteLine("それ以外です");
            //    break;
            //}
            //繰り返し（while）
            Console.WriteLine("[繰り返し（while）]");
            int count = 0;
            while(count < 5)
            {
                count++;
                Console.WriteLine("while:{0}回目",count);
            }

            //繰り返し(do~while)
            Console.WriteLine("[繰り返し（do ~ while）]");
            int count2 = 0;//ループカウンタとして作成
            do
            {
                count2++;
                Console.WriteLine("do~while:{0}回目", count2);
            } while (count2 < 5);
            //繰り返し(for)
            Console.WriteLine("[繰り返し（for）]");
            for(int i = 0; i < 5; i++)
            {
                Console.WriteLine("for:{0}回目", i);
            }

            //繰り返し(foreach)
            Console.WriteLine("[繰り返し（foreach文1）]");
            int[] ar4 = { 1, 2, 3 };
            foreach (var x in ar4)
            {
                Console.WriteLine(x);
            }

            //繰り返し（foreach文２）
            Console.WriteLine("[繰り返し（foreach文２）]");
            //多次元構造を持つ配列
            int[,]ar5 = { { 1,2,3,4} }













        }

    }
   
}
