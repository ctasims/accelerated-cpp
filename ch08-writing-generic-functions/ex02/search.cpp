// Rewritten, original from 6.5
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>

template<class In> In search2(In b, In e, In b2, In e2)
{
    while (b != e) {
        auto el1 = *b;
        if (*b == *b2) {  // first element match. Inspect sub-sequence.
            In b3 = b;
            In b4 = b2;
            while (*b3++ == *b4++)
                ;
            if (b3 == e2)
                return b;
        }
        ++b;
    }
    return e;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> nums2 = {2, 3};
    auto res = search2(nums.begin(), nums.end(), nums2.begin(), nums2.end());
    cout << *res << endl;

    return 0;
}

