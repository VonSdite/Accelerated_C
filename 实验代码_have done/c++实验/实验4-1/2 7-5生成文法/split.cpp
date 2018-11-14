#include <string>
#include <cctype>
#include <vector>

#include "split.h"

using std::vector;
using std::string;

vector<string> split(const string &s)
{
	vector<string> ret;
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