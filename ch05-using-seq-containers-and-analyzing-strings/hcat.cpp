
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave space between pics
    string::size_type widthl = width(left) + 1;

    // indices to look at elemens from left and right respectively
    vector<string>::size_type i = 0, j = 0;

    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size()) {
        // construct new string to hold chars from both pictures
        string s;

        // copy a row from the left-hand side, if there is one
        if (i != left.size()) {
            s = left[i++];
        }

        // pad to full width
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
