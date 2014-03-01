#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;


int main()
{
    cout << "Please enter a list of numbers: ";
    vector<double> nums;

    // get numbers
    double x;
    while (cin >> x)
        nums.push_back(x);

    typedef vector<double>::size_type vec_sz;
    vec_sz sz = nums.size();

    // ensure numbers were entered
    if (sz == 0) {
        cout << "Please enter numbers." << endl;
        return 1;
    }

    sort(nums.begin(), nums.end());

    cout << "Number quartiles: " << endl;
    vec_sz median = nums.size() / 2;
    vec_sz quart = nums.size() / 4;
    cout << quart;

    vec_sz i;
    for (i=0; i < nums.size(); i++) {
        if (i == quart || i == median || i == (nums.size() - quart))
            cout << endl;

        cout << nums[i] << " ";
    }

    return 0;
}
