#ifndef GUARD_find_url
#define GUARD_find_url

// find_url header file
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

std::vector<std::string> find_url(const std::string &s);
bool not_url_char(char c);

std::string::const_iterator url_end(
        std::string::const_iterator b, std::string::const_iterator e);

std::string::const_iterator url_beg(
        std::string::const_iterator b, std::string::const_iterator e);

#endif
