using System;
using System.Diagnostics.CodeAnalysis;

namespace class_kouzoutai
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Test型の変数の作成
            Test tes1;  //Test型のtes1という名前の変数を作成
            Test tes2;
            //インスタンスの作成
            tes1 = new Test();
            tes2 = new Test();

            //インスタンスを使って処理を行う
            tes1.Count();//1
            tes1.Count();//2
            tes1.Count();//3
            tes2.Count();//1
            tes2.Count();//2
            tes1.DelCount();//2
            tes2.DelCount();//1
            //確認
            tes1.OUtCount();
            tes2.OUtCount();
        }
    }

    //クラスの作成
    public class Test
    {
        //メンバ変数
        int a = 0;

        //メンバ変数
        public void Count()
        {
            a++;
        }
        public void DelCount()
        {
            a--;
        }
        public void OUtCount()
        {
           
        }
    }

}
