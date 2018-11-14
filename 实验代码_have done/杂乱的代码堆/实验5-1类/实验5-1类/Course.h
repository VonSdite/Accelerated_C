#ifndef GUARD_COURSE_H
#define GUARD_COURSE_H

#include <string>
#include <iostream>
#include <cctype>

class Student_Info
{
public:
	Student_Info();											//创建空的学生类对象
	Student_Info(std::istream &);							//读一个流从而构造一个对象

	//类型提供的接口
	std::string name() const { return stu_name; }			//学生名字

	double grade() const { return (midterm + final) / 2; }	//计算平均成绩

	std::istream& read(std::istream &);

private:
	std::string stu_name;
	double midterm;
	double final;
};

//按字母顺序排序
bool compare_name(Student_Info &, Student_Info &);

//判断成绩是否合格
std::string pass_or_not(double);

#endif // !GUARD_COURSE_H
