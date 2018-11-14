#include <iostream>
#include "split.h"


using namespace std;

//�����ַ���
istream& read_strings(istream&, String_list&);

void print_star();

int main(int argc, char const *argv[])
{
	typedef String_list::iterator Str_iter;

	String_list lis;

	cout << "�������ַ���(��EOF����):" << endl;
	read_strings(cin, lis);										//�����ַ���

	print_star();

	cout << "˳�����������ַ���:" << endl;
	for (Str_iter it = lis.begin(); it != lis.end(); it = it->next)
	{
		cout << *it << endl;
	}

	print_star();

	cout << "�������������ַ���:" << endl;
	for (Str_iter it = lis.rbegin(); it != lis.rend(); it = it->pre)
	{
		cout << *it << endl;
	}

	print_star();

	cout << "����split����������һ���ַ����������ո�:" << endl;
	string tmp;
	getline(cin, tmp);
	lis = split(tmp);

	print_star();

	cout << "��������ĵ�������:" << endl;
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