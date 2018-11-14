#include "iostream"
#include "string"
using namespace std;
int main(int argc, char const *argv[])
{
	cout<<"Please enter your first name:";
	string name;
	cin>>name;
	const string hello = "hello";
	const string Hello = hello + "jaj";
	const string greeting = "Hello, " + name + "!";
	const string spcaces(greeting.size()+2,' '); 
	const string second = "*" + spcaces + "*";
	const string first(second.size(), '*');
	cout<<first<<endl;
	cout<<second<<endl;
	cout<<"* "<<greeting<<" *"<<endl;
	cout<<second<<endl;
	cout<<first<<endl;
	return 0;
}