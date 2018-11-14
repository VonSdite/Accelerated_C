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
			//若读到“//”符则说明该行为注释，跳过本次循环继续下一次读取
			if ((('/' == s[0]) && ('/' == s[1])) || s.empty())
				continue;
			//确定冒号所在位置从而读到冒号前的字符串
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
