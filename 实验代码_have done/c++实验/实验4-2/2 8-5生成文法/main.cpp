#include <iostream>
#include <list>
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

//��һ���ض�������������һ���ķ�
Grammar read_grammar(istream &in)
{
	Grammar ret;
	string line;

	//������
	while (getline(in, line))
	{
		//������ָ�ɵ���
		vector<string> entry = split(line);

		if (!entry.empty())
			//���������洢������Ĺ���
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}

int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("��������ڷ�Χ��");

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

template<typename Out>
void gen_aux(const Grammar &g, const string &word, list<string> &ret, Out os)
{
	if (!bracketed(word))
	{
		ret.push_back(word);
	}
	else
	{
		//Ϊ��Ӧ��word�Ĺ���λ

		Grammar::const_iterator it = g.find(word);

		if (it == g.end())
			throw logic_error("empty rule");

		//��ȡ���ܵĹ��򼯺�
		const Rule_collection &c = it->second;

		//�ӹ��򼯺������ѡ��һ������
		const Rule &r = c[nrand(c.size())];

		//�洢���
		list<string> List;

		//�ݹ�չ����ѡ���Ĺ���
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
		{
			gen_aux(g, *i, ret,os);
			if (*((*i).begin()) != '<')
			{
				*os++ = *i;
				List.push_back(*i);
			}
		}
	}
}

template<typename Out>
list<string> gen_sentence(const Grammar &g, Out os)
{
	list<string> ret;
	gen_aux(g, "<sentence>", ret, os);
	return ret;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	//�������
	list<string> sentence = gen_sentence(read_grammar(cin), ostream_iterator<string>(cout, " "));

	cout << endl;

	return 0;
}