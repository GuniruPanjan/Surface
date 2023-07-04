namespace Csya_pu4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //インスタンスの作成
            //引数無しコントラクタ
            Test a = new Test();
            //引数ありコントラクタ
            Test b = new Test(8);
            //確認
            a.Show();
            b.Show();
        }
    }
    public class Test
    {
        //メンバ変数
        int state = 0;
        //コンストラクタ
        //引数無しコンストラクタ

        public Test() { }
        //引数ありコンストラクタ

        public Test(int input)
        {
            state = input;
        }
        //メンバ変数
        public void Show()
        {
            Console.WriteLine(state);
        }
    }

}