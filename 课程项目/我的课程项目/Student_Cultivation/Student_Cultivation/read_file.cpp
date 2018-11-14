//读取三个文件并进行解析运行
#include <fstream>
#include <string>
#include <algorithm>
#include "read_file.h"
#include "split.h"

using std::ifstream;
using std::string;
using std::vector;
using std::cerr;
using std::endl;

std::map<std::string, std::map<std::string, int> > woo_cnt;				//记录一个人向一个人表白的次数

																		//读取学生数据
int read_stu(Dorm& dorm, Students& students, const char* f_name)
{
	ifstream infile(f_name);
	if (infile)
	{
		Student_info record;
		size_t floor_num;
		size_t room_num;
		char temp;
		while (record.read(infile))
		{
			infile >> floor_num;
			infile >> temp;									//读取楼层号与宿舍号之间的‘-’符
			infile >> room_num;
			if (dorm.extract_limit(floor_num, room_num))
			{
				record.set_dorm(floor_num, room_num);

				//判断宿舍是否为空，若为空则直接将record插入，同时将学生加入全体学生信息
				if (dorm[floor_num][room_num].empty())
				{
					dorm.add_stu(floor_num, room_num, record.name());
					dorm.set_gender(floor_num, room_num, record.sex());
					students[record.name()] = record;
				}
				//若不为空，则根据性别判断是否将学生加入该宿舍同时判断该宿舍人数是否超过限制
				else
				{
					if (dorm.get_room_gender(floor_num, room_num) == record.sex() && dorm.extract_limit(floor_num, room_num))
					{
						dorm.add_stu(floor_num, room_num, record.name());
						students[record.name()] = record;
					}
				}
			}
		}
	}
	else
	{
		cerr << "cannot open file " << f_name << endl;
		return 1;
	}

	return 0;
}

//读取对应指令
int read_instructions(Instruction& instructions, const char* f_name)
{
	ifstream infile(f_name);
	if (infile)
	{
		string s;
		vector<string> temp;
		while (getline(infile, s))
		{
			if (!s.empty())
			{
				temp = split(s);
				instructions.push_back(temp);
			}
		}
	}
	else
	{
		cerr << "cannot open file " << f_name << endl;
		return 1;
	}

	return 0;
}

