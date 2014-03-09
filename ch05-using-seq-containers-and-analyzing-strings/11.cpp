/*
 * Exercise 5.10: finding palindromes
 */
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
#include <iostream>
using std::istream;



bool has_ascender(string &word);
bool has_descender(string &word);
string longest(vector<string> &words);
istream& read(istream& in, string &word);


int main()
{
    std::ifstream infile("words.txt");
    string word;
    vector<string> cenders;

    while (read(infile, word)) {
        if (has_ascender(word) || has_descender(word))
            cenders.push_back(word);
    }

    // find longest
    string longest_cender = longest(cenders);
    cout << "Longest cender is " << longest_cender << endl;

    // test functions
    //string word;
    //while (cin >> word) {
        //if (has_ascender(word))
            //cout << word << " has ascender" << endl;
        //else if (has_descender(word))
            //cout << word << " has descender" << endl;
        //else
            //cout << word << " has neither" << endl;
    //}
    return 0;
}


bool has_ascender(string &word)
{
    char c;
    string::size_type i;
    for (i = 0; i < word.length(); i++) {
        c = word[i];
        // if ascender found, immediately return true.
        if (c == 'b' || c == 'd' || c == 'f' || c == 'h' || c == 'k' ||
                c == 'l' || c == 't') {
            return true;
        }
    }
    // no ascenders found.
    return false;
}


bool has_descender(string &word)
{
    char c;
    string::size_type i;
    for (i = 0; i < word.length(); i++) {
        c = word[i];
        // if descender found, immediately return true.
        if (c == 'g' || c == 'j' || c == 'p' || c == 'q' || c == 'y') {
            return true;
        }
    }
    // no descenders found.
    return false;
}


string longest(vector<string> &words)
{
    /*
     * Find longest word in a vector of words and return it
     */
    string::size_type max = 0;
    string longest = "";
    for (vector<string>::const_iterator i = words.begin(); i != words.end(); ++i) {
        if (i->size() > max) {
            max = i->size();
            longest = *i;
        }
    }
    return longest;
}

istream& read(istream& in, string &word)
{
    /*
     * Read string from stream
     */
    in >> word;
    return in;
}


