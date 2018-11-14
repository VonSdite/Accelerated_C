#include "iostream"
#include "string"
using namespace std;
int main(int argc, char const *argv[])
{
	//请求用户输入姓名
	cout << "Please enter your first name: ";

	//读入用户输入的姓名
	string name;
	cin >> name;
	//构造我们将要输出的信息
	const string greeting = "Hello, " + name + "!";

	//设置围住问候语的空格数
	const int pad = 1;

	//构造行数和列数
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	//构造空白行
	const string spaces(greeting.size() + pad * 2, ' ');

	//输出一个空白行，将输出与输入分隔开
	cout << endl;

	//输出rows行
	for (int r = 0; r < rows; ++r)
	{
		string::size_type c = 0;
		while (c != cols)
		{
			//是否输出问候语
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				//是否位于边界上
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
				{
					cout << "*";
					c++;
				}
				//是否是问候语与框架之间的空格
				else if (r == pad + 1)
				{
					cout << " ";
					c++;
				}
				//是否输出空白行
				else
				{
					cout << spaces;
					c += spaces.size();
				}
			}
		}
		cout << endl;
	}
	return 0;
}