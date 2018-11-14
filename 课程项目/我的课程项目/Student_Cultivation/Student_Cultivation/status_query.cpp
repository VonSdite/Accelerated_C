//学生状态查询
#include "status_query.h"
#include <windows.h>
#include <iomanip>

//宏定义更加方便改颜色！！
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

//用于显示每一项状态项
void print_status(string item, double num)
{
	print_line();
	cout << "*         " << item << "         ||";
	int num_length = get_length((int)num);
	string blank = string((21 - num_length) / 2, ' ');
	streamsize prec = cout.precision();
	cout << blank << fixed << setprecision(2) << num << blank;
	setprecision(prec);
	if ((num_length % 2) != 0)
		cout << '*' << endl;
	else
		cout << ' ' << '*' << endl;
}

//某学生状态查询
int stu_status_query(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	string blank;	//用于存储中间输出的空格
	system("cls");
	string name;
	print_line();
	cout << "*             ";
	color_change_blue(">> 查询某学生的状态 <<");
	cout << "             *" << endl;
	print_line();
	cout << "请输入学生姓名(输入0返回主菜单):";
	while ((cin >> name) && (students.find(name) == students.end()))
	{
		system("cls");
		print_line();
		cout << "*             ";
		color_change_blue(">> 查询某学生的状态 <<");
		cout << "             *" << endl;
		print_line();
		if (name == "0")
			return 1;
		cout << "学生不存在！" << endl;
		cout << "请重新输入学生姓名(输入0返回主菜单):";
	}
	//由于students是const引用，所以不能直接使用[]运算符
	Students::const_iterator iter = students.find(name);
	system("cls");
	//标题栏
	print_line();
	blank = string((32 - (iter->second).name().size()) / 2, ' ');
	cout << '*' << blank << ">> " << (iter->second).name() << "の状态信息" << " <<" << blank << '*' << endl;
	//姓名栏
	print_line();
	blank = string((24 - (iter->second).name().size()) / 2, ' ');
	cout << "*         姓名         ||" << blank << (iter->second).name() << blank << '*' << endl;
	//性别栏
	print_line();
	cout << "*         性别         ||" << "           ";
	if ("男" == (iter->second).sex())
		cout << "男";
	else
		cout << "女";
	cout << "           *" << endl;
	//状态栏
	print_status("体重", (iter->second).weight());
	print_status("金钱", (iter->second).money());
	print_status("知识", (iter->second).knowledge());
	if ("男" == (iter->second).sex())
		print_status("健康", (iter->second).special());
	else
		print_status("容貌", (iter->second).special());
	print_status("魅力", (iter->second).charm());

	print_line();
	cout << "*       " << "曾退学过否" << "     ||";
	string blank2 = string(9, ' ');
	cout << blank2 << " ";
	if ((iter->second).get_is_quit_school())
		cout << "是";
	else cout << "否";
	cout << blank2 << "   *" << endl;

	print_line();
	cout << "*       " << "是否恋爱中" << "     ||";
	string blank3 = string(9, ' ');
	cout << blank3 << " ";
	if ((iter->second).love_status())
		cout << "是";
	else cout << "否";
	cout << blank3 << "   *" << endl;


	print_line();
	cout << "*         " << "宿舍号" << "       ||";
	string blank1 = string(8, ' ');
	streamsize prec = cout.precision();
	cout << blank1 << " "
		<< std::setw(2) << std::setfill('0')
		<< (iter->second).get_floor()
		<< "-"
		<< std::setw(2) << std::setfill('0')
		<< (iter->second).get_room() << blank;
	setprecision(prec);
	cout << '*' << endl;

	print_line();
	cout << "回车返回主菜单";
	cin.ignore();
	getchar();

	return 0;
}