//运行指令
int run_instructions(const Instruction& instructions, Dorm& dorm, Students& students, Students& quit_stu)
{
	for (auto it : instructions)
	{
		if ("ADD" == it[0])
		{
			if ("FLOOR(s)" == it[2])
			{
				dorm.add_floor(atoi(it[1].c_str()));
			}
			else if ("ROOM(s)" == it[2])
			{
				dorm.add_room(atoi(it[4].c_str()), atoi(it[1].c_str()));
			}
			else if ("BED(s)" == it[2])
			{
				dorm.add_capacity(atoi(it[4].c_str()),
					atoi(it[5].c_str()), atoi(it[1].c_str()));
			}
		}
		else
		{
			for (std::vector<std::string>::const_iterator iter = it.begin() + 1; iter != it.end(); iter++)
			{
				if ("ENROL" == *iter)
				{
					if (students.find(it[0]) != students.end() && quit_stu.find(it[0]) == quit_stu.end())
						continue;
					int floor_num = atoi(iter[1].c_str());
					int room_num = atoi(iter[2].c_str());
					if (dorm.extract_limit(floor_num, room_num))
					{
						Student_info record(it[0], it[1]);
						if (quit_stu.find(it[0]) != quit_stu.end())
						{
							record = quit_stu[it[0]];
							quit_stu.erase(it[0]);
						}
						//判断宿舍是否为空，若为空则直接将record插入，同时将学生加入全体学生信息
						if (dorm[floor_num][room_num].empty())
						{
							dorm.add_stu(floor_num, room_num, record.name());
							dorm.set_gender(floor_num, room_num, record.sex());
							record.set_dorm(floor_num, room_num);
							students[record.name()] = record;
						}
						//若不为空，判断宿舍是否满人，不满人则根据性别判断是否将学生加入该宿舍
						else
						{
							if (dorm.extract_limit(floor_num, room_num))
							{
								if (dorm.get_room_gender(floor_num, room_num) == record.sex())
								{
									dorm.add_stu(floor_num, room_num, record.name());
									record.set_dorm(floor_num, room_num);
									students[record.name()] = record;
								}
							}
						}
					}
					continue;
				}
				if (students.find(it[0]) == students.end())
					continue;
				if ("MOVE" == *iter)
				{
					int pre_floor_num = atoi(iter[2].c_str());
					int pre_room_num = atoi(iter[3].c_str());
					if ((students[it[0]].get_floor() != pre_floor_num) ||
						(students[it[0]].get_room() != pre_room_num))
						continue;
					int floor_num = atoi(iter[5].c_str());
					int room_num = atoi(iter[6].c_str());
					if (dorm.extract_limit(floor_num, room_num))
					{
						if (students[it[0]].sex() == dorm.get_room_gender(floor_num, room_num))
						{
							dorm.delete_stu(pre_floor_num, pre_room_num, it[0]);
							dorm.add_stu(floor_num, room_num, it[0]);
							students[it[0]].set_dorm(floor_num, room_num);
						}
					}
					continue;
				}
				if ("QUIT" == *iter)
				{
					dorm.delete_stu(students[it[0]].get_floor(),
						students[it[0]].get_room(), it[0]);
					students[it[0]].set_quit_school();
					students[it[0]].set_dorm(0, 0);
					quit_stu[it[0]] = students[it[0]];
					continue;
				}
				if ("WOO" == *iter)
				{
					if (students.find(iter[1]) == students.end())
						continue;
					if (students[iter[1]].love_status())
					{
						++woo_cnt[it[0]][iter[1]];
						if (woo_cnt[it[0]][iter[1]] < 3) continue;
						else
						{
							double delta = fabs(students[it[0]].charm() - students[iter[1]].charm()) /
								std::max(students[it[0]].charm(), students[iter[1]].charm());
							if (delta > dou(Configure::configure["LOVE_RECONSTUCT_STANDARD"]))
								continue;
							if (students[it[0]].love_status())
							{
								students[students[it[0]].get_lover_name()].set_single();
							}
							students[students[iter[1]].get_lover_name()].set_single();
							students[it[0]].add_lover(iter[1]);
							students[iter[1]].add_lover(it[0]);
							continue;
						}
					}
					double delta = fabs(students[it[0]].charm() - students[iter[1]].charm()) /
						std::max(students[it[0]].charm(), students[iter[1]].charm());
					if (delta > dou(Configure::configure["LOVE_STANDARD"]))
						continue;
					if (students[it[0]].love_status())
					{
						students[students[it[0]].get_lover_name()].set_single();
					}
					students[it[0]].add_lover(iter[1]);
					students[iter[1]].add_lover(it[0]);
					students[it[0]].set_love_cnt();
					students[iter[1]].set_love_cnt();
					continue;
				}
				if ("BREAK" == *iter)
				{
					if (students.find(iter[-1]) == students.end())
						continue;
					if ((students[it[0]].love_status() && students[iter[-1]].love_status())
						&& (iter[-1] == students[it[0]].get_lover_name()))
					{
						students[it[0]].set_single();
						students[iter[-1]].set_single();
						continue;
					}
				}
				if ("EAT" == *iter)
				{
					iter++;
					students[it[0]].eat(atof((*iter).c_str()));
					students[it[0]].count_charm();
					continue;
				}
				if ("STUDY" == *iter)
				{
					iter++;
					students[it[0]].study(atof((*iter).c_str()));
					students[it[0]].count_charm();
					continue;
				}
				if ("WORK" == *iter)
				{
					iter++;
					students[it[0]].work(atof((*iter).c_str()));
					students[it[0]].count_charm();
					continue;
				}
				if ("EXERCISE" == *iter)
				{
					if (students[it[0]].sex() != "男")
						continue;
					iter++;
					students[it[0]].special_activity(atof((*iter).c_str()));
					students[it[0]].count_charm();
					continue;
				}
				if ("MAKEUP" == *iter)
				{
					if (students[it[0]].sex() == "男")
						continue;
					iter++;
					students[it[0]].special_activity(atof((*iter).c_str()));
					students[it[0]].count_charm();
					continue;
				}
			}
		}

	}
	return 0;
}
