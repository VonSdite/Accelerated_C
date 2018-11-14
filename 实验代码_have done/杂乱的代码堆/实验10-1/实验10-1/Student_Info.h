#ifndef GUARD_STUDENT_INFO
#define GUARD_STUDENT_INFO

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Student_Info
{
public:
	//计数代码
	static int copy_num;							//复制次数
	static int destory_num;							//删除次数
	static int creat_num;							//创建次数
	static int evaluation_num;						//赋值次数

	Student_Info(const Student_Info&);				//复制构造函数
	~Student_Info() { ++destory_num; }				//析构函数
	Student_Info& operator=(const Student_Info&);	//赋值运算符函数

	Student_Info();									//创建空的学生类对象
	Student_Info(std::istream &);					//读一个流从而构造一个对象

	//类型提供的接口
	std::string name() const { return stu_name; }	//返回学生名字
	bool valid() const { return !homework.empty(); }//判断是否有效
	double midterm_stu() const { return midterm; }
	double final_stu() const { return final; }
	std::vector<double> get_homework() const { return homework; }

	std::istream& read(std::istream &);				//读取信息
	std::istream& read_hw(std::istream &, std::vector<double> &);	//读取家庭作业成绩

	double grade() const;							//算成绩

private:
	std::string stu_name;							//学生名字
	double midterm, final;							//期中成绩， 期末成绩
	std::vector<double> homework;					//平时作业成绩
};


double grade(const Student_Info& s);

bool fgrade(const Student_Info& s);

bool pgrade(const Student_Info& s);

//6.3.1节的extract_fails函数
std::vector<Student_Info> extract_fails_first(std::vector<Student_Info>& students);

//6.3.2节的extract_fails函数
std::vector<Student_Info> extract_fails_second(std::vector<Student_Info>& students);

#endif // !GUARD_STUDENT_INFO
