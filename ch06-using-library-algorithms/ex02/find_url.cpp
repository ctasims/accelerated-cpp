#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using std::string;
using std::vector;


bool not_url_char(char c)
{
    // characters, in addition to alphanumerics, that can appear in URL
    static const string url_ch = "~;/?:@=&$-_.+!*(),";

    // see whether c can appear in a URL and return the negative
    return !(
            std::isalnum(c) ||
            std::find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}


string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    /*
     * Find end of url string in between given iterators.
     */
    return std::find_if(b, e, not_url_char);
}


string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    typedef string::const_iterator iter;

    // i marks where the separator was found
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        // make sure the separator isn't at the beginning or end of the line
        if (i != b && i + sep.size() != e) {
            // beg marks beginning of the protocol name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            // is there at least one appropriate char before and after separator?
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }

        // the separator we found wasn't part of a URL.
        // Advance i past this separator.
        i += sep.size();
    }
    return e;
}


vector<string> find_url(const string &s)
{
    /*
     * Return all URL strings in given string.
     */
    std::vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // look through entire input
    while (b != e) {

        // look for one or more letters followed by ://
        b = url_beg(b, e);

        // if we found it
        if (b != e) {
            // get rest of URL
            iter after = url_end(b, e);

            // remember the URL
            ret.push_back(string(b, after));

            // advance b and check for more URLs on this line
            b = after;
        }
    }
    return ret;
}

