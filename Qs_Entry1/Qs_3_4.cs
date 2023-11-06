using Qs_Entry1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    

    internal class Qs_3_4
    {
        static void Main(string[] args)
        {
            //抽象クラス
            Console.WriteLine("抽象クラス");
            Slime ene1 = new Slime();
            Goblin ene2 = new Goblin();
            ene1.Show();
            ene2.Show();
            ene1.Attack();
            ene2.Attack();

            //インターフェース
            Console.WriteLine("インターフェース");
            Ihp[] hps = { new CreePeer(), new Block() };
            foreach(var hp in hps)
            {
                hp.Damage(1);
                hp.Show();
                hp.Damage(2);
                hp.Show();
            }
        }
    }

    //抽象クラス

    abstract class Enemy
    {
        //抽象プロパティ
        abstract public string Name { get; }
        abstract public int Level { get; }
        //抽象メソッド
        public abstract void Attack();

        //実装済みメソッド
        public void Show()
        {
            Console.WriteLine(Name);
            Console.WriteLine(Level);
        }
    }
    class Slime : Enemy
    {
        public override string Name { get { return "スライム"; } }
        public override int Level { get {return 4; } }
        //抽象メソッドの実装
        public override void Attack()
        {
            Console.WriteLine("28のダメージ！\n");
        }
    }
    class Goblin : Enemy
    {
        public override string Name { get { return "ゴブリン"; } }
        public override int Level { get { return 8; } }
        public override void Attack()
        {
            Console.WriteLine("38のダメージ！\n");
        }
    }

    //インターフェース
    interface Ihp
    {
        void Damage(int a);
        void Show();
    }
    interface IName
    {
        void SetName(string name);
    }
    class CreePeer : Ihp , IName
    {
        private int _hp = 10;
        private string _name = "";

        public void SetName(string name)
        {
            _name = name;
        }

        public void Damage(int a)
        {
            _hp = _hp - a;
        }
        public void Show()
        {
            Console.WriteLine(Damage);
            Console.WriteLine(_hp);
        }
    }
}
class Block : Ihp
{
    private int _hp = 10;

    public void Damage(int a)
    {
        _hp = _hp - a * 2;
    }

}
