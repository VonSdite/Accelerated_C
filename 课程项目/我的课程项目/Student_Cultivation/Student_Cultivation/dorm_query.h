//ѧ�������ѯ
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

//ͨ��ѧ���������Ҷ�Ӧ�����
int name2room(const Students&);
//ͨ������Ų��ҷ���������ѧ��
int room2name(const Dorm&);

#endif