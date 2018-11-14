#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

istream& read_word(istream& in, vector<string> &words)
{
	if(in)
	{
		words.clear();
		string str;
		while(in>>str) words.push_back(str);
		in.clear();
	}
	return in;
}

void if_slower(string str)
{
	int flag=1;
	for (unsigned int i = 0; i < str.size(); ++i)
	{
		if(!islower(str[i]))
		{
			flag=0;
			break;
		}
	}
	if(flag) cout<<' '<<str; 
}

void if_upper(string str)
{
	int flag=1;
	for (unsigned int i = 0; i < str.size(); ++i)
	{
		if(!isupper(str[i]))
		{
			flag=0;
			break;
		}
	}
	if(flag) cout<<' '<<str; 
}

void if_first_upper(string str)
{
	if(isupper(str[0])&&str.size()>1)
	{
		if(islower(str[1])) cout<<' '<<str;
	}
}

int main(int argc, char const *argv[])
{
	vector<string> words;
	read_word(cin,words);

	cout<<"小写单词:";
	for (vector<string>::reverse_iterator it=words.rbegin(); it != words.rend(); ++it)
	{
		if_slower(*it);
	}
	cout<<endl;

	cout<<"首字母大写单词:";
	for (vector<string>::reverse_iterator it=words.rbegin(); it != words.rend(); ++it)
	{
		if_first_upper(*it);
	}
	cout<<endl;

	cout<<"大写单词:";
	for (vector<string>::reverse_iterator it=words.rbegin(); it != words.rend(); ++it)
	{
		if_upper(*it);
	}
	cout<<endl;

	return 0;
}