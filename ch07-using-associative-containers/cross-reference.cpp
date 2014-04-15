#include <cctype>
#include <vector>
using std::vector;

#include <algorithm>
#include <string>
using std::string;
#include <map>
using std::map;
#include <iostream>
using std::endl;
using std::cin;
using std::cout;
#include <istream>


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


// find all lines that refer to each word in the input
map<string, vector<int> > xref(
        std::istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    // read next line
    while (getline(in, line)) {
        ++line_number;

        // break input into words
        vector<string> words = find_words(line);

        // remember that each word occurs on current line
        for (vector<string>::const_iterator it = words.begin();
                it != words.end(); ++it) {
            ret[*it].push_back(line_number);
        }
    }
    return ret;
}


int main()
{
    // call xref using split by default
    map<string, vector<int>> ret = xref(cin);

    // write the results
    for (map<string, vector<int>>::const_iterator it = ret.begin();
            it != ret.end(); ++it) {
        cout << it->first << " occurs on line(s): ";

        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;  // write first line number

        ++line_it;
        // write rest of line nums, if any
        while (line_it != it->second.end()) {
            cout << ", " << *line_it;
            ++line_it;
        }

        // write new line to separate words
        cout << endl;
    }
    return 0;
}
