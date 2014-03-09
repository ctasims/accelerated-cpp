#include <string>
#include <algorithm>


bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}
