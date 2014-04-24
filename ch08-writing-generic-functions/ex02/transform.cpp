// Rewritten, original from 6.5
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>


template<class In, class Fn, class Out>
void transform2(In b, In e, Out d, Fn comp)
{
    while (b != e)
        *d++ = comp(*b++);
}


int inc(int n) {
    return n + 1;
}

int main() {
    vector<int> nums = {5, -4, 1, -6, 7};
    vector<int> nums2;
    transform2(nums.begin(), nums.end(), std::back_inserter(nums2), inc);
    copy(nums2.begin(), nums2.end(), std::ostream_iterator<int>(cout, " "));

    return 0;
}
