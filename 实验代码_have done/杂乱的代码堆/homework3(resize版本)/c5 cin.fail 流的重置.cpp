#include "iostream"
#include "limits"

using namespace std;

int main(int argc, char const *argv[])
{
	int a;
	while(1)
	{
		cin>>a;
		cout<<"hah";
		int flag=1;

		//如果遇到 非EOF导致的 流错误， 则需要执行 cin.ignore
		if(cin.eof()) flag=0;
		cin.clear();
		if(flag) cin.ignore(numeric_limits<int>::max(), '\n');


		// cin.sync();
	}
	return 0;
}