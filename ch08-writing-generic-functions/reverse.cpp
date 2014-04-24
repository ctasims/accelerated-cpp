#include <iostream>
#include <ostream>
#include <string>
#include <iterator>
#include <algorithm>
using std::string;


template<class Bi> void reverse2(Bi begin, Bi end)
{
    while (begin != end) {
        --end;
        if (begin != end)
            std::swap(*begin++, *end);
    }
}

int main() {
    string str = "this is a bird";
    reverse2(str.begin(), str.end());
    copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout));
    return 0;
}
