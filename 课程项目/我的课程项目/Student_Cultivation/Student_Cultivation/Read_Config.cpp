#include "Read_Config.h"

Config Configure::configure;										//定义Configure里的静态变量

int Configure::read_conf(const char* f_name)
{
	std::ifstream infile(f_name);									//读入配置文件
	if (infile)
	{
		std::string s;
		std::string::size_type num;
		int flag = 0;												//用于标志公式是否要多行读取
		std::string tmp;
		while (getline(infile, s))
		{
			//若读到“//”符则说明该行为注释，跳过本次循环继续下一次读取
			if ((('/' == s[0]) && ('/' == s[1])) || s.empty())		//判断是否为注释
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
