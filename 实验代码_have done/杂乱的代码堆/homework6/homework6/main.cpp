#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>

#include "Student_info.h"
#include "grade.h"
#include "analysis.h"

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;


using std::max;


vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	// invariant: elements `[0,' `i)' of `students' represent passing grades
	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
			++i;
	}
	return fail;
}

int main() {
	vector<Student_info> did_male, didnt_male, did_female, didnt_female;
	Student_info student;
	string::size_type maxlen = 0;
	while (read(cin, student)) {
		if (did_all_hw(student))
		{
			if (student.sex == "male")
				did_male.push_back(student);
			else did_female.push_back(student);
		}
		else
		{
			if (student.sex == "male")
				didnt_male.push_back(student);
			else didnt_female.push_back(student);
		}
	}

	cout << "Male:\n";

	if (did_male.empty()) {
		cout << "No student did all the homework!" << endl;
		
	}

	if (didnt_male.empty()) {
		cout << "Every student did all the homework!" << endl;
	
	}
	write_analysis(cout, "median", grade_aux, did_male, didnt_male);
	write_analysis(cout, "average", average_grade, did_male, didnt_male);
	write_analysis(cout, "median of homework turned in",
		optimistic_median, did_male, didnt_male);

	cout << endl << endl
		<< "Female:\n";

	if (did_female.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}

	if (didnt_female.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	write_analysis(cout, "median", grade_aux, did_female, didnt_female);
	write_analysis(cout, "average", average_grade, did_female, didnt_female);
	write_analysis(cout, "median of homework turned in",
		optimistic_median, did_female, didnt_female);
	return 0;
}
