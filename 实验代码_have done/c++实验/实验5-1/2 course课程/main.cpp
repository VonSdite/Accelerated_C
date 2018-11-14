#include "Course.h"

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<Student_Info> students;
	vector<Student_Info> students_pass;				//用于存储合格的学生
	vector<Student_Info> students_fail;				//用于存储不合格的学生
	Student_Info one_student;
	string::size_type maxlen = 0;

	ifstream in(argv[1]);							//从main函数第一个参数读入数据
	ofstream out1(argv[2]);							//输出到main函数第二个参数中
	ofstream out2(argv[3]);							//输出到main函数第三个参数中

	//读入并储存学生信息
	while (one_student.read(in))
	{
		maxlen = max(maxlen, one_student.name().size());
		students.push_back(one_student);
	}

	sort(students.begin(), students.end(), compare_name);

	for (auto it : students)
	{
		out1 << it.name() << string(maxlen + 1 - it.name().size(), ' ');
		string grade = pass_or_not(it.grade());
		out1 << grade << endl;

		if (it.grade() >= 60) students_pass.push_back(it);
		else students_fail.push_back(it);
	}

	for (auto it : students_pass)
	{
		out2 << it.name() << string(maxlen + 1 - it.name().size(), ' ');
		string grade = pass_or_not(it.grade());
		out2 << grade << endl;
	}

	for (auto it : students_fail)
	{
		out2 << it.name() << string(maxlen + 1 - it.name().size(), ' ');
		string grade = pass_or_not(it.grade());
		out2 << grade << endl;
	}

	return 0;
}