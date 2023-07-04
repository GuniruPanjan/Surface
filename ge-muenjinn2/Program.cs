



/*課題６
void P(int i)
{
    
    for (int j = 1; j <= 9; j++)
    {
       Console.Write("{0},", i * j);
       
    }
    Console.WriteLine("\n");
}

 P(int.Parse(Console.ReadLine()));
*/

/*課題５
void P(int a)
{
    for (int j = 0; j < a; j++)
    {
        for (int i = 0; i < (j + 1); i++)
        {
            Console.Write("$");
        }
        Console.WriteLine("");
    }

    return;

}


 P(3);
 P(4);
 P(5);
*/









/*課題４
int[] ar1= { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
for(int i = 0; i < 10; i++)
{
    Console.WriteLine("a[{0}] = {1}",i, ar1[i]);
}
*/







/*課題３
int a = 1;
do
{
    Console.WriteLine("a = {0}", a);
    a++;
}
while (a <= 10);
*/





/*課題２
Console.Write("整数を入力：");
int num = int.Parse(Console.ReadLine());
for(int i = 1; i <= num; i++)
{
    if(num % i == 0)
    {
        Console.WriteLine("{0}",i);
    }
}
*/




/*課題１
for(int i = 0; i < 10; i++)
{
    Console.WriteLine("HelloC#");
    
}
*/


/*復習２
//関数は引数を渡し、返り値を得る
//例えば、足し算をする関数Aがあるとすると
//Ａに引数：１，２を渡せば、返り値：３を得る
//というような事である。
//【以下、文法】
//返り値の型　関数名（引数の型　引数名）｛処理｝
//【文法終了】
//整数の足し算を行う関数
int IAdd(int a, int b)
{
    int ans;
    ans = a + b;
    return ans;
}
//整数の引き算を行う関数
int ISub(int a, int b)
{
    int ans;
    ans = a - b;
    return ans;
}
//実数の足し算
double DAdd(double a, double b)
{
    double ans;
    ans = a + b;
    return ans;
}
//実数の引き算
double DSub(double a, double b)
{
    double ans;
    ans = a - b;
    return ans;
}
//文字列の足し算
string SAdd(string a, string b)
{
    string ans;
    ans = a + b;
    return ans;
}
//配列の値の合計
int ASUM(int[] a)
{
    int ans = 0;
    //forでもかけるが、foreachだと超楽
    foreach(int s in a)
    {
        ans += s;
    }
    return ans;

}

//【関数の実行】
int i_kaerichi;
double d_kaerichi;
string s_kaerichi;
//IADD
i_kaerichi = IAdd(1, 2);//Addの処理でreturnした結果（ans)をkaerichiに入れてる
Console.WriteLine(i_kaerichi);
//ISub
d_kaerichi = ISub(2, 1);
Console.WriteLine(d_kaerichi);
//DADD
d_kaerichi = DAdd(1.24, 2.4);
Console.WriteLine(d_kaerichi);
//DSub
d_kaerichi = DSub(2.45, 0.43);
Console.WriteLine(d_kaerichi);
//SAdd
s_kaerichi = SAdd("age", "Age");
Console.WriteLine(s_kaerichi);
//ASUM
int[] arr = { 1, 2, 3 };
i_kaerichi = ASUM(arr);
Console.WriteLine(i_kaerichi);
*/



/*復習１
//変数の作成（宣言）
int a;//整数型（小：-2147483648 ～ 2147483647)
long b;//整数型（大：-922337203685477508 ～ 922337203685477507)
float c;//実数（小：桁数が小さい（８桁くらい））
double d;//実数（大：桁数が大きい（１６桁くらい））
char e;//文字（小：一文字だけ）
string f;//文字列（大：複数文字）

//変数の初期化（最初の値を代入）
a = 2147483640;
b = 21474836400;
c = 1.24f;//実数は基本はdobule型なので、float型に変換する
d = 1.23456789009876;
e = 'あ';//char柄の一文字を表すときは''でくくる
f = "あばばば";//複数文字（文字列）を表すときは""でくくる

//変数の宣言と初期化を同時に行う（全ての変数でできる。例として、intとdoubleでやる）
int g = 2;
double h = 2.345;
int i = 2, j = 4, k = 5;//複数同時にもできる
double l = 2.3, m = 3.4, n = 4.5;

//データの表示（基本）
Console.WriteLine("hey");//改行して表示
Console.Write("hey");//改行せずに表示
Console.Write("hey");//改行せずに表示

//データの表示（変数の表示）
Console.WriteLine(a);//変数aの中身が表示される
Console.WriteLine("{0},{1}",a, b);//変数bが{1}に表示される
Console.WriteLine("あばば{0}あばべ{1}", a, b);//変数aが{0}に、変数ｂが{1}に表示される
Console.WriteLine(a + b);//a+bの計算結果が表示される（つまり解散結果を表示できる）

//計算（整数でやるが、実数も同じ）
int ans = 0, va1 = 1, val2 = 2;
ans = va1 + val2;//足し算
ans = va1 - val2;//引き算
ans = va1 * val2;//掛け算
ans = va1 / val2;//割り算
ans = va1 % val2;//余りの計算

//配列の作成（整数でやるが、実数も同じ）
int[] ar;

//配列の初期化（要素５の配列を作成）
ar = new int[5];

//配列の宣言と初期化を同時に
int[] ar2 = new int[5];//中身の無い配列をつくる場合
int[] ar3 = { 1, 2, 3, 4, 5 };//中身も同時に作る場合

//if文
Console.WriteLine("数値を入力してください：");
int num = int.Parse(Console.ReadLine());
if(num ==0)
{
    Console.WriteLine(num); 
}
else if(num == 1)
{
    Console.WriteLine(num);
}
else
{
    Console.WriteLine(num);
}

//switch文
Console.WriteLine("数値を入力してください：");
num = int.Parse(Console.ReadLine());
switch (num)
{
    case 0:
    case 1:
    case 2:
        Console.WriteLine("0～2です。");
        break;
    case 3:
        Console.WriteLine("3です。");
        break;
    default:
        Console.WriteLine("0～3以外です。");
        break;

}

//roop1:while
int count = 0;//ループカウンタとして作成
while(count < 5)//5回ループ
{
    Console.WriteLine("while:{0}回目", count);
    count++;
}

//roop2:for
for(int s = 0; s < 5; s++)
{
    Console.WriteLine("for:{0}回目", s);
}

//roop3:foreach(要素全てを吐き出すまでループ）
int[] ar4 = { 1, 2, 3 };
//ar4の中の要素が1ループ毎にvに入る）
//つまり、1週目は、２週目はv=ar4[1],3週目はv=ar[2]
foreach(var v in ar4)
{
    Console.WriteLine("foreach:{0}", v);
}
*/