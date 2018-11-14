//与宿舍类相关的函数
#include "dormitory.h"

Dorm::Dorm()
{
	//设置宿舍楼初始层数
	floor_limit = (size_t)dou(Configure::configure["FLOOR"]);

	//设置每层的初始房间数
	for (size_t floor_num = 1; floor_num <= floor_limit; floor_num++)
	{
		room_limit[floor_num] = (size_t)dou(Configure::configure["ROOM"]);
	}

	//设置每间房的初始容量
	for (size_t floor_num = 1; floor_num <= floor_limit; floor_num++)
	{
		for (size_t room_num = 1; room_num <= room_limit[floor_num]; room_num++)
		{
			capacity_limit[floor_num][room_num] = (size_t)dou(Configure::configure["CAPACITY"]);
		}
	}
}

Room Dorm::get_stu(size_t floor_num, size_t room_num) const
{
	Floor::const_iterator iter = (dorm.find(floor_num)->second).find(room_num);
	return iter->second;
}

void Dorm::add_stu(size_t floor_num, size_t room_num, std::string stu_name)
{
	dorm[floor_num][room_num].insert(stu_name);
}

bool Dorm::extract_limit(size_t floor_num, size_t room_num)
{
	if (floor_num <= floor_limit)
		if (room_num <= room_limit[floor_num])
			if (dorm[floor_num][room_num].size() <= capacity_limit[floor_num][room_num])
				return true;

	return false;
}

bool Dorm::extract_exist(size_t floor_num, size_t room_num) const
{
	if (floor_num <= floor_limit)
	{
		std::map<size_t, size_t>::const_iterator iter = room_limit.find(floor_num);
		if (room_num <= iter->second)
			return true;
	}

	return false;
}

void Dorm::delete_stu(size_t floor_num, size_t room_num, std::string stu_name)
{
	dorm[floor_num][room_num].erase(stu_name);
}

Floor& Dorm::operator[](size_t floor_num)
{
	return dorm[floor_num];
}

void Dorm::set_gender(size_t floor_num, size_t room_num, std::string gender)
{
	room_gender[floor_num][room_num] = gender;
}

std::string Dorm::get_room_gender(size_t floor_num, size_t room_num)
{
	return room_gender[floor_num][room_num];
}

void Dorm::add_floor(size_t add_num)
{
	for (size_t floor_num = floor_limit + 1; floor_num <= floor_limit + add_num; floor_num++)
	{
		room_limit[floor_num] = (size_t)dou(Configure::configure["ROOM"]);
	}
	for (size_t floor_num = floor_limit + 1; floor_num <= floor_limit + add_num; floor_num++)
	{
		for (size_t room_num = 1; room_num <= room_limit[floor_num]; room_num++)
		{
			capacity_limit[floor_num][room_num] = (size_t)dou(Configure::configure["CAPACITY"]);
		}
	}
	floor_limit += add_num;
}

void Dorm::add_room(size_t floor_num, size_t add_num)
{
	for (size_t room_num = room_limit[floor_num] + 1; room_num <= room_limit[floor_num] + add_num; room_num++)
	{
			capacity_limit[floor_num][room_num] = (size_t)dou(Configure::configure["CAPACITY"]);
	}
	room_limit[floor_num] += add_num;
}

void Dorm::add_capacity(size_t floor_num, size_t room_num, size_t add_num)
{
	capacity_limit[floor_num][room_num] += add_num;
}

std::ifstream& Dorm::set_init(std::ifstream& is)
{
	//设置楼层数
	is >> floor_limit;

	//设置每层的房间数
	for (size_t floor_num = 1; floor_num <= floor_limit; floor_num++)
	{
		is >> room_limit[floor_num];
	}

	//设置每间房的容量
	for (size_t floor_num = 1; floor_num <= floor_limit; floor_num++)
	{
		for (size_t room_num = 1; room_num <= room_limit[floor_num]; room_num++)
		{
			is >> capacity_limit[floor_num][room_num];
		}
	}
	return is;
}
