#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::string greeting = "Hello, " + name + "!"; // Note we CANNOT concatenate string literals,
                                                   // only string names with other string names or literals.
    std::string spaces (greeting.size(), ' ');  // Note this (int N, charC ) constructor repeats the char N times
    std::string second = "* " + spaces + " *";
    std::string first(second.size(), '*');

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " + greeting + " *" << std::endl; // Need to add additional * and space on each end
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;

}
