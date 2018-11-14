#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <vector>

#include "split.h"

using namespace std;

map<string, vector<int>> xref(istream& in,vector<string> find_words(const string&)=split)
{
	string line;
	int line_number=0;
	map<string, vector<int>> ret;

	while(getline(in,line))
	{
		++line_number;

		vector<string> words=find_words(line);

		for(auto it:words)
		{
			if(find(ret[it].begin(), ret[it].end(),line_number)==ret[it].end())
				ret[it].push_back(line_number);
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	map<string, vector<int>> ret=xref(cin);

	for(auto it:ret)
	{
		cout<<it.first<<" 出现的行在: ";

		for(auto LN:it.second)
		{
			cout<<LN<<" ";
		}

		cout<<endl;
	}

	return 0;
}