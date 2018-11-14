#include "grade.h"
#include "median.h"

//根据学生的期中考试、期末考试成绩以及家庭作业成绩来计算总成绩
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

//根据期中、期末考试成绩以及保存家庭作业的向量来计算学生的总成绩
double grade(double midterm, double final, const std::vector<double> &hw)
{
	if (hw.size() == 0)
		throw std::domain_error("this student has done no homework");
	return grade(midterm, final, median(hw));
}