#include "grade.h"
#include "median.h"

//����ѧ�������п��ԡ���ĩ���Գɼ��Լ���ͥ��ҵ�ɼ��������ܳɼ�
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

//�������С���ĩ���Գɼ��Լ������ͥ��ҵ������������ѧ�����ܳɼ�
double grade(double midterm, double final, const std::vector<double> &hw)
{
	if (hw.size() == 0)
		throw std::domain_error("this student has done no homework");
	return grade(midterm, final, median(hw));
}