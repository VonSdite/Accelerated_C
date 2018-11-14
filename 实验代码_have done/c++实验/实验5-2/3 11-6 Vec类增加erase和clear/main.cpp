#include "Vec.h"

#include <iostream>

using namespace std;

//分割线
void print_star();

//读入信息
template <class T>
istream& read_vec(istream& in, Vec<T>& vec);

int main(int argc, char const *argv[])
{
	Vec<int> a;

	cout << "输入测试样例(以EOF结束):" << endl;
	read_vec(cin, a);							//读入信息

	print_star();

	int pos;
	cout << "输入要删除的元素位置: ";
	cin >> pos;
	--pos;
	Vec<int>::iterator it = a.begin();

	//找到要删除的位置
	for (size_t i = 0; i < pos && it != a.end(); i++)
	{
		++it;
	}

	//判断所找位置是否越界
	if (it == a.end())
	{
		print_star();
		cout << "所要删除的位置越界!" << endl;
	}
	else
	{
		a.erase(it);									//删除该位置元素

		print_star();

		cout << "删除样例中的元素为:" << endl;
		for (auto it : a)
		{
			cout << it << " ";
		}
	}

	print_star();

	cout << "清空样例:" << endl;
	a.clear();
	if (a.empty()) cout << "清空成功！" << endl;
	else cout << "清空失败！" << endl;

	return 0;
}

template <class T>
istream& read_vec(istream& in, Vec<T>& vec)
{
	if (in)
	{
		vec.clear();

		T tmp;
		while (in >> tmp)
			vec.push_back(tmp);
		in.clear();
	}
	return in;
}

void print_star()
{
	cout << endl << "********************************************************" << endl;
}