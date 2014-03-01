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

    sort(words.begin(), words.end());

    int count = 1;
    int i;
    string word = words[0];

    for (i=1; i < words.size(); i++) {
        // next is same
        if (word == words[i])
            count++;
        else {
            cout << word << " " << count << endl;
            count = 1;
        }
        word = words[i];
    }
    cout << word << " " << count << endl;

    return 0;
}

