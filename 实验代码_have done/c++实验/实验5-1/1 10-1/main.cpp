#include "grade.h"
#include "letter_grade.h"
#include "median.h"
#include "Student_Info.h"

#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<Student_Info> students;
	Student_Info one_student;
	string::size_type maxlen = 0;

	//������������
	while (one_student.read(cin))
	{
		maxlen = max(maxlen, one_student.name().size());
		students.push_back(one_student);
	}

	//����ĸ˳������ѧ����¼
	sort(students.begin(), students.end(), compare);

	//���ѧ�������ͳɼ�
	for (auto it : students)
	{
		cout << it.name() << string(maxlen + 1 - it.name().size(), ' ');
		try
		{
			string final_grade = letter_grade(it.grade());
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e)
		{
			cout << e.what() << "  ";
			cout << letter_grade(0.2 * it.midterm_stu() + 0.4 * it.final_stu()) << endl;
		}
	}


	return 0;
}