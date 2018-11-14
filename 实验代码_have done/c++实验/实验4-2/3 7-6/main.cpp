#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>

#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

//从一个特定的输入流读入一个文法
Grammar read_grammar(istream &in)
{
	Grammar ret;
	string line;

	//读输入
	while (getline(in, line))
	{
		//将输入分割成单词
		vector<string> entry = split(line);

		if (!entry.empty())
			//用种类来存储相关联的规则
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}

int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("随机数不在范围内");

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while (r >= n);

	return r;
}

bool bracketed(const string &s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}


void gen_aux(const Grammar &g, const string &word, vector<string> &ret, vector<string>& tokens)
{
	if (!bracketed(word))
	{
		ret.push_back(word);
	}
	else
	{
		//为对应于word的规则定位

		Grammar::const_iterator it = g.find(word);

		if (it == g.end())
			throw logic_error("empty rule");

		//获取可能的规则集合
		const Rule_collection &c = it->second;

		//从规则集合中随机选择一条规则
		const Rule &r = c[nrand(c.size())];

		//将规则压入栈堆
		//用反向迭代器是因为是在栈尾压栈出栈
		for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
		{
			tokens.push_back(*i);
		}
	}
}


vector<string> gen_sentence(const Grammar &g)
{
	vector<string> tokens;
	vector<string> ret;
	tokens.push_back("<sentence>");

	while (!tokens.empty())
	{
		string token = tokens.back();
		tokens.pop_back();
		gen_aux(g, token, ret, tokens);
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	//生成语句
	vector<string> sentence = gen_sentence(read_grammar(cin));

	//输出语句
	vector<string>::const_iterator it = sentence.begin();

	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	while (it != sentence.end()) {
		cout << " " << *it;
		++it;
	}

	cout << endl;


	return 0;
}