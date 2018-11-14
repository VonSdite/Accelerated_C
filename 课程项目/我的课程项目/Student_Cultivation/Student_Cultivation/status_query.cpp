//ѧ��״̬��ѯ
#include "status_query.h"
#include <windows.h>
#include <iomanip>

//�궨����ӷ������ɫ����
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

//������ʾÿһ��״̬��
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

//ĳѧ��״̬��ѯ
int stu_status_query(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	string blank;	//���ڴ洢�м�����Ŀո�
	system("cls");
	string name;
	print_line();
	cout << "*             ";
	color_change_blue(">> ��ѯĳѧ����״̬ <<");
	cout << "             *" << endl;
	print_line();
	cout << "������ѧ������(����0�������˵�):";
	while ((cin >> name) && (students.find(name) == students.end()))
	{
		system("cls");
		print_line();
		cout << "*             ";
		color_change_blue(">> ��ѯĳѧ����״̬ <<");
		cout << "             *" << endl;
		print_line();
		if (name == "0")
			return 1;
		cout << "ѧ�������ڣ�" << endl;
		cout << "����������ѧ������(����0�������˵�):";
	}
	//����students��const���ã����Բ���ֱ��ʹ��[]�����
	Students::const_iterator iter = students.find(name);
	system("cls");
	//������
	print_line();
	blank = string((32 - (iter->second).name().size()) / 2, ' ');
	cout << '*' << blank << ">> " << (iter->second).name() << "��״̬��Ϣ" << " <<" << blank << '*' << endl;
	//������
	print_line();
	blank = string((24 - (iter->second).name().size()) / 2, ' ');
	cout << "*         ����         ||" << blank << (iter->second).name() << blank << '*' << endl;
	//�Ա���
	print_line();
	cout << "*         �Ա�         ||" << "           ";
	if ("��" == (iter->second).sex())
		cout << "��";
	else
		cout << "Ů";
	cout << "           *" << endl;
	//״̬��
	print_status("����", (iter->second).weight());
	print_status("��Ǯ", (iter->second).money());
	print_status("֪ʶ", (iter->second).knowledge());
	if ("��" == (iter->second).sex())
		print_status("����", (iter->second).special());
	else
		print_status("��ò", (iter->second).special());
	print_status("����", (iter->second).charm());

	print_line();
	cout << "*       " << "����ѧ����" << "     ||";
	string blank2 = string(9, ' ');
	cout << blank2 << " ";
	if ((iter->second).get_is_quit_school())
		cout << "��";
	else cout << "��";
	cout << blank2 << "   *" << endl;

	print_line();
	cout << "*       " << "�Ƿ�������" << "     ||";
	string blank3 = string(9, ' ');
	cout << blank3 << " ";
	if ((iter->second).love_status())
		cout << "��";
	else cout << "��";
	cout << blank3 << "   *" << endl;


	print_line();
	cout << "*         " << "�����" << "       ||";
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
	cout << "�س��������˵�";
	cin.ignore();
	getchar();

	return 0;
}

//���״̬��ֵ
int print_max_status(string item, const vector<Students::const_iterator>& max,
	const vector<Students::const_iterator>& min, double max_num, double min_num)
{
	char quit_ch = NULL;	//��¼�ڷ�ҳ��ʾ�����У��û��Ƿ�Ҫ��;�˳��������˵�
	int count_line_num = 0;
	string blank;
	int num_length;
	system("cls");
	print_line();
	cout << '*' << string(18, ' ') << item << "��ֵ��ѯ" << string(18, ' ') << '*' << endl;
	print_line();
	cout << "*      ��ֵ     ||     ����     ||     ��ֵ      *" << endl;
	cin.ignore();
	streamsize prec = cout.precision();
	for (vector<Students::const_iterator>::const_iterator iter = max.begin(); iter != max.end(); iter++)
	{
		if (count_line_num == 9)
		{
			count_line_num = 0;
			print_line();
			cout << "�س���ʾ��һҳ(����0�������˵�)";
			quit_ch = getchar();
			if ('0' == quit_ch)
				return 1;
			system("cls");
			print_line();
			cout << '*' << string(18, ' ') << item << "��ֵ��ѯ" << string(18, ' ') << '*' << endl;
			print_line();
			cout << "*      ��ֵ     ||     ����     ||     ��ֵ      *" << endl;
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
			cout << "�س���ʾ��һҳ(����0�������˵�)";
			quit_ch = getchar();
			if ('0' == quit_ch)
				return 1;
			system("cls");
			print_line();
			cout << '*' << string(18, ' ') << item << "��ֵ��ѯ" << string(18, ' ') << '*' << endl;
			print_line();
			cout << "*      ��ֵ     ||     ����     ||     ��ֵ      *" << endl;
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
	setprecision(prec);	//���������Ϊһ��ʼ��״̬
	print_line();

	return 0;
}

//״̬��ֵ��ѯ
int status_max_query(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	string status;	//���ڶ���Ҫ��ѯ��״̬����
	vector<Students::const_iterator> max;	//���ڱ���ָ���״̬���ֵѧ���ĵ�����
	vector<Students::const_iterator> min;	//���ڱ���ָ���״̬��Сֵѧ���ĵ�����
	double max_num, min_num;	//���ڴ洢״̬�����Сֵ
	system("cls");
	print_line();
	cout << "*               ";
	color_change_blue(">> ״̬��ֵ��ѯ <<");
	cout << "               *" << endl;
	print_line();
	cout << "������Ҫ��ѯ��״̬(��:����)(����0�������˵�):";
	while ((cin >> status) && (status != "0"))
	{
		if (status == "����")
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
			print_max_status("����", max, min, max_num, min_num);
			cout << "�س��������˵�";
			getchar();
			break;
		}
		if (status == "��Ǯ")
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
			print_max_status("��Ǯ", max, min, max_num, min_num);
			cout << "�س��������˵�";
			getchar();
			break;
		}
		if (status == "֪ʶ")
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
			print_max_status("֪ʶ", max, min, max_num, min_num);
			cout << "�س��������˵�";
			getchar();
			break;
		}
		if (status == "��ò")
		{
			Students::const_iterator iter = students.begin();
			while ("��" == (iter->second).sex())
				iter++;
			if (iter == students.end())
			{
				cout << "ѧ��������û��Ů��" << endl;
				cout << "�س��������˵�";
				cin.ignore();
				getchar();
				break;
			}
			max.push_back(iter);
			min.push_back(iter);
			min_num = max_num = (iter->second).special();
			for (; iter != students.end(); iter++)
			{
				if ("Ů" == (iter->second).sex())
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
			print_max_status("��ò", max, min, max_num, min_num);
			cout << "�س��������˵�";
			getchar();
			break;
		}
		if (status == "����")
		{
			Students::const_iterator iter = students.begin();
			while ("Ů" == (iter->second).sex())
				iter++;
			if (iter == students.end())
			{
				cout << "ѧ��������û������" << endl;
				cout << "�س��������˵�";
				cin.ignore();
				getchar();
				break;
			}
			max.push_back(iter);
			min.push_back(iter);
			min_num = max_num = (iter->second).special();
			for (; iter != students.end(); iter++)
			{
				if ("��" == (iter->second).sex())
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
			print_max_status("����", max, min, max_num, min_num);
			cout << "�س��������˵�";
			getchar();
			break;
		}
		if (status == "����")
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
			print_max_status("����", max, min, max_num, min_num);
			cout << "�س��������˵�";
			getchar();
			break;
		}
		else
		{
			system("cls");
			print_line();
			cout << "*               ";
			color_change_blue(">> ״̬��ֵ��ѯ <<");
			cout << "               *" << endl;
			print_line();
			cout << "�������!" << endl;
			cout << "����������Ҫ��ѯ��״̬(����0�������˵�):";
		}
	}

	return 0;
}

