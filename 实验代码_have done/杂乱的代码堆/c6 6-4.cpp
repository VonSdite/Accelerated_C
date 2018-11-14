#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> u(33,100);

  vector<int> v;
  // copy(u.begin(),u.end(),back_inserter(v));
  copy(u.begin(), u.end(),inserter(v, v.begin()));

  for (int s:v)
  {
    cout<<s<<endl;
  }
  return 0;
}