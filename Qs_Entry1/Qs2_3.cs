using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs2_3
    {
        static void Main(string[] args)
        {
            //カプセルか
            Console.WriteLine("カプセル化");
            Sample sample = new Sample("Ohara", 43, "学校法人となってからの年齢が入っています");
            Console.WriteLine("Name: {0}", sample.Name);

            Console.WriteLine("Age: {0}", sample.Age);
            Console.WriteLine("Comment: {0}", sample.Comment);
            sample.Comment = "簿記公の創立はもっと前です";
            Console.WriteLine("Comment: {0}", sample.Comment);

            //partialクラス
            Console.WriteLine("partialクラス");
            Echo echo = new Echo();
            echo.Message = "hello";
            echo.ShowMessage();
        }
    }

    //カプセル化
    public class Sample
    {
        private string _name = "";
        private int _age = 0;
        public string Comment = "";

        public string Name { get { return _name; } }
        public int Age { get { return _age; } }

        public Sample() { }
        public Sample(string name, int age, string com)
        {
            _name = name;
            _age = age;
            Comment = com;
        }
    }

    //partialクラス
    public partial class Echo
    {
        public string Message { get; set; } = "";
    }
    public partial class Echo
    {
        public void ShowMessage()
        {
            Console.WriteLine(Message);
        }
    }

}
