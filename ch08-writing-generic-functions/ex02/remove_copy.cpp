// Rewritten, originall from 6.5
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>


template<class In, class Out, class Val>
void remove_copy2(In b, In e, Out d, Val t)
{
    while (b != e) {
        if (*b != t)
            *d++ = *b;
        ++b;
    }
}


int main() {
    vector<int> nums = {5, -4, 1, -6, 7};
    vector<int> nums2;
    remove_copy2(nums.begin(), nums.end(), std::back_inserter(nums2), 1);
    copy(nums2.begin(), nums2.end(), std::ostream_iterator<int>(cout, " "));

    return 0;
}


