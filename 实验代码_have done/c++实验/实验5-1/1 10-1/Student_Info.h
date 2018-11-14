#ifndef GUARD_STUDENT_INFO
#define GUARD_STUDENT_INFO

#include <string>
#include <vector>
#include <iostream>

class Student_Info
{
public:
	Student_Info();									//创建空的学生类对象
	Student_Info(std::istream &);					//读一个流从而构造一个对象
	
	//类型提供的接口
	std::string name() const { return stu_name; }	//返回学生名字
	bool valid() const { return !homework.empty(); }//判断是否有效
	double midterm_stu() const { return midterm; }
	double final_stu() const { return final; }

	std::istream& read(std::istream &);				//读取信息
	std::istream& read_hw(std::istream &, std::vector<double> &);	//读取家庭作业成绩

	double grade() const;							//算成绩

private:
	std::string stu_name;							//学生名字
	double midterm, final;							//期中成绩， 期末成绩
	std::vector<double> homework;					//平时作业成绩
};

bool compare(const Student_Info &, const Student_Info &);

#endif // !GUARD_STUDENT_INFO
