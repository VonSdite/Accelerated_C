#include "Student_Info.h"
#include "grade.h"


Student_Info::Student_Info() : midterm(0), final(0) { }	//创建空的学生类对象

Student_Info::Student_Info(std::istream & is) { read(is);}	//读一个流从而构造一个对象

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


double Student_Info::grade() const
{
	return ::grade(midterm, final, homework);
}

Student_Info::Student_Info(const Student_Info& stu)
{
	stu_name = stu.name();
	midterm = stu.midterm_stu();
	final = stu.final_stu();
	homework = stu.get_homework();
	++copy_num;
}

Student_Info& Student_Info::operator=(const Student_Info& rhs)
{
	if (&rhs != this)
	{
		stu_name = rhs.name();
		midterm = rhs.midterm_stu();
		final = rhs.final_stu();
		homework = rhs.get_homework();
		++evaluation_num;
	}
	return *this;
}


double grade(const Student_Info& s)
{
	return grade(s.midterm_stu(), s.final_stu(), s.get_homework());
}

bool fgrade(const Student_Info& s)
{
	return grade(s) < 60;
}

bool pgrade(const Student_Info& s)
{
	return !fgrade(s);
}

std::vector<Student_Info> extract_fails_first(std::vector<Student_Info>& students)
{
	std::vector<Student_Info> fail;
	std::remove_copy_if(students.begin(), students.end(), std::back_inserter(fail), pgrade);
	students.erase(std::remove_if(students.begin(), students.end(), fgrade), students.end());

	return fail;
}

std::vector<Student_Info> extract_fails_second(std::vector<Student_Info>& students)
{
	std::vector<Student_Info>::iterator iter = std::stable_partition(students.begin(), students.end(), pgrade);
	std::vector<Student_Info> fail(iter, students.end());
	students.erase(iter, students.end());

	return fail;
}