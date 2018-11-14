//学生恋爱查询
#include "lover_query.h"
#include <windows.h>

//宏定义更加方便改颜色！！
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)



//查找某个学生的恋爱史
int lover_history_query(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	string s;
	int sort_num;
	int num_length;
	char quit_ch = NULL;	//记录在分页显示过程中，用户是否要中途退出返回主菜单
	int count_line_num = 0;	//统计输出行数
	string name;	//用于存储要查询的学生姓名
	set<string> stu_name;	//将恋人姓名存储到set中便于对姓名排序
	map<double, set<string> > stu_charm_name;	//将恋人魅力值、姓名存储到map和set中，便于对魅力值和姓名排序
	string blank;
	string status;	//显示学生当前恋爱状态
	system("cls");
	print_line();
	cout << "*             ";
	color_change_blue(">> 查询某学生恋爱史 <<");
	cout << "             *" << endl;
	print_line();
	cout << "*                   1.时间排序                   *" << endl;
	cout << "*                   2.姓名排序                   *" << endl;
	cout << "*                   3.魅力排序                   *" << endl;
	print_line();
	cout << "请输入学生姓名和排序方式" << endl;
	cout << "如(张三 1)(输入0返回主菜单):" << endl;
	while (cin >> name)
	{
		if ("0" == name)
			return 1;
		if (students.find(name) == students.end())
		{
			system("cls");
			print_line();
			cout << "*             ";
			color_change_blue(">> 查询某学生恋爱史 <<");
			cout << "             *" << endl;
			print_line();
			cout << "*                   1.时间排序                   *" << endl;
			cout << "*                   2.姓名排序                   *" << endl;
			cout << "*                   3.魅力排序                   *" << endl;
			print_line();
			cout << "学生不存在，请重新输入!" << endl;
			cout << "请输入学生姓名和排序方式" << endl;
			cout << "如(张三 1)(输入0返回主菜单):" << endl;
			cin.ignore();
			continue;
		}
		cin >> sort_num;
		if ((sort_num < 1) || (sort_num > 3))
		{
			system("cls");
			print_line();
			cout << "*             ";
			color_change_blue(">> 查询某学生恋爱史 <<");
			cout << "             *" << endl;
			print_line();
			cout << "*                   1.时间排序                   *" << endl;
			cout << "*                   2.姓名排序                   *" << endl;
			cout << "*                   3.魅力排序                   *" << endl;
			print_line();
			cout << "输入有误，请重新输入!" << endl;
			cout << "请输入学生姓名和排序方式" << endl;
			cout << "如(张三 1)(输入0返回主菜单):" << endl;
			continue;
		}
		break;
	}
	Students::const_iterator iter = students.find(name);
	const vector<string>& lover_history = (iter->second).get_lover_history();
	system("cls");
	print_line();
	blank = string((34 - (iter->second).name().size()) / 2, ' ');
	cout << '*' << blank << ">> " << (iter->second).name() << "の恋爱史" << " <<" << blank << '*' << endl;
	print_line();
	if ((iter->second).love_status())
	{
		blank = string((28 - (iter->second).get_lover_name().size()) / 2, ' ');
		status = "*" + blank + "与" + (iter->second).get_lover_name() + "恋爱ing(*￣︶￣*)/" + blank + "*";
	}
	else
	{
		status = "*             本宝宝单身中o(≧口≦)o             *";
	}
	cout << status << endl;
	print_line();
	cin.ignore();
	if (0 == lover_history.size())
		cout << "*                   恋爱史为空                   *" << endl;
	else
	{
		switch (sort_num)
		{
		case 1:
			for (vector<string>::const_iterator it = lover_history.begin(); it != lover_history.end(); it++)
			{
				if (15 == count_line_num)
				{
					count_line_num = 0;
					print_line();
					cout << "回车显示下一页(输入0返回主菜单)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					blank = string((34 - (iter->second).name().size()) / 2, ' ');
					cout << '*' << blank << ">> " << (iter->second).name() << "の恋爱史" << " <<" << blank << '*' << endl;
					print_line();
					cout << status << endl;
					print_line();
				}
				blank = string((48 - (*it).size()) / 2, ' ');
				cout << '*' << blank << *it << blank << '*' << endl;
				count_line_num++;
			}
			break;
		case 2:
			for (vector<string>::const_iterator it = lover_history.begin(); it != lover_history.end(); it++)
			{
				stu_name.insert(*it);
			}
			for (set<string>::const_iterator it = stu_name.begin(); it != stu_name.end(); it++)
			{
				if (15 == count_line_num)
				{
					count_line_num = 0;
					print_line();
					cout << "回车显示下一页(输入0返回主菜单)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					blank = string((34 - (iter->second).name().size()) / 2, ' ');
					cout << '*' << blank << ">> " << (iter->second).name() << "の恋爱史" << " <<" << blank << '*' << endl;
					print_line();
					cout << status << endl;
					print_line();
				}
				blank = string((48 - (*it).size()) / 2, ' ');
				cout << '*' << blank << *it << blank << '*' << endl;
				count_line_num++;
			}
			break;
		case 3:
			Students::const_iterator stu_iter;
			for (vector<string>::const_iterator it = lover_history.begin(); it != lover_history.end(); it++)
			{
				stu_iter = students.find(*it);
				stu_charm_name[(stu_iter->second).charm()].insert(*it);
			}
			streamsize prec = cout.precision();
			cout << "*                 姓名----魅力值                 *" << endl;
			for (map<double, set<string> >::const_iterator it = stu_charm_name.begin();
				it != stu_charm_name.end(); it++)
			{
				for (set<string>::const_iterator stu_it = (it->second).begin();
					stu_it != (it->second).end(); stu_it++)
				{
					if (15 == count_line_num)
					{
						count_line_num = 0;
						print_line();
						cout << "回车显示下一页(输入0返回主菜单)";
						quit_ch = getchar();
						if ('0' == quit_ch)
							return 1;
						system("cls");
						print_line();
						blank = string((34 - (iter->second).name().size()) / 2, ' ');
						cout << '*' << blank << ">> " << (iter->second).name() << "の恋爱史" << " <<" << blank << '*' << endl;
						print_line();
						cout << status << endl;
						print_line();
						cout << "*                 姓名----魅力值                 *" << endl;
					}
					cout << "*                 " << *stu_it;
					num_length = get_length((int)(it->first));
					blank = string(11 - (*stu_it).size() - num_length, '-');
					cout << blank << fixed << setprecision(2) << it->first
						<< "                 *" << endl;
					count_line_num++;
				}
			}
			setprecision(prec);
		}
	}
	print_line();
	cout << "回车返回主菜单";
	getchar();

	return 0;
}

