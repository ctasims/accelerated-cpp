#include <iostream>
#include <string>
using std::string;


template <class In, class X> In find(In begin, In end, const X& x)
{
    while (begin != end && *begin != x)
        ++begin;
    return begin;
}


int main() {
    string str = "this is a bird";
    string::iterator it = find(str.begin(), str.end(), 'a');
    std::cout << *it << std::endl;
    return 0;
}
