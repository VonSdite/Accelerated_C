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

	//读入一行
	while (getline(in, line))
	{
		++line_number;

		//将输入行分割成单词
		vector<string> words = find_urls(line);

		//记住当前单词的出现的行号
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
	//默认使用 split 来调用 xref
	map<string, vector<int>> ret = xref(cin);

	//输出结果
	for (auto it : ret)
	{
		//输出单词
		cout << it.first << " 出现的行在: ";

		//输出单词所在行
		for (auto LN : it.second)
		{
			cout << LN << " ";
		}

		cout << endl;
	}

	return 0;
}