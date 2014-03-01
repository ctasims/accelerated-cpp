// source file for word_read related functions

# include "word_read.h"

using std::vector;
using std::string;
using std::istream;


// read words into vector
istream& read(istream& in, vector<string>& words) {
    if (in) {
        // get rid of previous contents
        words.clear();

        // read words in
        string st;
        while (in >> st) {
            words.push_back(st);
        }

        // clear the stream so input will work next
        in.clear();
    }

    return in;
}
