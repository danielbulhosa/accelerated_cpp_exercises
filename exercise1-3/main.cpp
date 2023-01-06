#include <iostream>
#include <string>

int main() {
    // This program is valid because each "version" of s is properly
    // defined within its particular scope.
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
    }
    {
        const std::string s = "another string";
        std::cout << s << std::endl;
    }
    return 0;
}
