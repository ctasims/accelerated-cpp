// rewrite median to use iterators and not pass vector by value
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;

template<class Val, class In> Val median2(In b, In e, Val x)
{
    typedef typename vector<Val>::size_type vec_sz;

    vec_sz size = e - b;
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(b, e);
    vec_sz mid = size/2;

    return x + (size % 2 == 0 ? (*(b+mid) + *(b+mid-1)) / 2 : *(b+mid));
}


int main()
{
    vector<int> ns = {1, 4, 5, 8, 6};
    double med = median2(ns.begin(), ns.end(), 0.0);
    cout << med << endl;
    return 0;
}
