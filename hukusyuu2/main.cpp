#include <iostream>

//クラスとポインタ
//大体構造体と同じ
class TestClass
{
public:
	TestClass();
	~TestClass();

	void print();
	//メンバー変数は本来安全のためprivateにするのが望ましいが
	//説明の都合上今回はpublicで
public:
	//説明の都合上、メンバーは４Byteの変数のみ使う
	int num0;     //4
	int num1;     //8
	float fnum0;  //12
	float fnum1;  //16

};
//コンストラクタ
TestClass::TestClass():
	num0(10),
	num1(20),
	fnum0(30.0f),
	fnum1(40.0f)
{

}
//デストラクタ
TestClass::~TestClass()
{

}
//メンバー変数の値を表示する
void TestClass::print()
{
	std::cout << "num1 = " << num1 << std::endl;
}


int main()
{
	//クラスはメモリ上にどのように配置される？
	TestClass testClass;

	//TestClassのデータサイズは？
	//sizeof演算子をしようしてサイズを確認する
	//クラスの場合も構造体と同じく、メンバ変数のみがメモリ上に配置される
	std::cout << "size =" << sizeof(testClass) << std::endl;

	//クラスのメンバ変数にアクセスする
	//ドット演算子を使用する
	std::cout << "num0 =" << testClass.num0 << std::endl;
	//クラスのメンバー変数を呼ぶ
	testClass.print();
	//クラスのポインタ
	//構造体やint型の変数と同じ
	TestClass* ptestClass =  &testClass;
	//ポインタからメンバー変数にアクセスする
	//構造体と同じくアロー演算子を使用する
	std::cout << "fnum0 = " << ptestClass->fnum1 << std::endl;
	//メンバー関数を呼ぶ
	//こちらもアロー演算子を使う
	ptestClass->print();




	return 0;

}

#if false
	//変数宣言を行ったとき、メモリ上に変数を保存するための領域が確保される
	// メモリ上のどこに配置されるかはわからない
	// わからないが配列は必ず順番に並んで確保される
	// 構造体は宣言した順番に並べて確保される

	//変数の宣言　メモリ上にintのサイズ分の領域が確保される
	int num = 4;
	//配列の宣言　intが3つ準備される　配列はメモリ上に並んで配置される
	int tbl[3] = { 1,2,3 };

	//構造体の宣言 構造体のメンバーは構造体を宣言したときに並べた順番にメモリ確保される
	StructTest test = 
	{
		10,     //num0
		20,     //num1
		30.0f,  //fnum0
		40.0f   //fnum1
	};
	//構造体の配列
	StructTest testTbl[3];

	//ポインタの宣言
	//ポインタ→アドレスを保存するための変数
	//データ型*　ポインタ名　　といった形式で宣言する
	//int* pNum;   //初期をしないとポインタの中にどんな数字が入っているかわからない
	int* pNum = nullptr;    //ポインタはnullptrで初期化するのが一般的

	//int型の変数numのアドレスを取得してpNumに保存したい
	pNum = &num;

	//pNumの中身（numのアドレス）を表示する
	std::cout << pNum << std::endl;

	//アドレスpNumの中に入っている数値を表示する
	if (pNum != nullptr)     //nullptrはどこもさしていないのでnullptrでないことを確認してから処理する
	{
		*pNum = 10; // ポインタが参照する先にデータを格納する
		std::cout << (*pNum) << std::endl;   //ポインタが参照する先のデータを表示する
	}
	//構造体軽く復習
	test.num0 = 16;
	std::cout << test.num0 << std::endl;



	//構造体のポインタ
	StructTest* pStructTest = &test;
	//pStructtestの表示
	std::cout << pStructTest << std::endl;
	//pStructTestが指し示す中身の表示
	//構造体のポインタからそのメンバーを参照したい場合、
	//ドット演算子(.)ではなくアロー演算子(->)を使用する
	std::cout << pStructTest->fnum0 << std::endl;

	return 0;
}
#endif