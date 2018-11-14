#ifndef GUARD_STATUS_QUERY
#define GUARD_STATUS_QUERY

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include "show_menu.h"
//ѧ��״̬��ѯ
#include "read_file.h"

using std::cin;
using std::string;
using std::fixed;
using std::setprecision;
using std::streamsize;
using std::vector;
using std::map;
using std::set;

//ĳѧ��״̬��ѯ
int stu_status_query(const Students&);
//״̬��ֵ��ѯ
int status_max_query(const Students&);
//״̬��Χ��ѯ
int status_range_query(const Students&);

#endif