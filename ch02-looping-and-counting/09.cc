#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main()
{
    int num1;
    int num2;
    cout << "Enter integer 1: ";
    cin >> num1;
    cout << "Enter integer 2: ";
    cin >> num2;

    if (num1 > num2)
        cout << "First is larger" << endl;
    else if (num1 < num2)
        cout << "Second is larger" << endl;
    else
        cout << "They're equal!" << endl;

    return 0;
}



