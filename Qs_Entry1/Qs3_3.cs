using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs3_3
    {
        static void Main(string[] args)
        {
            //ポリモーフィズム
            Vector v1 = new Vector();
            Vector v2 = new Vector2();
            Vector v3 = new Vector3();


            //継承の確認
            v1.Check();
            v2.Check();
            v3.Check();

            //オーバーロード
            v1 = new Vector(1, 2);
            v2 = new Vector2(v1);
            v3 = new Vector3(v2);
            v1.Show();
            v2.Show();
            v3.Show();

            Vector[] v = { new Vector(1,2), new Vector2(v1), new Vector3(v2) };
            foreach(var temp in v)
            {
                temp.Show();
            }

        }
    }

    public class Vector
    {
        protected float X { get; private set; }
        protected float Y { get; private set; }
        protected float Z { get; private set; }

        //親コンストラクタ
        public Vector() { X = 0; Y = 0; Z = 0; }
        public Vector(float x,float y) : this() { X = x; Y = y; Z = 0; }
        public Vector(float x,float y,float z) : this() { X = x;Y = y; Z = z; }
        public Vector(Vector v) : this() { X = v.X; Y = v.Y; Z = v.Z; }

        //親クラスメソッド
        public virtual void Show()
        {
            Console.WriteLine("x:" + X);
        }
        public void Check()
        {
            Console.WriteLine("継承されています");
        }

    }
    public class Vector2 : Vector
    {
        public Vector2() : base() {}
        public Vector2(float x,float y) : base(x, y) { }
        public Vector2(Vector v) : base(v) { }

        public override void Show()
        {
            Console.WriteLine("x:" + this.X + ",y" + this.Y);
        }
    }
    public class Vector3 : Vector
    {
        public Vector3() : base() { }
        public Vector3(float x, float y) : base(x, y) { }
        public Vector3(Vector v) : base(v) { }

        public override void Show()
        {
            Console.WriteLine("x:" + this.X + ",y" + this.Y);
        }
    }
}
