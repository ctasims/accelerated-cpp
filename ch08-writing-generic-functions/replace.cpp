#include <iostream>
#include <string>
using std::string;

template<class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
    while (beg != end) {
        if (*beg == x)
            *beg = y;
        ++beg;
    }
}

int main() {
    string str = "this is a bird";
    replace(str.begin(), str.end(), 'a', 'r');
    std::cout << str << std::endl;
    return 0;
}
