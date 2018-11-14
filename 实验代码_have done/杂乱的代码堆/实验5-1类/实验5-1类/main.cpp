#include "Course.h"

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<Student_Info> students;
	vector<Student_Info> students_pass;				//���ڴ洢�ϸ��ѧ��
	vector<Student_Info> students_fail;				//���ڴ洢���ϸ��ѧ��
	Student_Info one_student;
	string::size_type maxlen = 0;

	ifstream in(argv[1]);							//��main������һ��������������
	ofstream out1(argv[2]);							//�����main�����ڶ���������
	ofstream out2(argv[3]);							//�����main����������������

	//���벢����ѧ����Ϣ
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