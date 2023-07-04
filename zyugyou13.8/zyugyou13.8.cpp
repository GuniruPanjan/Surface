#include<iostream>
using namespace std;

int main()
{
	bool isFlag = true;
#if false
	if (isFlag)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
#else
	//3€‰‰ŽZŽq‚ðŽg‚Á‚Ä‘‚«Š·‚¦
	cout << (isFlag ? "TRUE" : "FALSE") << endl;
#endif


	return 0;
}