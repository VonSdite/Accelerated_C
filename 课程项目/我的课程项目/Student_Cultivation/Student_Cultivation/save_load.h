#ifndef GUARD_SAVE_LOAD_H
#define GUARD_SAVE_LOAD_H

#include <fstream>
#include <iostream>
#include "Dormitory.h"
#include "Student_info.h"
#include "read_file.h"

using std::ifstream;
using std::ofstream;
using std::endl;

bool load_info(Dorm& dorm, Students& students, ifstream& infile)			//����
{
	Student_info record;
	size_t floor_num;
	size_t room_num;
	char temp;

	dorm.set_init(infile);							//��������֮ǰ����Ϣ
	while (record.read(infile))
	{
		infile >> floor_num;
		infile >> temp;								//��ȡ¥����������֮��ġ�-����
		infile >> room_num;
		if (dorm.extract_limit(floor_num, room_num))
		{
			record.set_dorm(floor_num, room_num);

			//�ж������Ƿ�Ϊ�գ���Ϊ����ֱ�ӽ�record���룬ͬʱ��ѧ������ȫ��ѧ����Ϣ
			if (dorm[floor_num][room_num].empty())
			{
				dorm.add_stu(floor_num, room_num, record.name());
				dorm.set_gender(floor_num, room_num, record.sex());
				students[record.name()] = record;
			}
			//����Ϊ�գ�������Ա��ж��Ƿ�ѧ�����������ͬʱ�жϸ����������Ƿ񳬹�����
			else
			{
				if (dorm.get_room_gender(floor_num, room_num) == record.sex() && dorm.extract_limit(floor_num, room_num))
				{
					dorm.add_stu(floor_num, room_num, record.name());
					students[record.name()] = record;
				}
			}
			students[record.name()].set_init(infile);
		}
	}
	return 0;
}

bool save_info(Dorm& dorm, Students& students, ofstream& infile)			//�浵
{
	infile << dorm.get_floor_limit() << endl;
	std::map<size_t, size_t> room = dorm.get_room_limit();
	for (size_t i = 1; i <= dorm.get_floor_limit(); i++)
	{
		infile << room[i] << endl;
	}

	std::map<size_t, std::map<size_t, size_t> > capacity = dorm.get_capacity_limit();
	for (size_t floor_num = 1; floor_num <= dorm.get_floor_limit(); floor_num++)
	{
		for (size_t room_num = 1; room_num <= room[floor_num]; room_num++)
		{
			infile << capacity[floor_num][room_num] << " ";
		}
		infile << endl;
	}

	for (auto it : students)
	{
		infile << it.second.name() << " "
			<< it.second.sex() << " "
			<< it.second.get_floor() << "-"
			<< it.second.get_room() << " "
			<< it.second.weight() << " "
			<< it.second.money() << " "
			<< it.second.knowledge() << " "
			<< it.second.charm() << " "
			<< it.second.special() << " "
			<< it.second.love_status() << " "
			<< it.second.get_is_quit_school() << endl
			<< it.second.get_lover_num() << " ";

		std::vector<std::string> love = it.second.get_lover_history();
		for (size_t i = 0; i < it.second.get_lover_num(); i++)
		{
			infile << love[i] << " ";
		}
		infile << endl;
	}
	return 0;
}


#endif // !GUARD_SAVE_LOAD_H
