#include "Student_Info.h"
#include "grade.h"


Student_Info::Student_Info() : midterm(0), final(0) { }				//�����յ�ѧ�������

Student_Info::Student_Info(std::istream & is) { read(is); }			//��һ�����Ӷ�����һ������

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
		homework.clear();				//���ԭ�ȵ�����

		//��ȡƽʱ��ҵ�ɼ�
		double x;
		while (in >> x)
		{
			homework.push_back(x);
		}

		in.clear();						//�������ʹ���붯������һ��ѧ����Ч
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