#include <cctype>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <istream>
#include <stdexcept>

using namespace std;


typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


// true if the argument is whitespace, false otherwise
bool space(char c) { return isspace(c); }

// false is arg is whitespacae, true otherwise
bool not_space(char c) { return !isspace(c); }

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy chars in [i, j)
        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}


// read a grammar from given input stream
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // read the input
    while (getline(in, line)) {
        // split input into words
        vector<string> entry = split(line);
        if (!entry.empty()) {
            // use category to store the associated rule
            ret[entry[0]].push_back(
                    Rule(entry.begin() + 1, entry.end()));
        }
    }
    return ret;
}


bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// return a random integer in the range [0, n)
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX) {
        throw domain_error("Argument to nrand is out of range");
    }

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}


template<class Out>
void gen_aux(const Grammar& g, const string& word, Out ret)
{
    if (!bracketed(word)) {
        *ret = word;
        ret++;
    } else {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");

        // fetch the set of possible results
        const Rule_collection& c = it->second;

        // from which we select one at random
        const Rule& r = c[nrand(c.size())];

        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
            gen_aux(g, *i, ret);
        }
    }
}


template<class Out>
void gen_sentence(const Grammar& g, Out ret)
{
    gen_aux(g, "<sentence>", ret);
}

int main()
{
    // generate the sentence
    vector<string> sentence;
    gen_sentence(read_grammar(cin), sentence.begin());

    // write first word, if any
    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }

    // write the rest of the words, each preceded by a space
    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    return 0;
}
