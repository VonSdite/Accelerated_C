//ѧ��������ѯ
#include "lover_query.h"
#include <windows.h>

//�궨����ӷ������ɫ����
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)



//����ĳ��ѧ��������ʷ
int lover_history_query(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	string s;
	int sort_num;
	int num_length;
	char quit_ch = NULL;	//��¼�ڷ�ҳ��ʾ�����У��û��Ƿ�Ҫ��;�˳��������˵�
	int count_line_num = 0;	//ͳ���������
	string name;	//���ڴ洢Ҫ��ѯ��ѧ������
	set<string> stu_name;	//�����������洢��set�б��ڶ���������
	map<double, set<string> > stu_charm_name;	//����������ֵ�������洢��map��set�У����ڶ�����ֵ����������
	string blank;
	string status;	//��ʾѧ����ǰ����״̬
	system("cls");
	print_line();
	cout << "*             ";
	color_change_blue(">> ��ѯĳѧ������ʷ <<");
	cout << "             *" << endl;
	print_line();
	cout << "*                   1.ʱ������                   *" << endl;
	cout << "*                   2.��������                   *" << endl;
	cout << "*                   3.��������                   *" << endl;
	print_line();
	cout << "������ѧ������������ʽ" << endl;
	cout << "��(���� 1)(����0�������˵�):" << endl;
	while (cin >> name)
	{
		if ("0" == name)
			return 1;
		if (students.find(name) == students.end())
		{
			system("cls");
			print_line();
			cout << "*             ";
			color_change_blue(">> ��ѯĳѧ������ʷ <<");
			cout << "             *" << endl;
			print_line();
			cout << "*                   1.ʱ������                   *" << endl;
			cout << "*                   2.��������                   *" << endl;
			cout << "*                   3.��������                   *" << endl;
			print_line();
			cout << "ѧ�������ڣ�����������!" << endl;
			cout << "������ѧ������������ʽ" << endl;
			cout << "��(���� 1)(����0�������˵�):" << endl;
			cin.ignore();
			continue;
		}
		cin >> sort_num;
		if ((sort_num < 1) || (sort_num > 3))
		{
			system("cls");
			print_line();
			cout << "*             ";
			color_change_blue(">> ��ѯĳѧ������ʷ <<");
			cout << "             *" << endl;
			print_line();
			cout << "*                   1.ʱ������                   *" << endl;
			cout << "*                   2.��������                   *" << endl;
			cout << "*                   3.��������                   *" << endl;
			print_line();
			cout << "������������������!" << endl;
			cout << "������ѧ������������ʽ" << endl;
			cout << "��(���� 1)(����0�������˵�):" << endl;
			continue;
		}
		break;
	}
	Students::const_iterator iter = students.find(name);
	const vector<string>& lover_history = (iter->second).get_lover_history();
	system("cls");
	print_line();
	blank = string((34 - (iter->second).name().size()) / 2, ' ');
	cout << '*' << blank << ">> " << (iter->second).name() << "������ʷ" << " <<" << blank << '*' << endl;
	print_line();
	if ((iter->second).love_status())
	{
		blank = string((28 - (iter->second).get_lover_name().size()) / 2, ' ');
		status = "*" + blank + "��" + (iter->second).get_lover_name() + "����ing(*�����*)/" + blank + "*";
	}
	else
	{
		status = "*             ������������o(�R�ڨQ)o             *";
	}
	cout << status << endl;
	print_line();
	cin.ignore();
	if (0 == lover_history.size())
		cout << "*                   ����ʷΪ��                   *" << endl;
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
					cout << "�س���ʾ��һҳ(����0�������˵�)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					blank = string((34 - (iter->second).name().size()) / 2, ' ');
					cout << '*' << blank << ">> " << (iter->second).name() << "������ʷ" << " <<" << blank << '*' << endl;
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
					cout << "�س���ʾ��һҳ(����0�������˵�)";
					quit_ch = getchar();
					if ('0' == quit_ch)
						return 1;
					system("cls");
					print_line();
					blank = string((34 - (iter->second).name().size()) / 2, ' ');
					cout << '*' << blank << ">> " << (iter->second).name() << "������ʷ" << " <<" << blank << '*' << endl;
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
			cout << "*                 ����----����ֵ                 *" << endl;
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
						cout << "�س���ʾ��һҳ(����0�������˵�)";
						quit_ch = getchar();
						if ('0' == quit_ch)
							return 1;
						system("cls");
						print_line();
						blank = string((34 - (iter->second).name().size()) / 2, ' ');
						cout << '*' << blank << ">> " << (iter->second).name() << "������ʷ" << " <<" << blank << '*' << endl;
						print_line();
						cout << status << endl;
						print_line();
						cout << "*                 ����----����ֵ                 *" << endl;
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
	cout << "�س��������˵�";
	getchar();

	return 0;
}

