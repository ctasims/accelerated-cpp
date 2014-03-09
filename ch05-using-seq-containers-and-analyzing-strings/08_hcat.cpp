#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;


string::size_type width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = std::max(maxlen, v[i].size());
    }
    return maxlen;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave space between pics
    string::size_type widthl = width(left) + 1;

    // indices to look at elemens from left and right respectively
    vector<string>::size_type i = 0, j = 0;

    // construct new string to hold chars from both pictures
    string s;

    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size()) {

        // copy a row from the left-hand side, if there is one
        if (i != left.size()) {
            s = left[i++];
        }

        // pad to full width
        cout << s << endl;
        s += string(widthl - s.size(), ' ');

        // copy row from rhs, if there is one
        if (j != right.size()) {
            s += right[j++];
        }

        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}


int main()
{
    vector<string> left = {
        "*****",
        "aaaaa"
    };

    vector<string> right = {
        "*****",
        "bbbbb",
        "*****"
    };

    vector<string> result = hcat(left, right);

    // print result
    for (std::vector<string>::const_iterator i = result.begin(); i != result.end(); ++i) {
        cout << *i << endl;
    }
    
    return 0;
}
