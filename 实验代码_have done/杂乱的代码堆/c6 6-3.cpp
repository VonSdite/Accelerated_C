#include <algorithm>
#include <vector>
#include "iostream"

using namespace std;

int main() {
  vector<int> u(10, 100);
  vector<int> v;
  v.resize(10);
  copy(u.begin(), u.end(), v.begin());
  cout<<v[1]<<endl;

  return 0;
}