//输出状态最值
int print_max_status(string item, const vector<Students::const_iterator>& max,
	const vector<Students::const_iterator>& min, double max_num, double min_num)
{
	char quit_ch = NULL;	//记录在分页显示过程中，用户是否要中途退出返回主菜单
	int count_line_num = 0;
	string blank;
	int num_length;
	system("cls");
	print_line();
	cout << '*' << string(18, ' ') << item << "最值查询" << string(18, ' ') << '*' << endl;
	print_line();
	cout << "*      最值     ||     姓名     ||     数值      *" << endl;
	cin.ignore();
	streamsize prec = cout.precision();
	for (vector<Students::const_iterator>::const_iterator iter = max.begin(); iter != max.end(); iter++)
	{
		if (count_line_num == 9)
		{
			count_line_num = 0;
			print_line();
			cout << "回车显示下一页(输入0返回主菜单)";
			quit_ch = getchar();
			if ('0' == quit_ch)
				return 1;
			system("cls");
			print_line();
			cout << '*' << string(18, ' ') << item << "最值查询" << string(18, ' ') << '*' << endl;
			print_line();
			cout << "*      最值     ||     姓名     ||     数值      *" << endl;
		}
		print_line();
		cout << "*      MAX      ||";
		blank = string((14 - ((*iter)->second).name().size()) / 2, ' ');
		cout << blank << ((*iter)->second).name() << blank << "||";
		num_length = get_length((int)max_num);
		blank = string((12 - num_length) / 2, ' ');
		cout << blank << fixed << setprecision(2) << max_num << blank;
		if ((num_length % 2) == 0)
			cout << '*' << endl;
		else
			cout << ' ' << '*' << endl;
		count_line_num++;
	}
	for (vector<Students::const_iterator>::const_iterator iter = min.begin(); iter != min.end(); iter++)
	{
		if (count_line_num == 9)
		{
			count_line_num = 0;
			print_line();
			cout << "回车显示下一页(输入0返回主菜单)";
			quit_ch = getchar();
			if ('0' == quit_ch)
				return 1;
			system("cls");
			print_line();
			cout << '*' << string(18, ' ') << item << "最值查询" << string(18, ' ') << '*' << endl;
			print_line();
			cout << "*      最值     ||     姓名     ||     数值      *" << endl;
		}
		print_line();
		cout << "*      MIN      ||";
		blank = string((14 - ((*iter)->second).name().size()) / 2, ' ');
		cout << blank << ((*iter)->second).name() << blank << "||";
		num_length = get_length((int)min_num);
		blank = string((12 - num_length) / 2, ' ');
		cout << blank << fixed << setprecision(2) << min_num << blank;
		if ((num_length % 2) == 0)
			cout << '*' << endl;
		else
			cout << ' ' << '*' << endl;
		count_line_num++;
	}
	setprecision(prec);	//将输出流设为一开始的状态
	print_line();

	return 0;
}

