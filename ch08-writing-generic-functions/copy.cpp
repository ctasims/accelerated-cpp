#include <iostream>
#include <ostream>
#include <string>
#include <iterator>
#include <algorithm>
using std::string;

template<class In, class Out>
Out copy2(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

int main() {
    string str = "this is a bird";
    string str2 = "I like a";
    copy2(str.begin(), str.end(),
            std::ostream_iterator<char>(std::cout));
    return 0;
}
