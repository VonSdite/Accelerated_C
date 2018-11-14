#pragma once

#include <algorithm>
#include <cctype>
#include <string>

#include "List.h"

using std::find_if;
using std::isspace;
using std::string;

inline bool space(char c) {
	return isspace(c);
}

inline bool not_space(char c) {
	return !isspace(c);
}

List<string> split(const string& str) {          // changed
	List<string> l;
	typedef string::const_iterator iter;
	iter i = str.begin();

	while (i != str.end()) {
		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word
		iter j = find_if(i, str.end(), space);

		// copy the characters in `[i,' `j)'
		if (i != str.end())
			l = cons(string(i, j), l);

		i = j;
	}

	return reverse(l);
}
