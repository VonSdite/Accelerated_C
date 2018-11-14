#include "iostream"
#include "string"
using namespace std;

//声明输出长方形的函数
void output_rectangle();

//声明输出等腰三角形的函数
void output_isosceles_triangle();

//声明输出田字的函数
void output_tian();


int main(int argc, char const *argv[])
{
	while (true)
	{
		//请求用户输入选择项，1表示长方形，2表示等腰三角形， 3表示田字， 4表示退出
		cout << "Please enter your choice\n";
		cout << "1.rectangle\n2.isosceles triangle\n3.Tian\n4.quit\n";
		cout << endl << "Choice: ";
		//读入用户的选择
		int choice;
		cin >> choice;

		cout << endl;

		//用于退出程序
		int quit = 0;

		switch (choice)
		{
		//创建长方形
		case 1: output_rectangle(); break;

		//创建等腰三角形
		case 2: output_isosceles_triangle(); break;

		//创建田字
		case 3: output_tian(); break;

		//退出程序
		case 4: quit++; break;

		//错误输入
		default: cout << "Wrong Input"; break;
		}

		//判断是否退出
		if (quit) break;

		//暂停 清屏
		system("pause>nul&&cls");
	}
	return 0;
}

void output_rectangle()
{
	//请求用户输入长方形的长和宽
	cout << "Please enter the length and width of the rectangle:\n";

	//读入用户输入的长和框
	int re_length, re_width;
	cout << "Length :";
	cin >> re_length;
	cout << "Width :";
	cin >> re_width;

	//输出空白行，分隔输入和输出
	cout << endl;

	//构造长方形的一行
	const string rectangle_row(re_length, '*');
	const string spaces(re_length - 2, ' ');
	const string rectangle_row_second = "*" + spaces + "*";

	//输出长方形
	for (int i = 0; i < re_width; ++i)
	{

		if (i == 0 || i == re_width - 1) cout << rectangle_row << endl;
		else cout << rectangle_row_second << endl;
	}
}

void output_isosceles_triangle()
{
	//请求用户输入等腰三角形的底边长
	cout << "Please enter the bottom of the isosceles triangle(only odd number):";

	//读取用户输入的底边长，注只能是奇数
	int tri_bottom;
	cin >> tri_bottom;

	//提示用户输入奇数
	if(tri_bottom%2==0) 
	{
		printf("\nPlease enter odd number!\n");
		return;
	}

	//计算等腰三角形的高度
	const int height = (tri_bottom + 1) / 2;

	//输出等腰三角形
	for (int i = 0, j = height - 1 ; i < height; ++i, --j)
	{
		//每行的空格
		string spaces(j, ' ');

		//三角形的每行
		if (i == 0) cout << spaces << "*" << endl;
		else if (i != height - 1)
		{
			string blank(2 * i - 1, ' ');
			string one_row = "*" + blank + "*";
			cout << spaces << one_row << endl;
		}
		else
		{
			string one_row(2 * (i + 1) - 1, '*');
			cout << one_row << endl;
		}
	}
}

void output_tian()
{
	//请求用户输入田字，只能为奇数，同时要大于等于3
	cout << "Please enter the cols and rows of the Tian(only odd number and >=3):\n";

	//读取用户输入的行和列
	int rows, cols;
	cout << "Cols:";
	cin >> cols;

	//提示用户输入奇数并且大于3
	if(cols%2==0||cols<3) 
	{
		printf("\nPlease enter odd number or >=3!\n");
		return;
	}

	cout << "Rows:";
	cin >> rows;

	//提示用户输入奇数并且大于3
	if(rows%2==0||rows<3) 
	{
		printf("\nPlease enter odd number or >=3!\n");
		return;
	}

	//设置田字的每行
	const string first(cols, '*');
	const string second_blank((cols-3)/2,' ');
	const string second="*"+second_blank+"*"+second_blank+"*";

	//输出田字
	for (int i = 0; i < rows; ++i)
	{
		//判断是否在中间或者是顶部或下部
		if(i==0||i==rows-1||i==rows/2) cout<<first<<endl;
		else cout<<second<<endl;
	}
}