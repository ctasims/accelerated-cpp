#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{

    // SQUARE
    const int square_s = 5;
    // invariant: we have written r rows so far
    for (int r = 0; r != square_s; ++r) {
        // invariant: we have written c characters so far in the current row
        for (string::size_type c = 0; c != square_s; c++) {
            // are we on border?
            if (r == 0 || r == square_s - 1 || c == 0 || c == square_s - 1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
    
    cout << endl;

    // RECTANGLE
    const int rect_w = 5;
    const int rect_l = 8;
    // invariant: we have written r rows so far
    for (int r = 0; r != rect_w; ++r) {
        // invariant: we have written c characters so far in the current row
        for (string::size_type c = 0; c != rect_l; c++) {
            // are we on border?
            if (r == 0 || r == rect_w - 1 || c == 0 || c == rect_l - 1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }

    cout << endl;


    // TRIANGLE
    const int tri_width = 31;
    const int tri_height = tri_width / 2 + 1;
    
    // top row? add *
    for (int r = 0; r != tri_height; r++) {
        for (int c = 0; c != tri_width; c++) {
            // top of triangle
            if (r == 0) cout << "*";
            else {
                if (c == r || c == tri_width - r - 1)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
