#ifndef GUARD_URLS_H
#define GUARD_URLS_H

#include <vector>
#include <string>
using std::string;
using std::vector;

bool not_url_char(char);
string::const_iterator url_end(string::const_iterator, string::const_iterator);
string::const_iterator url_beg(string::const_iterator, string::const_iterator);
vector<string> find_urls(const string&);
std::vector<std::string> find_urls(const std::string& s);

#endif
