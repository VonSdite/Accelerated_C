//ѧ�������ѯ
#include "dorm_query.h"
#include <windows.h>

//�궨����ӷ������ɫ����
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

//ͨ��ѧ���������Ҷ�Ӧ�����
int name2room(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	char quit_ch = NULL;	//��¼�ڷ�ҳ��ʾ�����У��û��Ƿ�Ҫ��;�˳��������˵�
	int count_line_num = 0;	//ͳ��������������Ӷ��������ʱһҳ������
	int count_input_num = 0;	//ͳ���û�������������Ӷ���������ʱһҳ������
	string names;
	string temp_name;
	vector<string> stu_names;	//���ڴ洢Ҫ��ѯ��ѧ������
	system("cls");
	print_line();
	cout << "*             ";
	color_change_blue(">> ��ѯѧ���ķ���� <<");
	cout << "             *" << endl;
	print_line();
	cout << "������1������ѧ������,EOF����(����0�������˵�):" << endl;
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
				color_change_blue(">> ��ѯѧ���ķ���� <<");
				cout << "             *" << endl;
				print_line();
				cout << "������1������ѧ������,EOF����(����0�������˵�):" << endl;
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
			color_change_blue(">> ѧ����Ӧ�ķ���� <<");
			cout << "             *" << endl;
			print_line();
			cout << "δ����ѧ������,����������!" << endl;
			cout << "������1������ѧ������,EOF����(����0�������˵�):" << endl;
		}
		else
			break;
	}
	system("cls");
	print_line();
	cout << "*             ";
	color_change_blue(">> ѧ����Ӧ�ķ���� <<");
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
			cout << "�س���ʾ��һҳ(����0�������˵�)";
			quit_ch = getchar();
			if ('0' == quit_ch)
				return 1;
			system("cls");
			print_line();
			cout << "*             ";
			color_change_blue(">> ѧ����Ӧ�ķ���� <<");
			cout << "             *" << endl;
			print_line();
		}
		if ((it = students.find(*iter)) == students.end())
			cout << "*             " << *iter << string(12 - (*iter).size(), '-')
			<< "ѧ��������" << "             *" << endl;
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
	cout << "�س��������˵�";
	getchar();

	return 0;
}

//ͨ������Ų��ҷ���������ѧ��
int room2name(const Dorm& dorm)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	char quit_ch = NULL;	//��¼�ڷ�ҳ��ʾ�����У��û��Ƿ�Ҫ��;�˳��������˵�
	int count_line_num = 0;	//ͳ���������
	size_t floor_num;	//���ڴ洢Ҫ��ѯ�ķ����
	size_t room_num;
	string s;
	string blank;
	string sort_way;
	std::set<std::string> stu_name;
	system("cls");
	print_line();
	cout << "*            ";
	color_change_blue(">> ��ѯ����Ŷ�Ӧѧ�� <<");
	cout << "            *" << endl;
	print_line();
	cout << "�����뷿��ź���������ʽ(����0�������˵�)" << endl;
	cout << "(����Ϊasc,����Ϊdes)(��:07-12 asc):" << endl;
	
	while (getline(cin, s))
	{
		if (s == "0")
			return 1;
		else if (s.find('-') == string::npos)
		{
			system("cls");
			print_line();
			cout << "*            ";
			color_change_blue(">> ��ѯ����Ŷ�Ӧѧ�� <<");
			cout << "            *" << endl;
			print_line();
			cout << "������������������!" << endl;
			cout << "�����뷿��ź���������ʽ(����0�������˵�)" << endl;
			cout << "(����Ϊasc,����Ϊdes)(��:07-12 asc):" << endl;
		}
		else
		{
			sort_way = *(split(s).rbegin());
			if ((sort_way != "asc") && (sort_way != "des"))
			{
				system("cls");
				print_line();
				cout << "*            ";
				color_change_blue(">> ��ѯ����Ŷ�Ӧѧ�� <<");
				cout << "            *" << endl;
				print_line();
				cout << "������������������!" << endl;
				cout << "�����뷿��ź���������ʽ(����0�������˵�)" << endl;
				cout << "(����Ϊasc,����Ϊdes)(��:07-12 asc):" << endl;
			}
			else
				break;
		}
	}
	floor_num = atoi(s.substr(0, s.find('-')).c_str());
	room_num = atoi(s.substr(s.find('-') + 1).c_str());
	system("cls");
	print_line();
	cout << "*               >> �����:";
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
					cout << "�س���ʾ��һҳ(����0�������˵�)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					cout << "*               >> �����:";
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
					cout << "�س���ʾ��һҳ(����0�������˵�)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					cout << "*               >> �����:";
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
		cout << "*                  ����Ų�����                  *" << endl;
	}
	print_line();
	cout << "�س��������˵�";
	getchar();

	return 0;
}