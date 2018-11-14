#include <algorithm>
#include <list>
#include <string>
#include <ctime>
#include "grade.h"
#include "Student_info.h"

using std::max;

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}

int main()
{
	list<Student_info> vs;
	Student_info s;
	string::size_type maxlen = 0;
	while (read(cin, s)) {
		maxlen = max(maxlen, s.name.size());
		vs.push_back(s);
	}

	clock_t start = clock();
	list<Student_info> fails = extract_fails(vs);
	clock_t elapsed = clock() - start;

	cout << "Elapsed: " << elapsed << " ms " << endl;

	return 0;
}
