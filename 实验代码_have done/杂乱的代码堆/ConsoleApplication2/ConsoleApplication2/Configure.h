#ifndef GUARD_CONFIGURE_H
#define GUARD_CONFIGURE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>

class Configure
{
public:
	static int read_conf(const char*);
	static double get_conf(std::string);

private:
	static std::map<std::string, double> configure;
};
#endif // !GUARD_CONFIGURE_H

