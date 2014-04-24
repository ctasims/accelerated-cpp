#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;


template<class Type, class Iter>
Type median2(const Iter b, const Iter e)
{
    vector<Type> v(b, e);

    auto size = v.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(v.begin(), v.end());
    auto mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

int main() {
    const int arr[] = {1, 4, 6, 7};
    size_t arr_size = sizeof(arr)/sizeof(*arr);
    vector<int> arr2 = {1, 4, 6, 7};

    cout << median2<int>(arr, arr+arr_size) << " "
        << median2<int>(arr2.begin(), arr2.end()) << endl;
}
