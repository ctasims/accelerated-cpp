#include "word_read.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <ios>
using std::istream;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <algorithm>
using std::sort;


int main()
{
    vector<string> words;
    typedef vector<string>::size_type vec_sz;
    vec_sz num_words = 0;

    // read and store words
    read(cin, words);
    num_words = words.size();

    // sort words for counting
    sort(words.begin(), words.end());

    vec_sz i;
    int word_count = 0;
    string word = words[0];

    for (i=0; i != words.size(); i++) {
        if (word == words[i]) {
            word_count++;
        } else {
            cout << word << " seen " << word_count << " times" << endl;
            word_count = 1;
        }
        word = words[i];
    }
    cout << word << " seen " << word_count << " times" << endl;

    return 0;
}
