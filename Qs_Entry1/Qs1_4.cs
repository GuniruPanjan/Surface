using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    /*構造体
     * 構造体は参照型ではなく、値型である
     * C#において、intやfloatなどの値型の型は
     * enum（列挙型）を除きすべて構造体で作られている
     * だからフィールド（メンバ変数）とかメソッド（メンバ関数）とか持つ
     * 例：int.Parse(),配列名.Length　など*/

    /*使いどころ
     * 参照型の機能が必要ない場合、クラスより構造体として定義した方が効率的です
     * 同じ機能のクラスと構造体を100万個ずつインスタンス化した場合
     * 単純にインスタンス化するだけならクラスが約100msに対して構造体では30msと処理時間が短くなります
     * 例えば*/
    internal class Qs1_4
    {
        static void Main(string[] args)
        {
            Enemy enemy;
            //変数ごとに初期化していく
            enemy.X = 1;
            enemy.Y = 2;
            enemy.Z = 3;
            Console.WriteLine("[enemyの確認：]");
            Console.WriteLine("x:" + enemy.X + ",y:" + enemy.Y + ",z:" + enemy.Z);
            Console.WriteLine(enemy.AllAdd());

            //引数付きコンストラクタを用いて一括で初期する
            Enemy enemy2 = new Enemy(2, 3, 4);
            Console.WriteLine("[enemy2の確認:]");
            Console.WriteLine("x:" + enemy2.X + ",y:" + enemy2.Y + ",z:" + enemy2.Z);
            Console.WriteLine("AllAdd:" + enemy2.AllAdd());

            Enemy enemy3 = enemy2;

            //初期化
            enemy3.X = 1;
            enemy3.Y = 2;
            enemy3.Z = 3;
            Console.WriteLine("enemy3:" + "x:" + enemy3.X + ",y:" + enemy3.Y + ",z:" + enemy3.Z);
            Console.WriteLine("enemy2:" + "x:" + enemy2.X + ",y:" + enemy2.Y + ",z:" + enemy2.Z);

            //構造体か？　クラスか？　の例
            Enemy enemy4 = new Enemy(2, 3, 4);
            int temp = 0;

            enemy4.X = temp;
            temp = enemy4.Y;
            temp = 0;
            enemy4.Z = temp;

            //このような処理なら、クラス
            Enemy tempEnemy;
            tempEnemy = enemy;
            tempEnemy = enemy2;
            tempEnemy = enemy3;
            tempEnemy = enemy4;
        }
    }

    //大量の雑魚ポップを構造体で表現する
    public struct Enemy
    {
        public int X;
        public int Y;
        public int Z;

        //public itn z = 1;//フィールド初期化子は使えない

        //コンストラクタ
        public Enemy(int x, int y, int z)
        {
            X = x; Y = y; Z = z;
        }

        //メソッド
        public float AllAdd()
        {
            return 0;
        }
    }
}
