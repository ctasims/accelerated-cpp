/*
 * Exercise 6.2 test the find_urls function.
 */
#include "find_url.h"
using std::string;
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string test = "test string http://google.com here's a broken one\n "
        "http:   //test.com but this one is good: "
        "https://github.com.";

    vector<string> urls = find_url(test);

    for (std::vector<string>::const_iterator i = urls.begin();
            i != urls.end(); ++i) {
        cout << *i << endl;
    }
    
}

