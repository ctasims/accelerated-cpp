/*
 * Exercise 6.1
 * Reimplement frame and hcat operations from 5.8.1 and 5.8.3 to use iterators.
 */
#include <string>
using std::string;
#include <vector>
using std::vector;


string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    vector<string>::const_iterator iter;
    for (iter = v.begin(); iter != v.end(); ++iter) {
        maxlen = max(maxlen, iter->size());
    }
    return maxlen;
}


vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk and a space
    vector<string>::const_iterator iter;
    for (iter = v.begin(); iter != v.end(); ++iter) {
        ret.push_back("* " + *iter +
                string(maxlen - iter->size(), ' ') + " *");
    }

    // write the top border
    ret.push_back(border);
    return ret;
}


vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave space between pics
    string::size_type widthl = width(left) + 1;

    // indices to look at elemens from left and right respectively
    vector<string>::size_type i = 0, j = 0;
    vector<string>::const_iterator i = left.begin();
    vector<string>::const_iterator j = right.begin();

    // continue until we've seen all rows from both pictures
    while (i != left.end() || j != right.end()) {
        // construct new string to hold chars from both pictures
        string s;

        // copy a row from the left-hand side, if there is one
        if (i != left.end()) {
            s = *i++;
        }

        // pad to full width
        s += string(widthl - s.size(), ' ');

        // copy row from rhs, if there is one
        if (j != right.end()) {
            s += *j++;
        }

        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}
