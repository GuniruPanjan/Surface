using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static Vector2;

namespace Qs_Entry1
{
    internal class Qs1_3
    {
        static void Main(string[] args)
        {
            //クラスの基本
            Console.WriteLine("[クラスの基本:]");

            Vector2 v1 = new Vector2();
            Vector2 v2 = new Vector2(2.0f, 2.0f);
            Console.WriteLine("v1:" + v1.OutStaring());
            Console.WriteLine("v2:" + v2.OutStaring());
            //publicは外からアクセス可能
            v1.X = 1.0f;
            v1.Y = 2.0f;
            //メンバ変数は各インスタンスからアクセスできる
            Console.WriteLine("v1(長さ):" + v1.Legnth());
            Console.WriteLine("v2(長さ):" + v2.Legnth());

            //Vector2型ではなく値型でなく、参照型であることの確認
            Console.WriteLine("[参照型であることの確認:]");
            //参照型ならばv1とv2は同じものになる
            //値型ならば
            v1 = v2;
            Console.WriteLine("v1(=直後):" + v1.OutStaring());
            
            v2.Y = 1.0f;
            Console.WriteLine("v1(=直後):" + v1.OutStaring());

            //プロパティを持つクラス
            Console.WriteLine("[プロパティを持つクラス:]");
            Enemy ene = new Enemy();
            Console.WriteLine("ene(初期):" + ene.OutString());
            ene.Hp = 6;
            //HPが減少するとAtも上昇
            Console.WriteLine("ene(Hp減少):" + ene.OutString());
            //ene.At = 8; Atは読み取り専用で、コメント外すとエラー

            //自動実装プロパティ
            Console.WriteLine("[自動実装プロパティ：]");
            Enemy2 ene2 = new Enemy2();

        }
    }
}

/*クラスの基本
 * クラスは基本的には以下の４つで構成されています
 * フィールド(メンバ変数)
 * コンストラクタ
 * デストラクタ
 * メソッド
 * ここに関してはＣ++と同じです
 * Ｃ＃のクラスで最も注意すべき点は
 * Ｃ++と違って値型がなく、参照型しかないということです
 * つまり、*とかつけなくても常にクラス変数はポインタです
 * 例外はありますが、基本的に参照渡ししかできませんので注意しましょう*/

//Vector2
public class Vector2
{
    //フィールド（メンバ変数）
    public float X;
    public float Y;

    //コンストラクタ
    public Vector2()
    {
        X = 0;
        Y = 0;
    }
    public Vector2(float x, float y)
    {
        //自分自身のポインタです　引数と名前が被ったりしたときに使用
        this.X = x;
        this.Y = y;
    }

    //デストラクタ
    ~Vector2()
    {
        /*メモリ管理を自分で行うC++では
         * 大変便利なデストラクタだが、C#ではほとんど役にたたない
         * なぜならC#にはガベージコレクションという機能があり
         * メモリ管理はそれが行うため、いつデストラクタが呼ばれるか予測不能である
         * なので必要になったときのために書き方を知っておく程度でよい*/
    }

    //メソッド
    //長さを返す
    public float Legnth()
    {
        //平方根の計算
        return MathF.Sqrt(X * X + Y * Y);
    }
    //成分の値を文字列に返す
    public string OutStaring()
    {
        return "X" + X.ToString() + ",Y" + Y.ToString();
    }

    /*プロパティを持つクラス
     * C#ではクラスはプロパティを持つことが出来ます
     * プロパティとは
     * クラス外部から見るとメンバー変数のようにふるまい
     * クラス内部から見るとメソッドのように振る舞うものです
     * つまり、メンバ変数の値を変えたり、与えたりする際に
     * 決められてた行動を起こすことが出来ます
     * Ｃ＋＋ではgetterとかstterという形でメンバ変数で実装されることが多いです*/

    //プロパティをもつクラスの例
    //ＨＰが減ると攻撃力が上がるエネミー
    public class Enemy
    {
        private int _hp = 8;
        private int _at = 8;

        //プロパティ
        public int Hp
        {
            //外部に渡すときの処理
            get { return _hp; }

            //外部から値を受け取るときの処理
            set
            {
                _at += _hp - value; //hpが減ると攻撃力も増加する
                _hp = value;
            }
        }
        public int At
        {
            get { return _at; }
            //setがないので、外部から_atを変更することは出来ない
        }
        public string OutString()
        {
            return "Hp:" + _hp.ToString() + ",At:" + _at.ToString();
        }

    }

    //自動実装プロパティ
    public class Enemy2
    {
        //自動実装プロパティ
        public int Hp { get; set; } = 8;//読み込み書き込み可
        public int At { get; }//読み込み可、書き込み不可


    }
}
