// Rewritten, original from 6.5
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>

template<class In, class Fn> In find_if2(In b, In e, Fn p)
{
    while (b != e) {
        if (p(*b))
            return b;
        ++b;
    }
    return e;
}

bool inc(int n) {
    return n > 0;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = find_if2(nums.begin(), nums.end(), inc);
    cout << *res << endl;

    return 0;
}
