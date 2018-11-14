#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>

#include "Student_info.h"
#include "grade.h"


using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;


using std::max;


vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;

	vector<Student_info>::size_type i = 0;


	
	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			students.insert(students.begin(), students[i]);
			++i;
		}
		++i;
	}

	students.resize(students.size() - fail.size());

	return fail;
}

int main() {
	vector<Student_info> vs;
	Student_info s;
	string::size_type maxlen = 0;
	while (read(cin, s)) {
		maxlen = max(maxlen, s.name.size());
		vs.push_back(s);
	}


	clock_t start = clock();
	vector<Student_info> fails = extract_fails(vs);
	clock_t elapsed = clock() - start;

	cout << "Elapsed: " << elapsed << " ms " << endl;


	return 0;
}
