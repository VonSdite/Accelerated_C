//��ȡ�����ļ������н�������
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include <algorithm>

#include "Student_info.h"
#include "Dormitory.h"

typedef std::map<std::string, Student_info> Students;	//���ڴ洢ѧ����Ϣ

typedef std::vector<std::vector<std::string> > Instruction;	//���ڴ洢ָ����Ϣ

															//��ȡѧ������
int read_stu(Dorm&, Students&, const char*);

//��ȡ��Ӧָ��
int read_instructions(Instruction&, const char*);

//����ָ��
int run_instructions(const Instruction&, Dorm&, Students&, Students&);