// Rewritten, original from 6.5
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>

template<class In> bool equal2(In b, In e, In d)
{
    while (b != e) {
        if (*b++ != *d++)
            return false;
    }
    return true;

}

int main() {
    vector<int> nums = {2, 3};
    vector<int> nums2 = {2, 3};
    auto res = equal2(nums.begin(), nums.end(), nums2.begin());
    cout << res << endl;

    return 0;
}

