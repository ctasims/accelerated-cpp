/*
 * Exercise 6.3
 * Line 1 creates a vector with ten instances of the int 100.
 * Line 3 wants to copy u into v, but the size of the vector isn't defined.
 * Perhaps it throws an error.
 *
 * Yep, it crashes on the copy.
 *
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::copy;

#include <iterator>


int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());

    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}
