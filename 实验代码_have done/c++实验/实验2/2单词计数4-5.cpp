#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

istream& read_words(istream& in, vector<string>& words)
{
  if (in)
  {
    words.clear();
    string word;

    while (in >> word)
      words.push_back(word);

    in.clear();
  }

  return in;
}

int main(int argc, char const *argv[])
{
  //定义存储单词的向量
  //请求输入并读入单词
  cout << "Please enter the words: " << endl;
  vector<string> words;
  read_words(cin, words);

  //输出输入的单词的数目
  cout << "Num of words: " << words.size() << endl;

  //对输入的单词进行排序，以便后续计数
  sort(words.begin(), words.end());

  //定义每个单词的前驱，进行访问
  string prev_word = "";
  int count = 0;

  //进行计数
  for (vector<string>::size_type i = 0; i < words.size(); ++i)
  {
    if (words[i] != prev_word)
    {
      if (prev_word != "")
        cout << prev_word << " <--------> " << " appeared " << count << " times" << endl;

      prev_word = words[i];
      count = 1;
    }
    else
      ++count;
  }
  //输出最后一个单词出现的次数
  cout << prev_word << " <--------> " << " appeared " << count << " times" << endl;

  return 0;
}