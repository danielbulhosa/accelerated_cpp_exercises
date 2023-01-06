#include <iostream>

int main() {
    // Note that strings on different lines without intervening operators get concatenated, just like in Python.
    // We just needed to add the appropriate new line characters and escape characters to have the code print out correctly.
    std::cout
        << "#include <iostream>\n"
           "\n"
           "int main() {\n"
           "    std::cout << \"Hello, World!\" << std::endl;\n"
           "    return 0;"
        << std::endl;
    return 0;
}
