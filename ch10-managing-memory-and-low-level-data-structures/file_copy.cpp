#include <string>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream infile("in");
    ofstream outfile("out");

    string s;

    while (getline(infile, s))
        outfile << s << endl;
    return 0;
}
