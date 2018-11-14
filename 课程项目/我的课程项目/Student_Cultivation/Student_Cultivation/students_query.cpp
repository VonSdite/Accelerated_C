//学生系统查询界面
#include "students_query.h"
#include <windows.h>

//宏定义更加方便改颜色！！
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

#define color_change_red(a)  SetConsoleTextAttribute(handle, 0x0c);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

//学生系统查询界面
int students_query(Dorm& dorm, Students& students, Students& quit_stu)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	start();

	system("mode con cols=51 lines=25");		//设置显示窗口的列数和行数

	if (show_hello_screen())					//显示欢迎界面
		return 0;

	string select_num;
	string tmp;
	int select = 1;
	char ch;
	show_main_menu(select);

	//确认用户是否要退出系统
	bool confirm = false;

	//作为二级菜单case的选择以及跳出
	int select_one = 1;
	int flag1 = 0;
	int select_two = 1;
	int flag2 = 0;
	int select_three = 1;
	int flag3 = 0;

	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:
					--select;
					if (0 == select) select = 4;
					break;
				case 80:
					++select;
					if (5 == select) select = 1;
					break;
				}
				show_main_menu(select);
				break;
			case 27:
				show_main_menu(select);
				color_change_red("您确定要退出系统吗(y/n): ");
				see_guangbiao();
				while (cin >> tmp)
				{
					if (("y" == tmp) || ("Y" == tmp))
					{
						confirm = true;
						break;
					}
					else if (("n" == tmp) || ("N" == tmp))
					{
						confirm = false;
						break;
					}
					else
					{
						show_main_menu(select);
						cout << "输入有误，请重新输入!" << endl;
						color_change_red("您确定要退出系统吗(y/n): ");
					}
				}
				if (!confirm)
				{
					cover_guangbiao();
					show_main_menu(select);
				}
				break;
			case 8:
				if (show_hello_screen())						//显示欢迎界面
					return 0;
				show_main_menu(select);
				break;
			case 13:
				switch (select)
				{
				case 1:
					status_menu(select_one);
					while (1)
					{
						if (_kbhit())
						{
							ch = _getch();
							switch (ch)
							{
							case -32:
								ch = _getch();
								switch (ch)
								{
								case 72:
									--select_one;
									if (0 == select_one) select_one = 4;
									break;
								case 80:
									++select_one;
									if (5 == select_one) select_one = 1;
									break;
								}
								status_menu(select_one);
								break;
							case 13:
								see_guangbiao();
								switch (select_one)
								{
								case 4:
									flag1 = 1;
									break;
								case 1:
									stu_status_query(students);
									break;
								case 2:
									status_max_query(students);
									break;
								case 3:
									status_range_query(students);
								}
								break;
							}
							cover_guangbiao();
							if (flag1)
							{
								flag1 = 0;
								break;
							}
							status_menu(select_one);
						}
					}
					break;
				case 2:
					dorm_menu(select_two);
					while (1)
					{
						if (_kbhit())
						{
							ch = _getch();
							switch (ch)
							{
							case -32:
								ch = _getch();
								switch (ch)
								{
								case 72:
									--select_two;
									if (0 == select_two) select_two = 3;
									break;
								case 80:
									++select_two;
									if (4 == select_two) select_two = 1;
									break;
								}
								dorm_menu(select_two);
								break;
							case 13:
								see_guangbiao();
								switch (select_two)
								{
								case 3:
									flag2 = 1;
									break;
								case 1:
									name2room(students);
									break;
								case 2:
									room2name(dorm);
								}
								break;
							}
							cover_guangbiao();
							if (flag2)
							{
								flag2 = 0;
								break;
							}
							dorm_menu(select_two);
						}
					}
					break;
				case 3:
					love_menu(select_three);
					while (1)
					{
						if (_kbhit())
						{
							ch = _getch();
							switch (ch)
							{
							case -32:
								ch = _getch();
								switch (ch)
								{
								case 72:
									--select_three;
									if (0 == select_three) select_three = 4;
									break;
								case 80:
									++select_three;
									if (5 == select_three) select_three = 1;
									break;
								}
								love_menu(select_three);
								break;
							case 13:
								see_guangbiao();
								switch (select_three)
								{
								case 4:
									flag3 = 1;
									break;
								case 1:
									lover_history_query(students);
									break;
								case 2:
									lover_history_max(students);
									break;
								case 3:
									lover_charm_max(students);
								}
								break;
							}
							cover_guangbiao();
							if (flag3)
							{
								flag3 = 0;
								break;
							}
							love_menu(select_three);
						}
					}
					break;
				case 4:
					see_guangbiao();
					show_main_menu(select);
					color_change_red("您确定要退出系统吗(y/n): ");
					string tmp;
					while (cin >> tmp)
					{
						if (("y" == tmp) || ("Y" == tmp))
						{
							confirm = true;
							break;
						}
						else if (("n" == tmp) || ("N" == tmp))
						{
							confirm = false;
							break;
						}
						else
						{
							show_main_menu(select);
							cout << "输入有误，请重新输入!" << endl;
							color_change_red("您确定要退出系统吗(y/n): ");
						}
					}
					if (!confirm)
					{
						cover_guangbiao();
						show_main_menu(select);
					}
					break;
				}
			}
			if (confirm)
				break;
			show_main_menu(select);
		}
	}

	return 0;
}