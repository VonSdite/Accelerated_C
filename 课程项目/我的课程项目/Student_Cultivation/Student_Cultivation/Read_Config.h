//���������ļ���ȡ��Ľṹ
#ifndef GUARD_READ_CONFIG_H
#define GUARD_READ_CONFIG_H

#include <map>
#include <fstream>
#include <string>
#include <iostream>

#define dou(a) atof(const_cast<const char *>(a.c_str()))	//���ڽ������е��ַ���ת��Ϊdouble����

typedef std::map<std::string, std::string> Config;	//���ڴ洢��Ӧ��������Ϣ


//�����ļ���ȡ��Ľṹ
class Configure
{
public:
	static int read_conf(const char*);				//��ȡ�����ļ�
	static Config configure;						//�洢�����ļ���Ϣ
};


#endif // !GUARD_READ_CONFIG_H

