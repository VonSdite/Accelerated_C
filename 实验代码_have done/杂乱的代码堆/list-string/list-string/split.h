#ifndef GUARD_SPLIT_H
#define GUARD_SPLIT_H

#include "String_list.h"

String_list split(const std::string&);

using std::string;
String_list split(const string &s)
{
	String_list ret;
	typedef string::size_type string_size;
	string_size i = 0;
	while (i != s.size())
	{
		//忽略前端的空白
		while (i != s.size() && isspace(s[i]))
			++i;

		string_size j = i;
		while (j != s.size() && !isspace(s[j]))
			++j;

		//复制在[i，j）中的字符串
		if (i != j)
		{
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}
#endif