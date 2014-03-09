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

istream& read(istream& in, string &word);
bool is_palindrome(string);
string longest(vector<string> &words);


int main()
{
    vector<string> palindromes;
    string word;

    // iterate over word list
    std::ifstream infile("words.txt");
    while (read(infile, word))
        // check if word is palindrome and add to list
        if (is_palindrome(word))
            palindromes.push_back(word);

    // print palindromes
    for (vector<string>::const_iterator i = palindromes.begin();
            i != palindromes.end(); ++i) {
        cout << *i << endl;
    }
    cout << endl << endl;

    // find longest palindrome and print it.
    string longest_word = longest(palindromes);
    cout << "Longest palindrome is "<< longest_word << endl;

    return 0;
}


istream& read(istream& in, string &word) {
    /*
     * Read string from stream
     */
    in >> word;
    return in;
}


bool is_palindrome(string word)
{
    //  start at beginning and end of word
    //  match letters until i == j or i > j
    //  if at any time they don't match, return false
    //  otherwise return true at end
    string::size_type i, j, sz = word.size();
    for (i = 0, j = sz-1; i < j; ++i, --j)
        if (word[i] != word[j])
            return false;
    return true;
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

