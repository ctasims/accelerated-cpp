#include <vector>
using std::vector;

#include <string>
using std::string;
using std::getline;

#include <cctype>
using std::isspace;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <istream>
using std::istream;


vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    // ivnariant: we have processed characters [original value of i, i)
    while (i != s.size()) {
        //ignore leading blanks
        // invariant: characters in range [origin i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the chars in range [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            ++j;

        // if we found some nonwhitespace chars
        if (i != j) {
            // copy from s starting at i and taking j - 1 chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }

    }
    return ret;
}


int main2()
{
    string s;

    // read and split each line of input
    while (getline(cin, s)) {
        vector<string> v = split(s);

        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); ++i) {
            cout << v[i] << endl;
        }
    }
    return 0;
}


int main()
{
    string s;
    while (cin >> s) {
        cout << s << endl;
    }
    return 0;
}