//查询恋爱史最多的学生
int lover_history_max(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	char quit_ch = NULL;	//记录在分页显示过程中，用户是否要中途退出返回主菜单
	int count_line_num = 0;	//存储输出的行数，从而限制输出时一页的数量
							//用于存储恋爱史最多的学生姓名，使用set便于对姓名排序
	set<string> stu_name;
	//用于存储指向恋爱史最多学生的迭代器,先存储迭代器避免过多次获取学生姓名降低效率
	vector<Students::const_iterator> max_stu;
	int num_length;
	size_t max_num = 0;
	system("cls");
	print_line();
	cout << "*             ";
	color_change_blue(">> 恋爱史最多的学生 <<");
	cout << "             *" << endl;
	print_line();
	for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
	{
		if ((iter->second).get_lover_num() > max_num)
		{
			max_num = (iter->second).get_lover_num();
			max_stu.clear();
			max_stu.push_back(iter);
		}
		else if ((iter->second).get_lover_num() == max_num)
		{
			max_stu.push_back(iter);
		}
	}
	for (vector<Students::const_iterator>::const_iterator iter = max_stu.begin();
		iter != max_stu.end(); iter++)
	{
		stu_name.insert(((*iter)->second).name());
	}
	num_length = get_length(max_num);
	cin.ignore();
	for (set<string>::const_iterator iter = stu_name.begin(); iter != stu_name.end(); iter++)
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
			color_change_blue(">> 恋爱史最多的学生 <<");
			cout << "             *" << endl;
			print_line();
		}
		cout << "*                 " << *iter << string(14 - (*iter).size() - num_length, '-')
			<< max_num << "                 *" << endl;
		count_line_num++;
	}
	print_line();
	cout << "回车返回主菜单";
	getchar();

	return 0;
}

//查询恋人魅力值最大的学生
int lover_charm_max(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	char quit_ch = NULL;	//记录在分页显示过程中，用户是否要中途退出返回主菜单
	int count_line_num = 0;	//存储输出的行数，从而限制输出时一页的数量
	int num_length;
	vector<Students::const_iterator> max;	//用于保存指向魅力最大值学生的迭代器
	set<string> max_stu_name;	//用于保存最大魅力值的学生姓名，使用set便于对学生姓名进行排序
	double max_num = (students.begin()->second).charm();	//用于存储状态最大、最小值
	max.push_back(students.begin());
	system("cls");
	print_line();
	cout << "*           ";
	color_change_blue(">> 恋人魅力值最高的学生 <<");
	cout << "           *" << endl;
	print_line();
	max.push_back(students.begin());
	cin.ignore();
	for (Students::const_iterator iter = students.begin()++; iter != students.end(); iter++)
	{
		if (max_num == (iter->second).charm())
			max.push_back(iter);
		else if (max_num < (iter->second).charm())
		{
			max_num = (iter->second).charm();
			max.clear();
			max.push_back(iter);
		}
	}
	num_length = get_length((int)max_num) + 3;
	for (vector<Students::const_iterator>::const_iterator iter = max.begin(); iter != max.end(); iter++)
	{
		max_stu_name.insert((*iter)->second.name());
	}
	streamsize prec = cout.precision();
	for (set<string>::const_iterator iter = max_stu_name.begin(); iter != max_stu_name.end(); iter++)
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
			cout << "*           ";
			color_change_blue(">> 恋人魅力值最高的学生 <<");
			cout << "           *" << endl;
			print_line();
		}
		cout << "*" << string(14, ' ') << *iter << string(20 - (*iter).size() - num_length, '-') << fixed <<
			setprecision(2) << max_num << string(14, ' ') << '*' << endl;
		count_line_num++;
	}
	setprecision(prec);
	print_line();
	cout << "回车返回主菜单";
	getchar();

	return 0;
}