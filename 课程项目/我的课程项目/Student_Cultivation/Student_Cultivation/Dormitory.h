//定义宿舍类结构
#ifndef GUARD_DORMITORY_H
#define GUARD_DORMITORY_H

#include <map>
#include <set>
#include <string>
#include <fstream>
#include "Read_Config.h"

//定义宿舍樓、樓層、房間的數據結構
typedef std::set<std::string> Room;					//宿舍房间，使用set便于对学生姓名排序
typedef std::map<int, Room> Floor;					//宿舍楼层，使用map便于快速找到对应房间号的房间
typedef std::map<int, Floor> Dormitory;				//宿舍楼，使用map便于快速找到对应楼层号的楼层

class Dorm
{
public:
	Dorm();

	//获取某房间的学生姓名
	Room get_stu(size_t, size_t) const;

	//在宿舍中添加学生，如果添加成功则返回true，否则返回false
	void add_stu(size_t, size_t, std::string);

	//删除宿舍中某个学生即该学生退学或换宿舍----退学
	void delete_stu(size_t, size_t, std::string);

	//通过楼层数访问内部楼层
	Floor& operator[](size_t);

	//设置宿舍学生性别
	void set_gender(size_t, size_t, std::string);

	//获取宿舍学生性别
	std::string get_room_gender(size_t, size_t);

	//检测是否超出限制
	bool extract_limit(size_t, size_t);

	//检测房间号是否存在
	bool extract_exist(size_t, size_t) const;

	//增加楼层数
	void add_floor(size_t);

	//增加房间数
	void add_room(size_t, size_t);

	//增加房间容量
	void add_capacity(size_t, size_t, size_t);

	std::ifstream& set_init(std::ifstream&);

	size_t get_floor_limit() const { return floor_limit; }
	std::map<size_t, size_t> get_room_limit() const { return room_limit; }
	std::map<size_t, std::map<size_t, size_t> > get_capacity_limit() const { return capacity_limit; }
private:
	Dormitory dorm;

	//楼层数限制
	size_t floor_limit;

	//键值为楼层数，对应元素的值为每层楼的房间数限制
	std::map<size_t, size_t> room_limit;

	//分别以楼层数、房间数为键值，对应元素的值为房间容量限制
	std::map<size_t, std::map<size_t, size_t> > capacity_limit;

	//设置宿舍学生性别
	std::map<size_t, std::map<size_t, std::string> > room_gender;
};

#endif