//��ѯ����ʷ����ѧ��
int lover_history_max(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	char quit_ch = NULL;	//��¼�ڷ�ҳ��ʾ�����У��û��Ƿ�Ҫ��;�˳��������˵�
	int count_line_num = 0;	//�洢������������Ӷ��������ʱһҳ������
							//���ڴ洢����ʷ����ѧ��������ʹ��set���ڶ���������
	set<string> stu_name;
	//���ڴ洢ָ������ʷ���ѧ���ĵ�����,�ȴ洢�������������λ�ȡѧ����������Ч��
	vector<Students::const_iterator> max_stu;
	int num_length;
	size_t max_num = 0;
	system("cls");
	print_line();
	cout << "*             ";
	color_change_blue(">> ����ʷ����ѧ�� <<");
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
			cout << "�س���ʾ��һҳ(����0�������˵�)";
			quit_ch = getchar();
			if ('0' == quit_ch)
				return 1;
			system("cls");
			print_line();
			cout << "*             ";
			color_change_blue(">> ����ʷ����ѧ�� <<");
			cout << "             *" << endl;
			print_line();
		}
		cout << "*                 " << *iter << string(14 - (*iter).size() - num_length, '-')
			<< max_num << "                 *" << endl;
		count_line_num++;
	}
	print_line();
	cout << "�س��������˵�";
	getchar();

	return 0;
}

//��ѯ��������ֵ����ѧ��
int lover_charm_max(const Students& students)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	char quit_ch = NULL;	//��¼�ڷ�ҳ��ʾ�����У��û��Ƿ�Ҫ��;�˳��������˵�
	int count_line_num = 0;	//�洢������������Ӷ��������ʱһҳ������
	int num_length;
	vector<Students::const_iterator> max;	//���ڱ���ָ���������ֵѧ���ĵ�����
	set<string> max_stu_name;	//���ڱ����������ֵ��ѧ��������ʹ��set���ڶ�ѧ��������������
	double max_num = (students.begin()->second).charm();	//���ڴ洢״̬�����Сֵ
	max.push_back(students.begin());
	system("cls");
	print_line();
	cout << "*           ";
	color_change_blue(">> ��������ֵ��ߵ�ѧ�� <<");
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
			cout << "�س���ʾ��һҳ(����0�������˵�)";
			quit_ch = getchar();
			if ('0' == quit_ch)
				return 1;
			system("cls");
			print_line();
			cout << "*           ";
			color_change_blue(">> ��������ֵ��ߵ�ѧ�� <<");
			cout << "           *" << endl;
			print_line();
		}
		cout << "*" << string(14, ' ') << *iter << string(20 - (*iter).size() - num_length, '-') << fixed <<
			setprecision(2) << max_num << string(14, ' ') << '*' << endl;
		count_line_num++;
	}
	setprecision(prec);
	print_line();
	cout << "�س��������˵�";
	getchar();

	return 0;
}