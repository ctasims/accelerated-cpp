// Rewritten, originall from 6.5
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>


template<class In, class Out, class Fn>
void remove_copy_if2(In b, In e, Out d, Fn p)
{
    while (b != e) {
        if (!p(*b))
            *d++ = *b;
        ++b;
    }
}


int inc(int n) {
    return n < 0;
}

int main() {
    vector<int> nums = {5, -4, 1, -6, 7};
    vector<int> nums2;
    remove_copy_if2(nums.begin(), nums.end(), std::back_inserter(nums2), inc);
    copy(nums2.begin(), nums2.end(), std::ostream_iterator<int>(cout, " "));

    return 0;
}