//��ʾ������õķ�Χ��ѯ����
int show_sorted_stu(const map<double, set<string> >& sorted_stu, string item, string sort_way)
{
	char quit_ch = NULL;	//��¼�ڷ�ҳ��ʾ�����У��û��Ƿ�Ҫ��;�˳��������˵�
	int count_line_num = 0;		//�洢������������Ӷ��������ʱһҳ������
	int num_length;	//�洢״ֵ̬����
	system("cls");
	print_line();
	cout << "*               >> " << item << "��Χ��ѯ <<               *" << endl;
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
					cout << "�س���ʾ��һҳ(����0�������˵�)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					cout << "*               >> " << item << "��Χ��ѯ <<               *" << endl;
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
		cout << "�س��������˵�";
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
					cout << "�س���ʾ��һҳ(����0�������˵�)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					cout << "*               >> " << item << "��Χ��ѯ <<               *" << endl;
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
		cout << "�س��������˵�";
		getchar();
	}

	return 0;
}

//״̬��Χ��ѯ
int status_range_query(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	//���ڴ洢����������ѧ����״ֵ̬��ʹ��map���ڶ�״ֵ̬����ʹ��set���ڶ���������
	map<double, set<string> > sorted_stu;
	double min_num, max_num;	//�洢��ѯ��Χ
	string sort_way;	//�洢��ʾ������ʽ
	string status;	//�洢Ҫ��ѯ��״̬����
	system("cls");
	print_line();
	cout << "*               ";
	color_change_blue(">> ״̬��Χ��ѯ <<");
	cout << "               *" << endl;
	print_line();
	cout << "������״̬����Χ������ʽ(����0�������˵�)" << endl;
	cout << "(����Ϊasc,����Ϊdes)(��:���� 70 80 asc):" << endl;
	while ((cin >> status) && (status != "0"))
	{
		if (!(cin >> min_num >> max_num >> sort_way) || (min_num > max_num) ||
			((sort_way != "asc") && (sort_way != "des")))
		{
			system("cls");
			print_line();
			cout << "*               ";
			color_change_blue(">> ״̬��Χ��ѯ <<");
			cout << "               *" << endl;
			print_line();
			cout << "������������������!" << endl;
			cout << "������״̬����Χ������ʽ(����0�������˵�)" << endl;
			cout << "(����Ϊasc������Ϊdes)(��:���� 70 80 asc):" << endl;
			continue;
		}
		cin.ignore();
		if ("����" == status)
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
		if ("��Ǯ" == status)
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
		if ("֪ʶ" == status)
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
		if ("��ò" == status)
		{
			for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
			{
				if ("��" == (iter->second).sex())
					continue;
				if ((min_num > (iter->second).knowledge()) || (max_num < (iter->second).knowledge()))
					continue;
				sorted_stu[(iter->second).knowledge()].insert((iter->second).name());
			}
			show_sorted_stu(sorted_stu, status, sort_way);
			break;
		}
		if ("����" == status)
		{
			for (Students::const_iterator iter = students.begin(); iter != students.end(); iter++)
			{
				if ("Ů" == (iter->second).sex())
					continue;
				if ((min_num > (iter->second).knowledge()) || (max_num < (iter->second).knowledge()))
					continue;
				sorted_stu[(iter->second).knowledge()].insert((iter->second).name());
			}
			show_sorted_stu(sorted_stu, status, sort_way);
			break;
		}
		if ("����" == status)
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