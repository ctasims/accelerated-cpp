#include <iostream>
using std::cout;

#include <iomanip>


int sqrt(int n) {
    return n * n;
}

// print squares of numbers up to 100.
// Values should line up nicely.
int main()
{
    int i;
    for (i=1; i != 101; ++i) {
        cout << std::setw(3) << i << '\t' << std::setw(5) << sqrt(i)
            << std::endl;
    }
}
