//学生宿舍查询
#include "dorm_query.h"
#include <windows.h>

//宏定义更加方便改颜色！！
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

//通过学生姓名查找对应房间号
int name2room(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	char quit_ch = NULL;	//记录在分页显示过程中，用户是否要中途退出返回主菜单
	int count_line_num = 0;	//统计输出的行数，从而限制输出时一页的数量
	int count_input_num = 0;	//统计用户输入的行数，从而限制输入时一页的数量
	string names;
	string temp_name;
	vector<string> stu_names;	//用于存储要查询的学生姓名
	system("cls");
	print_line();
	cout << "*             ";
	color_change_blue(">> 查询学生的房间号 <<");
	cout << "             *" << endl;
	print_line();
	cout << "请输入1个或多个学生姓名,EOF结束(输入0返回主菜单):" << endl;
	while (1)
	{
		while (getline(cin, names))
		{
			if (names == "0")
				return 1;
			if (18 == count_input_num)
			{
				count_input_num = 0;
				system("cls");
				print_line();
				cout << "*             ";
				color_change_blue(">> 查询学生的房间号 <<");
				cout << "             *" << endl;
				print_line();
				cout << "请输入1个或多个学生姓名,EOF结束(输入0返回主菜单):" << endl;
			}
			else
			{
				istringstream sin(names);
				while (sin >> temp_name)
					stu_names.push_back(temp_name);
			}
			count_input_num++;
		}
		cin.clear();
		if (stu_names.empty())
		{
			system("cls");
			print_line();
			cout << "*             ";
			color_change_blue(">> 学生对应的房间号 <<");
			cout << "             *" << endl;
			print_line();
			cout << "未输入学生姓名,请重新输入!" << endl;
			cout << "请输入1个或多个学生姓名,EOF结束(输入0返回主菜单):" << endl;
		}
		else
			break;
	}
	system("cls");
	print_line();
	cout << "*             ";
	color_change_blue(">> 学生对应的房间号 <<");
	cout << "             *" << endl;
	print_line();
	Students::const_iterator it;
	for (vector<string>::const_iterator iter = stu_names.begin();
		iter != stu_names.end(); iter++)
	{
		if (19 == count_line_num)
		{
			count_line_num = 0;
			print_line();
			cout << "回车显示下一页(输入0返回主菜单)";
			quit_ch = getchar();
			if ('0' == quit_ch)
				return 1;
			system("cls");
			print_line();
			cout << "*             ";
			color_change_blue(">> 学生对应的房间号 <<");
			cout << "             *" << endl;
			print_line();
		}
		if ((it = students.find(*iter)) == students.end())
			cout << "*             " << *iter << string(12 - (*iter).size(), '-')
			<< "学生不存在" << "             *" << endl;
		else
		{
			cout << "*             " << *iter << string(17 - (*iter).size(), '-');
			if ((*it).second.get_floor() < 10)
				cout << '0' << (*it).second.get_floor() << '-';
			else
				cout << (*it).second.get_floor() << '-';
			if ((*it).second.get_room() < 10)
				cout << '0' << (*it).second.get_room() << "             *" << endl;
			else
				cout << (*it).second.get_room() << "             *" << endl;
		}
		count_line_num++;
	}
	print_line();
	cout << "回车返回主菜单";
	getchar();

	return 0;
}

//通过房间号查找房间中所有学生
int room2name(const Dorm& dorm)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	char quit_ch = NULL;	//记录在分页显示过程中，用户是否要中途退出返回主菜单
	int count_line_num = 0;	//统计输出行数
	size_t floor_num;	//用于存储要查询的房间号
	size_t room_num;
	string s;
	string blank;
	string sort_way;
	std::set<std::string> stu_name;
	system("cls");
	print_line();
	cout << "*            ";
	color_change_blue(">> 查询房间号对应学生 <<");
	cout << "            *" << endl;
	print_line();
	cout << "请输入房间号和姓名排序方式(输入0返回主菜单)" << endl;
	cout << "(升序为asc,降序为des)(如:07-12 asc):" << endl;
	
	while (getline(cin, s))
	{
		if (s == "0")
			return 1;
		else if (s.find('-') == string::npos)
		{
			system("cls");
			print_line();
			cout << "*            ";
			color_change_blue(">> 查询房间号对应学生 <<");
			cout << "            *" << endl;
			print_line();
			cout << "输入有误，请重新输入!" << endl;
			cout << "请输入房间号和姓名排序方式(输入0返回主菜单)" << endl;
			cout << "(升序为asc,降序为des)(如:07-12 asc):" << endl;
		}
		else
		{
			sort_way = *(split(s).rbegin());
			if ((sort_way != "asc") && (sort_way != "des"))
			{
				system("cls");
				print_line();
				cout << "*            ";
				color_change_blue(">> 查询房间号对应学生 <<");
				cout << "            *" << endl;
				print_line();
				cout << "输入有误，请重新输入!" << endl;
				cout << "请输入房间号和姓名排序方式(输入0返回主菜单)" << endl;
				cout << "(升序为asc,降序为des)(如:07-12 asc):" << endl;
			}
			else
				break;
		}
	}
	floor_num = atoi(s.substr(0, s.find('-')).c_str());
	room_num = atoi(s.substr(s.find('-') + 1).c_str());
	system("cls");
	print_line();
	cout << "*               >> 房间号:";
	if (floor_num < 10)
		cout << '0' << floor_num << '-';
	else
		cout << floor_num << '-';
	if (room_num < 10)
		cout << '0' << room_num << " <<               *" << endl;
	else
		cout << room_num << " <<               *" << endl;
	print_line();
	if (dorm.extract_exist(floor_num, room_num))
	{
		stu_name = dorm.get_stu(floor_num, room_num);
		if (sort_way == "asc")
		{
			for (std::set<std::string>::const_iterator iter = stu_name.begin();
				iter != stu_name.end(); iter++)
			{
				if (19 == count_line_num)
				{
					count_line_num = 0;
					print_line();
					cout << "回车显示下一页(输入0返回主菜单)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					cout << "*               >> 房间号:";
					if (floor_num < 10)
						cout << '0' << floor_num << '-';
					else
						cout << floor_num << '-';
					if (room_num < 10)
						cout << '0' << room_num << " <<               *" << endl;
					else
						cout << room_num << " <<               *" << endl;
					print_line();
				}
				blank = string((48 - (*iter).size()) / 2, ' ');
				cout << '*' << blank << *iter << blank << '*' << endl;
				count_line_num++;
			}
		}
		else
		{
			for (std::set<std::string>::const_reverse_iterator iter = stu_name.rbegin();
				iter != stu_name.rend(); iter++)
			{
				if (19 == count_line_num)
				{
					count_line_num = 0;
					print_line();
					cout << "回车显示下一页(输入0返回主菜单)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					cout << "*               >> 房间号:";
					if (floor_num < 10)
						cout << '0' << floor_num << '-';
					else
						cout << floor_num << '-';
					if (room_num < 10)
						cout << '0' << room_num << " <<               *" << endl;
					else
						cout << room_num << " <<               *" << endl;
					print_line();
				}
				blank = string((48 - (*iter).size()) / 2, ' ');
				cout << '*' << blank << *iter << blank << '*' << endl;
				count_line_num++;
			}
		}
	}
	else
	{
		cout << "*                  房间号不存在                  *" << endl;
	}
	print_line();
	cout << "回车返回主菜单";
	getchar();

	return 0;
}