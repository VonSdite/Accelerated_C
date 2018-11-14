#include <iostream>
#include <string>

using namespace std;


typedef string::size_type str_sz;

int main(int argc, char const *argv[])
{
  //定义用来记录最长字符串长度和最短字符串长度的变量
  str_sz longest_length = 0;
  str_sz shortest_length = 0;

  //请求输入并读入字符串
  cout << "Please enter the string: " << endl;
  string s;
  while (cin >> s)
  {
    //记录最长的字符串长度
    if (longest_length == 0 || s.size() > longest_length)
    {
      longest_length = s.size();
    }

    //记录最短的字符串长度
    if (shortest_length == 0 || s.size() < shortest_length)
    {
      shortest_length = s.size();
    }
  }

  //输出结果
  cout << "Longest length: " << longest_length << endl;
  cout << "Shortest length: " << shortest_length << endl;

  return 0;
}
