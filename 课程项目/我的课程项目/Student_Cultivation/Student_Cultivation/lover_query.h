//ѧ��������ѯ
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

//����ĳ��ѧ��������ʷ
int lover_history_query(const Students&);
//��ѯ����ʷ����ѧ��
int lover_history_max(const Students&);
//��ѯ��������ֵ����ѧ��
int lover_charm_max(const Students&);

#endif