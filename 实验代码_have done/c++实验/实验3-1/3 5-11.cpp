#include "iostream"
#include "string"
#include "vector"

using namespace std;

bool not_hangword(string word)
{
	string::size_type i = 0;
	for (; i < word.size(); ++i)
	{
		if (word[i] == 'b' || word[i] == 'd' || word[i] == 'f' || word[i] == 'h' || word[i] == 'k' || word[i] == 't' || word[i] == 'l' || word[i] == 'g' || word[i] == 'j' || word[i] == 'p' || word[i] == 'q' || word[i] == 'y')
			break;
	}
	if (i < word.size()) return false;
	else return true;
}

istream& read_words(istream& in, vector<string>& words)
{
	if (in)
	{
		words.clear();
		string word;

		while (in >> word)
		{
			if (not_hangword(word))
			{
				words.push_back(word);
			}
			else cout << "这个单词含有上行字母或下行字母" << endl;
		}

		in.clear();
	}

	return in;
}

int main(int argc, char const *argv[])
{
	cout << "Please enter words(end by EOF, line by line): \n";
	vector<string> words;
	read_words(cin, words);
	string::size_type max_len = 0;
	string max_string = "";
	for (vector<string>::size_type i = 0; i < words.size(); ++i)
	{
		if (words[i].size() > max_len)
		{
			max_len = words[i].size();
			max_string = words[i];
		}
	}
	if (max_len != 0)
		cout << "不含上行字母也没有下行字母的最长单词是: " << max_string << endl;
	else cout << "不存在不含上行字母也不含下行字母的单词" << endl;
	return 0;
}