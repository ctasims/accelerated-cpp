#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <ostream>
#include <algorithm>
#include <iterator>
using std::ostream_iterator;


// true if the argument is whitespace, false otherwise
bool space(char c)
{
    return isspace(c);
}

// false is arg is whitespacae, true otherwise
bool not_space(char c)
{
    return !isspace(c);
}

template<class Out>
void split(const string& str, Out os)
{
    typedef string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy characters in [i, j)
        if (i != str.end())
            *os++ = string(i, j);

        i = j;
    }
}


int main()
{
    string s;
    while (getline(cin, s))
        split(s, ostream_iterator<string>(cout, "\n"));
    return 0;
}
