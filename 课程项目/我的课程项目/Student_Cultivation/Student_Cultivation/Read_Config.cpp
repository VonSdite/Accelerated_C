#include "Read_Config.h"

Config Configure::configure;										//����Configure��ľ�̬����

int Configure::read_conf(const char* f_name)
{
	std::ifstream infile(f_name);									//���������ļ�
	if (infile)
	{
		std::string s;
		std::string::size_type num;
		int flag = 0;												//���ڱ�־��ʽ�Ƿ�Ҫ���ж�ȡ
		std::string tmp;
		while (getline(infile, s))
		{
			//��������//������˵������Ϊע�ͣ���������ѭ��������һ�ζ�ȡ
			if ((('/' == s[0]) && ('/' == s[1])) || s.empty())		//�ж��Ƿ�Ϊע��
			{
				flag = 0;
				continue;
			}
			if ((num = s.find(":", 0)) != std::string::npos)
				configure[s.substr(0, num)] = &s[num + 2];
			else if ((num = s.find("=", 0)) != std::string::npos)
			{
				tmp = s.substr(0, num - 1);
				configure[tmp] = &s[num + 2];
				flag = 1;
			}
			else if (flag)
			{
				configure[tmp] += s;
			}
		}
	}
	else
	{
		std::cerr << "cannot open file " << f_name << std::endl;
		return 1;
	}

	return 0;
}
