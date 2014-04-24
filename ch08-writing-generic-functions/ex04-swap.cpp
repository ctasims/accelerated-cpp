#include <iostream>
#include <ostream>
#include <string>
#include <iterator>
#include <algorithm>
using std::string;


template<class Val> void swap2(Val& x, Val& y) {
    auto temp = x;
    x = y;
    y = temp;
}

template<class Bi> void reverse2(Bi begin, Bi end)
{
    auto temp = *begin;
    while (begin != end) {
        --end;
        if (begin != end) {
            swap2(*begin++, *end);
            //temp = *begin;
            //*begin = *end;
            //*end = temp;
            //begin++;
        }
    }
}

int main() {
    string str = "this is a bird";
    reverse2(str.begin(), str.end());
    copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout));
    return 0;
}
