/*
 * Exercise 5.5
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::string;


bool compare(string const &lhs, string const &rhs)
{
    return lhs.size() < rhs.size();
}


vector<string> center(vector<string> &pic)
{
    /*
     * Given a picture, pad each line to its full with in a symmetric fashion.
     */
    // find longest line
    vector<string>::iterator longest = std::max_element(
            pic.begin(), pic.end(), compare);
    string longest_line = *longest;
    
    // for each line,
    // determine necessary padding
    // create string of left padding
    // add original line
    // then add right padding
    int padding;
    bool odd;
    vector<string> padded_pic;
    for (vector<string>::iterator i = pic.begin(); i != pic.end(); ++i) {
        string line;
        padding = longest_line.size() - i->size();
        odd = padding % 2 ? true : false;
        string padded_str(padding/2, ' ');
        line += padded_str;
        line += *i;
        line += padded_str;
        if (odd)
            line += ' ';

        padded_pic.push_back(line);

        cout << line << endl;
    }
    return padded_pic;
    
}


int main()
{
    vector<string> pic = {
        "abcd",
        "123123123",
        "abcde"
    };
    center(pic);

    return 0;
}
