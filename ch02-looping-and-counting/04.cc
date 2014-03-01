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
    const int pad = 1;

    // total # of rows to write
    const int rows = pad * 2 + 3;

    // separate output from input
    cout << endl;

    const string::size_type cols = greeting.size() + pad * 2 + 2;
    const string space_padding(greeting.size() + pad*2, ' ');

    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        // invariant: we have written c characters so far in the current row
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                // are we on border?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else {
                    // in pad line?
                    if (r != 0 && r != rows - 1 && r != pad + 1) {
                        cout << space_padding;
                        c += space_padding.size() - 1;
                    } else
                        cout << " ";
                }
                c++;
            }
        }
        cout << endl;
    }

    return 0;
}


