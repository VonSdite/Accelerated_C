//定义配置文件读取类的结构
#ifndef GUARD_READ_CONFIG_H
#define GUARD_READ_CONFIG_H

#include <map>
#include <fstream>
#include <string>
#include <iostream>

#define dou(a) atof(const_cast<const char *>(a.c_str()))	//便于将解析中的字符串转换为double类型

typedef std::map<std::string, std::string> Config;	//用于存储相应的配置信息


//配置文件读取类的结构
class Configure
{
public:
	static int read_conf(const char*);				//读取配置文件
	static Config configure;						//存储配置文件信息
};


#endif // !GUARD_READ_CONFIG_H

