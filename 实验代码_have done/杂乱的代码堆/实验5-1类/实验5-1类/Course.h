#ifndef GUARD_COURSE_H
#define GUARD_COURSE_H

#include <string>
#include <iostream>
#include <cctype>

class Student_Info
{
public:
	Student_Info();											//�����յ�ѧ�������
	Student_Info(std::istream &);							//��һ�����Ӷ�����һ������

	//�����ṩ�Ľӿ�
	std::string name() const { return stu_name; }			//ѧ������

	double grade() const { return (midterm + final) / 2; }	//����ƽ���ɼ�

	std::istream& read(std::istream &);

private:
	std::string stu_name;
	double midterm;
	double final;
};

//����ĸ˳������
bool compare_name(Student_Info &, Student_Info &);

//�жϳɼ��Ƿ�ϸ�
std::string pass_or_not(double);

#endif // !GUARD_COURSE_H
