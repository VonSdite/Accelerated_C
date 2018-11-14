#include "iostream"
#include "string"
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	while(getline(cin,str,',')) 
	{
		cout<<str<<endl;
	}
	return 0;
}