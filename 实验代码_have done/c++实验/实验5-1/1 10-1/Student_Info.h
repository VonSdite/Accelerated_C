#ifndef GUARD_STUDENT_INFO
#define GUARD_STUDENT_INFO

#include <string>
#include <vector>
#include <iostream>

class Student_Info
{
public:
	Student_Info();									//�����յ�ѧ�������
	Student_Info(std::istream &);					//��һ�����Ӷ�����һ������
	
	//�����ṩ�Ľӿ�
	std::string name() const { return stu_name; }	//����ѧ������
	bool valid() const { return !homework.empty(); }//�ж��Ƿ���Ч
	double midterm_stu() const { return midterm; }
	double final_stu() const { return final; }

	std::istream& read(std::istream &);				//��ȡ��Ϣ
	std::istream& read_hw(std::istream &, std::vector<double> &);	//��ȡ��ͥ��ҵ�ɼ�

	double grade() const;							//��ɼ�

private:
	std::string stu_name;							//ѧ������
	double midterm, final;							//���гɼ��� ��ĩ�ɼ�
	std::vector<double> homework;					//ƽʱ��ҵ�ɼ�
};

bool compare(const Student_Info &, const Student_Info &);

#endif // !GUARD_STUDENT_INFO
