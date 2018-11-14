#include "iostream"
#include "map"
#include "vector"

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	map<string, int> counters;
	map<int, vector<string>> words_fre;


	cout << "请输入单词,以 EOF 结束：\n";
	while (cin >> s)
		++counters[s];

	for (auto c : counters)
	{
		words_fre[c.second].push_back(c.first);
	}

	cout << "单词出现的次数:              单词：\n";
	for (auto wf : words_fre)
	{
		cout << "               " << wf.first << "                   ";

		for (auto s : wf.second)
		{
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}