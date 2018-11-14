#include "Course.h"

Student_Info::Student_Info() : midterm(0), final(0) { }				//�����յ�ѧ�������

Student_Info::Student_Info(std::istream &is) { read(is); }			//��һ�����Ӷ�����һ������

//����ѧ����Ϣ
std::istream& Student_Info::read(std::istream &in)
{
	in >> stu_name >> midterm >> final;
	return in;
}

//�ж��Ƿ�ϸ�
std::string pass_or_not(double grade)
{
	static const char* const letters[] = { "P", "F" };
	if (grade >= 60) return letters[0];
	else if (grade >= 0 && grade < 60) return letters[1];
	return "?\?\?";
}

//����ĸ˳������	
bool compare_name(Student_Info &x, Student_Info &y)
{
	std::string a = x.name(), b = y.name();
	if(islower(x))
	return x.name() < y.name();
}




