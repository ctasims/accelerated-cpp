// ask for a person's name and generate a framed greeting.
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    // build message we intend to write
    const string greeting = "Hello, " + name + "!";

    // number of blanks around the greeting
    const int side_pad = 1;

    const int vertical_pad = 2;

    // total # of rows to write
    const int rows = vertical_pad * 2 + 3;

    // separate output from input
    cout << endl;

    const string::size_type cols = greeting.size() + side_pad * 2 + 2;

    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        // invariant: we have written c characters so far in the current row
        while (c != cols) {
            if (r == vertical_pad + 1 && c == side_pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                // are we on border?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                c++;
            }
        }
        cout << endl;
    }

    return 0;
}