//状态最值查询
int status_max_query(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	string status;	//用于读入要查询的状态类型
	vector<Students::const_iterator> max;	//用于保存指向该状态最大值学生的迭代器
	vector<Students::const_iterator> min;	//用于保存指向该状态最小值学生的迭代器
	double max_num, min_num;	//用于存储状态最大、最小值
	system("cls");
	print_line();
	cout << "*               ";
	color_change_blue(">> 状态最值查询 <<");
	cout << "               *" << endl;
	print_line();
	cout << "请输入要查询的状态(如:体重)(输入0返回主菜单):";
	while ((cin >> status) && (status != "0"))
	{
		if (status == "体重")
		{
			max.push_back(students.begin());
			min.push_back(students.begin());
			min_num = max_num = (students.begin()->second).weight();
			for (Students::const_iterator iter = students.begin()++; iter != students.end(); iter++)
			{
				if (max_num == (iter->second).weight())
					max.push_back(iter);
				if (min_num == (iter->second).weight())
					min.push_back(iter);
				if (max_num < (iter->second).weight())
				{
					max_num = (iter->second).weight();
					max.clear();
					max.push_back(iter);
				}
				else if (min_num >(iter->second).weight())
				{
					min_num = (iter->second).weight();
					min.clear();
					min.push_back(iter);
				}
			}
			print_max_status("体重", max, min, max_num, min_num);
			cout << "回车返回主菜单";
			getchar();
			break;
		}
		if (status == "金钱")
		{
			max.push_back(students.begin());
			min.push_back(students.begin());
			min_num = max_num = (students.begin()->second).money();
			for (Students::const_iterator iter = students.begin()++; iter != students.end(); iter++)
			{
				if (max_num == (iter->second).money())
					max.push_back(iter);
				if (min_num == (iter->second).money())
					min.push_back(iter);
				if (max_num < (iter->second).money())
				{
					max_num = (iter->second).money();
					max.clear();
					max.push_back(iter);
				}
				else if (min_num >(iter->second).money())
				{
					min_num = (iter->second).money();
					min.clear();
					min.push_back(iter);
				}
			}
			print_max_status("金钱", max, min, max_num, min_num);
			cout << "回车返回主菜单";
			getchar();
			break;
		}
		if (status == "知识")
		{
			max.push_back(students.begin());
			min.push_back(students.begin());
			min_num = max_num = (students.begin()->second).knowledge();
			for (Students::const_iterator iter = students.begin()++; iter != students.end(); iter++)
			{
				if (max_num == (iter->second).knowledge())
					max.push_back(iter);
				if (min_num == (iter->second).knowledge())
					min.push_back(iter);
				if (max_num < (iter->second).knowledge())
				{
					max_num = (iter->second).knowledge();
					max.clear();
					max.push_back(iter);
				}
				else if (min_num >(iter->second).knowledge())
				{
					min_num = (iter->second).knowledge();
					min.clear();
					min.push_back(iter);
				}
			}
			print_max_status("知识", max, min, max_num, min_num);
			cout << "回车返回主菜单";
			getchar();
			break;
		}
		if (status == "容貌")
		{
			Students::const_iterator iter = students.begin();
			while ("男" == (iter->second).sex())
				iter++;
			if (iter == students.end())
			{
				cout << "学生数据中没有女生" << endl;
				cout << "回车返回主菜单";
				cin.ignore();
				getchar();
				break;
			}
			max.push_back(iter);
			min.push_back(iter);
			min_num = max_num = (iter->second).special();
			for (; iter != students.end(); iter++)
			{
				if ("女" == (iter->second).sex())
				{
					if (max_num == (iter->second).special())
						max.push_back(iter);
					if (min_num == (iter->second).special())
						min.push_back(iter);
					if (max_num < (iter->second).special())
					{
						max_num = (iter->second).special();
						max.clear();
						max.push_back(iter);
					}
					else if (min_num >(iter->second).special())
					{
						min_num = (iter->second).special();
						min.clear();
						min.push_back(iter);
					}
				}
			}
			print_max_status("容貌", max, min, max_num, min_num);
			cout << "回车返回主菜单";
			getchar();
			break;
		}
		if (status == "健康")
		{
			Students::const_iterator iter = students.begin();
			while ("女" == (iter->second).sex())
				iter++;
			if (iter == students.end())
			{
				cout << "学生数据中没有男生" << endl;
				cout << "回车返回主菜单";
				cin.ignore();
				getchar();
				break;
			}
			max.push_back(iter);
			min.push_back(iter);
			min_num = max_num = (iter->second).special();
			for (; iter != students.end(); iter++)
			{
				if ("男" == (iter->second).sex())
				{
					if (max_num == (iter->second).special())
						max.push_back(iter);
					if (min_num == (iter->second).special())
						min.push_back(iter);
					if (max_num < (iter->second).special())
					{
						max_num = (iter->second).special();
						max.clear();
						max.push_back(iter);
					}
					else if (min_num >(iter->second).special())
					{
						min_num = (iter->second).special();
						min.clear();
						min.push_back(iter);
					}
				}
			}
			print_max_status("健康", max, min, max_num, min_num);
			cout << "回车返回主菜单";
			getchar();
			break;
		}
		if (status == "魅力")
		{
			max.push_back(students.begin());
			min.push_back(students.begin());
			min_num = max_num = (students.begin()->second).charm();
			for (Students::const_iterator iter = students.begin()++; iter != students.end(); iter++)
			{
				if (max_num == (iter->second).charm())
					max.push_back(iter);
				if (min_num == (iter->second).charm())
					min.push_back(iter);
				if (max_num < (iter->second).charm())
				{
					max_num = (iter->second).charm();
					max.clear();
					max.push_back(iter);
				}
				else if (min_num >(iter->second).charm())
				{
					min_num = (iter->second).charm();
					min.clear();
					min.push_back(iter);
				}
			}
			print_max_status("魅力", max, min, max_num, min_num);
			cout << "回车返回主菜单";
			getchar();
			break;
		}
		else
		{
			system("cls");
			print_line();
			cout << "*               ";
			color_change_blue(">> 状态最值查询 <<");
			cout << "               *" << endl;
			print_line();
			cout << "输入错误!" << endl;
			cout << "请重新输入要查询的状态(输入0返回主菜单):";
		}
	}

	return 0;
}

