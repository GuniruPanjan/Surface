
/*素数の計算課題２*/
Console.WriteLine("0以上の自然数を入力してください");
string input = Console.ReadLine();
int num = int.Parse(input);
int i ;
int sum;
int count = 0;
bool flag;

for (i = 2; i <= num ; i++)
{
    while (count < i)
    {

        if ((i % count) == 0)
        {
            flag = false;
        }

        count++;


      
    }
    if(flag)
    {

    }
}










/*素数の計算課題１
Console.WriteLine("[0以上の自然数を入力してください]");
string input = Console.ReadLine();//宣言と同時に取得できる
int num = int.Parse(input);//同士
int i;

for(i = 2; i <= num / 2; i++)
{
    if((num % i) == 0)
    {
        break;
    }
}

if(i > (num / 2))
{
    Console.WriteLine("{0}は素数である", num);
}
else
{
    Console.WriteLine("{0}は素数ではない", num);
}
*/







/*入力
string input = Console.ReadLine();//宣言と同時に取得もできる
int num = int.Parse(input);//同士

//while文
Console.WriteLine("[while文]");
int count = 0;
while(count<num)
{
    Console.WriteLine(count);
    count++;
}

//do～while文
Console.WriteLine("[do～while文]");
count = 0;
do
{
    Console.WriteLine(count);
    count++;
} while (count < num);

//for文
Console.WriteLine("[for文]");
for(int i = 0; i < num; i++)
{
    Console.WriteLine(i);
}

//foreach文
//配列の作成
int[] arr = { 0, 1, 2, 3, 4, 5 };
Console.WriteLine("[foreach文{0, 1, 2, 3, 4, 5}]");
foreach(var n in arr)
{
    Console.WriteLine(n);
}
*/




/*if文
Console.WriteLine("[if文]");
//入力
string input = Console.ReadLine();//宣言と同時に取得できる
int num = int.Parse(input);//同上

//比較演算子6種
if (num == 3)
{
    Console.WriteLine("input is 3");
}
if (num != 3)
{
    Console.WriteLine("input is not 3");
}
if (num > 3)
{
    Console.WriteLine("input is bigger 3");
}
if (num < 3)
{
    Console.WriteLine("input is smaller 3");
}
if (num >= 3)
{
    Console.WriteLine("input is over 3");
}
if (num <= 3)
{
    Console.WriteLine("input is under 3");
}

//if～else if～else文
Console.WriteLine("[if～else if～else文]");
//入力
input = Console.ReadLine();//宣言と同時に取得できる
num = int.Parse(input);//同士

//条件分岐
if(num < 3)
{
    Console.WriteLine("input is smaller 3");
}
else if (num > 3)
{
    Console.WriteLine("input is bigger 3");
}
else
{
    Console.WriteLine("input is 3");
}

//swtich文
Console.WriteLine("[switch文]");
//入力
input = Console.ReadLine();//宣言と同時に取得もできる
num = int.Parse(input);//同士

//条件分岐
switch(num)
{
    case 0:
    case 1:
    case 2:
        Console.WriteLine("input is 0～2");
        break;
    case 3:
        Console.WriteLine("input is 3");
        break;
    default:
        Console.WriteLine("input is bigger 3");
        break;

}

//[&&]カツ、と、[||]オア
Console.WriteLine("[&&]カツ、と、[||]オア");
//入力
input = Console.ReadLine();//宣言と同時に取得できる
num = int.Parse(input);//同士

//条件分岐
if (num>2 && num<4)
{
    Console.WriteLine("inputは2以上かつ4以下なので、3である");
}
if(num<2 || num>8)
{
    Console.WriteLine("inputは2より小さいか8より大きいので、2～8ではない");
}
*/


/*入力
string input = Console.ReadLine();
int num = int.Parse(input);

//while
int ans = 0;
int count = 0;//カウント変数
while (count <= num)
{
    ans = ans + count;
    count++;//カウンタ変数の更新
}
Console.WriteLine("while:0～{0}までの合計は{1}", num, ans);

//do～while
ans = 0;
count = 0;
do
{
    ans = ans + count;
    count++;
} while (count <= num);
Console.WriteLine("do～while:0～{0}までの合計は{1}", num, ans);

//for
ans = 0;
for (int i= 0; i <= num; i++)
{
    ans = ans + i;
}
Console.WriteLine("for:0～{0}までの合計は{1}",num , ans);

//foreach
ans = 0;
int[] arr = { 1, 2, 3, 4 };
foreach(var n in arr)
{
    ans = ans + n;
}
Console.WriteLine("配列arrの要素数は{0}であり、要素の合計は{1}", arr.Length, ans);
*/




/*入力
string input = Console.ReadLine();
int num = int.Parse(input);

条件分岐if～else
if (num <= 3)
{
    Console.WriteLine("3より小さいです。");
}
else if(num <= 5)
{
    Console.WriteLine("3～5です。");
}
else
{
    Console.WriteLine("5よりも大きいです。");
}

奇数か偶数かのチェック
bool flag = ((num % 2) == 1);

条件分岐switch文
switch(flag)
{
    case true:
        Console.WriteLine("奇数です。");
        break;
    case false:
        Console.WriteLine("偶数です。");
        break;
    default:
        Console.WriteLine("ここには到達できません。");
        break;
}
*/