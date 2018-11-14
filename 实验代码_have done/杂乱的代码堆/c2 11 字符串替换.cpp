#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

//用于替换掉所有 "bullshit" 成 "bush"
void replace_all(string& str);

int main(int argc, char const *argv[])
{
	//用于获取每个字符
	char c;

	//建立初始空串origin 和 final， 记录最终结果
	string origin = "", final = "";

	//用于去除多余的空格和制表符的标记
	int blank_flag = 1;

	//提示用户输入一段话
	cout << "Please enter what you want to say(end with EOF):\n";

	//获取用户输入的话
	while (cin.get(c))
	{
		//记录最初的输入
		origin += c;

		//判断是否是空格或者是制表符
		//判断是否是回车的原因是因为当用户输入一行话最后加了空格
		//而在下一段话开头又加了空格，避免因为回车而导致没有清除多个空格
		//所以判断是否是回车
		if (c != ' ' && c != '	' && c != '\n') blank_flag = 1;

		//去掉回车换行符
		if (c != '\n' && blank_flag)
		{
			//将大写字母变成小写字母
			if (c >= 'A' && c <= 'Z') c += 32;

			//将小写字母变成大写字母
			else if (c >= 'a' && c <= 'z') c -= 32;

			//将制表符换成 空格
			if (c == '	') final += " ";
			else final += c;

			//已经记录过一次空格或者制表符，改变标记
			if (c == ' ' || c == '	') blank_flag = 0;
		}
	}

	//清除不雅话语“bullshit”
	replace_all(final);

	//输出最初的输入
	cout << endl << "The origin input:\n" << origin << endl;

	//输出替换后的结果
	cout << endl << "The final output:\n" << final << endl << endl;

	return 0;
}

//用于替换掉所有 "bullshit" 成 "bush"
void replace_all(string& str)
{
	//设置一个将原字符串全部变为小写的字符串作为查找
	string str_find=str;
	transform(str_find.begin(),str_find.end(),str_find.begin(),(int(*)(int))tolower);

	//设置要被替换的字符串
	const string old_value = "bullshit";


	//设置用来替换的字符串
	const string new_value = "bush";

	//用于替换
	while (true)
	{
		//定义初始位置
		string::size_type pos = 0;

		//找到要替换的位置
		if ((pos = str_find.find(old_value)) != string::npos)
		{
			str.replace(pos, old_value.length(), new_value);
			str_find.replace(pos, old_value.length(), new_value);
		}
		//退出循环
		else break;
	}
}