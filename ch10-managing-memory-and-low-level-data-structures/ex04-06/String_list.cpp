
#include "String_list.h"
#include <algorithm>

using namespace std;


String_list::String_list() {}

String_list::String_list(list<string> l) {
    strings = l;
}

std::string String_list::front() const {
    return strings.front();
}

std::string String_list::back() const {
    return strings.back();
}

void String_list::push_front(std::string str) {
    strings.push_front(str);
}

void String_list::push_back(std::string str) {
    strings.push_back(str);
}

void String_list::pop_front() {
    strings.pop_front();
}

void String_list::pop_back() {
    strings.pop_back();
}


// true if the argument is whitespace, false otherwise
bool space(char c) { return isspace(c); }

// false is arg is whitespacae, true otherwise
bool not_space(char c) { return !isspace(c); }

String_list split(const string& str)
{
    typedef string::const_iterator iter;
    String_list sl;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy characters in [i, j)
        if (i != str.end())
            sl.push_back(string(i, j));

        i = j;
    }
    return sl;
}


int main() {
    list<string> testlist = {"one", "two", "three"};
    String_list sl1 = String_list(testlist);

    string splittest = "one two three";
    String_list split_str = split(splittest);

}
