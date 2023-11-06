using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs3_2
    {
        static void Main(string[] args)
        {
            //クラスへのアクセス
            Console.WriteLine("クラスへのアクセス(this(),base())");
            //Base x = new Base();
            //Base y = new Base("gege");
            Derived x = new Derived();
            x.Show();
            x.Show2();

            //オーバーライド
            Console.WriteLine("オーバーライド");
            Derived2 x2 = new Derived2();
            x2.show();
            x2.show2();

            Base2 x3 = x2;
            x3.show();
        }
    }
    public class Base
    {
        public Base()
        {
            Console.WriteLine("Base");
        }
        public Base(string name)
        {
            Console.WriteLine("名前付きBase.");
        }
        public void Show()
        {
            Console.WriteLine("Hello.");
        }
    }
    public class Derived : Base
    {
        public Derived() : base("")
        {
            Console.WriteLine("Derive.");
        }
        public void Show2()
        {
            base.Show(); //親クラスのメソッドの実行
            Console.WriteLine("hello2.");
        }
    }

    //オーバーライド
    public class Base2
    {
        public virtual void show()
        {
            Console.WriteLine("Show_Base2");
        }
        public void show2()
        {
            Console.WriteLine("Show2_Base2");
        }
    }
    public class Derived2 : Base2
    {
        public override void show()
        {
            Console.WriteLine("Show_Base2");
        }
        public new void show2()
        {
            Console.WriteLine("Show2_Base2");
        }
    }
}
