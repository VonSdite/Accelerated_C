#include "Course.h"

Student_Info::Student_Info() : midterm(0), final(0) { }				//创建空的学生类对象

Student_Info::Student_Info(std::istream &is) { read(is); }			//读一个流从而构造一个对象

//读入学生信息
std::istream& Student_Info::read(std::istream &in)
{
	in >> stu_name >> midterm >> final;
	return in;
}

//判断是否合格
std::string pass_or_not(double grade)
{
	static const char* const letters[] = { "P", "F" };
	if (grade >= 60) return letters[0];
	else if (grade >= 0 && grade < 60) return letters[1];
	return "?\?\?";
}

//按字母顺序排序	
bool compare_name(Student_Info &x, Student_Info &y)
{
	std::string a = x.name(), b = y.name();
	if(islower(x))
	return x.name() < y.name();
}




