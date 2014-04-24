// Rewritten, original from 6.5
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>

template<class In, class Val> Val accumulate2(In b, In e, Val t)
{
    auto res = t;
    while (b != e)
        res += *b++;
    return res;
}


int main() {
    vector<int> nums = {1, 2, 3};
    auto res = accumulate2(nums.begin(), nums.end(), 1);
    cout << res << endl;

    return 0;
}
