#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    int fail_count = 0;
    // for each file in the input list
    for (int i = 1; i < argc; ++i) {
        ifstream in(argv[i]);

        // if it exists, write its contents. Otherwise display error.
        if (in) {
            string s;
            while (getline(in, s))
                cout << s << endl;
        } else {
            cerr << "cannot open file " << argv[i] << endl;
            ++fail_count;
        }
    }
    return fail_count;
}
