//分割字符串并返回存储所有单词的vector(在课本基础上进行了改写)
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "split.h"

using std::find_if;
using std::string;
using std::vector;

using std::isspace;
using std::istringstream;


//改写的split函数，能够分割中文
vector<string> split(const string& str)
{
	istringstream is(str);

	vector<string> ret;
	string word;

	while (is >> word)
	{
		size_t pos;
		if ((pos = word.find('-', 0)) != string::npos)
		{
			ret.push_back(word.substr(0, pos));
			ret.push_back(&word[pos + 1]);
		}
		else ret.push_back(word);
	}

	return ret;
}