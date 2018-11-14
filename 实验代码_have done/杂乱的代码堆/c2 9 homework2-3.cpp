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

	//输出一个空白行
	cout << endl;

	//请求用户输入问候语与框架之间的间隔
	cout << "Please enter the pad between the greeting and the frame:\n";
	int pad_up, pad_down, pad_left, pad_right;

	//读入上间隔
	cout << "Up pad:";
	cin >> pad_up;

	//读入下间隔
	cout << "Down pad:";
	cin >> pad_down;

	//读入左间隔
	cout << "Left pad:";
	cin >> pad_left;

	//读入右间隔
	cout << "Right pad:";
	cin >> pad_right;

	//构造行数和列数
	const int rows = pad_up + pad_down + 3;
	const string::size_type cols = greeting.size() + pad_left + pad_right + 2;

	//构造输出的空白行
	const string spaces(greeting.size() + pad_left + pad_right, ' ');

	//输出空白行，将输出与输入分隔开
	cout << endl;

	//输入rows行
	for (int r = 0; r < rows; ++r)
	{
		string::size_type c = 0;
		while (c != cols)
		{
			//是否输出问候语
			if (r == pad_up + 1 && c == pad_left + 1)
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
				else if (r == pad_up + 1)
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