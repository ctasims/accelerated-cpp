#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using std::vector;

template<class Ran, class X>
bool binary_search2(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
        // find midpoint of range
        Ran mid = begin + (end - begin) / 2;
        // see which part of the range contains x; keep looking there
        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        // *mid == x
        else return true;
    }
    return false;
}


int main() {
    vector<int> nums = {1, 4, 6, 7, 9, 11};
    bool res = binary_search2(nums.begin(), nums.end(), 4);
    std::cout << res << std::endl;
    return 0;
}
