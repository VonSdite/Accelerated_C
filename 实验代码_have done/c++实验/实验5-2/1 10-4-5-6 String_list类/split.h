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
		//����ǰ�˵Ŀհ�
		while (i != s.size() && isspace(s[i]))
			++i;

		string_size j = i;
		while (j != s.size() && !isspace(s[j]))
			++j;

		//������[i��j���е��ַ���
		if (i != j)
		{
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}
#endif