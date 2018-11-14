#include "Student_Info.h"
#include "grade.h"


Student_Info::Student_Info() : midterm(0), final(0) { }				//创建空的学生类对象

Student_Info::Student_Info(std::istream & is) { read(is); }			//读一个流从而构造一个对象

std::istream& Student_Info::read(std::istream &in)
{
	in >> stu_name >> midterm >> final;
	read_hw(in, homework);
	return in;
}

std::istream& Student_Info::read_hw(std::istream &in, std::vector<double> &homework)
{
	if (in)
	{
		homework.clear();				//清除原先的内容

		//读取平时作业成绩
		double x;
		while (in >> x)
		{
			homework.push_back(x);
		}

		in.clear();						//清除流以使输入动作对下一个学生有效
	}
	return in;
}

bool compare(const Student_Info &x, const Student_Info &y)
{
	return x.name() < y.name();
}

double Student_Info::grade() const
{
	return ::grade(midterm, final, homework);
}