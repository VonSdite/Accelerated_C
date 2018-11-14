//学生宿舍查询
#ifndef GUARD_DORM_QUERY
#define GUARD_DORM_QUERY

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "read_file.h"
#include "show_menu.h"
#include "split.h"

using std::cin;
using std::string;
using std::vector;
using std::istringstream;

//通过学生姓名查找对应房间号
int name2room(const Students&);
//通过房间号查找房间中所有学生
int room2name(const Dorm&);

#endif