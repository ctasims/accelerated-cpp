// Rewritten, original from 6.5
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>

/**
 * Partition elements in range [b, e) according to whether they pass comp.
 * Track earliest elems that pass and fail.
 * Whenever elem is encountered that fails test, switch it with a pass if pass is later.
 */
template<class Out, class Val> Out remove2(Out b, Out e, Val t) {
    // track next elems that pass and fail the comp
    Out next_t = b;
    Out next_f = b;
    auto temp = *b;

    // operate until there are no more passing elements to check.
    while (next_f != e) {
        // find next matching element
        while (*next_t != t)
            next_t++;

        // find next failing element
        while (*next_f == t)
            next_f++;

        // switch with next failed elem if failed elem is later
        if ((next_t - next_f) < 0) {
            temp = *next_t;
            *next_t = *next_f;
            *next_f = temp;
        }
        ++next_f;
    }
    return next_t;
}


int main() {
    vector<int> nums = {5, -4, 1, -6, 7};
    remove2(nums.begin(), nums.end(), 1);
    copy(nums.begin(), nums.end(), std::ostream_iterator<int>(cout, " "));

    return 0;
}
