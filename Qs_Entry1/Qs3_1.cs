using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs3_1
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Baseのコンストラクタ後にDerivedのコンストラクタが実行");
            Derived x = new Derived();

            Console.WriteLine("Baseを継承しているので、Baseのメソッドが使える");
            x.Show();

            Console.WriteLine("派生クラス内で基本クラスのメソッドを使える");
            x.ShowPlus();

            Console.WriteLine("基本クラスの変数で派生クラスのインスタンスを扱える");
            Base y = x;
            y.Show();//親の変数のまま、親のメソッドは使える

        }

    }

    //継承

    public class Base
    {
        public Base()
        {
            Console.WriteLine("基本クラスのコンストラクタ");
        }
        public void Show()
        {
            Console.WriteLine("Hello");
        }
    }
    //派生クラス
    public class Derived : Base
    {
        public Derived()
        {
            Console.WriteLine("派生クラスのコンストラクタ");
        }
        public void Show()
        {
            Console.WriteLine()
        }
    }

}
