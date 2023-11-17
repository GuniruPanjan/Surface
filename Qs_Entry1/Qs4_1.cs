
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Qs_Entry1
{
    internal class Qs4_1
    {
        static void Main(string[] args)
        {
            //宣言と初期化
            List<string> list = new List<string>();

            //要素の追加
            list.Add("one");
            //配列ごとに入れる
            string[] insert = { "two", "three" };
            list.AddRange(insert);

            //確認
            foreach(string item in list) { Console.WriteLine(item); }

            //要素の削除
            list.Remove("two");

            //要素を入れ替えて挿入
            list.Insert(1, "3");
            list.Insert(1, "3");
            list.Insert(1, "3");

            list.RemoveAt(3);

            foreach (string item in list) { Console.WriteLine(item); }
            Console.WriteLine(list.Count);

            Console.WriteLine("要素への単純アクセス");
            foreach (string item in list) { Console.WriteLine(item); }

            //クラスを型指定することも出来ます
            Dictionary<string, GameObject> GameObjectList = new Dictionary<string, GameObject>();
            //インスタンスの格納
            GameObjectList.Add("tanaka", new GameObject("tanaka", 80));
            GameObjectList.Add("masaru", new GameObject("masaru", 64));
            //確認
            Console.WriteLine("クラスを格納したコレクション");
            GameObject temp = GameObjectList["tanaka"];
            Console.WriteLine("{0}{1}", temp.Name, temp.Hp);
            temp = GameObjectList["masaru"];
            Console.WriteLine("{0}{1}", temp.Name, temp.Hp);

            Queue<GameObject> blockList = new Queue<GameObject>();
            //インスタンスの格納
            blockList.Enqueue(new GameObject("first", 1));
            blockList.Enqueue(new GameObject("second", 2));
            blockList.Enqueue(new GameObject("third", 3));
            //確認
            Console.WriteLine("[Queueの例:]");
            Console.WriteLine(blockList.Dequeue().Name);
            Console.WriteLine(blockList.Dequeue().Name);
            Console.WriteLine(blockList.Dequeue().Name);

            // Stackの例(LIFO):
            //一つ前の状態に戻すときなどに使用
            Stack<GameObject> stack = new Stack<GameObject>();
            //インスタンスの格納
            stack.Push(new GameObject("first", 1));
            stack.Push(new GameObject("second", 2));
            stack.Push(new GameObject("third", 3));
            //確認
            Console.WriteLine("[Stackの例:]");
            Console.WriteLine(stack.Pop().Name);
            Console.WriteLine(stack.Pop().Name);
            Console.WriteLine(stack.Pop().Name);

            //ランキングの例
            //<key(int),Value(GameObject)>
            SortedDictionary<int, GameObject> ranking = new SortedDictionary<int, GameObject>();
            //ランキングデータの挿入
            ranking.Add(98, new GameObject("tanaka", 98));
            ranking.Add(88, new GameObject("shitamichi", 88));
            ranking.Add(99, new GameObject("uehara", 99));

            //降順で並び変え

            //確認
            Console.WriteLine("ランキングの例");
            foreach(var temp2 in ranking)
            {
                Console.WriteLine("名前：{0},得点{1}", temp2.Value.Name, temp2.Key);
            }

        }
    }

    public class GameObject
    {
        public string Name { get; }
        public int Hp { get; }

        public GameObject()
        {
            Hp = 0;
            Name = "noName";
        }
        public GameObject(string name, int hp)
        {
            Name = name;
            Hp = hp;
        }

    }
}
