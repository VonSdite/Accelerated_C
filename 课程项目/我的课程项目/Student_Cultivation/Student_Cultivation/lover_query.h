//学生恋爱查询
#ifndef GUARD_LOVER_QUERY
#define GUARD_LOVER_QUERY

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
#include "read_file.h"
#include "show_menu.h"

using std::cin;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::streamsize;
using std::fixed;
using std::setprecision;

//查找某个学生的恋爱史
int lover_history_query(const Students&);
//查询恋爱史最多的学生
int lover_history_max(const Students&);
//查询恋人魅力值最大的学生
int lover_charm_max(const Students&);

#endif