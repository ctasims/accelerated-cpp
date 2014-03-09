// Exercise 5.1

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <sstream>
#include <string>
using std::string;

#include <algorithm>

#include <vector>
using std::vector;

#include <numeric>
#include <iterator>


vector<string> split(const string &s, char);
vector<string> &split(const string &s, char, vector<string> &elems);
vector< vector<string> > generate_rotations(const string);
void print_index(vector<string>&, int);
string concat_vec_strings(vector<string>&,
        vector<string>::iterator,
        vector<string>::iterator);


int main()
{

    vector< vector<string> > all_rotations;
    vector<string> input_lines;
    string line;
    
    // read in all input
    while (std::getline(cin, line)) {
        input_lines.push_back(line);
    }

    // break lines into vectors of words
    vector<string>::size_type num_lines = input_lines.size();

    // for each input line, generate rotations.
    vector<string>::const_iterator iter;
    for (iter = input_lines.begin(); iter != input_lines.end(); ++iter) {
        // each rotation is vector of strings, one word per string.
        // End/beginnig of phrase is marked by '\t' string.
        vector< vector<string> > rotations = generate_rotations(*iter);

        // append rotations to our full set
        all_rotations.insert(all_rotations.end(),
                rotations.begin(), rotations.end());
    }

    // sort all rotations based on beginning word.
    std::sort(all_rotations.begin(), all_rotations.end(),
            std::less< vector<string> >());


    vector< vector<string> >::iterator phrase;
    int margin = 20;
    for (phrase = all_rotations.begin(); phrase != all_rotations.end();
            ++phrase) {
        print_index(*phrase, margin);
    }

    return 0;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


// from http://stackoverflow.com/a/236803/875127
vector<string> &split(const string &s, char delim, vector<string> &elems) {
    std::stringstream ss(s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector< vector<string> > generate_rotations(const string phrase) {
    /*
     * Given a string of words, generate all rotations of that string.
     */
    vector<string> v_phrase = split(phrase, ' ');
    // Add phrase delimiter to know where it actually ends.
    int num_words = v_phrase.size();
    v_phrase.push_back("00");
    vector< vector<string> > rotations;
    for (int i = 0; i != num_words; ++i) {
        // determine beginning word of next rotation
        rotations.push_back(v_phrase);
        std::rotate(v_phrase.begin(), v_phrase.begin() + 1, v_phrase.end());
    }
    return rotations;
}


void print_index(vector<string> &line, int margin) {
    /*
     * Print formatted index line
     */
    // find position of delimiter in vector
    int delim_pos = std::find(line.begin(), line.end(), "00") - line.begin();
    // compile second part of string
    string pre_string = concat_vec_strings(line,
            line.begin()+delim_pos+1, line.end());
    //string pre_string = std::accumulate(
            //line.begin()+delim_pos+1, line.end(), string(" ") );
    // compile first part of string
    //int start = delim_pos + 1;
    string post_string = concat_vec_strings(line,
            line.begin(), line.begin()+delim_pos);
    //string post_string = std::accumulate(
            //line.begin(), line.begin()+delim_pos, string(" ") );
    //cout << endl << pre_string << endl;
    //cout << "3";
    // build string of empty spaces to account for margin
    string spaces(margin - pre_string.length(), ' ');
    cout << spaces << pre_string << '\t' << post_string << endl;
    //string test = std::accumulate(line.begin(), line.end(), string("") );
    //cout << test << endl;

    return;
}


string concat_vec_strings(vector<string> &vec,
        vector<string>::iterator start,
        vector<string>::iterator end) {
    std::stringstream ss;
    std::copy(start, end, std::ostream_iterator<string>(ss, " "));
    string result = ss.str();
    if (!result.empty()) {
        result.resize(result.length() - 1);  // trim trailing space
    }
    return result;
}
