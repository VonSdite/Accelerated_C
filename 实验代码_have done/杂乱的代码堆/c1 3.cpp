#include "iostream"
#include "string"
using namespace std;
int main(int argc, char const *argv[])
{
	{
		string s = "a string";
		{
			string x=s+",really";
			cout<<s<<endl;
		}
		//cout<<x<<endl;
	}
	return 0;
}