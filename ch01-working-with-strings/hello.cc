// ask for a person's name and then greet them
#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter your first name: ";

    // read the name
    std::string name;
    std::cin >> name;

    // write greeting
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}
