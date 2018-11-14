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
	//��������
	static int copy_num;							//���ƴ���
	static int destory_num;							//ɾ������
	static int creat_num;							//��������
	static int evaluation_num;						//��ֵ����

	Student_Info(const Student_Info&);				//���ƹ��캯��
	~Student_Info() { ++destory_num; }				//��������
	Student_Info& operator=(const Student_Info&);	//��ֵ���������

	Student_Info();									//�����յ�ѧ�������
	Student_Info(std::istream &);					//��һ�����Ӷ�����һ������

	//�����ṩ�Ľӿ�
	std::string name() const { return stu_name; }	//����ѧ������
	bool valid() const { return !homework.empty(); }//�ж��Ƿ���Ч
	double midterm_stu() const { return midterm; }
	double final_stu() const { return final; }
	std::vector<double> get_homework() const { return homework; }

	std::istream& read(std::istream &);				//��ȡ��Ϣ
	std::istream& read_hw(std::istream &, std::vector<double> &);	//��ȡ��ͥ��ҵ�ɼ�

	double grade() const;							//��ɼ�

private:
	std::string stu_name;							//ѧ������
	double midterm, final;							//���гɼ��� ��ĩ�ɼ�
	std::vector<double> homework;					//ƽʱ��ҵ�ɼ�
};


double grade(const Student_Info& s);

bool fgrade(const Student_Info& s);

bool pgrade(const Student_Info& s);

//6.3.1�ڵ�extract_fails����
std::vector<Student_Info> extract_fails_first(std::vector<Student_Info>& students);

//6.3.2�ڵ�extract_fails����
std::vector<Student_Info> extract_fails_second(std::vector<Student_Info>& students);

#endif // !GUARD_STUDENT_INFO
