#include "grade.h"
#include "median.h"
#include "Student_Info.h"

#include <iomanip>

using namespace std;

//��ʼ����������
int Student_Info::copy_num = 0;
int Student_Info::destory_num = 0;
int Student_Info::evaluation_num = 0;
int Student_Info::creat_num = 0;

void display_times();
void print_star();

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


	//����
	//print_star();
	//cout << "6.3.1��extract_fails������Student_info����Ĵ��������ơ���ֵ�����ٴ���:" << endl;
	//extract_fails_first(students);
	//display_times();
	//print_star();

	print_star();
	cout << "6.3.2��extract_fails������Student_info����Ĵ��������ơ���ֵ�����ٴ���:" << endl;
	extract_fails_second(students);
	display_times();
	print_star();

	return 0;
}

void display_times()
{
	cout << Student_Info::creat_num << endl;
	cout << Student_Info::copy_num << endl;
	cout << Student_Info::evaluation_num << endl;
	cout << Student_Info::destory_num << endl;
}


void print_star()
{
	cout << endl << "********************************************************" << endl;
}