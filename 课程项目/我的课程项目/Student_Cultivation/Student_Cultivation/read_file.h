//读取三个文件并进行解析运行
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include <algorithm>

#include "Student_info.h"
#include "Dormitory.h"

typedef std::map<std::string, Student_info> Students;	//用于存储学生信息

typedef std::vector<std::vector<std::string> > Instruction;	//用于存储指令信息

															//读取学生数据
int read_stu(Dorm&, Students&, const char*);

//读取对应指令
int read_instructions(Instruction&, const char*);

//运行指令
int run_instructions(const Instruction&, Dorm&, Students&, Students&);