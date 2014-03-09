#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <cctype>
#include <string>
using std::string;

int main()
{
    vector<string> lowercase;
    vector<string> uppercase;
    string s;

    while (cin >> s) {
        if (std::isupper(s[0])) {
            uppercase.push_back(s);
        } else {
            lowercase.push_back(s);
        }
    }

    for (std::vector<string>::const_iterator i = lowercase.begin();
            i != lowercase.end(); ++i) {
        cout << *i << " ";
    }

    // now print uppercase words
    for (std::vector<string>::const_iterator i = uppercase.begin();
            i != uppercase.end(); ++i) {
        cout << *i << " ";
    }
    
}
