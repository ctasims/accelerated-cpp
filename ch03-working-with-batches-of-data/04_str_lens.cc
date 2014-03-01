#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;


int main()
{
    cout << "Please enter a list of words: ";
    vector<string> words;

    // get numbers
    string x;
    while (cin >> x)
        words.push_back(x);

    typedef vector<string>::size_type vec_sz;
    vec_sz sz = words.size();

    // ensure numbers were entered
    if (sz == 0) {
        cout << "Please enter words." << endl;
        return 1;
    }

    int shortest = words[0].length();
    int longest = words[0].length();
    string::size_type len = 0;
    vec_sz i;
    string word;

    for (i=1; i < words.size(); i++) {
        word = words[i];
        len = word.length();
        if (len < shortest)
            shortest = len;
        else if (len > longest)
            longest = len;
    }
    cout << "Longest string: " << longest << endl;
    cout << "Shortest string: " << shortest << endl;

    return 0;
}


