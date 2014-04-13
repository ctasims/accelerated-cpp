#include <iostream>
#include <string>
#include <vector>
#include <numeric>


std::string concat(const std::vector<std::string>& s)
{
    /*
     * Concatenate all string in vector in one pass.
     */
    std::string str;
    for (std::vector<std::string>::const_iterator i = s.begin(); i != s.end(); ++i) {
        str += *i; 
    }
    return str; 
}

std::string concat2(const std::vector<std::string>& s)
{
    /*
     * Concatenate all string in vector in one pass.
     */
    std::string str;
    str = std::accumulate(s.begin(), s.end(), std::string(""));
    return str; 
}


int main()
{
    std::vector<std::string> s = {
        "first ",
        "second ",
        "third "
    };

    std::string result = concat(s);
    std::cout << result << std::endl;

    std::string result2 = concat2(s);
    std::cout << result2 << std::endl;

    return 0;
}
