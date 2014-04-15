#include <string>
#include <cctype>
#include <vector>
#include <algorithm>


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


vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy chars in [i, j)
        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

