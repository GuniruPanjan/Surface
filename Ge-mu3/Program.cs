//関数の定義


/*演習２課題
using System.IO.Pipes;

int getPos(int firstX, int firstSpeed, int accel, int second)
{
    int pos = 0;


    //物理で習う式のまま
    pos = (accel * second * second / 2) + firstSpeed * second + firstX; 


    return pos;
}

//入力
Console.WriteLine("初期位置：");
int firstX = int.Parse(Console.ReadLine());
Console.WriteLine("初速度：");
int firstSpeed = int.Parse(Console.ReadLine());
Console.WriteLine("加速度：");
int accel = int.Parse(Console.ReadLine());
Console.WriteLine("秒数：");
int second = int.Parse(Console.ReadLine());

int ans = getPos(firstX, firstSpeed, accel, second);

Console.WriteLine("物体の位置：{0}", ans);
*/
/*//課題２
int Gcd(int a, int b)
{
    int small;
    int ans = 0;
   if(a == 0)
    {
        return b;
    }

   if(b == 0)
    {
        return a;
    }

   if(a > b)
    {
        small = b;
    }
   else
    {
        small = a;
    }

   for(int i = small; i > 0; i--)
    {
        if(a % i == 0 && b % i == 0)
        {
            ans = i;
            break;
        }
    }

    return ans;
}

//関数の実行
Console.WriteLine(Gcd(18, 12));
Console.WriteLine(Gcd(180, 127));
Console.WriteLine(Gcd(80, 64));
*/






/*//課題１
bool CheckPrime(int i)
{

    bool ans = 0;

    for (int num = 2; num <= i; num++)
    {


        if ((i % num) == 0)
        {
            break;
        }

        if (num > (i / 2))
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    return ans;
}



//関数の実行
Console.WriteLine(CheckPrime(17));
Console.WriteLine(CheckPrime(27));
Console.WriteLine(CheckPrime(3511));
*/


/*//三角形の面積をだす関数
int TriangleArea(int x, int y)
{
    //結果を入れる変数
    int ans;

    ans = (x * y) / 2;

    return ans;
}

//関数の実行
int ans;

ans = TriangleArea(4, 6);

Console.WriteLine(ans);
*/

/*//n^m乗をだす関数
int Pow(int n, int m)
{
    int ans = 1;//掛け算ができるように１を入れておく

    for(int i = 0; i < m; i++)
    {
        ans *= n;
    }

    return ans;
}

//関数の実行
int ansInt;

ansInt = Pow(3, 3);

Console.WriteLine(ansInt);
*/
/*//配列の合計を計算する関数
int SumArr(int[] input)
{
    int ans = 0;

    foreach(int temp in input)
    {
        ans += temp;
    }

    return ans;
}

//関数の実行
int ans;
int[] input = { 1, 2, 3, 4, 5 };

ans = SumArr(input);

Console.WriteLine(ans);
*/
/*//break文
for (int i = 0; i < 100; i++)
{
    Console.WriteLine("{0}", i);
        if(i == 10)
    {
        break;
    }
}
*/