//显示已排序好的范围查询内容
int show_sorted_stu(const map<double, set<string> >& sorted_stu, string item, string sort_way)
{
	char quit_ch = NULL;	//记录在分页显示过程中，用户是否要中途退出返回主菜单
	int count_line_num = 0;		//存储输出的行数，从而限制输出时一页的数量
	int num_length;	//存储状态值长度
	system("cls");
	print_line();
	cout << "*               >> " << item << "范围查询 <<               *" << endl;
	print_line();
	if (sort_way == "asc")
	{
		for (map<double, set<string> >::const_iterator iter = sorted_stu.begin();
			iter != sorted_stu.end(); iter++)
		{
			for (set<string>::const_iterator it = iter->second.begin();
				it != iter->second.end(); it++)
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
					cout << "*               >> " << item << "范围查询 <<               *" << endl;
					print_line();
				}
				cout << '*' << string(15, ' ') << *it;
				num_length = get_length((int)(iter->first)) + 3;
				cout << string(18 - (*it).size() - num_length, '-');
				streamsize prec = cout.precision();
				cout << fixed << setprecision(2) << iter->first << string(15, ' ') << '*' << endl;
				count_line_num++;
			}
		}
		print_line();
		cout << "回车返回主菜单";
		getchar();
	}
	else
	{
		for (map<double, set<string> >::const_reverse_iterator iter = sorted_stu.rbegin();
			iter != sorted_stu.rend(); iter++)
		{
			for (set<string>::const_reverse_iterator it = iter->second.rbegin();
				it != iter->second.rend(); it++)
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
					cout << "*               >> " << item << "范围查询 <<               *" << endl;
					print_line();
				}
				cout << '*' << string(15, ' ') << *it;
				num_length = get_length((int)(iter->first)) + 3;
				cout << string(18 - (*it).size() - num_length, '-');
				streamsize prec = cout.precision();
				cout << fixed << setprecision(2) << iter->first << string(15, ' ') << '*' << endl;
				count_line_num++;
			}
		}
		print_line();
		cout << "回车返回主菜单";
		getchar();
	}

	return 0;
}

//状态范围查询
int status_range_query(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	//用于存储符合条件的学生及状态值，使用map便于对状态值排序，使用set便于对姓名排序
	map<double, set<string> > sorted_stu;
	double min_num, max_num;	//存储查询范围
	string sort_way;	//存储显示的排序方式
	string status;	//存储要查询的状态类型
	system("cls");
	print_line();
	cout << "*               ";
	color_change_blue(">> 状态范围查询 <<");
	cout << "               *" << endl;
	print_line();
	cout << "请输入状态、范围、排序方式(输入0返回主菜单)" << endl;
	cout << "(升序为asc,降序为des)(如:体重 70 80 asc):" << endl;
	while ((cin >> status) && (status != "0"))
	{
		if (!(cin >> min_num >> max_num >> sort_way) || (min_num > max_num) ||
			((sort_way != "asc") && (sort_way != "des")))
		{
			system("cls");
			print_line();
			cout << "*               ";
			color_change_blue(">> 状态范围查询 <<");
			cout << "               *" << endl;
			print_line();
			cout << "输入有误，请重新输入!" << endl;
			cout << "请输入状态、范围、排序方式(输入0返回主菜单)" << endl;
			cout << "(升序为asc，降序为des)(如:体重 70 80 asc):" << endl;
			continue;
		}
		cin.ignore();
		if ("体重" == status)
		{
			for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
			{
				if ((min_num > (iter->second).weight()) || (max_num < (iter->second).weight()))
					continue;
				sorted_stu[(iter->second).weight()].insert((iter->second).name());
			}
			show_sorted_stu(sorted_stu, status, sort_way);
			break;
		}
		if ("金钱" == status)
		{
			for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
			{
				if ((min_num > (iter->second).money()) || (max_num < (iter->second).money()))
					continue;
				sorted_stu[(iter->second).money()].insert((iter->second).name());
			}
			show_sorted_stu(sorted_stu, status, sort_way);
			break;
		}
		if ("知识" == status)
		{
			for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
			{
				if ((min_num > (iter->second).knowledge()) || (max_num < (iter->second).knowledge()))
					continue;
				sorted_stu[(iter->second).knowledge()].insert((iter->second).name());
			}
			show_sorted_stu(sorted_stu, status, sort_way);
			break;
		}
		if ("容貌" == status)
		{
			for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
			{
				if ("男" == (iter->second).sex())
					continue;
				if ((min_num > (iter->second).knowledge()) || (max_num < (iter->second).knowledge()))
					continue;
				sorted_stu[(iter->second).knowledge()].insert((iter->second).name());
			}
			show_sorted_stu(sorted_stu, status, sort_way);
			break;
		}
		if ("健康" == status)
		{
			for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
			{
				if ("女" == (iter->second).sex())
					continue;
				if ((min_num > (iter->second).knowledge()) || (max_num < (iter->second).knowledge()))
					continue;
				sorted_stu[(iter->second).knowledge()].insert((iter->second).name());
			}
			show_sorted_stu(sorted_stu, status, sort_way);
			break;
		}
		if ("魅力" == status)
		{
			for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
			{
				if ((min_num > (iter->second).charm()) || (max_num < (iter->second).charm()))
					continue;
				sorted_stu[(iter->second).charm()].insert((iter->second).name());
			}
			show_sorted_stu(sorted_stu, status, sort_way);
			break;
		}
	}

	return 0;
}