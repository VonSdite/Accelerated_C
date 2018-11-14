#include <iostream>
#include "split.h"


using namespace std;

//读入字符串
istream& read_strings(istream&, String_list&);

void print_star();

int main(int argc, char const *argv[])
{
	typedef String_list::iterator Str_iter;

	String_list lis;

	cout << "请输入字符串(以EOF结束):" << endl;
	read_strings(cin, lis);										//读入字符串

	print_star();

	cout << "顺序输出输入的字符串:" << endl;
	for (Str_iter it = lis.begin(); it != lis.end(); it = it->next)
	{
		cout << *it << endl;
	}

	print_star();

	cout << "逆序输出输入的字符串:" << endl;
	for (Str_iter it = lis.rbegin(); it != lis.rend(); it = it->pre)
	{
		cout << *it << endl;
	}

	print_star();

	cout << "检验split函数，输入一行字符串，包含空格:" << endl;
	string tmp;
	getline(cin, tmp);
	lis = split(tmp);

	print_star();

	cout << "分离出来的单词如下:" << endl;
	for (Str_iter it = lis.begin(); it != lis.end(); it = it->next)
	{
		cout << *it << endl;
	}

	return 0;
}

istream& read_strings(istream& in, String_list& lis)
{
	if (in)
	{
		lis.clear();

		string tmp;
		while (in >> tmp)
			lis.push_back(tmp);
		in.clear();
	}
	return in;
}

void print_star()
{
	cout << endl <<"********************************************************" << endl;
}