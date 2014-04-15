#include <string>
using std::string;

#include <map>
using std::map;

#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <vector>
using std::vector;


int main()
{
    string s;
    map<string, int> counters;  // store each word and an associated counter
    map<int, vector<string>> sorted_counters;

    // read input and keep track of each word and how often it's seen.
    while (cin >> s)
        ++counters[s];

    // track counters in sorted order
    for (map<string, int>::const_iterator it = counters.begin();
            it != counters.end(); ++it) {
        sorted_counters[it->second].push_back(it->first);
    }


    // iterate over words with same # occurrences
    for (map<int, vector<string>>::const_iterator it = sorted_counters.begin();
            it != sorted_counters.end(); ++it) {
        vector<string> words = it->second;
        // for each set of words, print occurrence #
        for (vector<string>::const_iterator s = words.begin();
                s != words.end(); ++s) {
            cout << *s << "\t" << counters[*s] << endl;
        }
    }
    return 0;
}
