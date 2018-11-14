#include "grade.h"
#include "median.h"
#include "Student_Info.h"

#include <iomanip>

using namespace std;

//初始化计数代码
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

	//读并储存数据
	while (one_student.read(cin))
	{
		maxlen = max(maxlen, one_student.name().size());
		students.push_back(one_student);
	}


	//测试
	//print_star();
	//cout << "6.3.1节extract_fails函数对Student_info对象的创建、复制、赋值和销毁次数:" << endl;
	//extract_fails_first(students);
	//display_times();
	//print_star();

	print_star();
	cout << "6.3.2节extract_fails函数对Student_info对象的创建、复制、赋值和销毁次数:" << endl;
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