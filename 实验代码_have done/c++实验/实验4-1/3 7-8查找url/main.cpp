#include <map>
#include <iostream>
#include <string>
#include <vector>

#include "split.h"
#include "urls.h"

using namespace std;

map<string, vector<int>> xref(istream& in, vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int>> ret;

	//����һ��
	while (getline(in, line))
	{
		++line_number;

		//�������зָ�ɵ���
		vector<string> words = find_urls(line);

		//��ס��ǰ���ʵĳ��ֵ��к�
		for (auto it : words)
		{
			if (find(ret[it].begin(), ret[it].end(), line_number) == ret[it].end())
				ret[it].push_back(line_number);
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	//Ĭ��ʹ�� split ������ xref
	map<string, vector<int>> ret = xref(cin);

	//������
	for (auto it : ret)
	{
		//�������
		cout << it.first << " ���ֵ�����: ";

		//�������������
		for (auto LN : it.second)
		{
			cout << LN << " ";
		}

		cout << endl;
	}

	return 0;
}