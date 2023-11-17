using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs4_2
    {
        static void Main(string[] args)
        {
            /*ジェネリック*/
            //C++ではテンプレートと呼ばれる機能です。
            //作成した機能で使用するデータ型を、使用時に任意に決定できる機能です。
            //コレクションもこのジェネリックによって実装されています。
            //任意に決定できる型を『メソッド名名<T>』で指定する。

            //ジェネリックメソッド
            void Swap<T>(ref T a, ref T b)
            {
                T temp = a;
                a = b;
                b = temp;
            }

            float a = 1.2f, b = 1.7f;
            Swap<float>(ref a, ref b);
            Console.WriteLine("{0},{1}", a, b);
        }

        //ジェネリッククラス
        Jene<int> temp = new Jene<int>();


        //タプルを用いた処理
        Tuple<string, int> user1 = new Tuple<string, int>();
        Tuple<string, int> user2 = new Tuple<string, int>();
        user1.Item1 = "tanaka"; user1.Item2 = 78;
            user2.Item1 = "tanaka"; user2.Item2 = 88;
    }
    //ジェネリッククラス
    //クラス内で使われる方を実装時に任意で設定できる。
    //任意に設定する型を『クラス名<T>』で指定する。
    //また、以下のような単純に複数の値を入れるようなクラスは
    //Tupleと一般的に呼ばれます。
    class Tuple<T1,T2>
    {
        public T1 Item1 { get; set; }
        public T1 Item2 { get; set; }
    }

    //ジェネリッククラス
    class Jene<T>
    {
        public T a;
        public T b;
    }
}
