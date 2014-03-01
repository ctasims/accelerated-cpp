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


int main()
{
    vector<string> words;
    typedef vector<string>::size_type vec_sz;
    vec_sz num_words = 0;

    // read and store words
    read(cin, words);
    num_words = words.size();

    cout << "You typed in " << num_words << " words." << endl;

    return 0;
}
