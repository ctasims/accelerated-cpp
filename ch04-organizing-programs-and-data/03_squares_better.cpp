#include <iostream>
using std::cout;

#include <iomanip>
#include <string>

#include <cmath>
using std::log10;


int sqrt(int n) {
    return n * n;
}

// similar to SO answer: how to get length of int
int get_num_length(int i) {
    return (int) log10 ((double) i) + 1;
}


// print squares of numbers up to 100.
// Values should line up nicely.
int main()
{
    int max = 1000;
    int i;
    int num_width = get_num_length(max);
    int sqr_width = get_num_length(sqrt(max));

    for (i=1; i != max; ++i) {
        cout << std::setw(num_width) << i << std::setw(sqr_width) << sqrt(i)
            << std::endl;
    }
}

