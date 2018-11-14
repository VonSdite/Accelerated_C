#include "iostream"
#include "numeric"
#include "vector"

using namespace std;

istream &read(istream &in, vector<string> &str)
{
	if (in)
	{
		str.clear();
		string tmp;
		while (in >> tmp)
			str.push_back(tmp);
		in.clear();
	}
	return in;
}

string cat_all(vector<string> &str)
{
	string tmp;
	return accumulate(str.begin(), str.end(), tmp);
}

int main(int argc, char const *argv[])
{
	vector<string> str;

	cout << "Please enter strings(end by EOF):\n";
	read(cin, str);

	string str_cat_all = cat_all(str);

	cout << str_cat_all << endl;
	return 0;
}