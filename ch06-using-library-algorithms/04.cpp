/*
 * Exercise 6.3
 *
 * Can either resize space or use back_inserter for resizing.
 * Can also just declare v using u or using size of u.
 *
 * back_inserter comes with ample overhead every time it's run.
 * Looks like it relies on push_back().
 *
 * `resize` method does extra work, so best is to just initialize with correct size.
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
    //vector<int> v(u.size());

    v.resize(u.size());
    copy(u.begin(), u.end(), v.begin());

    //copy(u.begin(), u.end(), std::back_inserter(v));

    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}
