#ifndef GUARD_STATUS_QUERY
#define GUARD_STATUS_QUERY

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include "show_menu.h"
//学生状态查询
#include "read_file.h"

using std::cin;
using std::string;
using std::fixed;
using std::setprecision;
using std::streamsize;
using std::vector;
using std::map;
using std::set;

//某学生状态查询
int stu_status_query(const Students&);
//状态最值查询
int status_max_query(const Students&);
//状态范围查询
int status_range_query(const Students&);

#endif