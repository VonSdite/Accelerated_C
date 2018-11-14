#include <memory>
#include <iostream>
#include <vector>

using namespace std;

struct STR
{
	vector<int> b;
};

int main()
{
	allocator<STR> alloc;
	STR* a = alloc.allocate(9);
	
	a[0].b.push_back(10);

	return 0;
}
