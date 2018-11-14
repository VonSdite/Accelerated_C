#include "Configure.h"

std::map<std::string, double> Configure::configure;

int Configure::read_conf(const char* f_name)
{
	std::ifstream infile(f_name);
	if (infile)
	{
		std::string s;
		std::string::size_type num;
		while (getline(infile, s))
		{
			//��������//������˵������Ϊע�ͣ���������ѭ��������һ�ζ�ȡ
			if ((('/' == s[0]) && ('/' == s[1])) || s.empty())
				continue;
			//ȷ��ð������λ�ôӶ�����ð��ǰ���ַ���
			num = s.find(':', 0);
			configure[s.substr(0, num)] = atof(&s[num + 2]);
		}
		configure["LOVER_CHARM_DELTA"] /= 100;
	}
	else
	{
		std::cerr << "cannot open file " << f_name << std::endl;
		return 1;
	}

	return 0;
}

double Configure::get_conf(std::string conf_name)
{
	return configure[conf_name];
}
