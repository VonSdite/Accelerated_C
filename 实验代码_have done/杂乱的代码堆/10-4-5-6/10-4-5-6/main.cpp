#include <iostream>

#include "List.h"
#include "split.h"

using namespace std;

int main() {
	string arr1[] = { "Hello", "to", "the", "world!" };
	string arr2[] = { "a", "b", "c" };
	string arr3[] = { "x", "y", "z" };

	cout << List<string>() << endl;
	cout << List<string>(NULL, NULL) << endl;
	cout << List<string>(arr1, arr1 + 4) << endl;
	cout << reverse(List<string>(arr1, arr1 + 4)) << endl;
	cout << append(List<string>(arr2, arr2 + 3), List<string>(arr3, arr3 + 3))
		<< endl;


	return 0;
}
