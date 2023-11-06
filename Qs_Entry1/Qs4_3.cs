using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs4_3
    {
        static void Main(string[] args)
        {
            /*ジェネリックインターフェース*/
            Console.WriteLine("[ジェネリックインターフェース:]");
            Sample<string> sample = new Sample<string>();
            sample.Value = "gege";
            Console.WriteLine("{0}", sample.GetValue());

            //用意された型制約
            //C#に標準で用意されたイテレータを使った制約
            //ほかにもあるので、マイクロソフトのリファレンスで確認してください。
            static T Min<T>(T v1, T v2) where T : IComparable
            {
                return v1.CompareTo(v2) < 0 ? v1 : v2;
            }
            Console.WriteLine(Min(4, 5));
            Console.WriteLine(Min(4.5f,6.4f));
        }
    }

    /*ジェネリックインターフェース*/
    //ジェネリックで定義する事を矯正するインターフェースです。
    //ジェネリックインターフェースをジェネリッククラスで継承することもできます。
    class Sample<T> : IComponent<T>
    {
        public T Value { get; set; }
        public T GetValue() { return Value; }
    }
    interface IComponent<T>
    {
        T Value { get; set; }

        T GetValue() { return Value; }
    }

    //ジェネリックの型制約
    //ジェネリックはあらゆる型を指定できます。
    //しかし、使用できる型を制限したい場合もあります。
    //その際に型制約を使います。
    //例えば、受け取った値の比較をしてその結果を返すジェネリック型を作りたいとします。
    //しかし、全ての型だと比較できないものもあります。
    //そういう場合は型制約を行うということです。
    //構文:
    //where 型パラメータ名 : 型制約

    //struct制約
    //値型は全てstructという話がありました。
    //つまり、値型のみの制約です(stringなどの参照型は弾かれます).
    class temp1<T> where T : struct
    {

    }

    //class制約
    //参照型はすべてclassでした。なので、参照のみの制約
    class temp2<T> where T : class
    {

    }

    //型名による制約1
    //指定クラスを継承してるかどうかでの制約
    class temp3<T> where T : BaseClass
    {

    }

    //型名による制約2
    //指定インターフェースを継承しているかどうかでの制約
    class temp4<T> where T : A,B,C,D<T>
    {

    }

    //new制約
    //引数無しコンストラクタを持つ型のみを指定
    class temp5<T> where T : BaseClass,new()
    {

    }

    //生の制約
    //型パラメータに、異なる型パラメータの制約を指定することを生の型制約と呼びます。
    //以下の例だと、T2型を継承している型かどうかの制約ということです。
    class temp6<T1, T2> where T1 : T2 { }
    //部品
    class BaseClass { }
    interface A { }
    interface B { }
    interface C { }
    interface D<T> { }
}
