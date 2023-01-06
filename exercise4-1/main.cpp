#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // We write a shorter program to test the idea.
    std::string ex_string = "hello there";
    int ex_int = 2;
    // This FAILS because there is not function (template) with this signature!
    // To get it to work we need to declare ex_int to be of std::string:size_type type.
    std::max(ex_int, ex_string);

    return 0
}
