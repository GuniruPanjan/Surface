using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Intrinsics;
using System.Text;
using System.Threading.Tasks;

namespace Qs2_Entry2
{
    internal class Qs2_pro
    {
        static void Main(string[] args)
        {
            /*問題1(等速運動と等加速度運動)*/
            Console.WriteLine("【問題1(等速運動と等加速度運動)：】");
            Vector2 obj = new Vector2();
            Vector2 speed = new Vector2(1.2f, 1.4f);//初速。秒速(/s)
            Vector2 accel = new Vector2(0.1f, 0.2f);//加速度
            Vector2 temp;
            //計算
            temp = obj + speed * 3;
            Console.WriteLine("・初速speed(1.2f,1.4f)で3秒間等速運動:\n" + temp.OutString());
            temp = speed * 3 + (accel * 3 * 3) / 2;
            Console.WriteLine("・初速speed(1.2f,1.4f), 加速度accel(0.1f,0.2f)で3秒間等加速度運動:\n" + temp.OutString());


            /*問題2(放物線運動)*/
            Console.WriteLine("【問題2(放物線運動)：】");
            Vector2 gravity = new Vector2(0, -9.8f);
            speed.Set(1.0f, 24.0f);//(/s)
            accel.Set(0.0f, 0.0f);//(/s)

            //60fpsの世界にする
            gravity = gravity / 60;
            accel = accel / 60;

            //計算
            for (int time = 1; true; time++)
            {
                //現在の速度
                speed = speed + gravity + accel;

                //現在のオブジェクトの位置
                obj = obj + speed;

                //obj位置
                //Console.WriteLine(speed.OutString() + " " + (float)time / 60);

                //地面に付いたかの判定                
                if (speed.Y <= 0.0f)
                {
                    Console.WriteLine("物体が地面に付くのに{0}秒以上掛かりました。", (float)time / 60);
                    break;
                }


            }
        }

        //2Dゲーム向けベクタークラスの作成
        public class Vector2
        {
            //フィールド
            private float _x;
            private float _y;

            //staticフィールド
            public static Vector2 zero = new Vector2();//ゼロベクトル
            public static Vector2 one = new Vector2(1, 1);
            public static Vector2 up = new Vector2(0, 1);
            public static Vector2 left = new Vector2(-1, 0);
            public static Vector2 down = new Vector2(0, -1);
            public static Vector2 right = new Vector2(1, 0);

            //プロパティ
            public float X { get { return _x; } }
            public float Y { get { return _y; } }
            public float Magnitude  //ベクトルの大きさを返す
            {
                get
                {
                    return MathF.Sqrt(X * X + Y * Y);
                }
            }
            public float SqrMagnitude  //ベクトルの大きさの２乗を返す
            {
                get
                {
                    return X * X + Y * Y;
                }
            }
            public Vector2 Nomalized  //単位ベクトルを返す
            {
                get
                {
                    return new Vector2(_x / Magnitude, _y / Magnitude);
                }
            }


            //コンストラクタ
            public Vector2()
            {
                _x = 0;_y = 0;
            }
            public Vector2(float x,float y)
            {
                _x = x; _y = y;
            }

            //public
            public string Outstring()
            {
                return "x" + this._x + "y" + this._y + ",magnitude:" + this.Magnitude;
            }
            public void Set(float x,float y)
            {
                _x = x;
                _y = y;
            }

            //static metho
            public static float Dot(Vector2 v1, Vector2 v2)
            {
                return v1.X * v2.X + v1.Y * v2.Y;
            }
            public static float Angle(Vector2 v1,Vector2 v2)
            {
                float angle = 0;
                float cosTheta = 0;

                //コサインΘを出す
                //内積
                cosTheta = Dot(v1, v2) / (v1.Magnitude * v2.Magnitude);
                //コサインΘから角度を出す
                angle = MathF.Acos(cosTheta);

                return angle;
            }
            public static float Distance(Vector2 v1, Vector2 v2) //距離
            {
                //2点間の距離なので、2点間を結ぶベクトルの長さと同じ
                //(v2-v1).Magunitude;でも同じ
                return (v1 - v2).Magnitude;
            }
            public static float Scale(Vector2 v1, Vector2 v2)//等倍等宿ではない　拡大縮小（アダマール積）
            {
                return new Vector2(v1.X * v2.X, v1.Y * v2.Y);
            }
            public static Vector2 Prependicular(Vector2 v1)
            {
                return new Vector2(-v1.Y, v1.X);
            }
            //法線を基準にした反射ベクトル
            public static Vector2 Reflect(Vector2 v1,Vector2 nVec)
            {
                //反射するための基準ベクトルを法線ベクトルから作成
                Vector2 nV = v1 * Dot(v1,nVec);

                return 2 * nV - v1;
            }


            //演算子オーバーロード
            public static Vector2 operator-(Vector2 left,Vector2 right)
            {
                return new Vector2(left.X - right.X, left.Y - right.Y);
            }
            public static Vector2 operator *(Vector2 left, float right)
            {
                return new Vector2(left.X * right, left.Y * right);
            }
            public static Vector2 operator *(float left, Vector2 right)
            {
                return new Vector2(left * right.X, left * right.Y);
            }
        }
    }
}