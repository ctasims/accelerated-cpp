#include <string>
using std::string;
#include <map>
using std::map;
#include <iostream>
using std::endl;
using std::cin;
using std::cout;


int main()
{
    string s;
    map<string, int> counters;  // store each word and an associated counter

    // read input and keep track of each word and how often it's seen.
    while (cin >> s)
        ++counters[s];

    // write words and associated counts
    for (map<string, int>::const_iterator it = counters.begin();
            it != counters.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }
    return 0;
}
